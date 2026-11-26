typedef struct Obj71 {
    u8 pad0[0x10];
    s32 x10;
    s32 x14;
    s32 x18;
    u8 pad1C[0x58];
    s32 x74;
    u8 pad78[4];
    s32 x7C;
    u8 pad80[4];
    s32 *x84;
} Obj71;
extern s32 gCamSpeedScale;
s32 cameraGetMode(void);

void func_80071A50(Obj71 *o) {
    if (o->x7C == 0) {
        o->x7C = 1;
        if (o->x74 != 0) {
            o->x84 = &o->x10;
        } else {
            if (cameraGetMode() == 0x16) {
                o->x84 = &o->x14;
            } else {
                o->x84 = &o->x18;
            }
        }
    }
    *o->x84 += gCamSpeedScale << 8;
}
