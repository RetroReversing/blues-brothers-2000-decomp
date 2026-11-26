typedef struct G {
    u8 p0[8]; f32 f8; u8 p1[8]; s32 f14; s32 f18; u8 p2[0x28]; f32 f44; u8 p3[0x1C]; s32 f64; u8 p4[0x14]; s32 f7C; s32 f80;
    u8 p5[4]; s32 f88;
} G;
extern void func_8002D620();
extern s32 func_8006DA0C(G *);
extern void func_8004303C(G *);
extern s32 func_8002D5CC(G *);
extern f32 func_8002D340(f32, f32, f32);

void func_8006E250(G *arg0) {
    f32 temp_fv0;
    s32 temp_v0;

    if (arg0->f7C == 0) {
        arg0->f14 = -0x3F9C;
        arg0->f7C = 1;
        arg0->f18 = 0;
        arg0->f80 = 0;
        arg0->f88 = 0;
        arg0->f64 = 0xA;
        func_8002D620();
    }
    if (func_8006DA0C(arg0) == 0) {
        func_8004303C(arg0);
        switch (arg0->f80) {
        case 0:
            if (func_8002D5CC(arg0) != 0) {
                arg0->f64 = 0xA;
                temp_fv0 = func_8002D340(arg0->f44 - 300.0f, arg0->f8, 20.0f);
                arg0->f8 = temp_fv0;
                if (temp_fv0 == (arg0->f44 - 300.0f)) {
                    arg0->f80 = 1;
                    return;
                }
            }
            break;
        case 1:
            if (func_8002D5CC(arg0) != 0) {
                arg0->f64 = 5;
                arg0->f88 += 0x800;
                if (arg0->f88 == 0x8000) {
                    arg0->f80 = 2;
                    return;
                }
            }
            break;
        case 2:
            if (func_8002D5CC(arg0) != 0) {
                arg0->f64 = 0xA;
                temp_fv0 = func_8002D340(arg0->f44, arg0->f8, 20.0f);
                arg0->f8 = temp_fv0;
                if (temp_fv0 == arg0->f44) {
                    arg0->f80 = 3;
                    return;
                }
            }
            break;
        case 3:
            if (func_8002D5CC(arg0) != 0) {
                arg0->f64 = 5;
                arg0->f88 -= 0x800;
                if (arg0->f88 == 0) {
                    arg0->f80 = 0;
                }
            }
            break;
        }
    }
}
