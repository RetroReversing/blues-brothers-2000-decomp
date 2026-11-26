typedef struct Obj {
    u8 p0[4]; f32 f4; f32 f8; f32 fC; u8 p1[0x30]; f32 f40; f32 f44; f32 f48; s32 f4C; s32 f50; s32 f54;
    u8 p3[0x38]; s32 f90; u8 p4[8]; void *f9C;
} Obj;
extern f32 func_800379C8();
extern s32 D_800B4C1C[3];
extern f32 D_800B4C20;
extern s32 D_80140200;
extern f32 D_8014022C;
extern f32 D_80140234;
extern void func_8003C760(void);

s32 func_8003C5D8(Obj *arg0) {
    f32 temp_fv0;
    s32 temp_s1;
    s32 temp_v1;

    temp_s1 = arg0->f90;
    temp_fv0 = func_800379C8();
    D_8014022C = temp_fv0;
    if ((f64) temp_fv0 == -1000000.0) {
        arg0->f4 = arg0->f40;
        arg0->f8 = arg0->f44;
        arg0->fC = arg0->f48;
        D_8014022C = D_80140234;
        return arg0->f90;
    }
    if (arg0->f8 <= temp_fv0) {
        arg0->f8 = temp_fv0;
        arg0->f50 = 0;
        arg0->f90 = 1;
    } else {
        D_800B4C1C[0] = 0;
        D_800B4C1C[1] = 0;
        D_800B4C1C[2] = 0;
        arg0->f90 = 0;
    }
    temp_v1 = arg0->f90;
    if ((temp_v1 == 1) && ((f64) D_800B4C20 < 0.8)) {
        if (temp_s1 == temp_v1) {
            arg0->f4 = arg0->f40;
            arg0->f8 = arg0->f44;
            arg0->fC = arg0->f48;
            D_8014022C = D_80140234;
            return temp_v1;
        }
        arg0->f9C = func_8003C760;
        arg0->f4C = 0;
        arg0->f50 = 0;
        arg0->f54 = 0;
        return 1;
    }
    if (200.0f < (arg0->f8 - arg0->f44)) {
        D_80140200 = 0;
        arg0->f4 = arg0->f40;
        arg0->f8 = arg0->f44;
        arg0->fC = arg0->f48;
        D_8014022C = D_80140234;
        return arg0->f90;
    }
    return arg0->f90;
}
