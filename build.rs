use cc;

fn main() {
    cc::Build::new()
        .file("src/positionner/M2_POS_Control.c")
        .file("src/positionner/M2_POS_Control_data.c")
        .compile("m2_pos_controller");
    cc::Build::new()
        .file("src/piezostack/M2_PZT_Control.c")
        .file("src/piezostack/M2_PZT_Control_data.c")
        .compile("m2_pzt_controller");
    cc::Build::new()
        .file("src/tiptilt/TT_Control.c")
        .file("src/tiptilt/TT_Control_data.c")
        .compile("m2_tt_controller");
}
