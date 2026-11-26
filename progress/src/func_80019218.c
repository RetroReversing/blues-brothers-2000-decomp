/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_800252D8();                                /* extern */
M2C_UNK setTextPos(M2C_UNK, s32);                /* extern */
M2C_UNK func_800271A8(s32, M2C_UNK);                /* extern */
M2C_UNK drawInt(s32);                         /* extern */
M2C_UNK drawFloat(f32);                         /* extern */
M2C_UNK func_80028710(s32);                         /* extern */
M2C_UNK drawText(M2C_UNK *);                   /* extern */
f32 approachF32(f32, f32, f32);                   /* extern */
extern M2C_UNK D_80000AA4;
extern M2C_UNK D_80000AAC;
extern M2C_UNK D_80000AB0;
extern M2C_UNK D_80000AB8;
extern M2C_UNK D_80000AC0;
extern M2C_UNK D_80000AC8;
extern M2C_UNK D_80000AD0;
extern M2C_UNK D_80000AD8;
typedef struct { u8 pad[0x1C]; s32 x1C; } Rec20;
extern Rec20 D_800AA134[];
extern s32 D_800AB9B4;
extern f32 D_800B9EC4;
extern s32 gCamSpeedScale;
extern void *gCameraTarget;
extern s32 D_800BD0FC;
extern s32 D_800BD100;
extern f32 D_8014022C;
extern s32 D_80178270;
extern u8 D_801858A0[];

void func_80019218(void *arg0) {
    char buf[64];
    f32 x;
    f32 a;
    s32 base;
    s32 ix;
    s32 row;
    s32 t;

    x = M2C_FIELD(arg0, f32 *, 4);
    base = D_800AA134[D_800BD100].x1C;
    ix = x;
    if (D_800AB9B4 != 0) {
        t = gCamSpeedScale * 4;
        a = -160.0f;
    } else {
        a = 0.0f;
        t = gCamSpeedScale * 4;
    }
    do { M2C_FIELD(arg0, f32 *, 4) = approachF32(a, x, t); } while (0);
    row = ix + 20;
    base += D_800BD0FC * 60;
    func_800271A8(row, 0);
    drawText(&D_80000AA4);
    drawInt((func_800252D8() + 0x200) / 1024);
    drawText(&D_80000AAC);
    func_800271A8(row, 1);
    drawText(&D_80000AB0);
    drawInt(D_80178270);
    func_800271A8(row, 2);
    drawText(&D_80000AB8);
    drawInt(((u32) D_801858A0 - 0x80000000) >> 10);
    drawText(&D_80000AAC);
    func_800271A8(row, 5);
    drawText(&D_80000AC0);
    drawInt(M2C_FIELD(gCameraTarget, s32 *, 0x90));
    func_800271A8(row, 6);
    drawText(&D_80000AC8);
    drawFloat(M2C_FIELD(gCameraTarget, f32 *, 0x50));
    func_800271A8(row, 7);
    drawText(&D_80000AD0);
    drawFloat(D_800B9EC4);
    func_800271A8(row, 8);
    drawText(&D_80000AD8);
    drawFloat(D_8014022C);
    setTextPos(0xA0, 0xD2 - ix);
    func_80028710(base + 4);
}
