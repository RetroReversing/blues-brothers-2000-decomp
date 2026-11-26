typedef struct { s32 a; s32 b; } Pair8;
s32 debugPrintf();
extern char D_80007C78[];
extern s32 D_800B7690;
extern Pair8 D_801407C8[];
void func_800486F8(s32 arg0) {
    s32 i;
    if (arg0 >= D_800B7690) {
        debugPrintf(D_80007C78);
    }
    for (i = arg0; i < D_800B7690 - 1; i++) { D_801407C8[i] = D_801407C8[i + 1]; }
    D_800B7690 -= 1;
}
