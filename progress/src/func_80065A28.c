typedef struct ObjV {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    u8 pad14[0x84 - 0x14];
    s32 f84;
    u8 pad88[0xC0 - 0x88];
    s32 fC0;
} ObjV;

f32 func_8002DD60(f32);
extern ObjV *D_800BD06C;
extern s32 D_80140210;
extern s32 D_80140214;

void func_80065A28(ObjV *arg0) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 lim;

    arg0->f0 = 0x101;
    if (arg0->fC0 == 0) {
        dx = func_8002DD60(D_800BD06C->x - arg0->x);
        dy = func_8002DD60(D_800BD06C->y - arg0->y);
        dz = func_8002DD60(D_800BD06C->z - arg0->z);
        if (dx < 100.0f && dy < 175.0f && (D_800BD06C->f10 >= -0x2AF7 && D_800BD06C->f10 <= 0x2AF7)) {
            arg0->fC0 = 1;
            D_80140214 = 0;
            D_80140210 = 1;
            arg0->f84 = D_800BD06C->x;
        }
    } else {
        lim = arg0->x + 50.0f;
        if (lim < D_800BD06C->x) {
            D_800BD06C->x = lim;
        }
        lim = arg0->x - 50.0f;
        if (D_800BD06C->x < lim) {
            D_800BD06C->x = lim;
        }
        if (D_800BD06C->z <= 190.0f && !(D_800BD06C->f10 >= -0x2AF7 && D_800BD06C->f10 <= 0x2AF7)) {
            D_80140214 = 1;
            D_80140210 = 0;
            arg0->fC0 = 0;
        }
    }
}
