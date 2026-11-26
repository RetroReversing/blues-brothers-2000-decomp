void *func_800232B4();
s32 func_80023874();
void *func_80023E18();
s32 func_80026CB4();
void func_80053EF0();
void func_800899DC();
extern char D_800080F0[];
extern char D_8000811C[];
extern s32 D_80107040;
extern s32 D_801070A0;
extern s32 D_80140228;
extern s32 D_8014AA94;
extern s32 D_8014AA9C;
extern s32 func_800541C0;

void func_80054324(s32 arg0, s32 arg1)
{
    s32 *var_s1;
    s32 var_s0;
    s32 var_s3;
    void *temp_v0;
    void *temp_v0_2;

    var_s3 = 0;
    if (func_80023874(0x800, 0) == 0) {
        D_8014AA9C = 0;
        D_8014AA94 = 0;
        D_80140228 = 0;
        D_801070A0 = 0;
        D_80107040 = 0;
        temp_v0 = func_80023E18(arg0);
        if (temp_v0 == NULL) {
            func_800899DC(D_800080F0);
        }
        func_80053EF0(temp_v0);
        var_s1 = *((s32 **) ((char *) temp_v0 + 8));
        if (arg1 != 0) {
            if (var_s3 < *((s16 *) ((char *) temp_v0 + 4))) {
                var_s0 = 0;
                do {
                    if (func_80026CB4(*var_s1, arg1) == 0) {
                        var_s3 = 1;
                        temp_v0_2 = func_800232B4(0x800, 0, 0, 0);
                        *((void **) ((char *) temp_v0_2 + 0x70)) = temp_v0;
                        *((s32 **) ((char *) temp_v0_2 + 0x74)) = var_s1;
                        *((s32 *) ((char *) temp_v0_2 + 0x9C)) = (s32) &func_800541C0;
                        *((s32 *) ((char *) temp_v0_2 + 0x64)) = 0xC8;
                        *((s32 *) ((char *) temp_v0_2 + 0xD8)) = 0;
                        break;
                    }
                    do { var_s1 += 3; } while (0);
                    var_s0 += 1;
                } while (var_s0 < *((s16 *) ((char *) temp_v0 + 4)));
            }
        }
        if (var_s3 == 0) {
            func_800899DC(D_8000811C, arg1);
        }
    }
}
