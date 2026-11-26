typedef struct X90E50B { s32 f0; u8 pad4[8]; s32 fC; u8 pad10[4]; s32 f14; } X90E50B;
typedef struct X90E50A { u8 pad0[8]; s32 f8; u8 padC[8]; s32 f14; s32 f18; X90E50B *f1C; } X90E50A;
s32 func_80091AD0(s32, void *, s32);

s32 func_80090E50(X90E50A *arg0) {
    if (arg0 == NULL || arg0->f1C == NULL) {
        return -2;
    }
    arg0->f14 = 0;
    arg0->f8 = 0;
    arg0->f18 = 0;
    arg0->f1C->f0 = -(arg0->f1C->fC != 0) & 7;
    func_80091AD0(arg0->f1C->f14, arg0, 0);
    return 0;
}

