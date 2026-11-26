s32 sendCommand(s32, s32);

typedef struct {
    u8 pad[0xCC];
    s32 cc;
    s32 d0;
    u8 pad2[0xDC - 0xD4];
    f32 dc;
} ObjH;

s32 func_80068CBC(ObjH *arg0) {
    s32 a;
    s32 b;
    s32 c;

    if (arg0->d0 == 0x113) {
        a = 0;
        if (arg0->dc < 90.0f) {
            return 0;
        }
        if (96.0f < arg0->dc && arg0->dc < 101.0f) {
            a = 1;
        }
        b = 0;
        if (115.0f < arg0->dc && arg0->dc < 120.0f) {
            b = 1;
        }
        c = 0;
        if (134.0f < arg0->dc && arg0->dc < 139.0f) {
            c = 1;
        }
        if ((a | b | c) != 0) {
            if (arg0->cc == 0) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0xB6);
                arg0->cc = 1;
            }
        } else {
            arg0->cc = 0;
        }
    }
    return 0;
}
