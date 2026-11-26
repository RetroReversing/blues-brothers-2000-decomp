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

void *func_80023874();
f32 func_8002D340(f32, f32, f32);      /* extern */
s32 func_8002D620();
s32 func_800899DC();
extern char D_800096B8[];
extern f32 D_800096D4;

void func_8007F7DC(void *arg0) {
    void *temp_v0;
    f32 temp;

    if ((*(s32 *)((s8 *)arg0 + 0x7C)) == 0) {
        (*(s32 *)((s8 *)arg0 + 0x7C)) = 1;
        (*(s32 *)((s8 *)arg0 + 0x84)) = 0;
        do { func_8002D620(); } while (0);
        temp = *(f32 *)((s8 *)arg0 + 0x48);
        (*(f32 *)((s8 *)arg0 + 0xC)) = (f32) (temp + 600.0f);
    }
    if ((*(s32 *)((s8 *)arg0 + 0x84)) >= 0xB) {
        func_800899DC(D_800096B8);
    }
    temp_v0 = (*(void **)((s8 *)arg0 + 0xA4));
    if (temp_v0 == NULL) {
        (*(void **)((s8 *)arg0 + 0xA4)) = func_80023874(0x102D, 0);
        (*(s32 *)((s8 *)arg0 + 0x84)) += 1;
        return;
    }
    if ((*(s32 *)((s8 *)temp_v0 + 0xFC)) < (*(s32 *)((s8 *)arg0 + 0x70))) {
        (*(f32 *)((s8 *)arg0 + 0xC)) = func_8002D340((*(f32 *)((s8 *)arg0 + 0x48)), (*(f32 *)((s8 *)arg0 + 0xC)), 8.0f);
    }
}

