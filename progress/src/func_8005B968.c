s32 approachS32(s32, s32, s32);
f32 approachF32(f32, f32, f32);
void syncActorPrevPos(void);
void func_80043328(void *, s32, s32);

typedef struct Obj {
    s32 state;          /* 0x00 */
    u8 pad04[0xC];
    s32 angle;          /* 0x10 */
    u8 pad14[0x38];
    f32 x4C;            /* 0x4C */
    u8 pad50[4];
    f32 x54;            /* 0x54 */
    u8 pad58[4];
    s32 x5C;            /* 0x5C */
    u8 pad60[0x1C];
    s32 x7C;            /* 0x7C */
    s32 x80;
    s32 x84;            /* 0x84 */
    s32 x88;            /* 0x88 */
    s32 x8C;            /* 0x8C */
    u8 pad90[0x10];
    void (*func)(struct Obj *); /* 0xA0 */
    s32 *xA4;           /* 0xA4 */
    u8 padA8[0x34];
    f32 xDC;            /* 0xDC */
} Obj;

void func_8005B968(Obj *arg0) {
    f32 speed;

    arg0->angle = arg0->x8C;
    if (arg0->x7C == 0) {
        syncActorPrevPos();
        arg0->x7C = 1;
        arg0->x88 = 1;
        func_80043328(arg0, 0xC9, 0x100);
        arg0->state = 0x101;
        return;
    }
    speed = 90.0f;
    arg0->x4C = approachF32(0.0f, arg0->x4C, speed);
    arg0->x54 = approachF32(0.0f, arg0->x54, speed);
    arg0->angle = approachS32(0x8000, arg0->angle, 0x5DC);
    if (arg0->xDC >= 20.0f) {
        arg0->x5C -= 0x12;
    }
    if (arg0->x5C < 0x12 || arg0->x84 != 0) {
        arg0->xA4[0xA8 / 4] = 0;
        arg0->func(arg0);
    }
}
