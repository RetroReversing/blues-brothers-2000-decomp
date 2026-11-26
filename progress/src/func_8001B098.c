typedef struct Vec3i {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct Obj {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x64 - 0x14];
    s32 x64;
    char pad68[0x9C - 0x68];
    void (*fn9C)(void);
    char padA0[0xBC - 0xA0];
    s32 xBC;
    s32 xC0;
    char padC4[0x108 - 0xC4];
} Obj;

Obj *func_80023088(s32);
Obj *func_800230B0(s32);
s32 randomRange(s32, s32);
s32 func_8002492C(f32, f32);
s32 approachAngle(s32, s32, s32);
s32 tickActorTimer(void *);
f32 func_8002DD60(f32);
f32 func_800385AC(void *);
void animStepKeys(void *);
void actorSetAnim(void *, s32, s32);
void debugPrintf(char *);
void func_8001B04C(void);
f32 sqrtf(f32);
s16 sins(u16);
s16 coss(u16);

extern char D_80000C04[];
extern f32 D_80000C10;
extern f32 D_80000C14;
extern f64 D_80000C18;
extern f32 D_80000C20;
extern f64 D_80000C28;
extern u8 D_800B9EC4[];
extern u8 gCamSpeedScale[];
extern u8 gCameraTarget[];
extern s32 D_8014A99C[];
extern u8 D_8014AA1C[];
#define BD (*(Obj **)gCameraTarget)

void func_8001B098(Obj *arg0) {
    Vec3i *path;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 spd;
    f64 lim;
    f32 dy;
    Obj *o;
    Obj *end;
    Obj *start;
    s32 r;

    path = *(Vec3i **)D_8014AA1C;
    animStepKeys(arg0);
    if (path == NULL) {
        debugPrintf(D_80000C04);
        return;
    }
    if (arg0->xC0 == 0) {
        BD->x0 = 0x101;
        arg0->xBC = 0;
        arg0->x4 = path[arg0->xBC].x;
        arg0->xC = path[arg0->xBC].z;
        arg0->x8 = func_800385AC(arg0);
        actorSetAnim(arg0, 4, 0x100);
        arg0->xC0 = 1;
        arg0->x0 = 3;
        BD = arg0;
    }
    dx = path[arg0->xBC].x - arg0->x4;
    dz = path[arg0->xBC].z - arg0->xC;
    dist = sqrtf(dx * dx + dz * dz);
    arg0->x10 = approachAngle(func_8002492C(dx, dz), arg0->x10, *(s32 *)gCamSpeedScale << 9);
    spd = *(f32 *)D_800B9EC4 * D_80000C10;
    arg0->x4 += ((s32)spd * sins(arg0->x10)) >> 15;
    arg0->xC += ((s32)spd * coss(arg0->x10)) >> 15;
    arg0->x8 = func_800385AC(arg0);
    if (dist < D_80000C14) {
        if (++arg0->xBC >= D_8014A99C[0] - 1) {
            arg0->xBC = 0;
        }
    }
    if (tickActorTimer(arg0) != 0) {
        arg0->x64 = 0;
        start = func_80023088(0);
        end = func_800230B0(0);
        o = start;
        if (o <= end) {
            lim = D_80000C18;
            do {
                if (o->x0 & 0x1000) {
                    dx = arg0->x4 - o->x4;
                    dy = arg0->x8 - o->x8;
                    dz = arg0->xC - o->xC;
                    if (!(D_80000C20 < dy) && !(lim < func_8002DD60(dx)) && !(lim < func_8002DD60(dz)) &&
                        !(D_80000C28 < (dist = sqrtf(dx * dx + dz * dz)))) {
                        arg0->fn9C = func_8001B04C;
                        r = randomRange(0, 5);
                        if (r == 0) {
                            actorSetAnim(arg0, 13, 0x100);
                        } else if (r == 1) {
                            actorSetAnim(arg0, 14, 0x100);
                        } else if (r == 2) {
                            actorSetAnim(arg0, 15, 0x100);
                        } else if (r == 3) {
                            actorSetAnim(arg0, 30, 0x100);
                        } else {
                            actorSetAnim(arg0, 18, 0x100);
                        }
                    }
                }
                o++;
            } while (o <= end);
        }
    }
}
