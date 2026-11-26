typedef struct Obj {
    f32 x00;
    f32 x;      /* 0x04 */
    f32 y;      /* 0x08 */
    f32 z;      /* 0x0C */
    s32 angle;  /* 0x10 */
    u8 pad14[4];
    s32 x18;    /* 0x18 */
    u8 pad1C[0x24];
    f32 cx;     /* 0x40 */
    f32 cy;
    f32 cz;     /* 0x48 */
    u8 pad4C[0x10];
    s32 timer;  /* 0x5C */
    u8 pad60[0x20];
    s32 radius; /* 0x80 */
    u8 pad84[0x1C];
    void (*func)(struct Obj *); /* 0xA0 */
} Obj;

s16 coss(u16);
s16 sins(u16);
extern s32 D_800B9ECC;

void func_80015518(Obj *arg0) {
    arg0->x18 += 0x4B4;
    arg0->x = arg0->cx + ((arg0->radius * coss(arg0->angle)) >> 15);
    arg0->z = arg0->cz + ((arg0->radius * sins(arg0->angle)) >> 15);
    arg0->y += 20.0f;
    arg0->radius += 10;
    arg0->angle += 0x1000;
    arg0->timer -= D_800B9ECC * 4;
    if (arg0->timer <= 0) {
        arg0->func(arg0);
    }
}
