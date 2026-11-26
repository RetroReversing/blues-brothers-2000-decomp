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
M2C_UNK func_8002713C(M2C_UNK, s32);                /* extern */
M2C_UNK func_800271A8(s32, M2C_UNK);                /* extern */
M2C_UNK func_800271D8(s32);                         /* extern */
M2C_UNK func_800272AC(f32);                         /* extern */
M2C_UNK func_80028710(s32);                         /* extern */
M2C_UNK func_8002889C(M2C_UNK *);                   /* extern */
f32 func_8002D340(f32, f32, f32);                   /* extern */
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
extern s32 D_800B9ECC;
extern void *D_800BD06C;
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
        t = D_800B9ECC * 4;
        a = -160.0f;
    } else {
        a = 0.0f;
        t = D_800B9ECC * 4;
    }
    do { M2C_FIELD(arg0, f32 *, 4) = func_8002D340(a, x, t); } while (0);
    row = ix + 20;
    base += D_800BD0FC * 60;
    func_800271A8(row, 0);
    func_8002889C(&D_80000AA4);
    func_800271D8((func_800252D8() + 0x200) / 1024);
    func_8002889C(&D_80000AAC);
    func_800271A8(row, 1);
    func_8002889C(&D_80000AB0);
    func_800271D8(D_80178270);
    func_800271A8(row, 2);
    func_8002889C(&D_80000AB8);
    func_800271D8(((u32) D_801858A0 - 0x80000000) >> 10);
    func_8002889C(&D_80000AAC);
    func_800271A8(row, 5);
    func_8002889C(&D_80000AC0);
    func_800271D8(M2C_FIELD(D_800BD06C, s32 *, 0x90));
    func_800271A8(row, 6);
    func_8002889C(&D_80000AC8);
    func_800272AC(M2C_FIELD(D_800BD06C, f32 *, 0x50));
    func_800271A8(row, 7);
    func_8002889C(&D_80000AD0);
    func_800272AC(D_800B9EC4);
    func_800271A8(row, 8);
    func_8002889C(&D_80000AD8);
    func_800272AC(D_8014022C);
    func_8002713C(0xA0, 0xD2 - ix);
    func_80028710(base + 4);
}
