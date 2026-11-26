void *func_80023874(s32, s32);
f32 func_8002D77C(void *, f32, s32);
s32 func_8003C9AC(void *, s32, s32, s32);
void func_800433A8(void *, s32, s32, void *);
void func_800899DC(char *);
extern char D_80000BEC[];
extern void *D_800B3960;
extern s32 D_800B5DD4;
extern void *D_800BD06C;
extern s32 func_8001AC3C;
extern s32 func_80023078;
extern s32 func_80034F50;
extern s32 func_8004303C;

typedef struct { u8 pad_0[4]; f32 x; f32 y; f32 z; } Vec;

void func_8001AD84(void *arg0) {
    f32 lim;
    void *o;
    void *p;
    void *q;
    void *r;

    lim = 500.0f;
    if (func_8002D77C(arg0, lim, 0) < lim && *(s32 *)((s8 *)D_800BD06C + 0xB8) == 5 && func_8003C9AC(arg0, 0, 1, 0) != 0) {
        *(void **)((s8 *)arg0 + 0x9C) = (s8 *)&func_80023078 + 8;
        o = func_80023874(0x137, 0);
        if (o != NULL) {
            *(void **)((s8 *)o + 0x9C) = &func_8001AC3C;
        }
        o = func_80023874(0x11F, 0);
        if (o != NULL) {
            ((Vec *)D_800B3960)->x = ((Vec *)o)->x;
            ((Vec *)D_800B3960)->y = ((Vec *)o)->y;
            ((Vec *)D_800B3960)->z = ((Vec *)o)->z;
            *(void **)((s8 *)D_800B3960 + 0xD8) = *(void **)((s8 *)D_800B3960 + 0x9C);
            *(void **)((s8 *)D_800B3960 + 0x9C) = &func_80034F50;
            p = func_80023874(0x1002, 0);
D_800B5DD4 = 0;
q = D_800BD06C;
*(void **)((s8 *)D_800B3960 + 0xA8) = p;
r = D_800B3960;
            func_800433A8(q, 1, 0x100, r);
            *(void **)((s8 *)D_800BD06C + 0x9C) = &func_8004303C;
            *(s32 *)((s8 *)func_80023874(6, 0) + 0x68) = -1;
            return;
        }
        func_800899DC(D_80000BEC);
    }
}
