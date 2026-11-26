f32 func_8002D340(f32, f32, f32);
f32 func_8002D66C(void *, f32, s32);
extern s32 D_800B9ECC;
extern f32 D_80000D64;

typedef struct {
    s32 flags0;
    s32 pad4;
    f32 y8;
    s32 padC;
    s32 i10;
    s32 i14;
    u8 pad18[0x44 - 0x18];
    f32 f44;
} Obj;

void func_8001E634(Obj *obj) {
    f32 h;
    f32 old;
    f32 nw;

    h = func_8002D66C(obj, 500.0f, 0);
    if (500.0f <= h) {
        obj->y8 = func_8002D340(obj->f44, obj->y8, 10.0f);
        obj->i14 = 0;
        return;
    }
    old = obj->y8;
    nw = func_8002D340(obj->f44 + 500.0f - h, old, 10.0f);
        obj->y8 = nw;
    obj->flags0 = 0x101;
    obj->i14 = (old - nw) * 128.0f;
    obj->i10 = obj->i10 + (f32)(D_800B9ECC * 4) * (500.0f - h);

}
