s32 func_8002492C(f32, f32);
void func_8002D3E4(s32 *, s32);
void func_8002DA80(s32 *);
void func_8004303C(void);

s32 func_80085998(s32 *obj) {
    f32 dx;
    f32 dz;
    f32 dist;

    dx = ((f32 *)obj)[0x40 / 4] - ((f32 *)obj)[1];
    dz = ((f32 *)obj)[0x48 / 4] - ((f32 *)obj)[3];
    func_8004303C();
    dist = sqrtf(dx * dx + dz * dz);
    obj[0x10 / 4] = func_8002492C(dx, dz);
    func_8002D3E4(obj, 0x87);
    func_8002DA80(obj);
    return dist < 150.0f;
}
