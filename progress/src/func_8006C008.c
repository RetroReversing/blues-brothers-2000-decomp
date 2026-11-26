void func_8001B990(s32, s32);
void syncActorPrevPos(void *);
void func_80043328(void *, s32, s32);
s32 func_8006B820(void *);
s32 func_8006BA14(void *);
s32 func_8006BA6C(void *);
s32 updateChaseVehicle(void *);
void func_8006C524(void *);
s32 func_80080DE0(s32);
void initSpline(s32, s32);
void func_80083A28(void *);
extern f32 D_80008F74;
extern f32 D_80008F78;
extern s32 D_800B9B18;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))
typedef s32 (*Fn)(void *);

void func_8006C008(void *arg0) {
    s32 r;

    if (F(arg0, s32, 0x7C) == 0) {
        if (func_80080DE0(F(arg0, s32, 0x70)) == 0) {
            initSpline(F(arg0, s32, 0x70), D_800B9B18);
        }
        F(arg0, s32, 0xBC) = 1;
        F(arg0, s32, 0x7C) = 1;
        F(arg0, s32, 0x78) = 0;
        syncActorPrevPos(arg0);
        F(arg0, Fn, 0xD8) = 0;
        if (F(arg0, f32, 0xAC) == 0.0f) {
            F(arg0, f32, 0xAC) = 0.015f;
        }
        if (F(arg0, f32, 0x104) == 0.0f) {
            F(arg0, f32, 0x104) = 300.0f;
        }
        F(arg0, f32, 0xB4) = 0.0f;
        F(arg0, s32, 0xBC) = 1;
        F(arg0, Fn, 0xD8) = func_8006BA14;
        F(arg0, s32, 0x6C) = 0;
    }
    if (F(arg0, Fn, 0xD8) != 0) {
        r = F(arg0, Fn, 0xD8)(arg0);
    }
    if (r != 0) {
        switch (F(arg0, s32, 0x78)) {
        case 7:
            F(arg0, s32, 0x78) = 1;
            F(arg0, Fn, 0xD8) = func_8006B820;
            break;
        case 6:
            if (F(arg0, s32, 0x8C) == 1) {
                F(arg0, s32, 0x78) = 0;
                F(arg0, Fn, 0xD8) = func_8006BA6C;
                break;
            }
            F(arg0, Fn, 0xD8) = updateChaseVehicle;
            F(arg0, s32, 0x64) = 1000;
            break;
        case 3:
            func_8006C524(arg0);
            return;
        default:
            F(arg0, Fn, 0xD8) = updateChaseVehicle;
            F(arg0, s32, 0x64) = 1000;
            break;
        }
        func_80043328(arg0, F(arg0, s32, 0x74) + F(arg0, s32, 0x78), 0x100);
        if (F(arg0, Fn, 0xD8) != 0) {
            F(arg0, Fn, 0xD8)(arg0);
        }
    }
    func_80083A28(arg0);
    if (F(arg0, s32, 0x78) == 5) {
        func_8001B990(0x200, 0x1A);
    }
}
