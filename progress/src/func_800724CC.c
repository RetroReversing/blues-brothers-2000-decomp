typedef struct {
    u8 pad_0[0x64];
    s32 f64;
    u8 pad_68[4];
    s32 f6C;
    u8 pad_70[0xC];
    s32 f7C;
    u8 pad_80[0xC];
    s32 f8C;
    s32 f90;
} Obj800724CC;

s32 func_8001B990(s32, s32);
s32 func_80023DBC(s32);
s32 tickActorTimer(void *);
void func_80034F1C(void *);
void func_80052A30(void);
void func_80052A5C(s32);
s32 func_80052A68(s32, char *);
void func_80052B24(s32, char *, void *);
void func_800723EC(void);
extern Obj800724CC *gCameraRig;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
extern s32 D_800BD0FC;

void func_800724CC(Obj800724CC *arg0) {
    s32 id;
    char *name = "inter1";

    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        D_800B3970 = 0x96;
        D_800B3974 = 0xB6;
        D_800B3978 = 0xC6;
        arg0->f90 = 0;
        arg0->f8C = 0;
        arg0->f6C = 0;
        arg0->f64 = 0x96;
        func_800723EC();
        if (D_800BD0FC == 0) {
            arg0->f7C = 0xA;
        }
    }
    if (arg0->f7C == 0xA) {
        if (func_8001B990(0x100, 0x28) != 0) {
            arg0->f7C = 1;
            return;
        }
        func_80052A30();
        D_800B5DD4 = 0;
        id = func_80023DBC(0xE63);
        if (func_80052A68(id, name) == 0 && tickActorTimer(arg0) != 0) {
            func_80052A5C(0);
            func_80052B24(id, name, arg0);
            arg0->f7C = 1;
            func_8001B990(0x200, 0x28);
        }
    }
    if (1000.0f < ((f32 *)gCameraTarget)[2]) {
        if (arg0->f6C == 0) {
            arg0->f6C = 1;
            gCameraRig->f6C = 2;
            func_80034F1C(gCameraRig);
        }
    } else {
        arg0->f6C = 0;
    }
}
