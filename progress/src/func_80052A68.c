void *func_80023E18();
s32 func_80026CB4();
s32 func_80053EF0();
s32 func_800899DC();
extern char D_800080F0[];
extern char D_80008104[];
s16 func_80052A68(s32 arg0, s32 arg1)
{
    s32 var_s0;
    void *temp_v0;
    void *var_s1;

    temp_v0 = func_80023E18(arg0);
    if (temp_v0 == NULL) {
        func_800899DC(D_800080F0);
        return 0;
    }
    func_80053EF0(temp_v0);
    var_s1 = *((void **) (((char *) temp_v0) + 8));
    if (arg1 != 0) {
        var_s0 = 0;
        if (*((s16 *) (((char *) temp_v0) + 4)) > 0) {
            do {
                if (func_80026CB4(*((s32 *) (((char *) var_s1) + 0)), arg1) == 0) {
                    return *((s16 *) (((char *) var_s1) + 0xA));
                }
                do { var_s0 += 1; } while (0);
                var_s1 += 0xC;
            } while (var_s0 < *((s16 *) (((char *) temp_v0) + 4)));
        }
        func_800899DC(D_80008104, arg1);
    }
    return 0;
}
