typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x4C - 0x14];
    f32 x4C;
    f32 x50;
    f32 x54;
    char pad58[0x84 - 0x58];
    s32 x84;
    char pad88[0x9C - 0x88];
    void (*fn9C)(void);
    char padA0[0xD8 - 0xA0];
    void (*fnD8)(void);
} Obj;

struct Obj *findActor(s32, struct Obj *);
s32 randomRange(s32, s32);
s32 func_8002492C(f32, f32);
void func_8002ADFC(s32, s32, void *);
s32 approachAngle(s32, s32, s32);
s32 func_8002D260(s32);
void func_8002D3E4(void *, s32);
f32 getCameraTargetDist(void *, f32, s32 *);
f32 func_8002DD60(f32);
void func_80043328(void *, s32, s32);
void actorSetAnim(void *, s32, s32);
s32 func_8005FD88(void *, void *);
void func_8005FE24(void);
f32 sqrtf(f32);

extern f32 D_800088DC;
extern u8 gFrameScale[];
extern u8 gCameraTarget[];
#define BD (*(Obj **)gCameraTarget)

void func_8005FE74(Obj *arg0) {
    s32 ang;
    s32 dist;
    s32 push;
    s32 dx;
    s32 dz;
    s32 t;
    Obj *bd;
    Obj *o;
    f32 x;
    f32 lim;
    f32 ex;
    f32 ez;

    dist = getCameraTargetDist(arg0, 400.0f, &ang);
    if (dist < 200) {
        bd = BD;
        x = arg0->x4;
        push = 200 - dist;
        dx = x - bd->x4;
        dz = arg0->xC - bd->xC;
        arg0->x4 = x + dx * (push / 4) / dist;
        arg0->xC += dz * (push / 4) / dist;
        bd->x4 -= dx * (push * 3 / 4) / dist;
        bd->xC -= dz * (push * 3 / 4) / dist;
        if (abs(func_8002D260(ang - arg0->x10)) < 0x1000) {
            if (func_8005FD88(BD, arg0) != 0) {
                func_8002ADFC(0x25, 500, arg0);
                actorSetAnim(arg0, 0x56, 0x100);
                arg0->x10 = ang;
            }
        }
    } else if (dist < 400) {
        arg0->x10 = approachAngle(ang, arg0->x10, 0x100);
        func_8002D3E4(arg0, 150);
    }
    t = arg0->x84 - *(s32 *)gFrameScale;
    arg0->x84 = t;
    if (t <= 0) {
        arg0->x84 = randomRange(150, 350);
        o = findActor(0x1018, NULL);
        if (o != NULL) {
            lim = D_800088DC;
            do {
                if (o != arg0) {
                    ex = arg0->x4 - o->x4;
                    ez = arg0->xC - o->xC;
                    if (sqrtf(ex * ex + ez * ez) < lim) {
                        func_80043328(arg0, 0x58, 0x100);
                        arg0->fnD8 = arg0->fn9C;
                        arg0->fn9C = func_8005FE24;
                        arg0->x4C = -func_8002DD60(arg0->x4C);
                        arg0->x54 = -func_8002DD60(arg0->x54);
                        arg0->x10 = func_8002492C(arg0->x4C, arg0->x54);
                        func_8002D3E4(arg0, 150);
                        arg0->x10 += 0x8000;
                        return;
                    }
                }
                o = findActor(0x1018, o);
            } while (o != NULL);
        }
    }
}
