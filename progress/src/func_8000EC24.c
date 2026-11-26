s16 coss(u16);
s16 sins(u16);
void func_80015C30(void *);
void *func_80023874(s32, void *);
void func_8002A360(s32, s32);
s32 func_8002D204(s32, s32, s32);
void func_8002D620(void *, void *);
f32 func_8002D66C(void *, f32, s32 *);
void func_800433A8(void *, s32, s32);
void func_8000EB94(void *);

typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x4C - 0x14];
    f32 x4C;
    f32 x50;
    f32 x54;
    char pad58[0x64 - 0x58];
    s32 x64;
    char pad68[0x70 - 0x68];
    s32 x70;
    char pad74[0x9C - 0x74];
    void (*fn9C)(void *);
    char padA0[0xAC - 0xA0];
    s32 xAC;
    s32 xB0;
    s32 xB4;
    char padB8[0xD0 - 0xB8];
    s32 xD0;
} Obj;

extern f32 D_800004EC;
extern f32 D_800004F0;
extern f32 D_800004F4;
extern f32 D_800004F8;
extern f32 D_800004FC;
extern f32 D_80000500;
extern f32 D_80000504;
extern Obj *D_800B3964[];
extern s32 D_800B9ECC[];
extern u8 D_800BD06C[];
#define BD (*(Obj **)D_800BD06C)

void func_8000EC24(Obj *arg0) {
    s32 ang;
    f32 lim;
    f32 d;
    s32 speed;
    s32 i;
    s32 t;
    Obj *e;

    lim = D_800004EC;
    d = func_8002D66C(arg0, lim, &ang);
    if (lim <= d) {
        return;
    }
    if (BD->xC < arg0->xC - D_800004F0) {
        return;
    }
    if (BD->x8 > arg0->x8) {
        return;
    }
    if (BD->xD0 != 11) {
        return;
    }
    speed = (s32)(lim - d);
    speed *= 20;
    speed = (D_800B9ECC[0] * speed) / 600;
    if (D_800004F0 <= d) {
        BD->x10 = func_8002D204(ang + 0x8000, BD->x10, D_800B9ECC[0] << 9);
        BD->xC += (speed * coss(ang - 0x8000)) >> 15;
        BD->x4 += (speed * sins(ang - 0x8000)) >> 15;
        return;
    }
    if (d < D_800004F0) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x57);
        for (i = 0; i < 4; i++) {
            func_80015C30(arg0);
        }
        BD->x8 = D_800004F4;
        if (arg0->x70 == 3) {
            BD->x8 = D_800004F8;
        }
        BD->xC = D_800004FC;
        e = func_80023874(0x1021, 0);
        while (e != 0) {
            if (e->x70 == arg0->x70) {
                BD->x4 = e->x4;
                break;
            }
            e = func_80023874(0x1021, e);
        }
        if (e != 0) {
            D_800B3964[0]->x70 = e->x70;
        }
        BD->x4C = 0.0f;
        BD->x50 = 0.0f;
        BD->x54 = D_80000500;
        BD->x10 = 0x8000;
        func_8002D620(BD, e);
        BD->fn9C = func_8000EB94;
        BD->xAC = 0;
        BD->xB0 = 0;
        BD->xB4 = 0;
        BD->x64 = 300;
        BD->x50 = D_80000504;
        func_800433A8(BD, 0x10, 0x100);
    }
}
