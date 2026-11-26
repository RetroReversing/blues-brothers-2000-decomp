extern s32 D_800A9548;
void func_8002D604(void *a);
f32 getCameraTargetDist(void *a, f32 b, s32 c);
void func_8003CCB4(void);
void func_8002ADFC(s32 a, s32 b, void *c);

void func_8001B46C(void *arg0) {
    s32 s0;
    void (*fn)(void *);
    int temp;

    if (((D_800A9548 >> *(s32 *) ((char *) arg0 + 0x70)) & 1) != 0) {
        ((void (*)(void *)) *(void **) ((char *) arg0 + 0xA0))(arg0);
        return;
    }
    func_8002D604(arg0);
    if ((s32) getCameraTargetDist(arg0, 100.0f, 0) >= 100) {
        return;
    }
    switch (*(s32 *) ((char *) arg0 + 0x70)) {
    case 0:
        s0 = 0xBC;
        break;
    case 1:
        s0 = 0xBD;
        break;
    case 2:
        s0 = 0xDB;
        break;
    case 3:
        s0 = 0xBE;
        break;
    default:
        s0 = 0x15;
        break;
    }
    func_8003CCB4();
    func_8002ADFC(s0, 0x3E8, arg0);
    fn = *(void (**)(void *)) ((char *) arg0 + 0xA0);
    D_800A9548 |= 1 << *(s32 *) ((char *) arg0 + 0x70);
    fn(arg0);
}
