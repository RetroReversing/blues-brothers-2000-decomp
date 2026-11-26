typedef struct Obj Obj;
typedef void (*Fn)(Obj *);
struct Obj {
    s32 f0; u8 p0[4]; f32 f8; u8 p1[0x38]; f32 f44; u8 p2[0x10]; s32 f58; s32 f5C; u8 p3[8]; s32 f68; u8 p4[4]; s32 f70;
    u8 p5[4]; s32 f78; u8 p6[0x24]; Fn fA0; u8 p7[0x1C]; s32 fC0;
};
extern s32 func_8001B990(s32, s32);
extern s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
extern Obj *func_80023874(s32, Obj *);
extern s32 abs(s32);
extern s16 coss(s32);
extern s32 D_800B9EA4;

void func_8001BC2C(Obj *arg0) {
    s32 temp_v0;
    s32 var_v0;
    Obj *var_v0_2;

    if (func_8001B990(0x100, 0x14) != 0) {
        arg0->fA0(arg0);
    } else {
        arg0->f0 = 0x119;
        if (arg0->f78 == 0) {
            arg0->f78 = 1;
            arg0->f68 = 0xD;
            arg0->f58 = func_800221C0(0, 1, 1, 3, 0, 0, 1, 0);
        }
        var_v0 = abs((s32) (arg0->f44 - arg0->f8));
        temp_v0 = 0xFF - (var_v0 >> 3);
        arg0->f5C = temp_v0;
        if (temp_v0 < 0) {
            arg0->f5C = 0;
        }
        if (arg0->f5C >= 0x100) {
            arg0->f5C = 0xFF;
        }
        if (func_8001B990(0x100, arg0->f70) != 0) {
            if ((arg0->f44 - 2000.0f) < arg0->f8) {
                arg0->f8 = arg0->f8 - 10.0f;
                var_v0_2 = func_80023874(0x1019, NULL);
                if (var_v0_2 != NULL) {
                    do {
                        var_v0_2->fC0 = 1;
                        var_v0_2 = func_80023874(0x1019, var_v0_2);
                    } while (var_v0_2 != NULL);
                }
            } else {
                func_8001B990(0x200, 0x14);
                arg0->fA0(arg0);
            }
        } else {
            arg0->f8 = arg0->f44 + (f32) ((s32) (coss((D_800B9EA4 * 0x64) & 0xFFFC) * 0x19) >> 0xE);
        }
    }
}
