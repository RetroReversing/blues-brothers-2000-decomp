/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_80026E84(f64, s32 *, s32, s32); /* extern */
s32 func_8002889C();

void func_800272AC(f32 arg0, s32 arg1) {
    u8 sp18[0x20];

    func_80026E84((f64) arg0, sp18, 0xA, 2);
    func_8002889C(sp18);
}
