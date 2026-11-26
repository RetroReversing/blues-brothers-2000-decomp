typedef struct ObjL ObjL;
struct ObjL {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    u8 pad14[0x74 - 0x14];
    s32 f74;
    u8 pad78[0x9C - 0x78];
    void *f9C;
    u8 padA0[0xA4 - 0xA0];
    ObjL *fA4;
    u8 padA8[0xC0 - 0xA8];
    s32 fC0;
    u8 padC4[0xD0 - 0xC4];
    s32 fD0;
    u8 padD4[0xDC - 0xD4];
    f32 fDC;
};

void debugPrintf(char *);
void func_80043328(ObjL *, s32, s32);
void animStepKeys(ObjL *);
void actorSetAnim(ObjL *, s32, s32);
s32 approachAngle(s32, s32, s32);
f32 approachF32(f32, f32, f32);
void sendCommand(s32, s32);
s32 func_80043248(ObjL *);
void func_800393F4(void);
extern char D_80008C4C[];
extern s32 gCamSpeedScale;

void func_8006542C(ObjL *arg0) {
    ObjL *t;
    s32 done;
    f32 tgt;

    t = arg0->fA4;
    if (t == NULL) {
        debugPrintf(D_80008C4C);
    }
    if (t->fC0 == 1) {
        if (arg0->fD0 != 1) {
            func_80043328(arg0, 1, 0x100);
        }
        animStepKeys(arg0);
    } else if (t->fC0 == 0) {
        if (t->f74 == 0) {
            actorSetAnim(arg0, 2, 0x100);
            t->f74 = 1;
        } else {
            arg0->f10 = approachAngle(0x7FFF, arg0->f10, gCamSpeedScale * 100);
            arg0->x = approachF32(t->x, arg0->x, 20.0f);
            arg0->y = approachF32(t->y + 15.0f, arg0->y, 20.0f);
            arg0->z = approachF32(t->z, arg0->z, 20.0f);
            animStepKeys(arg0);
        }
    } else {
        if (t->f74 == 0) {
            sendCommand(0x19, 0);
            func_80043328(arg0, 0x1A, 0x100);
            t->f74 = 1;
        } else {
            done = func_80043248(arg0);
            tgt = 180.0f;
            if (arg0->fDC > 7.0f) {
                arg0->z = approachF32(tgt, arg0->z, gCamSpeedScale * 29.0f);
            }
            arg0->y = approachF32(t->y, arg0->y, 20.0f);
            if (done != 0) {
                actorSetAnim(arg0, 1, 0x100);
                arg0->f9C = func_800393F4;
                arg0->fA4 = NULL;
            }
        }
    }
}
