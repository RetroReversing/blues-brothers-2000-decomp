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

s32 func_80024394(s32, s32);                /* extern */
s32 func_8002D620(void *);                      /* extern */
void *func_80042F00(s32, s32, s32, s32); /* extern */
s32 func_800433A8(void *, s32, s32);        /* extern */
s32 func_80050460(s32 *, s32 *);        /* extern */
s32 func_800852CC(void *, s32);                 /* extern */
extern s32 D_800B81D0;
extern s32 D_8014AA3E;
extern s32 func_8005BD8C;
extern s32 func_8005C7CC;
extern s32 func_8006DC44;

void *func_8005C700(s32 arg0) {
    s32 *__base_func_8005BD8C;
    void *temp_v0;

    func_80050460(&func_8005C7CC, &D_8014AA3E);
    temp_v0 = func_80042F00(0xD, 0, 0, 0);
    __base_func_8005BD8C = &func_8005BD8C;
    (*(s32 **)((s8 *)temp_v0 + 0x9C)) = (s32 *) (__base_func_8005BD8C + 0xE5);
    (*(s32 *)((s8 *)temp_v0 + 0)) = 0x1014;
    func_800433A8(temp_v0, 0x32, 0x100);
    func_800852CC(temp_v0, arg0);
    func_8002D620(temp_v0);
    if (D_800B81D0 != 0) {
        (*(s32 **)((s8 *)temp_v0 + 0x9C)) = &func_8006DC44;
        func_800433A8(temp_v0, 0x32, func_80024394(0xC0, 0x100));
        (*(s32 *)((s8 *)temp_v0 + 0xBC)) = 3;
    }
    return temp_v0;
}
