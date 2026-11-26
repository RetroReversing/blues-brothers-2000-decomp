typedef struct { f32 x, y, z; } Vec3f;
typedef struct Obj {
    f32 x00;
    Vec3f pos;  /* 0x04 */
    s32 x10;
    s32 x14;    /* 0x14 */
    u8 pad18[0x84];
    void *x9C;  /* 0x9C */
} Obj;

s32 func_8004303C(Obj *);
void func_80043328(Obj *, s32, s32);

void func_80050558(Obj *arg0) {
    Vec3f prev;
    f32 lim;

    prev.x = arg0->pos.x;
    prev.y = arg0->pos.y;
    prev.z = arg0->pos.z;
    func_8004303C(arg0);
    lim = 1000.0f;
    if (lim < arg0->pos.y) {
        arg0->pos.y -= 5.0f;
    }
    if (arg0->pos.y < lim) {
        arg0->pos.y = lim;
        func_80043328(arg0, 0x88, 0x100);
        arg0->x9C = func_8004303C;
        arg0->x14 += 0x4000;
        arg0->pos.y += 25.0f;
    }
}
