s32 func_80013654(s32);
s32 func_8001B990(s32, s32);
f32 func_8002D858(void *, s32);
s16 sins(u16);
extern s32 D_800B9EA4;
extern s32 D_800BD06C;

void func_800783E0(void *arg0) {
    s32 v;

    if (*(s32 *)((s8 *)arg0 + 0x7C) == 0) {
        if (func_8001B990(0x100, *(s32 *)((s8 *)arg0 + 0x70)) != 0) {
            *(s32 *)((s8 *)arg0 + 0x7C) = 2;
        } else {
            *(s32 *)((s8 *)arg0 + 0x7C) = 1;
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x7C) == 2) {
        if (*(s32 *)((s8 *)arg0 + 0x74) != 0) {
            *(s32 *)((s8 *)arg0 + 0x14) = sins((D_800B9EA4 * 110) & 0xFFFE) >> 5;
        } else {
            *(s32 *)((s8 *)arg0 + 0x14) += 0x800;
        }
    }
    if (!(200.0f < func_8002D858(arg0, 0)) && func_80013654(D_800BD06C) != 0) {
        *(s32 *)((s8 *)arg0 + 0x7C) = 2;
        func_8001B990(0x200, *(s32 *)((s8 *)arg0 + 0x70));
    }
}
