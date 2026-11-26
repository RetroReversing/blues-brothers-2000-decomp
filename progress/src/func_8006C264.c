void func_8003BF98(void *);
void func_80043328(void *, s32, s32);
extern void *gCameraTarget;
extern s32 D_80140230;
void func_8006C1D4(void *);

typedef struct {
    u8 pad0[8];
    f32 unk8;
    u8 padC[4];
    s32 unk10;
    u8 pad14[0x50];
    s32 unk64;
    u8 pad68[0x14];
    s32 unk7C;
    u8 pad80[4];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    u8 pad94[0x44];
    void (*unkD8)(void *);
    f32 unkDC;
    u8 padE0[0x10];
    s32 unkF0;
} Obj;

s32 func_8006C264(Obj *arg0) {
    arg0->unk10 = arg0->unk8C;
    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        arg0->unk88 = 1;
        func_80043328(arg0, 0xEF, 0x100);
        arg0->unk64 = 0xC8;
        return;
    }
    if (arg0->unk90 < 0x190 && arg0->unk7C == 1 && arg0->unkF0 == 0 &&
        ((Obj *)gCameraTarget)->unk8 < arg0->unk8 + 300.0f) {
        if (13.0f < arg0->unkDC && arg0->unkDC < 20.0f) {
            func_8003BF98(gCameraTarget);
            D_80140230 = 0x96;
            arg0->unk7C++;
        }
    }
    if (arg0->unk84 != 0) {
        arg0->unk7C = 0;
        arg0->unk88 = 0;
        arg0->unkD8 = func_8006C1D4;
    }
}
