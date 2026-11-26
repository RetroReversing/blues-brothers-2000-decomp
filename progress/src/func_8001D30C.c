typedef struct {
    s32 state;
    f32 x;
    f32 y;
    f32 z;
    s32 w10;
    s32 w14;
    s32 w18;
    u8 pad1C[0x44 - 0x1C];
    f32 ground;
    u8 pad48[0x50 - 0x48];
    f32 vel;
    u8 pad54[0x64 - 0x54];
    s32 timer;
    u8 pad68[0x70 - 0x68];
    s32 id;
    u8 pad74[0x90 - 0x74];
    s32 flag90;
    u8 pad94[0x9C - 0x94];
    void *cb;
    u8 padA0[0xA4 - 0xA0];
    void *saved;
    u8 padA8[0xB0 - 0xA8];
    f32 accel;
    u8 padB4[0xC0 - 0xB4];
    s32 flags;
} Obj;

s32 cameraGetMode(void);
s32 func_80013784(Obj *);
void func_80017F78();
void func_8001B990(s32, s32);
void updateCameraView(Obj *);
void sendCommand(s32, s32);
void getCameraTargetDist(Obj *, f32, s32);
void func_8001D2C0(Obj *);
extern s32 func_80023078;
extern s32 D_800A954C;
extern Obj *gCameraRig;
extern f32 D_800B9EC4;
extern Obj *D_800BD060;
extern s32 D_80140228;

void func_8001D30C(Obj *o)
{
    f32 hi;
    f32 lo;
    Obj *p;
    Obj *q;
    void *temp;

    hi = o->ground + 100.0f;
    o->accel = 0.0f;
    lo = o->ground - 30.0f;
    if (o->flag90 != 0) {
        if (func_80013784(o) != 0) {
            o->accel = -2400.0f;
        } else {
            o->accel = -2000.0f;
        }
    }
    o->accel = o->accel - (o->y - hi) * 18.0f;
    o->vel = o->vel + D_800B9EC4 * (o->accel - o->vel * 3.0f);
    o->y = o->y + D_800B9EC4 * o->vel;
    if (o->ground <= o->y) {
        o->y = o->ground;
        o->accel = 0.0f;
        o->vel = 0.0f;
    }
    o->state = 0x10E;
    getCameraTargetDist(o, 200.0f, 0);
    if (o->y < lo) {
        func_8001B990(0x200, o->id);
        o->y = lo;
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xF);
        if (cameraGetMode() == 7) {
            func_8001B990(0x200, o->id);
            if (D_800A954C == 0) {
                p = gCameraRig;
                temp = p->cb;
                p->cb = (void *)(&func_80023078 + 2);
                p->flags |= 1;
                p->saved = temp;
                q = D_800BD060;
                p->x = q->x;
                p->y = q->y;
                p->z = q->z;
                D_800A954C = 1;
                p->w10 = q->w10;
                D_80140228 = 0;
                p->w14 = q->w14;
                p->w18 = q->w18;
                updateCameraView(p);
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x72);
                o->cb = (void *)func_8001D2C0;
                o->timer = 300;
                return;
            }
        } else if (o->id == 1) {
            func_80017F78(10);
        }
        o->cb = (void *)(&func_80023078 + 2);
    }
}
