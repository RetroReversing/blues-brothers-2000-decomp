typedef struct Obj {
    u8 pad0[0xC0];
    s32 xC0;
    u8 padC4[0xF0 - 0xC4];
    s32 xF0;
    u8 padF4[0xFC - 0xF4];
    s32 xFC;
} Obj;

extern void sendCommand(s32, s32);
extern s32 randomRange(s32, s32);
extern void func_8002D124(void);
extern s16 D_800B9B1C[];

s32 func_80083920(Obj *o, s32 arg1) {
    s32 flags;
    s32 dmg;
    s32 hit;
    u32 bit;
    s32 i;

    if (!(o->xC0 & ~1)) {
        return 0;
    }
    hit = dmg = 0;
    bit = 0x100;
    flags = o->xC0;
    i = 8;
    do {
        if (flags & bit) {
            dmg = D_800B9B1C[i];
            if (bit == 0x10 || bit == 0x100) {
                hit = 1;
            }
            break;
        }
        bit >>= 1;
        i--;
    } while (bit != 0);
    if (arg1 != 0 && hit == 0) {
        return 0;
    }
    o->xC0 = 0;
    o->xFC -= dmg;
    o->xF0 = 0xC0;
    if (o->xFC <= 0) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x2E);
        func_8002D124();
        return 2;
    }
    sendCommand(0xC, 0x80);
    sendCommand(8, randomRange(0, 0xA) + 0xA9);
    func_8002D124();
    return 1;
}
