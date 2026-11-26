void func_80012110(void *);
s32 func_80024394(s32, s32);
s32 func_8002D5CC(void *);
void func_8002D620(void *);
void func_8003BF98(void *, s32);
void func_80059BC0(void *);
extern void *D_800BD06C;
extern s32 func_8000D620;

typedef struct {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x30];
    f32 x0;
    f32 y0;
    f32 z0;
    u8 pad4C[0x18];
    s32 unk64;
    u8 pad68[0x14];
    s32 unk7C;
    u8 pad80[0x1C];
    s32 *unk9C;
} Obj;

void func_8000D688(Obj *arg0) {
    s32 i;
    s32 dx, dy, dz;

    if (arg0->unk7C == 0) {
        func_8002D620(arg0);
        arg0->unk7C = 1;
    }
    arg0->x = arg0->x0 + func_80024394(-20, 20);
    arg0->z = arg0->z0 + func_80024394(-20, 20);
    if (func_8002D5CC(arg0) != 0) {
        arg0->unk64 = 100;
        arg0->unk9C = &func_8000D620;
        arg0->x = arg0->x0;
        arg0->z = arg0->z0;
        arg0->y = arg0->y0 - 600.0f;
        for (i = 0; i < func_80024394(2, 7); i++) {
            func_80012110(arg0);
        }
        dx = ((Obj *)D_800BD06C)->x - arg0->x;
        dz = ((Obj *)D_800BD06C)->z - arg0->z;
        dy = ((Obj *)D_800BD06C)->y - arg0->y;
        if (abs(dy) < 100 && abs(dx) + abs(dz) < 300) {
            func_8003BF98(D_800BD06C, dx);
            func_80059BC0(arg0);
        }
    }
}
