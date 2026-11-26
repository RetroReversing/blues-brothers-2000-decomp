typedef struct { u32 w0; u32 w1; } Gfx;

extern s32 D_800B5E10;
extern Gfx D_800B7488[][4];
extern Gfx D_800B7490[][4];
extern s32 D_80140304;
extern s32 D_80140308;

Gfx *func_80045678(Gfx *gfx, s32 mode, s32 flags) {
    Gfx *t;
    s32 i;

    if (D_80140304 == 0 && (flags & 1) && D_80140308 != mode) {
        D_80140308 = mode;
        if (mode == 2) {
            i = D_800B5E10; *gfx++ = D_800B7490[i][0];
        } else {
            i = D_800B5E10; *gfx++ = D_800B7488[i][0];
        }
    }
    return gfx;
}
