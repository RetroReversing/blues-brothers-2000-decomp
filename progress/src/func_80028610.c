/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

extern s32 gFontScale;
extern char gCharToGlyph[];
extern char gGlyphPadding[];

s32 func_80028610(u8 *arg0) {
    u8 temp_v0;
    s32 var_a2;
    char *var_a0;
    s32 idx;
    u8 *base;
    u8 *tbl;

    var_a2 = 0;
    tbl = (u8 *) gCharToGlyph;
    base = (u8 *) gGlyphPadding;
    var_a0 = arg0;
    for (;;) {
        temp_v0 = *(u8 *)var_a0 & 0xFF;
        var_a0 += 1;
        if (temp_v0 != 0) {
            idx = *(u8 *)((s32) temp_v0 + (s32) tbl);
            var_a2 = var_a2 + (2 + ((s32) (0xB - *(u8 *)(base + (idx - 0x20))) / (s32) gFontScale));
            continue;
        }
        break;
    }
    return var_a2;
}
