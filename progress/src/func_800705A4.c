typedef struct Obj {
    u8 pad00[0x78];
    s32 step;   /* 0x78 */
} Obj;
typedef struct Cam { f32 x0, x4, x8, z; } Cam;

void func_80023620(s32);
void func_8002369C(s32, s32);
void func_80023C58(s32);
void func_80023C64(s32);
s32 func_8002ECB8(void);
void func_8006DD34(s32);
extern Cam *D_800B3960;
extern s32 D_800B81D0;
extern s32 gCamSpeedScale;

s32 func_800705A4(Obj *arg0) {
    s32 scroll = 1;

    switch (arg0->step) {
    case 1:
        func_8006DD34(1);
        arg0->step++;
        break;
    case 2:
        if (func_8002ECB8() != 0) {
            func_80023620(1);
            func_8002369C(0x100, 0x1031);
            arg0->step++;
        }
        break;
    case 3:
        func_80023C64(0x10F);
        func_80023C58(0);
        D_800B81D0 = 0;
        return 1;
    default:
        scroll = 0;
        break;
    }
    if (scroll) {
        D_800B3960->z -= gCamSpeedScale * 15;
    }
    return 0;
}
