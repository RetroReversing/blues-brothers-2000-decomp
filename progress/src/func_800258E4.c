typedef struct {
    s32 a;
    s32 b;
} Pair;

extern void func_800A1D20(void *, s32 *);
extern void func_800258B0(void *);
extern void debugPrintf(char *, ...);
extern void *heapAlloc(s32);
extern void func_8002B410(void *, void *, s32);
extern char D_800010E0[];
extern s32 D_800AE140;
extern s32 D_80106A40;
extern Pair *D_80106A44;
extern u8 D_B00BD1E0[];

void func_800258E4(void) {
    s32 n;
    s32 i;
    Pair *p;

    if (D_800AE140 == 0) {
        func_800A1D20(D_B00BD1E0, &n);
        func_800258B0(&n);
        if (n >= 0xED9) {
            debugPrintf(D_800010E0, n, 0xED8);
        }
        p = heapAlloc(n * 8);
        D_80106A44 = p;
        func_8002B410(D_B00BD1E0 + 8, p, n * 8);
        for (i = 0; i < n; i++) {
            func_800258B0(&D_80106A44[i].a);
            func_800258B0(&D_80106A44[i].b);
            D_80106A44[i].a += (s32)D_B00BD1E0;
        }
        D_800AE140 = 1;
        D_80106A40 = n;
    }
}
