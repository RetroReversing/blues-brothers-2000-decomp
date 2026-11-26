typedef struct {
    /* 0x00 */ s32 pad0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ u8 pad10[0xA8];
    /* 0xB8 */ s32 kind;
} Obj;
typedef struct {
    s32 a;
    s32 h;
    s32 c;
} HRow;
f32 func_8002DD60(f32);
f32 sqrtf(f32);
extern Obj *D_800BD06C;
extern HRow D_800F4A00[];
extern HRow D_800F6188[];
extern s32 D_800F7910[];

s32 func_80060C94(Obj *arg0) {
    f32 r;
    f32 dx;
    f32 dz;
    f32 d;
    f32 k;
    f32 lo;
    f32 hi;
    s32 kind;

    kind = arg0->kind;
    lo = arg0->y + D_800F6188[kind].h - 300.0f;
    hi = arg0->y + D_800F4A00[kind].h + 300.0f;
    r = D_800F7910[kind] / 3.0f;
    if (D_800BD06C->y < lo) {
        return 0;
    }
    if (hi < D_800BD06C->y) {
        return 0;
    }
    dx = D_800BD06C->x - arg0->x;
    dz = D_800BD06C->z - arg0->z;
    if (r < func_8002DD60(dx)) {
        return 0;
    }
    if (r < func_8002DD60(dz)) {
        return 0;
    }
    d = sqrtf(dx * dx + dz * dz);
    if (r < d) {
        return 0;
    }
    k = r - d;
    dx = arg0->x - D_800BD06C->x;
    dz = arg0->z - D_800BD06C->z;
    D_800BD06C->x = D_800BD06C->x - dx * k / d;
    D_800BD06C->z = D_800BD06C->z - dz * k / d;
    return 1;
}
