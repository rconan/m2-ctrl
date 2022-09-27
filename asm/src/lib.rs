pub mod positionner;
pub mod ptt_fluid_damping;
mod actors_interface;
use actors_interface::*;

#[cfg(test)]
mod tests {
    use crate::ptt_fluid_damping::{U, Y};

    use super::*;
    #[test]
    fn positionner() {
        let _ = positionner::Controller::new();
    }
    #[test]
    fn ptt_fluid_damping() {
        let mut asm = ptt_fluid_damping::Controller::new();
        if let U::Rrbfs(u) = &mut asm.rrbfs {
            u[0] = 1e-6
        }
        for _ in 0..100 {
            asm.next();
        }
        if let Y::Ucp(y) = &asm.ucp {
            println!("Ucp: {:?}", y);
        }
        if let Y::Urb(y) = &asm.urb {
            println!("Urb: {:?}", y);
        }
        if let Y::Ufs(y) = &asm.ufs {
            println!("Ufs: {:?}", y);
        }
    }
}
