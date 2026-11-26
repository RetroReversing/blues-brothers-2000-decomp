s16 coss(u16);
s16 sins(u16);
extern s32 gCamSpeedScale;

typedef struct Obj {
    u8 pad0[4];
    f32 x;              /* 0x04 */
    f32 y;              /* 0x08 */
    f32 z;              /* 0x0C */
    union { s32 unk10; struct { u16 hi; u16 angle; } a; } u10;   /* 0x10 */
    u8 pad14[0x18 - 0x14];
    s32 unk18;          /* 0x18 */
    u8 pad1C[0x40 - 0x1C];
    f32 baseX;          /* 0x40 */
    u8 pad44[4];
    f32 baseZ;          /* 0x48 */
    u8 pad4C[0x5C - 0x4C];
    s32 timer;          /* 0x5C */
    u8 pad60[0x80 - 0x60];
    s32 radius;         /* 0x80 */
    u8 pad84[0xA0 - 0x84];
    void (*cb)(struct Obj *);  /* 0xA0 */
} Obj;

void func_80015870(Obj *arg0) {
    arg0->unk18 += gCamSpeedScale * 300;
    arg0->x = arg0->baseX + (f32)((arg0->radius * coss(arg0->u10.a.angle)) >> 15);
    arg0->z = arg0->baseZ + (f32)((arg0->radius * sins(arg0->u10.a.angle)) >> 15);
    arg0->radius += 10;
    arg0->u10.unk10 += gCamSpeedScale << 9;
    arg0->y += (f32)(gCamSpeedScale * 5);
    arg0->timer -= gCamSpeedScale * 4;
    if (arg0->timer <= 0) {
        arg0->cb(arg0);
    }
}
