typedef struct {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    u8 pad10[2];
    u16 unk12;
} Unk800BD06C_579E0;

typedef struct Unk800579E0 {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    s32 unk10;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x6C - 0x68];
    s32 unk6C;
    u8 pad70[0x7C - 0x70];
    s32 unk7C;
    u8 pad80[0x90 - 0x80];
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
    u8 padA0[0xC0 - 0xA0];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    s32 (*unkD8)(struct Unk800579E0 *);
    u8 padDC[0x100 - 0xDC];
    f32 unk100;
} Unk800579E0;

extern Unk800BD06C_579E0 *D_800BD06C;

s32 func_8004303C(void *arg0_in);
s32 func_80083920(void *o, s32 arg1);
s16 sins(u16);
s16 coss(u16);
void func_8002ADFC(s32 ch, s32 range, void *src);
void func_8002A360(s32, s32);
void func_8002D124(void);
void func_80043328(void *arg0, s32 arg1, s32 arg2);
s32 func_8002492C(f32, f32);
void func_800433A8(void *arg0, s32 arg1, s32 arg2);
f32 func_8002D66C(void *o, f32 r, s32 *ang);
s16 *func_800851D8(void *arg0);
s32 func_800571F4(void *arg0);
s32 func_80024394(s32 arg0, s32 arg1);
s32 func_8005738C(Unk800579E0 *);
s32 func_800571B0(Unk800579E0 *);
s32 func_80057858(Unk800579E0 *);
s32 func_80057658(Unk800579E0 *);
s32 func_800574D8(Unk800579E0 *);

void func_800579E0(Unk800579E0 *arg0) {
    s32 done;
    s32 result;
    s32 flags;
    s32 angle;
    f32 dist;

    if (arg0->unk6C == 0) {
        arg0->unk6C = 1;
        arg0->unkD8 = func_8005738C;
    }
    done = func_8004303C(arg0);
    flags = arg0->unkC0;
    result = func_80083920(arg0, arg0->unk7C);
    switch (result) {
    case 1:
        arg0->unk4 += (f32)((sins(D_800BD06C->unk12) * 5) >> 14);
        arg0->unkC += (f32)((coss(D_800BD06C->unk12) * 5) >> 14);
        arg0->unk7C = result;
        if (flags & 0x40) {
            func_8002ADFC(0xAE, 6000, arg0);
        } else {
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x2E);
            func_8002D124();
        }
        func_80043328(arg0, 0xC4, 0x100);
        done = 0;
        break;
    case 2:
        arg0->unk10 = func_8002492C(D_800BD06C->unk4 - arg0->unk4, D_800BD06C->unkC - arg0->unkC);
        arg0->unk9C = func_800571B0;
        func_800433A8(arg0, 0xC3, 0x100);
        return;
    }
    if (arg0->unk7C != 0) {
        if (done != 0) {
            arg0->unk7C = 0;
        }
        return;
    }
    dist = func_8002D66C(arg0, 2000.0f, &angle);
    arg0->unk100 = dist;
    arg0->unk90 = angle;
    if (dist < func_800851D8(arg0)[1]) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x4C);
        if (func_800571F4(arg0) == 0) {
            return;
        }
    }
    done = 0;
    if (arg0->unkD8 != NULL) {
        done = arg0->unkD8(arg0);
    }
    if (done == 0) {
        return;
    }
    switch (arg0->unkD0) {
    case 0xC1:
        if (done == 1) {
            arg0->unkD8 = func_80057858;
            arg0->unk64 = func_80024394(180, 400);
        } else {
            arg0->unkD8 = func_80057658;
        }
        break;
    case 0xC5:
        arg0->unkD8 = func_80057858;
        arg0->unk64 = func_80024394(180, 400);
        break;
    case 0xC0:
        if (done == 1) {
            arg0->unkD8 = func_800574D8;
            arg0->unk64 = func_80024394(100, 200);
        } else {
            arg0->unkD8 = func_80057658;
        }
        break;
    }
}
