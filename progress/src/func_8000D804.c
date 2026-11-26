typedef struct ObjD {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x18 - 0x10];
    s32 f18;
    u8 pad1C[0x40 - 0x1C];
    f32 f40;
    f32 f44;
    u8 pad48[0x64 - 0x48];
    s32 f64;
    u8 pad68[0x84 - 0x68];
    s32 f84;
    s32 f88;
    s32 f8C;
    s32 f90;
} ObjD;

s16 func_800944B0(u16);
s16 func_80095F60(u16);
s32 func_8002D5CC(ObjD *);
void func_8002ADFC(s32, s32, ObjD *);
s32 func_8002D260(s32);
f32 func_8002DD60(f32);
void func_8003C140(ObjD *);
extern s32 D_800B9EA4;
extern ObjD *D_800BD06C;

void func_8000D804(ObjD *arg0) {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 v;

    arg0->f88 = arg0->f90;
    arg0->f90 = arg0->f18;
    arg0->f18 = (func_800944B0((D_800B9EA4 + arg0->f8C) * 300) * 625) >> 11;
    arg0->y = (arg0->f44 + 434.0f) - (f32)((func_800944B0(arg0->f18) * 217) >> 14);
    arg0->x = arg0->f40 + (f32)((func_80095F60(arg0->f18) * 217) >> 14);
    if (arg0->f84 == 0) {
        if ((arg0->f90 <= arg0->f88 && arg0->f90 <= arg0->f18) ||
            (arg0->f90 >= arg0->f88 && arg0->f90 >= arg0->f18)) {
            arg0->f84 = 1;
            arg0->f64 = 20;
        }
    } else if (func_8002D5CC(arg0) != 0) {
        func_8002ADFC(0xBB, 2000, arg0);
        arg0->f84 = 0;
    }
    v = func_8002D260(arg0->f18);
    if (v < 0) {
        v = -v;
    }
    if (v < 5000) {
        dx = D_800BD06C->x - arg0->x;
        dz = D_800BD06C->z - arg0->z;
        if (!(200.0f < func_8002DD60(dx)) && !(200.0f < func_8002DD60(dz)) && !(200.0f < func_8002DD60(dy))) {
            func_8003C140(D_800BD06C);
        }
    }
}
