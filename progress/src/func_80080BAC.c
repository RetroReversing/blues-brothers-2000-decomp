typedef struct G G;
typedef void (*Fn)(G *);
struct G {
    s32 f0; f32 f4; f32 f8; f32 fC; s32 f10; s32 f14; u8 p0[0x4C]; s32 f64; s32 f68; u8 p1[4]; s32 f70; u8 p2[8]; s32 f7C;
    u8 p3[0x1C]; Fn f9C;
};
extern G *func_80017DEC(s32);
extern G *func_800232B4(s32, s32, s32, s32);
extern G *func_80023874(s32, G *);
extern s32 func_8002D260(s32);
extern s32 func_8002D5CC(G *);
extern f32 func_8002D66C(G *, f32, s32);
extern void func_80033DC4(G *);
extern void func_800340B4(G *);
extern f32 func_800385AC(G *);
extern void func_800433A8(G *, s32, s32);
extern void func_80080AF0(G *);
extern void func_8003930C(G *);
extern void func_800899DC();
extern G *D_800B3960;
extern s32 D_800B9ECC;
extern G *D_800BD06C;

void func_80080BAC(G *arg0) {
    G *temp_v0_2;

    if (arg0->f7C == 0) {
        arg0->f68 = -1;
        arg0->f7C = 1;
        arg0->f0 = 0x900;
    }
    if (225.0f < func_8002D66C(arg0, 250.0f, 0)) {
        arg0->f64 = 0;
        return;
    }
    if ((func_8002D5CC(arg0) != 0) && !(D_800BD06C->f8 < arg0->f8)) {
        temp_v0_2 = func_80023874(0x901, NULL);
        while (temp_v0_2 != NULL) {
            if (temp_v0_2->f70 == arg0->f70) {
                break;
            }
            temp_v0_2 = func_80023874(0x901, temp_v0_2);
        }
        if (temp_v0_2 == NULL) {
            func_800899DC("Can't find room startpoint!!");
        }
        D_800BD06C->f4 = temp_v0_2->f4;
        D_800BD06C->f8 = temp_v0_2->f8;
        D_800BD06C->fC = temp_v0_2->fC;
        D_800B3960->f9C = func_800340B4;
        temp_v0_2 = func_80017DEC(arg0->f70);
        if (temp_v0_2 != NULL) {
            D_800B3960->f4 = temp_v0_2->f4;
            D_800B3960->f8 = temp_v0_2->f8;
            D_800B3960->fC = temp_v0_2->fC;
            D_800B3960->f10 = temp_v0_2->f10;
            D_800B3960->f14 = temp_v0_2->f14;
            func_80033DC4(D_800B3960);
            func_800340B4(D_800B3960);
        } else {
            func_800899DC("Can't find quickcut camera #%d", arg0->f70);
        }
        D_800BD06C->f9C = func_8003930C;
        D_800BD06C->f64 = D_800B9ECC * 0x19;
        D_800BD06C->f8 = func_800385AC(D_800BD06C);
        D_800BD06C->f10 = func_8002D260(D_800B3960->f10 + 0x8000);
        func_800433A8(D_800BD06C, 2, 0x100);
        temp_v0_2 = func_800232B4(1, 0, 0, 0);
        temp_v0_2->f9C = func_80080AF0;
        temp_v0_2->f9C(temp_v0_2);
        arg0->f64 = 0x64;
    }
}
