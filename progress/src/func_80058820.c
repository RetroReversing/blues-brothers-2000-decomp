typedef struct {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
} Pos58820;

typedef struct {
    u8 pad0[8];
    f32 y;
    u8 padC[4];
    s32 angle;
    u8 pad14[0x40 - 0x14];
    f32 x;
    u8 pad44[4];
    f32 z;
    u8 pad4C[0x64 - 0x4C];
    s32 hp;
    u8 pad68[0x8C - 0x68];
    s32 unk8C;
    s32 unk90;
    u8 pad94[0xDC - 0x94];
    f32 unkDC;
    u8 padE0[0x104 - 0xE0];
    f32 range;
} Actor58820;

void func_8002D3E4(Actor58820 *, s32);
s32 func_8002D5E8(Actor58820 *);
void func_8002DA80(Actor58820 *);
f32 func_8002DD60(f32);
s32 func_8004303C(Actor58820 *);
s32 func_800772FC(Actor58820 *);
f32 sqrtf(f32);
extern Pos58820 *D_800BD06C;
extern f32 D_801700D0;

s32 func_80058820(Actor58820 *a) {
    s32 result = 0;
    s32 ok;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 dy;

    if (a->hp <= 0) {
        return 1;
    }
    ok = func_8004303C(a);
    if (a->unkDC > 9.0f && a->unkDC < 33.0f) {
        func_8002D3E4(a, 200);
    } else {
        func_8002D3E4(a, 0);
    }
    func_8002DA80(a);
    if (func_8002D5E8(a) != 0 && ok != 0) {
        result = func_800772FC(a);
        if (result != 0) {
            result = 3;
            a->unk8C = 0;
            a->angle += 0x8000;
        }
        a->unk90 = 150;
    }
    if (a->unk8C == 0) {
        dx = D_800BD06C->x - a->x;
        dz = D_800BD06C->z - a->z;
        dist = sqrtf(dx * dx + dz * dz);
        dy = D_800BD06C->y - a->y;
        if (dist < a->range && func_8002DD60(dy) < 300.0f) {
            return 2;
        }
        if (D_801700D0 < 250.0f) {
            return 5;
        }
    }
    return result;
}
