typedef struct Obj { u8 p0[8]; f32 f8; u8 p1[0x38]; f32 f44; u8 p2[0x44]; s32 f8C; } Obj;
extern s16 coss(s32);
extern s32 cameraGetMode();
extern void func_8002ADFC(s32, s32, Obj *);
extern s32 gTextWaveTime;

void func_800167C8(Obj *arg0) {
    s32 var_s1;

    if (cameraGetMode() == 3) {
        var_s1 = 0x7D0;
    } else {
        var_s1 = 0x3E8;
    }
    if ((arg0->f8 == arg0->f44) || (arg0->f8 == (arg0->f44 + (f32) ((s32) (coss(((arg0->f8C + gTextWaveTime) * 0xB4) & 0xFFFC) * 0x4B) >> 0xE)))) {
        func_8002ADFC(0x44, var_s1, arg0);
    }
    arg0->f8 = arg0->f44 + (f32) ((s32) (coss(((arg0->f8C + gTextWaveTime) * 0xB4) & 0xFFFC) * 0x4B) >> 0xE);
}
