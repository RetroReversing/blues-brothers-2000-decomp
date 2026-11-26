typedef struct Obj68E0C {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x78 - 0x14];
    s32 state;          /* 0x78 */
    s32 inited;         /* 0x7C */
    u8 pad80[0x88 - 0x80];
    s32 f88;
    u8 pad8C[0xD8 - 0x8C];
    s32 (*fn)(struct Obj68E0C *); /* 0xD8 */
    u8 padDC[0xF0 - 0xDC];
    s32 fF0;
    u8 padF4[0xFC - 0xF4];
    s32 count;          /* 0xFC */
} Obj68E0C;

void sendCommand(s32, s32);
void func_8002D124(void);
f32 func_8002D858(void *, s32 *);
s32 func_80043248(Obj68E0C *);
void func_80043328(void *, s32, s32);
s32 func_80068AE8(Obj68E0C *);
s32 func_80068B38(Obj68E0C *);
s32 func_80068BF8(Obj68E0C *);
s32 func_80068DE0(Obj68E0C *);
void debugPrintf(char *);
extern char D_80008DCC[];
extern u8 *gCameraRig;
extern u8 *D_800B3964;

void func_80068E0C(Obj68E0C *arg0) {
    s32 ret;

    ret = 0;
    if (arg0->inited == 0) {
        arg0->fn = func_80068AE8;
        arg0->state = 1;
        func_80043328(arg0, 0x113, 0x100);
        arg0->inited = 1;
    }
    func_8002D858(arg0, &arg0->f10);
    if (arg0->fn != NULL) {
        ret = arg0->fn(arg0);
    }
    if (*(s32 *)(D_800B3964 + 0x6C) == 0x10) {
        if (--arg0->count != 0) {
            arg0->state = 2;
            arg0->fn = func_80043248;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x52);
        } else {
            arg0->state = 5;
            arg0->fn = func_80068BF8;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x51);
        }
        func_8002D124();
        arg0->fF0 = 0xFA;
        arg0->f88 = 0;
        func_80043328(arg0, arg0->state + 0x112, 0x100);
        *(s32 *)(D_800B3964 + 0x6C) = 0;
        return;
    }
    if (ret != 0) {
        arg0->f88 = 0;
        switch (arg0->state) {
        case 0:
            arg0->state = 3;
            arg0->fn = func_80068B38;
            break;
        case 1:
            arg0->state = 0;
            arg0->fn = func_80043248;
            break;
        case 3:
            switch (ret) {
            case 1:
                arg0->state = ret;
                arg0->fn = func_80068DE0;
                break;
            case 2:
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x53);
                arg0->state = 4;
                arg0->fn = func_80043248;
                break;
            }
            break;
        case 2:
        case 4:
            arg0->state = 1;
            arg0->fn = func_80068DE0;
            break;
        default:
            debugPrintf(D_80008DCC);
            break;
        case 5:
            return;
        }
        *(s32 *)(gCameraRig + 0xA8) = 0;
        func_80043328(arg0, arg0->state + 0x112, 0x100);
    }
}
