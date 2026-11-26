s16 coss(u16);
s16 sins(u16);
void func_8002A360(s32, s32);
void func_8002D124(void);
f32 approachF32(f32, f32, f32);
s32 func_80043248(void *);
void actorSetAnim(void *, s32, s32);
void func_800660CC(void *, s32, s32);
extern void *gCameraTarget[];
extern f32 D_80008CEC;
extern f64 D_80008CF0;
extern f64 D_80008CF8;

typedef void (*Fn)(void *);
#define F(p, t, o) (*(t *)((char *)(p) + (o)))

void func_80066CA8(void *arg0) {
    void *o;
    s32 r;
    void *p;
    void *p2;
    void *p1;
    f32 k;
    f32 t;
    f32 a;
    void *q;
    s32 c;

    o = F(arg0, void *, 0xA4);
    p = gCameraTarget[0];
    F(o, s32, 0x68) = -1;
    F(p, s32, 0x68) = -1;
    F(p, s32, 0) = 0x101;
    F(arg0, s32, 0) = 3;
    F(arg0, f32, 0xAC) = F(arg0, f32, 4) + ((sins(F(arg0, u16, 0x12)) * 727) >> 14);
    c = (coss(F(arg0, u16, 0x12)) * 727) >> 14;
    k = D_80008CEC;
    p1 = gCameraTarget[0];
    F(arg0, f32, 0xB4) = F(arg0, f32, 0xC) + c;
    t = approachF32(F(arg0, f32, 0xAC), F(p1, f32, 4), k);
    q = gCameraTarget[0];
    F(q, f32, 4) = t;
    F(gCameraTarget[0], f32, 0xC) = approachF32(F(arg0, f32, 0xB4), F(q, f32, 0xC), k);
    r = func_80043248(arg0);
    func_800660CC(arg0, 0x6D6, 0);
    F(o, s32, 0x10) = F(arg0, s32, 0x10);
    if (F(arg0, s32, 0x8C) == 0 && F(arg0, f32, 0xDC) >= D_80008CF0 && F(arg0, f32, 0xDC) <= D_80008CF8) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x89);
        func_8002D124();
        F(arg0, s32, 0x8C) = 1;
    }
    if (r != 0) {
        actorSetAnim(o, 0xFD, 0x100);
        F(o, s32, 0x68) = 4;
        p2 = gCameraTarget[0];
        F(o, s32, 0x7C) = 0;
        F(p2, s32, 0x68) = 5;
        F(arg0, Fn, 0xA0)(arg0);
    }
}
