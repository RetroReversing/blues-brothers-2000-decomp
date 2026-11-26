/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s16 coss(s32);
void func_8001F1D0(void *);
M2C_UNK func_8001F230(void *);
M2C_UNK func_80022728(void *, M2C_UNK *, M2C_UNK);
M2C_UNK func_80024A3C(M2C_UNK *, M2C_UNK *, s32);
M2C_UNK func_80024B58(M2C_UNK *, M2C_UNK *, s32);
M2C_UNK func_80024BE0(M2C_UNK *, M2C_UNK *, s32);
M2C_UNK func_80024FE8(M2C_UNK *);
M2C_UNK func_80026C04(M2C_UNK *, M2C_UNK, M2C_UNK);
M2C_UNK func_80027060(s32, s32, s32, s32);
M2C_UNK func_80029F8C(M2C_UNK, s32 *);
extern s32 D_800B9EA4;
typedef struct { u32 w0; u32 w1; } Gfx;
extern Gfx *D_80177E18;

s32 func_8001FCF0(void *arg0) {
    char sp10[0x10];
    char sp20[0x28];
    char sp48[0x60];
    Gfx *p;
    Gfx *q;
    s32 c;

    func_80026C04(sp10, 0, 0xC);
    func_8001F230(arg0);
    c = 0xFF - ((s32) (((s32) (coss((D_800B9EA4 * 0x190) & 0xFFF0) * 0x7F) >> 0xF) + 0x80) / 2);
    func_80027060(c, c, c, M2C_FIELD(arg0, const s32 *, 0x5C));
    p = D_80177E18++;
    p->w0 = 0xFC30B261;
    p->w1 = 0xFF67FFFF;
    func_8001F1D0(arg0);
    func_80024FE8(sp20);
    func_80024B58(sp48, sp20, M2C_FIELD(arg0, const s32 *, 0x10));
    func_80024A3C(sp20, sp48, M2C_FIELD(arg0, const s32 *, 0x14));
    func_80024BE0(sp48, sp20, M2C_FIELD(arg0, const s32 *, 0x18));
    func_80022728(arg0, sp48, 1);
    q = D_80177E18++;
    q->w0 = 0xDE000000;
    q->w1 = M2C_FIELD(arg0, const s32 *, 0xE4);
    func_80029F8C(-1, (s32 *)q);
    return 1;
}
