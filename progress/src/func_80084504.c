typedef struct Unk80084504 {
    u8 pad0[0x64];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    u8 pad80[0x8C - 0x80];
    s32 unk8C;
    u8 pad90[0xAC - 0x90];
    f32 unkAC;
    u8 padB0[4];
    f32 unkB4;
    u8 padB8[4];
    s32 unkBC;
    u8 padC0[0xD8 - 0xC0];
    s32 (*unkD8)(struct Unk80084504 *);
    u8 padDC[0x104 - 0xDC];
    f32 unk104;
} Unk80084504;

extern s32 D_800B9B18;
extern char D_800099F8[];
extern char D_80009A0C[];

s32 func_80080DE0(s32 arg0);
void func_80081588(s32 idx, s32 closed);
void func_8002D620(void *arg0);
s32 func_80024394(s32 arg0, s32 arg1);
s32 func_80076080(void *arg0);
s32 func_8002D5CC(void *arg0);
s32 func_800853E8(void *arg0);
s32 func_80080594(void *arg0, s32 arg1);
s32 func_8002444C(void);
void func_80043328(void *arg0, s32 arg1, s32 arg2);
void func_800899DC(void *, ...);
void func_80083A28(void *);
s32 func_80084368(Unk80084504 *);
s32 func_80083CC4(Unk80084504 *);
s32 func_800847E8(Unk80084504 *);
s32 func_8006BB14(Unk80084504 *);
s32 func_80083E98(Unk80084504 *);

void func_80084504(Unk80084504 *arg0) {
    s32 result;

    result = 1;
    if (arg0->unk7C == 0) {
        if (func_80080DE0(arg0->unk70) == 0) {
            func_80081588(arg0->unk70, D_800B9B18);
        }
        arg0->unk7C = 1;
        arg0->unk78 = 0;
        func_8002D620(arg0);
        arg0->unkD8 = NULL;
        if (arg0->unkAC == 0.0f) {
            arg0->unkAC = 0.015f;
        }
        if (arg0->unk104 == 0.0f) {
            arg0->unk104 = 300.0f;
        }
        arg0->unkB4 = 0.0f;
        arg0->unkBC = 1;
        arg0->unk64 = func_80024394(25, 30) * 100;
    }
    if (func_80076080(arg0) != 0) {
        return;
    }
    func_8002D5CC(arg0);
    if (arg0->unkD8 != NULL) {
        result = arg0->unkD8(arg0);
    }
    func_800853E8(arg0);
    if (result != 0) {
        switch (arg0->unk78) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 6:
            switch (result) {
            case 1:
                arg0->unk78 = 1;
                arg0->unkD8 = func_80084368;
                break;
            case 2:
                arg0->unk78 = 4;
                arg0->unkD8 = func_80083CC4;
                break;
            case 3:
                arg0->unk78 = 2;
                arg0->unkD8 = func_800847E8;
                func_80080594(arg0, 0);
                break;
            default:
                func_800899DC(D_800099F8);
                break;
            }
            break;
        default:
            switch (result) {
            case 1:
                arg0->unk78 = 3;
                arg0->unkD8 = func_8006BB14;
                break;
            case 2:
                arg0->unk78 = 4;
                arg0->unkD8 = func_80083CC4;
                arg0->unk8C = 0;
                break;
            case 3:
                arg0->unk78 = 2;
                arg0->unkD8 = func_800847E8;
                func_80080594(arg0, 0);
                break;
            case 4:
                arg0->unk64 = func_80024394(25, 30) * 100;
                arg0->unk78 = 0;
                arg0->unkD8 = func_80083E98;
                if (func_8002444C() & 1) {
                    func_80080594(arg0, 2);
                } else {
                    func_80080594(arg0, 1);
                }
                break;
            default:
                func_800899DC(D_80009A0C);
                break;
            }
            break;
        }
        func_80043328(arg0, arg0->unk74 + arg0->unk78, 0x100);
        if (arg0->unkD8 != NULL) {
            arg0->unkD8(arg0);
        }
    }
    func_80083A28(arg0);
}
