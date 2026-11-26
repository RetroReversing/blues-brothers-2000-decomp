/* identical to __osPfsGetStatus in PENNY RACERS (matched), with its names changed by decompdecomp */
extern s8 D_800A3B34;
extern u8 D_8017DC10[];
s32 func_8009DB00(s32, void *);
s32 func_800A13B0(s32);
s32 __osPfsGetOneChannelData(s32, void *);
s32 osRecvMesg(s32, void *, s32);

s32 func_800A12D0(s32 arg0, s32 arg1) {
    u8 sp10[8];
    u8 sp18[8];
    s32 temp_s0;

    func_800A13B0(arg1);
    func_8009DB00(1, D_8017DC10);
    osRecvMesg(arg0, sp18, 1);
    temp_s0 = func_8009DB00(0, D_8017DC10);
    osRecvMesg(arg0, sp18, 1);
    __osPfsGetOneChannelData(arg1, sp10);
    if ((sp10[2] & 1) && (sp10[2] & 2)) {
        return 2;
    }
    if ((*(u16 *)&sp10[2] & 0x1FF) != 0x100) {
        return 1;
    }
    if (sp10[2] & 4) {
        return 4;
    }
    return temp_s0;
}
