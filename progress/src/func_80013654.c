typedef struct Obj {
    u8 pad0[0xB8];
    s32 fB8;
    u8 padBC[0x14];
    s32 fD0;
    u8 padD4[8];
    f32 fDC;
} Obj;
void sendCommand(s32, s32);
extern Obj *gCameraTarget;

s32 func_80013654(Obj *o) {
    Obj *p;

    if (o->fB8 == 5) {
        return 1;
    }
    p = gCameraTarget;
    if (p->fD0 == 13) {
        if (p->fDC < 7.0 || p->fDC > 11.0) {
            return 0;
        }
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xB1);
        return 1;
    }
    if (p->fD0 == 19) {
        if (p->fDC < 7.0 || p->fDC > 11.0) {
            return 0;
        }
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xB1);
        return 1;
    }
    if (p->fD0 == 14) {
        if (p->fDC < 8.0 || p->fDC > 13.0) {
            return 0;
        }
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xB1);
        return 1;
    }
    if (p->fD0 == 15) {
        if (p->fDC < 10.0 || p->fDC > 16.0) {
            return 0;
        }
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xB1);
        return 2;
    }
    return 0;
}
