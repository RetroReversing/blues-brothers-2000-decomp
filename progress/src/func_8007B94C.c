typedef struct {
    s32 unk0;
} Unk800BD06C;

typedef struct {
    u8 pad0[0xA8];
    s32 unkA8;
} Unk8007B94C_A4;

typedef struct Unk8007B94C {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    u8 padC[4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x44 - 0x1C];
    f32 unk44;
    u8 pad48[0x50 - 0x48];
    f32 unk50;
    u8 pad54[0x64 - 0x54];
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    u8 pad80[0xA0 - 0x80];
    void (*unkA0)(struct Unk8007B94C *);
    Unk8007B94C_A4 *unkA4;
    u8 padA8[4];
    f32 unkAC;
    u8 padB0[4];
    f32 unkB4;
    u8 padB8[0xF8 - 0xB8];
    s32 unkF8;
} Unk8007B94C;

extern s32 D_800BD100;
extern Unk800BD06C *D_800BD06C;
extern f32 D_800B9EC4;
extern s32 D_800B9ECC;
extern s32 D_8014A928[];

s32 func_80081990(f32 *out, s32 i, f32 t);
void func_8002D620(void *arg0);
s32 func_8002D5CC(void *arg0);
s32 func_80081AC0(f32 *out, s32 i, f32 t);
s32 func_8002492C(f32, f32);
f32 func_8002D8F4(void *arg0, s32 *arg1);
void *func_8003B980(void *o);
s32 func_8003BF98(void *o);

void func_8007B94C(Unk8007B94C *arg0) {
    s32 idx;
    s32 flag;
    f32 t;
    f32 sum;
    f32 vec[3];
    f32 dist;
    s32 mode;

    idx = arg0->unk70;
    flag = 0;
    if (arg0->unk7C == 0) {
        arg0->unk7C = D_800BD100;
    }
    arg0->unkF8 |= 1;
    switch (arg0->unk6C) {
    case 0:
        func_80081990(&arg0->unk4, idx, arg0->unkB4);
        func_8002D620(arg0);
        arg0->unk68 = -1;
        arg0->unk64 = 200;
        arg0->unk6C++;
        arg0->unk8 += 2000.0f;
        break;
    case 1:
        if (func_8002D5CC(arg0) != 0) {
            arg0->unk68 = 4;
            arg0->unk6C++;
        }
        break;
    case 2:
        t = D_800B9EC4;
        arg0->unk50 += t * -2700.0f;
        arg0->unk8 += arg0->unk50 * t;
        if (arg0->unk8 <= arg0->unk44) {
            arg0->unk8 = arg0->unk44;
            arg0->unk6C++;
        }
        break;
    default:
        sum = arg0->unkB4 + arg0->unkAC;
        arg0->unkB4 = sum;
        t = (f32)D_8014A928[idx] - 1.1f;
        if (t <= sum) {
            arg0->unkA4->unkA8 = 0;
            arg0->unkA0(arg0);
            break;
        }
        func_80081990(&arg0->unk4, idx, sum);
        if (arg0->unk7C == 4) {
            func_80081AC0(vec, idx, arg0->unkB4);
            arg0->unk10 = func_8002492C(vec[0], vec[2]);
            arg0->unk14 += D_800B9ECC << 10;
        } else if (arg0->unk70 < 7) {
            arg0->unk18 += D_800B9ECC << 10;
        } else {
            arg0->unk14 -= D_800B9ECC << 10;
        }
        dist = func_8002D8F4(arg0, NULL);
        do { do { mode = D_800BD100; } while (0); } while (0);
        if (mode == 1) {
            if (dist < 500.0) {
                if (D_800BD06C->unk0 == 3) {
                    func_8003B980(D_800BD06C);
                }
            }
        } else if (dist < 425.0f) {
            if (flag && D_800BD06C->unk0 == 3) {
                func_8003B980(D_800BD06C);
            } else {
                func_8003BF98(D_800BD06C);
            }
        }
        break;
    }
}

