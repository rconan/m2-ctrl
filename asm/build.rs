use cc;

fn main() {
    cc::Build::new()
        .file("src/positionner/M2_POS_Control.c")
        .file("src/positionner/M2_POS_Control_data.c")
        .compile("m2_pos_controller");
    cc::Build::new()
        .file("src/ptt_fluid_damping/pttASMC_FluidD.c")
        .file("src/ptt_fluid_damping/pttASMC_FluidD_data.c")
        .compile("m2_ptt_asmC_fd");
}
