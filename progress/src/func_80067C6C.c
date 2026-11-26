typedef struct Obj67C6C {
    s32 kind;
    f32 x, y, z;
    u8 pad10[2];
    u16 angle;
    u8 pad14[0x50 - 0x14];
    f32 unk50;
    u8 pad54[0xC0 - 0x54];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
} Obj67C6C;

s16 sins(u16);
s16 coss(u16);
s32 func_80024B0C(s32);
void func_8002A360(s32, s32);
void func_800433A8(Obj67C6C *, s32, s32);
f32 sqrtf(f32);
extern Obj67C6C *D_800BD06C;
extern s32 D_80140240;

s32 func_80067C6C(Obj67C6C *arg0) {
    s32 dy;
    s32 x;
    s32 z;
    s32 dx2;
    s32 dz2;
    f32 t;
    f32 fx;
    f32 fz;
    f32 d;

    dy = D_800BD06C->y - arg0->y;
    if (dy > 0) {
        if (arg0->unkD0 == 0xF7 || arg0->unkD0 == 0xF8) {
            x = arg0->x + (f32)(-(sins(arg0->angle) * 250) >> 15);
            z = arg0->z + (f32)(-(coss(arg0->angle) * 250) >> 15);
            dx2 = D_800BD06C->x - (f32)x;
            dz2 = D_800BD06C->z - (f32)z;
            if (func_80024B0C(dx2 * dx2 + dz2 * dz2) < 251) {
                if (D_800BD06C->unkD0 >= 43) {
                    arg0->unkC0 |= 4;
                }
                if (D_800BD06C->unk50 < 0.0f && dy < 150) {
                    D_800BD06C->unk50 = (D_80140240 * 3) / 2;
                    t = arg0->y + 75.0f;
                    if (D_800BD06C->y < t) {
                        D_800BD06C->y = t;
                    }
                    D_800BD06C->y += 1.0f;
                    func_800433A8(D_800BD06C, 5, 0x100);
                    func_8002A360(12, 0x80);
                    func_8002A360(8, 2);
                    return 0;
                }
            }
        }
        return 0;
    }
    fx = (arg0->x - D_800BD06C->x) + (f32)(-(sins(arg0->angle) * 150) >> 15);
    fz = (arg0->z - D_800BD06C->z) + (f32)(-(coss(arg0->angle) * 150) >> 15);
    d = sqrtf(fx * fx + fz * fz);
    if (d <= 400.0f) {
        D_800BD06C->x += fx * (d - 400.0f) / d;
        D_800BD06C->z += fz * (d - 400.0f) / d;
    }
    return 0;
}
