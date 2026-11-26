/* identical to func_80057050 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80195100 in BATMAN BEYOND RETURN (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8005E820 in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800C2F30 in AIDYN_CHRONICLES (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80064BF0 in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800A93A0 in TWINE (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009D8B0(void);

s32 func_800A9350(u32 devAddr, u32 *data) {
    if (func_8009D8B0()) {
        return -1;
    }
    *data = *(volatile u32 *)(devAddr | 0xA0000000);
    return 0;
}

s32 siRawWriteIo(u32 devAddr, u32 data) {
    if (func_8009D8B0()) {
        return -1;
    }
    *(volatile u32 *)(devAddr | 0xA0000000) = data;
    return 0;
}
