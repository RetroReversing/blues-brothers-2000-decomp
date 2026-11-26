typedef struct Obj {
    s32 type; f32 x; u8 p0[8]; s32 f10; u8 p1[0x2C]; f32 x40; u8 p2[0x28]; s32 f6C; u8 p3[0x10]; s32 f80;
} Obj;
extern s16 coss(s32);
extern void func_8002ADFC(s32, s32, Obj *);
extern f32 func_8002DD60(f32);
extern void animStepKeys(Obj *);
extern s32 func_8006DA0C(void);
extern s32 gTextWaveTime;

void func_8006DC44(Obj *arg0) {
    if (func_8006DA0C() == 0) {
        arg0->f10 = 0;
        animStepKeys(arg0);
        if (arg0->f6C & 1) {
            arg0->x = arg0->x40 + (f32) ((s32) (coss((gTextWaveTime * 0xFA) & 0xFFFE) * 0x7D) >> 0xD);
        }
        if (arg0->type == 0x1008) {
            if (495.0 < (f64) func_8002DD60(arg0->x - arg0->x40)) {
                if (arg0->f80 == 0) {
                    func_8002ADFC(0x38, 0x708, arg0);
                    arg0->f80 = 1;
                }
            } else {
                arg0->f80 = 0;
                return;
            }
        }
    }
}
