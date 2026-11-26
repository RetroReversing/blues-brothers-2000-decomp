/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_8002E018();
s32 func_8002E100();
s32 vec3Sub();

s32 func_8002E26C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp10[0x10];
    u8 sp20[0x10];

    vec3Sub(sp10, arg2, arg1);
    vec3Sub(sp20, arg3, arg1);
    func_8002E018(arg0, sp10, sp20);
    func_8002E100(arg0, arg0);
    return arg0;
}
