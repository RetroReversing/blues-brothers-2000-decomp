s32 cameraGetMode(void);
void *func_80042F00(s32, s32, s32, s32);
void actorSetAnim(void *, s32, s32);
void func_80050460(void *, void *);
void func_800852CC(void *, void *);
extern f32 D_80008800;
extern f64 D_80008808;
extern f32 D_80008810;
extern f32 D_80008814;
extern u8 D_8014AA55;
void func_8005CAA8(void);
void func_8005CB7C(void);
void func_8005D4E8(void);
void func_8005DEF8(void);
void func_8005E744(void);
void func_80084504(void);

void *func_8005E864(void *arg0) {
    s32 flag;
    u8 *o;
    u8 *c;
    s32 v;
    s32 w;
    s32 a1;
    s32 a2;

    flag = 0;
    func_80050460(func_8005E744, &D_8014AA55);
    o = func_80042F00(0x26, flag, flag, flag);
    *(s32 *)(o + 0) = 0x100D;
    func_800852CC(o, arg0);
    switch (cameraGetMode()) {
    case 7:
        *(void **)(o + 0x9C) = func_8005DEF8;
        actorSetAnim(o, 0xDF, 0x100);
        break;
    case 3:
        *(void **)(o + 0x9C) = func_8005D4E8;
        actorSetAnim(o, 0xE5, 0x70);
        flag = 1;
        break;
    case 1:
        *(void **)(o + 0x9C) = func_8005CB7C;
        actorSetAnim(o, 0xE5, 0x70);
        flag = 1;
        break;
    case 9:
        actorSetAnim(o, 0xE7, 0x100);
        flag = 1;
        break;
    default:
        actorSetAnim(o, 0xDE, 0x100);
        *(s32 *)(o + 0x74) = 0xDE;
        *(void **)(o + 0x9C) = func_80084504;
        break;
    }
    if (arg0 != NULL) {
        v = *(s32 *)((u8 *)arg0 + 0x74);
        if (v != 0) {
            *(f32 *)(o + 0x104) = v * 50.0f;
        }
        w = *(s32 *)((u8 *)arg0 + 0x78);
        if (w != 0) {
            *(f32 *)(o + 0xAC) = w * 0.015;
        }
    } else {
        *(f32 *)(o + 0x104) = 400.0f;
        *(f32 *)(o + 0xAC) = 0.015f;
    }
    if (flag != 0) {
        c = func_80042F00(0x64, *(f32 *)(o + 4), *(f32 *)(o + 8), *(f32 *)(o + 0xC));
        *(s32 *)(c + 0) = 0x101;
        actorSetAnim(c, 0xE9, 0x100);
        *(void **)(o + 0xA8) = c;
        *(void **)(c + 0xA4) = o;
        *(void **)(c + 0x9C) = (u8 *)func_8005CAA8 + 8;
    }
    return o;
}
