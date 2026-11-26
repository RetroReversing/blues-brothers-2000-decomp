s32 func_8002ADFC(s32, s32, void *);
extern f64 D_80009400;
extern f64 D_80009408;
extern f64 D_80009410;
extern f64 D_80009418;
extern f64 D_80009420;
extern f64 D_80009428;
extern f64 D_80009430;
extern f64 D_80009438;

void func_8007A2E8(void *arg0) {
    s32 var_v1;
    f32 *temp_v0;

    var_v1 = 0;
    temp_v0 = (f32 *)((s8 *)*(void **)((s8 *)arg0 + 0xA8) + 0xDC);
    if (D_80009400 <= *temp_v0 && *temp_v0 <= D_80009408) {
        var_v1 = 1;
    }
    if (D_80009410 <= *temp_v0 && *temp_v0 <= D_80009418) {
        var_v1 += 1;
    }
    if (D_80009420 <= *temp_v0 && *temp_v0 <= D_80009428) {
        var_v1 += 1;
    }
    if (D_80009430 <= *temp_v0 && *temp_v0 <= D_80009438) {
        var_v1 += 1;
    }
    if (var_v1 != 0) {
        func_8002ADFC(0xC0, 0x2BC, *(void **)((s8 *)arg0 + 0xA8));
    }
}

