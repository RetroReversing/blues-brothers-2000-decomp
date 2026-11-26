typedef struct G G;
typedef void (*Fn)(G *);
struct G {
    u8 p0[0x70]; s32 f70; u8 p1[4]; s32 f78; s32 f7C; s32 f80; u8 p2[0x18]; Fn f9C; u8 p3[0x20]; s32 fC0; u8 p4[0xC]; s32 fD0; u8 p5[8]; f32 fDC;
};
extern void fireActorEvents();
extern f32 func_8002D858(G *, s32);
extern void func_800799A8(G *);
extern void sendCommand(s32, s32);
extern void func_8003BF98(G *);
extern void func_80043328(G *, s32, s32);
extern void actorSetAnim(G *, s32, s32);
extern void func_80012718(G *);
extern void func_80079BBC(G *);
extern void debugPrintf();
extern s32 func_80043248(G *);
extern G *gCameraTarget;

void func_80079A08(G *arg0) {
    f32 temp_fv1;
    f32 temp_fv1_2;

    fireActorEvents();
    temp_fv1 = func_8002D858(arg0, 0);
    if ((arg0->fD0 == 0xDB) && (temp_fv1 < 250.0f)) {
        temp_fv1_2 = arg0->fDC;
        if (!(temp_fv1_2 < 30.0f)) {
            if (arg0->fC0 & ~1) {
                arg0->f9C = func_800799A8;
                sendCommand(0xC, 0x80);
                sendCommand(8, 9);
                return;
            }
        } else if ((arg0->f80 == 0) && (19.0f < temp_fv1_2)) {
            arg0->f80 = 1;
            func_8003BF98(arg0);
        }
    }
    if (arg0->f7C == 0) {
        switch (arg0->f78) {
        case 0:
            func_80043328(arg0, 0xDB, 0x100);
            actorSetAnim(gCameraTarget, 0x22, 0x80);
            arg0->f78 = 1;
            arg0->f80 = 0;
            func_80012718(arg0);
            break;
        case 1:
            func_80043328(arg0, 0xDD, 0x100);
            arg0->f78 = 2;
            break;
        case 2:
            func_80012718(arg0);
            arg0->f9C = func_80079BBC;
            arg0->f7C = 0;
            arg0->f78 = 0;
            return;
        default:
            debugPrintf("bad porcupine data!");
            break;
        }
    }
    arg0->f7C = (func_80043248(arg0) == 0);
}
