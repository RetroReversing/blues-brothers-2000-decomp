typedef struct Sub { u8 p0[0xA8]; s32 fA8; } Sub;
typedef struct Obj Obj;
typedef void (*Fn)(Obj *);
typedef s32 (*FnI)(Obj *);
struct Obj {
    u8 p0[4]; f32 x; f32 z; u8 p1[4]; s32 f10; u8 p2[0x70]; s32 f84; s32 f88; s32 f8C; s32 f90; u8 p3[0xC];
    FnI fA0; Sub *fA4; u8 p4[0x30]; Fn fD8;
};
typedef struct Pos { u8 p0[4]; f32 x; f32 z; } Pos;
extern void func_8002DA80(Obj *);
extern f32 func_8002DD60(f32);
extern s32 animStepKeys(Obj *);
extern s32 func_80043248(Obj *);
extern void func_8005B968(Obj *);
extern s32 func_80076080();
extern Pos *gCameraTarget;
extern f32 D_801700D0;
extern s32 D_801700D4;
extern void func_8005B6F8(Obj *);

void func_8005B300(Obj *arg0) {
    Fn temp_v0;
    f32 temp_fs0;
    s32 temp_a0;

    if (func_80076080() == 0) {
        temp_fs0 = gCameraTarget->x - arg0->x;
        if (750.0f < func_8002DD60(gCameraTarget->z - arg0->z)) {
            arg0->fA4->fA8 = 0;
            arg0->fA0(arg0);
            return;
        }
        temp_a0 = arg0->f10;
        arg0->f90 = (s32) D_801700D0;
        arg0->f10 = D_801700D4;
        arg0->f8C = temp_a0;
        if ((arg0->fD8 == func_8005B6F8) && (1750.0f < func_8002DD60(temp_fs0))) {
            arg0->fD8 = func_8005B968;
        }
        if (arg0->f88 != 0) {
            arg0->f84 = func_80043248(arg0);
        } else {
            arg0->f84 = animStepKeys(arg0);
        }
        func_8002DA80(arg0);
        temp_v0 = arg0->fD8;
        if (temp_v0 != NULL) {
            temp_v0(arg0);
        }
    }
}
