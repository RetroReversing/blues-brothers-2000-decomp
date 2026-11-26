typedef struct Obj142A0 {
    s32 flags;
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x74 - 0x14];
    s32 unk74;
    u8 pad78[0x8C - 0x78];
    s32 unk8C;
    s32 unk90;
    u8 pad94[0xA0 - 0x94];
    void (*update)(struct Obj142A0 *);
    u8 padA4[0xB8 - 0xA4];
    s32 unkB8;
    u8 padBC[0xC0 - 0xBC];
    s32 unkC0;
    u8 padC4[0xE4 - 0xC4];
    s32 unkE4;
    u8 padE8[0x108 - 0xE8];
} Obj142A0;

f32 func_8002D66C(Obj142A0 *, f32, s32 *);
void func_8002DA80(Obj142A0 *);
void func_80017CF0(Obj142A0 *);
s32 func_80023E3C(s32);
void func_80048820(f32 *, f32 *, s32);
s32 func_80048CD8(f32, f32, f32, f32, f32, f32, s32);
s32 func_8000F7A0(Obj142A0 *);
Obj142A0 *func_80023088(s32);
Obj142A0 *func_800230B0(s32);
void func_800851D8(Obj142A0 *);
f32 func_8002DD60(f32);
extern s32 D_800B4CE4;
extern s32 D_800B9EA0;
extern s32 D_800B9ECC;
extern Obj142A0 *D_800BD06C;

void func_800142A0(Obj142A0 *arg0) {
    f32 sp20[3];
    f32 sp30[3];
    s32 sp40;
    s32 d;
    Obj142A0 *p;
    Obj142A0 *end;
    Obj142A0 *start;
    f32 dx;
    f32 dy;
    f32 dz;

    d = func_8002D66C(arg0, 8000.0f, &sp40);
    arg0->unk10 += D_800B9ECC << 10;
    func_8002DA80(arg0);
    if (arg0->unk90 != 0) {
        func_80017CF0(arg0);
    }
    arg0->unk90 ^= 1;
    arg0->unk8C += D_800B9EA0;
    if (arg0->unk8C >= 1501 || (d < 200 && arg0->unk74 != 0)) {
        D_800BD06C->unkB8 = 1;
        D_800BD06C->unkE4 = func_80023E3C(1);
        D_800B4CE4 = 0;
        arg0->update(arg0);
        return;
    }
    sp20[0] = -50.0f;
    sp20[1] = -75.0f;
    sp20[2] = -50.0f;
    sp30[0] = 50.0f;
    sp30[1] = 75.0f;
    sp30[2] = 50.0f;
    sp20[0] = arg0->x + -50.0f;
    sp30[0] = arg0->x + 50.0f;
    sp20[1] = arg0->y + -75.0f;
    sp30[1] = arg0->y + 75.0f;
    sp20[2] = arg0->z + -50.0f;
    sp30[2] = arg0->z + 50.0f;
    func_80048820(sp20, sp30, 0);
    if (func_80048CD8(sp20[0], sp30[0], sp20[1], sp30[1], sp20[2], sp30[2], 0) != 0) {
        goto hit;
    found:
        p->unkC0 |= 0x5E;
    hit:
        arg0->update(arg0);
        D_800B4CE4 = 0;
        D_800BD06C->unkB8 = 1;
        D_800BD06C->unkE4 = func_80023E3C(1);
        return;
    }
    if (func_8000F7A0(arg0) != 0) {
        arg0->update(arg0);
        D_800B4CE4 = 0;
        D_800BD06C->unkB8 = 1;
        D_800BD06C->unkE4 = func_80023E3C(1);
    }
    start = func_80023088(0);
    end = func_800230B0(0);
    for (p = start; p <= end; p++) {
        if (p == arg0) {
            continue;
        }
        if (!(p->flags & 0x1000)) {
            continue;
        }
        func_800851D8(arg0);
        dx = arg0->x - p->x;
        dy = arg0->y - p->y;
        dz = arg0->z - p->z;
        if (200.0f < func_8002DD60(dx)) {
            continue;
        }
        if (300.0f < func_8002DD60(dy)) {
            continue;
        }
        if (200.0f < func_8002DD60(dz)) {
            continue;
        }
        goto found;
    }
}
