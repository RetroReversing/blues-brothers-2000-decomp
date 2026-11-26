typedef struct Obj8E Obj8E;
struct Obj8E {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    u8 pad14[0x30 - 0x14];
    f32 unk30;
    f32 unk34;
    f32 unk38;
    u8 pad3C[0x50 - 0x3C];
    f32 unk50;
    u8 pad54[0x88 - 0x54];
    s32 unk88;
    Obj8E *unk8C;
    s32 unk90;
    s32 unk94;
    u8 pad98[0xA8 - 0x98];
    Obj8E *unkA8;
    u8 padAC[0xB4 - 0xAC];
    f32 unkB4;
    u8 padB8[0xDC - 0xB8];
    f32 unkDC;
};

s16 coss(u16);
s16 sins(u16);
void func_8002ADFC(s32, s32, Obj8E *);
void func_8003BF98(Obj8E *);
s32 func_80043248(Obj8E *);
void func_800433A8(Obj8E *, s32, s32);
f32 sqrtf(f32);
extern s32 D_800B4CE0;
extern Obj8E *D_800BD06C;

s32 func_8007E810(Obj8E *arg0) {
    s32 v[3];
    s32 r[3];
    f32 p[3];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    Obj8E *o;
    s16 sn;
    s16 cs;

    func_80043248(arg0->unkA8);
    if (func_80043248(arg0) != 0) {
        if (arg0->unk88 != 0) {
            return 2;
        }
        return 1;
    }
    if (10.0f <= arg0->unkDC && arg0->unkDC < 12.0f) {
        func_8002ADFC(0xC9, 0x1770, arg0);
    }
    if (arg0->unk88 == 0 && 10.0f < arg0->unkDC) {
        o = arg0->unk8C;
        v[0] = o->unk30;
        v[1] = o->unk34;
        v[2] = o->unk38;
        r[0] = ((v[0] * coss(*(u16 *)((u8 *)arg0 + 0x12))) >> 15) + ((v[2] * sins(*(u16 *)((u8 *)arg0 + 0x12))) >> 15);
        sn = sins(*(u16 *)((u8 *)arg0 + 0x12));
        cs = coss(*(u16 *)((u8 *)arg0 + 0x12));
        r[1] = v[1];
        r[2] = -((v[0] * sn) >> 15) + ((v[2] * cs) >> 15);
        p[0] = arg0->x + r[0];
        p[1] = arg0->y + r[1];
        p[2] = arg0->z + r[2];
        dx = D_800BD06C->x - p[0];
        dz = D_800BD06C->z - p[2];
        dy = D_800BD06C->y - p[1];
        d = sqrtf(dx * dx + dy * dy + dz * dz);
        arg0->unkB4 = d;
        if (d < 1400.0f) {
            D_800B4CE0 = 1;
            func_8003BF98(D_800BD06C);
            D_800B4CE0 = 0;
            func_800433A8(D_800BD06C, 0x10, 0x100);
            D_800BD06C->unk94 = 0x1388;
            D_800BD06C->unk90 = 0;
            D_800BD06C->unk10 = arg0->unk10;
            D_800BD06C->unk50 += 900.0f;
            D_800BD06C->y += 600.0f;
            arg0->unk88++;
        }
    }
    return 0;
}
