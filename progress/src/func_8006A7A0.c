f32 func_8002D858(void *, s32 *);
s32 func_8002D260(s32);
void func_80043328(void *, s32, s32);
void func_8003BF98(void *);
s32 animStepKeys(void *);
s32 randomRange(s32, s32);
s32 func_80043248(void *);

s32 func_8006A7A0(u8 *obj) {
    s32 angle;
    f32 dist;
    s32 d;
    s32 near;
    s32 t;

    dist = func_8002D858(obj, &angle);
    t = func_8002D260(angle - *(s32 *) (obj + 0x10));
    d = abs(t);
    d = d < 2000;
    *(s32 *) (obj + 0x78) = 4;
    func_80043328(obj, *(s32 *) (obj + 0x74) + *(s32 *) (obj + 0x78), 0x100);
    if (*(s32 *) (obj + 0xD0) == *(s32 *) (obj + 0x74) + *(s32 *) (obj + 0x78)) {
        if (dist < 300.0f && 13.0f < *(f32 *) (obj + 0xDC) && *(f32 *) (obj + 0xDC) < 19.0f) {
            if (*(s32 *) (obj + 0x80) == 0 && d) {
                *(s32 *) (obj + 0x80) = 1;
                func_8003BF98(obj);
            }
        } else {
            *(s32 *) (obj + 0x80) = 0;
        }
    }
    t = func_8002D260(angle - *(s32 *) (obj + 0x10));
    d = abs(t);
    d = d < 0x4000;
    if (animStepKeys(obj) != 0) {
        *(s32 *) (obj + 0x64) = randomRange(0x32, 0x8C);
        if (!d) {
            return 3;
        }
        *(s32 *) (obj + 0x78) = 8;
        *(void **) (obj + 0xD8) = func_80043248;
        func_80043328(obj, *(s32 *) (obj + 0x74) + *(s32 *) (obj + 0x78), 0x100);
    }
    return 0;
}
