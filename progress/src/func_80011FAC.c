s32 sendCommand(s32, s32);
typedef struct ObjN {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad1[0xA0 - 0x10];
    void (*fn)(struct ObjN *);
} ObjN;
extern ObjN *gCameraTarget;

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_80011FAC(ObjN *arg0) {
    s32 dx;
    s32 dy;
    s32 dz;

    dx = arg0->x - gCameraTarget->x;
    dz = arg0->z - gCameraTarget->z;
    dy = arg0->y - gCameraTarget->y;
    if (ABS(dx) < 0xB4 && ABS(dy) < 0x168 && ABS(dz) < 0xB4) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x3B);
        arg0->fn(arg0);
    }
}
