typedef struct Obj Obj;
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ u8 pad14[0x54];
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[8];
    /* 0x74 */ s32 f74;
    /* 0x78 */ u8 pad78[4];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[8];
    /* 0x88 */ s32 f88;
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[8];
    /* 0x9C */ void *f9C;
    /* 0xA0 */ u8 padA0[4];
    /* 0xA4 */ Obj *fA4;
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0x14];
    /* 0xC0 */ s32 fC0;
};
Obj *func_800232B4(s32, s32, s32, s32);
Obj *findActor(s32, s32);
f32 approachF32(f32, f32, f32);
f32 func_8002DD60(f32);
s32 func_8003C9AC(Obj *, s32, s32, s32);
void func_80065260();
void func_8006542C();
void func_800656B4();
void func_80065770();
extern f32 D_80008C10;
extern f32 D_80008C14;
extern f32 D_80008C18;
extern f32 D_80008C1C;
extern f32 D_80008C20;
extern f32 D_80008C24;
extern f32 D_80008C28;
extern f32 D_80008C2C;
extern char D_800B3964[];
extern s32 D_800B5DD4[];
extern char gCameraTarget[];
extern s32 D_80140214[];

/* Elevator actor update: it stays put while the camera target is on the elevator (its f10 yaw is outside the +/-0x6D60 window) and otherwise moves toward its nearer floor. When the camera target is close and high enough, it takes the target as a rider; when it reaches the floor it spawns two markers and clears the target's flag. */
void elevatorActorUpdate(Obj *arg0) {
    f32 dxCam;
    f32 dzCam;
    f32 dyFloorA;
    f32 dyFloorB;
    f32 limit;
    f32 t;
    f32 offset;
    Obj *camActor;
    Obj *spawned;

    if ((*(Obj **)D_800B3964)->fC0 == 2) {
        return;
    }
    dxCam = func_8002DD60(arg0->x - (*(Obj **)gCameraTarget)->x);
    dzCam = func_8002DD60(arg0->z - (*(Obj **)gCameraTarget)->z);
    dyFloorA = func_8002DD60((f32)arg0->f8C - (*(Obj **)gCameraTarget)->y);
    dyFloorB = func_8002DD60((f32)arg0->f90 - (*(Obj **)gCameraTarget)->y);
    limit = D_80008C10;
    if (arg0->fC0 == 2) {
        if (!((*(Obj **)gCameraTarget)->z >= D_80008C14)) {
            return;
        }
        if ((*(Obj **)gCameraTarget)->f10 < -0x6D60 || (*(Obj **)gCameraTarget)->f10 > 0x6D60) {
            return;
        }
        arg0->fC0 = 0;
    }
    if (limit < dxCam) {
        return;
    }
    if (limit < dyFloorA && limit < dyFloorB) {
        return;
    }
    if (dyFloorB < dyFloorA) {
        dyFloorA = arg0->f90;
    } else {
        dyFloorA = arg0->f8C;
    }
    if (dyFloorA != arg0->y) {
        arg0->y = approachF32(dyFloorA, arg0->y, 100.0f);
    } else if ((*(Obj **)gCameraTarget)->z >= D_80008C18 && dxCam < D_80008C1C && func_8003C9AC(arg0, 1, 1, 1) != 0) {
        camActor = *(Obj **)gCameraTarget;
        if (camActor->f10 < -0x6D60 || camActor->f10 > 0x6D60) {
            camActor->f9C = func_8006542C;
            camActor->fA4 = arg0;
            D_80140214[0] = 0;
            camActor->z = D_80008C20;
            arg0->fA8 = camActor;
            arg0->f74 = 0;
        }
    }
    if (arg0->y < arg0->f8C) {
        arg0->y = arg0->f8C;
    }
    if (arg0->f90 < arg0->y) {
        arg0->y = arg0->f90;
    }
    if (dxCam < D_80008C24 && dzCam < D_80008C24) {
        D_800B5DD4[0] = 0;
        arg0->f9C = func_80065260;
        arg0->f7C = 0;
        arg0->f88 = 0;
        offset = D_80008C2C;
        spawned = func_800232B4(0x101, arg0->x, arg0->y + D_80008C28, arg0->z - offset);
        spawned->f9C = func_800656B4;
        spawned->fA4 = arg0;
        spawned = func_800232B4(0x101, arg0->x, arg0->y + offset, arg0->z - offset);
        spawned->f9C = func_80065770;
        spawned->fA4 = arg0;
        spawned = findActor(6, 0);
        if (spawned != 0) {
            spawned->f68 = -1;
        }
    }
}
