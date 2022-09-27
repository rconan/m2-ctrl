#![allow(irrefutable_let_patterns)]
/*! GMT Adaptive Secondary Mirror control clients

*/

use dos_actors::{
    impl_read, impl_update, impl_write,
    io::{Data, Read, UniqueIdentifier, Write},
    Update, UID,
};

use super::{positionner, ptt_fluid_damping};
use std::{ptr, sync::Arc};

/// positionner input
#[derive(UID)]
pub enum M2poscmd {}
/// positionner input
#[derive(UID)]
pub enum M2posFB {}
/// positionner output
#[derive(UID)]
pub enum M2posactF {}
/// Adaptive Optics controller piston, tilt and tilt inputs
#[derive(UID)]
pub enum Rrbfs {}
/// ASM 7 face sheets displacement
#[derive(UID)]
pub enum ASMFS6D {}
/// ASM 7 rigid bodies displacement displacement
#[derive(UID)]
pub enum ASMRB6D {}
/// ASM 7 cold plates force and moment
#[derive(UID)]
pub enum Ucp {}
/// ASM 7 rigid bodies force and moment
#[derive(UID)]
pub enum Urb {}
/// ASM 7 face sheets force and moment
#[derive(UID)]
pub enum Ufs {}

impl_update! {positionner}
impl_read! {positionner, (M2poscmd, m2_pos_cmd), (M2posFB, m2_pos_fb)}
impl_write! {positionner, (M2posactF,m2_pos_act_f)}
#[cfg(feature = "fem")]
impl_write! {positionner, (fem::fem_io::MCM2SmHexF, M2posactF,m2_pos_act_f)}
#[cfg(feature = "fem")]
impl_read! {positionner, (fem::fem_io::MCM2SmHexD, M2posFB, m2_pos_fb)}

impl_update! {ptt_fluid_damping}
impl_read! {ptt_fluid_damping, (Rrbfs, rrbfs), (ASMFS6D, asm_fs_6d), (ASMRB6D, asm_rb_6d)}
impl_write! {ptt_fluid_damping, (Ucp,ucp), (Urb,urb), (Ufs,ufs)}
#[cfg(feature = "fem")]
impl_write! {ptt_fluid_damping,
(fem::fem_io::MCM2CP6F, Ucp, ucp),
(fem::fem_io::MCM2RB6F, Urb, urb),
(fem::fem_io::MCM2Lcl6F, Ufs, ufs)}
#[cfg(feature = "fem")]
impl_read! {ptt_fluid_damping,
(fem::fem_io::MCM2Lcl6D, ASMFS6D, asm_fs_6d),
(fem::fem_io::MCM2RB6D, ASMRB6D, asm_rb_6d)}

#[cfg(test)]
mod tests {
    use super::*;
    type ASM<'a> = m2_ctrl::ptt_fluid_damping::Controller<'a>;

    fn norm(u: &[f64]) -> f64 {
        u.iter().map(|x| x * x).sum::<f64>().sqrt() // / u.len() as f64
    }

    #[test]
    fn zero_inputs() {
        let mut asm = ASM::new();
        for _ in 0..1000 {
            <ASM as Read<Rrbfs>>::read(&mut asm, Arc::new(Data::new(vec![0f64; 21])));
            <ASM as Read<ASMRB6D>>::read(&mut asm, Arc::new(Data::new(vec![0f64; 42])));
            <ASM as Read<ASMFS6D>>::read(&mut asm, Arc::new(Data::new(vec![0f64; 42])));
            asm.update();
        }
        let u_cp: Option<f64> = <ASM as Write<Ucp>>::write(&mut asm).map(|x| norm(&x));
        let u_rb: Option<f64> = <ASM as Write<Urb>>::write(&mut asm).map(|x| norm(&x));
        let u_fs: Option<f64> = <ASM as Write<Ufs>>::write(&mut asm).map(|x| norm(&x));
        println!("{:#?}{:#?}{:#?}", u_cp, u_rb, u_fs);
    }

