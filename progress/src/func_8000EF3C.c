s16 coss(u16);
s16 sins(u16);
extern s32 gTextWaveTime;
extern s32 gCamSpeedScale;

typedef struct Obj {
    s32 pad0;
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0x5C - 0x10];
    s32 t5C;
    u8 pad60[0x7C - 0x60];
    s32 r7C;
    u8 pad80[0xA0 - 0x80];
    void (*cbA0)(struct Obj *);
} Obj;

void func_8000EF3C(Obj *obj) {
    obj->x8 += 50.0f;
    obj->xC += (obj->r7C * coss(gTextWaveTime * 500 & 0xFFFC)) >> 15;
    obj->x4 += (obj->r7C * sins(gTextWaveTime * 500 & 0xFFFC)) >> 15;
    obj->r7C += 10;
    obj->t5C -= gCamSpeedScale;
    if (obj->t5C <= 0) {
        obj->cbA0(obj);
    }
}
