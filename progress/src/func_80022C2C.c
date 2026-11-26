typedef struct {
    u32 w0;
    u32 w1;
} Gfx4;
typedef struct {
    s32 m[4][4];
} Mtx4;
typedef struct {
    u8 pad0[0x28];
    f32 x;
    f32 y;
    f32 z;
    s32 sx;
    s32 sy;
    s32 sz;
    u8 pad40[0xAC];
    Mtx4 *mtx;
} Obj4;

void func_80022720(void);
void func_8002DE20(f32 (*)[3], f32 (*)[3], f32 (*)[3]);
void debugPrintf(const char *, s32, s32, const char *, s32);
void guMtxF2L(f32 (*)[4], Mtx4 *);
extern s32 D_800AB9A0;
extern s32 D_800B9EB8;
extern f32 D_800CD148[3][3];
extern Mtx4 D_800CD530[0x1A4][2];
extern Gfx4 *D_80177E18;

s32 func_80022C2C(Obj4 *arg0, f32 (*arg1)[3], s32 arg2) {
    f32 tmp[3][3];
    f32 mf[4][4];
    f32 (*r)[3];
    f32 sx, sy, sz;

    if (32767.0f < arg0->x) {
        arg0->x = 32767.0f;
        func_80022720();
    }
    if (32767.0f < arg0->y) {
        arg0->y = 32767.0f;
        func_80022720();
    }
    if (32767.0f < arg0->z) {
        arg0->z = 32767.0f;
        func_80022720();
    }
    if (arg0->x < -32767.0f) {
        arg0->x = -32767.0f;
        func_80022720();
    }
    if (arg0->y < -32767.0f) {
        arg0->y = -32767.0f;
        func_80022720();
    }
    if (arg0->z < -32767.0f) {
        arg0->z = -32767.0f;
        func_80022720();
    }
    if (arg2 != 0) {
        func_8002DE20(tmp, D_800CD148, arg1);
        r = tmp;
    } else {
        r = arg1;
    }
    sx = arg0->sx;
    sy = arg0->sy;
    sz = arg0->sz;
    sx *= 0.00390625;
    sy *= 0.00390625;
    sz *= 0.00390625;
    mf[0][0] = sx * r[0][0];
    mf[0][1] = sx * r[1][0];
    mf[0][2] = sx * r[2][0];
    mf[0][3] = 0.0f;
    mf[1][0] = sy * r[0][1];
    mf[1][1] = sy * r[1][1];
    mf[1][2] = sy * r[2][1];
    mf[1][3] = 0.0f;
    mf[2][0] = sz * r[0][2];
    mf[2][1] = sz * r[1][2];
    mf[2][2] = sz * r[2][2];
    mf[2][3] = 0.0f;
    mf[3][0] = arg0->x;
    mf[3][1] = arg0->y;
    mf[3][2] = arg0->z;
    mf[3][3] = 1.0f;
    guMtxF2L(mf, &D_800CD530[D_800AB9A0][D_800B9EB8]);
    {
        Gfx4 *g = D_80177E18++;
        g->w0 = 0xDA380003;
        g->w1 = (u32)&D_800CD530[D_800AB9A0][D_800B9EB8] + 0x80000000;
    }
    arg0->mtx = &D_800CD530[D_800AB9A0][D_800B9EB8];
    D_800AB9A0++;
    if (D_800AB9A0 >= 0x1A4) {
        debugPrintf("MAX NUMBER OF ROT_MATS EXCCEDED %d MAX=%d %s %d\n", D_800AB9A0, 0x1A4, "C:/PROJECTS/BLUES/MATRIX.c", 0x10F);
    }
    return D_800AB9A0 - 1;
}
