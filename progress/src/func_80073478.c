typedef struct ObjQ {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x7C - 0x10];
    s32 f7C;
} ObjQ;

ObjQ *findActor(s32, s32);
void debugPrintf(char *);
f32 approachF32(f32, f32, f32);
void func_80034FEC(ObjQ *, s32 *);
void updateCameraView(ObjQ *);
extern char D_80009100[];
extern s32 gCamSpeedScale;
extern ObjQ *D_800B3964;

void func_80073478(ObjQ *arg0) {
    s32 pos[3];
    ObjQ *t;

    t = findActor(0x1023, 0);
    if (t == NULL) {
        t = findActor(0x101E, 0);
        if (t == NULL) {
            debugPrintf(D_80009100);
        }
    }
    pos[0] = t->x;
    pos[1] = t->y + 500.0f;
    pos[2] = t->z;
    arg0->z = approachF32(t->z - 2000.0f, arg0->z, gCamSpeedScale * 10);
    arg0->x = approachF32(pos[0], arg0->x, gCamSpeedScale * 10);
    arg0->y = approachF32(pos[1], arg0->y, gCamSpeedScale * 10);
    if (arg0->z == t->z - 2000.0f && arg0->x == pos[0] && arg0->y == pos[1] && D_800B3964->f7C == 1) {
        D_800B3964->f7C = 2;
    }
    func_80034FEC(arg0, pos);
    updateCameraView(arg0);
}
