typedef struct Obj {
    f32 x00;
    f32 x;      /* 0x04 */
    f32 y;
    f32 z;      /* 0x0C */
    u8 pad10[0x30];
    f32 x40;    /* 0x40 */
    f32 x44;
    f32 x48;    /* 0x48 */
} Obj;

s32 func_8007DFAC(Obj *arg0) {
    if (sqrtf(arg0->x * arg0->x + arg0->z * arg0->z) > 4400.0f) {
        arg0->x = arg0->x40;
        arg0->z = arg0->x48;
        return 1;
    }
    return 0;
}
