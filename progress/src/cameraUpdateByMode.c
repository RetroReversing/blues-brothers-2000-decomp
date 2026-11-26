typedef struct Pos {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
} Pos;

typedef struct Obj495C {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
    char pad10[0x30];
    f32 hx;
    f32 hy;
    f32 hz;
    char pad4C[0x3C];
    s32 off;
    char pad8C[0x10];
    void *fn;
    char padA0[8];
    Pos *link;
} Obj495C;

extern s32 cameraGetMode(void);
extern void updateCameraView(Obj495C *);
extern s32 approachS32(s32, s32, s32);
extern f32 approachF32(f32, f32, f32);
extern void func_80034FEC(Obj495C *, s32 *);
extern void func_80036FB8(Obj495C *, s32);
extern void func_80064808();
extern f32 D_80008BDC;
extern f32 D_80008BE0;
extern f32 D_80008BE4;
extern f32 D_80008BE8;
extern f32 D_80008BEC;
extern f32 D_80008BF0;
extern f32 D_80008BF4;
extern f32 D_80008BF8;
extern f32 D_80008BFC;
extern f32 D_80008C00;
extern f32 D_80008C04;
extern f32 D_80008C08;
extern u8 D_800B9EAC[];
extern u8 D_800B9EB0[];
extern u8 gCamSpeedScale[];
extern u8 gCameraTarget[];
extern s32 D_800BD278[];
extern s32 D_800BD688[];
extern u8 D_80107040[];

#define CAM (*(Pos **)gCameraTarget)

/* Moves the camera toward its wanted position for the current camera mode (follow, fixed
   or scripted). Pans sideways from the pad, aims at the target or the player, then
   calls updateCameraView. */
void cameraUpdateByMode(Obj495C *view) {
    s32 focus[3];
    Pos *link;
    f32 targetX;
    f32 scale;
    f32 newY;
    f32 speed;
    f32 scaledZ;
    f32 homeX;
    f32 x;
    f32 homeY;
    f32 focusZ;

    if ((*(s32 *)D_80107040) & 2) {
        view->off = approachS32(-500, view->off, (*(s32 *)gCamSpeedScale) * 20);
    } else if ((*(s32 *)D_80107040) & 1) {
        view->off = approachS32(500, view->off, (*(s32 *)gCamSpeedScale) * 20);
    } else {
        view->off = approachS32(0, view->off, (*(s32 *)gCamSpeedScale) * 20);
    }
    do {
        link = view->link;
    } while (0);
    if (link != NULL) {
        targetX = CAM->x;
        scaledZ = CAM->z * D_80008BDC;
        focus[0] = ((link->x + 2.0f * targetX) - targetX * D_80008BDC) * D_80008BE0;
        focus[1] = link->y + CAM->y + (f32) view->off;
        focusZ = ((link->z + 2.0f * CAM->z) - scaledZ) * D_80008BE0;
    } else {
        focus[0] = CAM->x;
        focus[1] = CAM->y + D_80008BE4;
        focusZ = CAM->z;
    }
    focus[2] = focusZ;
    switch (cameraGetMode()) {
    case 5:
        view->fn = func_80064808;
        scale = (f32) (D_800BD688[2] - D_800BD278[2]);
        view->z = approachF32(CAM->z - D_80008BE8, view->z, (f32) ((*(s32 *)gCamSpeedScale) * 50));
        homeX = view->hx;
        homeY = view->hy;
        (*(f32 *)D_800B9EB0) = view->z / scale;
        view->x = homeX;
        view->y = homeY;
        (*(f32 *)D_800B9EAC) = view->x / (f32) (D_800BD688[0] - D_800BD278[0]);
        break;
    case 0x21:
        view->link = NULL;
        view->z = approachF32(CAM->z - D_80008BEC, view->z, (f32) ((*(s32 *)gCamSpeedScale) * 450));
        view->x = approachF32(CAM->x + (f32) view->off, view->x, (f32) ((*(s32 *)gCamSpeedScale) * 450));
        newY = approachF32(CAM->y + D_80008BF0, view->y, (f32) ((*(s32 *)gCamSpeedScale) * 450));
        view->y = newY;
        if (D_80008BF4 < newY) {
            view->y = D_80008BF4;
        }
        if (focus[1] >= 0x19AB) {
            focus[1] = 0x19AA;
        }
        if (view->x > D_80008BF8) {
            view->x = D_80008BF8;
        }
        if (view->x < D_80008BFC) {
            view->x = D_80008BFC;
        }
        focus[0] += view->off;
        break;
    case 0x37:
        speed = D_80008C00;
        view->z = approachF32(CAM->z, view->z, speed);
        view->x = approachF32(CAM->x + D_80008C04, view->x, speed);
        view->y = approachF32(CAM->y + D_80008C08, view->y, 50.0f);
        break;
    default:
        view->z = view->hz;
        view->x = view->hx;
        view->y = view->hy;
        break;
    }
    func_80034FEC(view, focus);
    updateCameraView(view);
    func_80036FB8(view, 3);
}
