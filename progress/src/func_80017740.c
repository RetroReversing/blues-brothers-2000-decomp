typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x8C];
    void *f9C;
    u8 padA0[0x50];
    s32 fF0;
} Obj;
extern Obj *gCameraTarget;
typedef struct { s32 a; s32 arr[7]; s32 idx; } S0E0; extern S0E0 D_800BD0E0;
Obj *func_80015258(Obj *);
void func_8002AD9C(void);
void func_8000C5B4(void);
void func_80014C34(void);
void func_80017710(void);

void func_80017740(Obj *o) {
    s32 dx;
    s32 dz;
    s32 dy;

    dx = o->x - gCameraTarget->x;
    dz = o->z - gCameraTarget->z;
    dy = o->y - gCameraTarget->y;
    if (abs(dx) < 180 && abs(dy) < 360 && abs(dz) < 180) {
        D_800BD0E0.arr[D_800BD0E0.idx]++;
        if (D_800BD0E0.arr[D_800BD0E0.idx] % 100 == 0) {
            func_80015258(gCameraTarget)->f9C = func_80014C34;
        }
        o->fF0 = 0xFF;
        o->f9C = func_80017710;
        func_8002AD9C();
        func_8000C5B4();
    }
}
