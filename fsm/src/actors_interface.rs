#![allow(irrefutable_let_patterns)]
/*!
# GMT Fast Steering Mirror control clients

The module implements the client interface for the GMT FSM control model from the [m2-ctrl] crate,
it includes:
 - the M2 positionner client
 - the M2 piezostack client
 - the M2 segment tip-tilt controller client

*The 3 clients are enabled with the `fsm` feature.*

# Example

M2 positionner actor:
```
use dos_actors::clients::fsm::*;
use dos_actors::prelude::*;
let mut m2_positionner: Actor<_> = fsm::positionner::Controller::new().into();
```

M2 piezostack actor:
```
# use dos_actors::clients::fsm::*;
# use dos_actors::prelude::*;
let mut m2_piezostack: Actor<_> = fsm::piezostack::Controller::new().into();
```

M2 segment tip-tilt actor:
```
# use dos_actors::clients::fsm::*;
# use dos_actors::prelude::*;
let sim_sampling_frequency: usize = 1000;//Hz
const FSM_RATE: usize = 5;
assert_eq!(sim_sampling_frequency / FSM_RATE, 200);
let mut m2_tiptilt: Actor<_, FSM_RATE, 1> = fsm::tiptilt::Controller::new().into();
```

[m2-ctrl]: https://github.com/rodrigo-romano/m2-ctrl-code/tree/2022-03-update
*/
use super::{piezostack, positionner, tiptilt};
use dos_actors::{
    impl_read, impl_update, impl_write,
    io::{Data, Read, UniqueIdentifier, Write},
    Update, UID,
};
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
/// piezostack input and tiptilt output
#[derive(UID)]
pub enum PZTcmd {}
/// piezostack input
#[derive(UID)]
pub enum PZTFB {}
/// piezostack output
#[derive(UID)]
pub enum PZTF {}
/// tiptilt input
#[derive(UID)]
pub enum TTSP {}
/// tiptilt output
#[derive(UID)]
pub enum TTFB {}

impl_update! {positionner}
impl_read! {positionner, (M2poscmd, m2_pos_cmd), (M2posFB, m2_pos_fb)}
impl_write! {positionner, (M2posactF,m2_pos_act_f)}
#[cfg(feature = "fem")]
impl_write! {fem::fem_io::MCM2SmHexF, positionner, (M2posactF,m2_pos_act_f)}
#[cfg(feature = "fem")]
impl_read! {fem::fem_io::MCM2SmHexD,positionner, (M2posFB, m2_pos_fb)}

impl_update! {piezostack}
impl_read! {piezostack, (PZTcmd, pzt_cmd), (PZTFB, pzt_fb)}
impl_write! {piezostack, (PZTF, pzt_f)}
#[cfg(feature = "fem")]
impl_read! {fem::fem_io::MCM2PZTD, piezostack, (PZTFB, pzt_fb)}
#[cfg(feature = "fem")]
impl_write! {fem::fem_io::MCM2PZTF,piezostack, (PZTF, pzt_f)}

impl_update! {tiptilt}
impl_read! {tiptilt, (TTSP, tt_sp), (TTFB, tt_fb)}
impl_write! {tiptilt, (PZTcmd, pzt_cmd)}
