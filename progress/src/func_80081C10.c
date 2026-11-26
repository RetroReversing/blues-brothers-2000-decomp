s32 randomRange(s32, s32);
typedef struct { s32 n; s32 b; s32 c; } RecA;
typedef struct { s32 v[5]; s32 w; s32 x; } RecB;
extern s32 D_800B87F0[];
extern s32 D_800B8808[];
extern RecB D_800B8EB0[];
extern RecA D_800B9000[];

void func_80081C10(void) {
    s32 i;
    s32 j;
    s32 *p;
    RecB *b;

    for (i = 1; i < 12; i++) {
        j = D_800B9000[i].n;
        b = &D_800B8EB0[i];
        for (; j < 5; j++) {
            b->v[j] = D_800B87F0[randomRange(0, 4)];
        }
        b->w = D_800B8808[randomRange(0, 5)];
    }
}
