typedef struct Obj Obj;
struct Obj {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    s32 angle;
    u8 pad14[0x5C];
    s32 unk70;
    s32 unk74;
    u8 pad78[4];
    s32 unk7C;
    u8 pad80[0x1C];
    void (*handler)(Obj *);
    u8 padA0[8];
    Obj *unkA8;
    u8 padAC[0x10];
    s32 unkBC;
    u8 padC0[0x1C];
    f32 unkDC;
};

s16 sins(u16);
s32 func_8002492C(f32, f32);
void func_80043328(Obj *, s32, s32);
void actorSetAnim(Obj *, s32, s32);
void func_80052A30(void);
s32 startStoryDialog(s32, char *, Obj *);
void func_800664A8(Obj *);
Obj *findActor(s32, s32);
void func_8002A360(s32, s32);
void func_8000F670(Obj *);
void func_800462A0(Obj *);
extern s32 D_80140228;
extern Obj *gCameraTarget;

s32 func_800674E4(Obj *arg0) {
    if (arg0->unk7C == 0) {
        func_80043328(arg0, 0xF9, 0x100);
        arg0->unk7C = 1;
        arg0->unk74 = 1;
        arg0->unk70 = 0;
        D_80140228 = 0;
        func_80052A30();
        gCameraTarget->x = arg0->x + (f32)((sins(arg0->angle) * 75) >> 13);
        gCameraTarget->z = arg0->z + (f32)((sins(arg0->angle) * 75) >> 13);
        gCameraTarget->angle = func_8002492C(gCameraTarget->x - arg0->x, gCameraTarget->z - arg0->z) + 0x8000;
        gCameraTarget->y = arg0->y;
        actorSetAnim(gCameraTarget, 1, 0x100);
        func_800664A8(arg0);
        return 0;
    }
    if (arg0->unk7C == 1 && arg0->unk70 != 0) {
        func_80043328(arg0, 0xFE, 0x100);
        arg0->unk70 = 0;
        arg0->unk74 = 0;
        if (startStoryDialog(arg0->unkBC, "warden_finished", arg0) != 0) {
            arg0->unk7C++;
        }
    } else {
        if (arg0->unk7C == 2) {
            if (findActor(0x800, 0) == NULL) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x5B);
                func_80043328(arg0, 0xF7, 0x100);
                arg0->unk74 = 1;
                arg0->unk70 = 0;
                arg0->unk7C++;
                if (arg0->unkA8 != NULL) {
                    arg0->unkA8->handler = func_8000F670;
                    arg0->unkA8 = NULL;
                }
            }
        }
        if (arg0->unk7C == 3 && arg0->unkDC > 32.0f && arg0->unkDC < 34.0f) {
            D_80140228 = 1;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xD6);
        }
        if (arg0->unk7C == 3 && arg0->unk70 != 0) {
            D_80140228 = 0;
            arg0->handler = func_800462A0;
        }
    }
}