    #[test]
    fn rrbfs_inputs() {
        let mut asm = ASM::new();
        for i in 0..100 {
            let mut rb_fs = vec![0.; 21];
            rb_fs[0] = 1e-6;
            <ASM as Read<Rrbfs>>::read(&mut asm, Arc::new(Data::new(rb_fs)));
            let mut asm_rb = vec![0.; 42];
            <ASM as Read<ASMRB6D>>::read(&mut asm, Arc::new(Data::new(asm_rb)));
            let mut asm_fs = vec![0.; 42];
            <ASM as Read<ASMFS6D>>::read(&mut asm, Arc::new(Data::new(asm_fs)));
            asm.update();
            let u_cp = <ASM as Write<Ucp>>::write(&mut asm);
            let u_rb = <ASM as Write<Urb>>::write(&mut asm);
            let u_fs = <ASM as Write<Ufs>>::write(&mut asm);
            /*             println!(
                "{i}.\nUcp: {:#.12?}\nUrb: {:#.12?}\nUfs: {:#.12?}",
                u_cp, u_rb, u_fs
            ); */
            if i == 99 {
                let u: &[f64] = u_cp.as_ref().unwrap();
                println!("Ucp[{i}]: {:?}", u);
                let u: &[f64] = u_rb.as_ref().unwrap();
                println!("Urb[{i}]: {:?}", u);
                let u: &[f64] = u_fs.as_ref().unwrap();
                println!("Ufs[{i}]: {:?}", u);
            }
        }
    }

    #[test]
    fn asmrb_inputs() {
        let mut asm = ASM::new();
        for i in 0..100 {
            let mut rb_fs = vec![0.; 21];
            <ASM as Read<Rrbfs>>::read(&mut asm, Arc::new(Data::new(rb_fs)));
            let mut asm_rb = vec![1e-6; 42];
            <ASM as Read<ASMRB6D>>::read(&mut asm, Arc::new(Data::new(asm_rb)));
            let mut asm_fs = vec![0.; 42];
            <ASM as Read<ASMFS6D>>::read(&mut asm, Arc::new(Data::new(asm_fs)));
            asm.update();
            let u_cp: Option<f64> = <ASM as Write<Ucp>>::write(&mut asm).map(|x| norm(&x));
            let u_rb: Option<f64> = <ASM as Write<Urb>>::write(&mut asm).map(|x| norm(&x));
            let u_fs: Option<f64> = <ASM as Write<Ufs>>::write(&mut asm).map(|x| norm(&x));
            println!(
                "{i}.\nUcp: {:#.12?}\nUrb: {:#.12?}\nUfs: {:#.12?}",
                u_cp, u_rb, u_fs
            );
        }
    }

    #[test]
    fn asmfs_inputs() {
        let mut asm = ASM::new();
        for i in 0..10 {
            let mut rb_fs = vec![0.; 21];
            <ASM as Read<Rrbfs>>::read(&mut asm, Arc::new(Data::new(rb_fs)));
            let mut asm_rb = vec![0.; 42];
            <ASM as Read<ASMRB6D>>::read(&mut asm, Arc::new(Data::new(asm_rb)));
            let mut asm_fs = vec![1e-6; 42];
            <ASM as Read<ASMFS6D>>::read(&mut asm, Arc::new(Data::new(asm_fs)));
            asm.update();
            let u_cp: Option<f64> = <ASM as Write<Ucp>>::write(&mut asm).map(|x| norm(&x));
            let u_rb: Option<f64> = <ASM as Write<Urb>>::write(&mut asm).map(|x| norm(&x));
            let u_fs: Option<f64> = <ASM as Write<Ufs>>::write(&mut asm).map(|x| norm(&x));
            println!(
                "{i}.\nUcp: {:#.12?}\nUrb: {:#.12?}\nUfs: {:#.12?}",
                u_cp, u_rb, u_fs
            );
        }
    }
}
