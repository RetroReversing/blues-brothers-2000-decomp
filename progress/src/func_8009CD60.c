/* identical to func_80039AD0 in PENNY RACERS (matched), with its names changed by decompdecomp */
s32 func_800970B0(void);
void func_800970D0(s32);
extern s32 *D_800BB5B0;

s32 func_8009CD60(void) {
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = func_800970B0();
    temp_s0 = D_800BB5B0[1];
    func_800970D0(temp_v0);
    return temp_s0;
}
