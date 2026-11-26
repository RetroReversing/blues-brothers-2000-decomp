typedef struct {
    s32 x, y, z;
} Vec3i_7DDB8;

s32 func_8002D298(s32, s32, s32);
void func_80047824(void *, s32, s32, s32, s32);

s32 func_8007DDB8(void *arg0, Vec3i_7DDB8 *pos, Vec3i_7DDB8 *dst) {
    void *o = *(void **)((u8 *)arg0 + 0xE8);

    if (o == NULL) {
        return 1;
    }
    func_80047824(o, 0, pos->x, pos->y, pos->z);
    func_80047824(o, 0, pos->x, pos->y, pos->z);
    pos->x = func_8002D298(dst->x, pos->x, 2);
    pos->y = func_8002D298(dst->y, pos->y, 2);
    pos->z = func_8002D298(dst->z, pos->z, 2);
    if (pos->x == dst->x && pos->y == dst->y && pos->z == dst->z) {
        return 1;
    }
    return 0;
}
