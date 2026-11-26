void func_80075008(void *);

void func_80075270(u8 *obj) {
    s32 v;

    if (*(s32 *) (obj + 0x7C) == 0) {
        v = *(s32 *) (obj + 0x34) * 0.6f;
        *(s32 *) (obj + 0x7C) = 1;
        *(s32 *) (obj + 0x74) = 0;
        *(s32 *) (obj + 0xBC) = 0;
        *(s32 *) (obj + 0xB4) = 0;
        *(f32 *) (obj + 0x4) = -59000.0f;
        *(f32 *) (obj + 0x8) = -528.0f;
        *(f32 *) (obj + 0xC) = 42900.0f;
        *(s32 *) (obj + 0x34) = v;
        *(s32 *) (obj + 0x38) = *(s32 *) (obj + 0x34);
        *(s32 *) (obj + 0x3C) = *(s32 *) (obj + 0x34);
        *(f32 *) (obj + 0xAC) = 0.019987f;
    }
    func_80075008(obj);
}
