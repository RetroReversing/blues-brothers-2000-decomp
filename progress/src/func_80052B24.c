#define FLD(e, T, off) (*(T *)((u8 *)(e) + (off)))
void *func_80023874(s32, s32);
s32 func_80082400(void);
void func_80027030(s32, s32);
void func_8000C5E4(void);
u8 *func_80023E18(s32);
void func_800899DC(char *, ...);
void func_800242A8(s32, s32, s32);
void *func_800232B4(s32, s32, s32, s32);
void func_80053EF0(u8 *);
s32 func_80026B50(char *, char *);
void func_80043328(u8 *, s32, s32);
void func_80053C94(void);
void func_80053CE0(void);
void func_80052EC0(void);
void func_8004303C(void);
extern char D_800080F0[];
extern char D_8000811C[];
extern u8 *D_800BD06C;
extern u8 *D_800B3960;
extern s32 D_800AE010;
extern s32 D_8014AA90;
extern f32 *D_8014AA94;
extern s32 D_8014AA98;
extern s32 D_8014AA9C;
extern s32 D_8014AAA0;
extern s32 D_800B5DD4;
extern s32 D_801070A0;
extern s32 D_80107040;
extern s32 D_80140228;

s32 func_80052B24(s32 arg0, char *arg1, f32 *arg2) {
    s32 found = 0;
    u8 *obj;
    u8 *lvl;
    u8 *rec;
    s32 i;
    s32 *q;
    u8 *p;
    s32 old;
    u8 *pl;

    if (func_80023874(0x800, 0) != 0) {
        return 0;
    }
    p = D_800BD06C;
    i = 0;
    if (FLD(p, s32, 0) == 3) {
        if (FLD(p, f32, 0x50) <= 0.0f) {
            i = FLD(p, s32, 0x90) == 1;
        }
    }
    if (!i) {
        if (func_80082400() == -1) {
            return 0;
        }
    }
    D_8014AA90 = D_800AE010;
    D_8014AA9C = 0;
    D_8014AA94 = 0;
    D_800B5DD4 = 0;
    D_801070A0 = 0;
    D_80107040 = 0;
    D_800AE010 = 0x12345678;
    func_80027030(2, D_8014AA90);
    D_80140228 = 0;
    do { func_8000C5E4(); pl = D_800B3960; FLD(pl, s32, 0xC0) = 2; lvl = func_80023E18(arg0); } while (0);
    if (lvl == NULL) {
        func_800899DC(D_800080F0);
    }
    func_800242A8(0x88, 0x560, 0);
    if (D_8014AAA0 != 0) {
        func_800242A8(0x89, D_8014AAA0, 0);
    }
    if (func_80023874(0x801, 0) == NULL) {
        FLD(func_800232B4(0x801, 0, 0, 0), void *, 0x9C) = func_80053C94;
    }
    if (func_80023874(0x802, 0) == NULL) {
        FLD(func_800232B4(0x802, 0, 0, 0), void *, 0x9C) = func_80053CE0;
    }
    obj = func_80023874(0x803, 0);
    if (obj == NULL) {
        FLD(func_800232B4(0x803, 0, 0, 0), void *, 0x9C) = func_80053CE0;
    } else {
        FLD(obj, s32, 0x7C) = 0;
    }
    func_80053EF0(lvl);
    rec = FLD(lvl, u8 *, 8);
    if (arg1 != NULL) {
        {
            for (i = 0; i < FLD(lvl, s16, 4); i++, rec += 12) {
                if (func_80026B50(arg1, FLD(rec, char *, 0)) == 0) {
                    found = 1;
                    obj = func_800232B4(0x800, 0, 0, 0);
                    if (arg2 != NULL) {
                        FLD(obj, f32, 4) = arg2[1];
                        FLD(obj, f32, 8) = arg2[2];
                        D_8014AA94 = arg2;
                        FLD(obj, f32, 0xC) = arg2[3];
                        FLD(obj, f32 *, 0xA4) = arg2;
                    }
                    pl = D_800B3960;
                    FLD(pl, s32, 0xD8) = FLD(pl, s32, 0x9C);
                    p = D_800BD06C;
                    FLD(obj, u8 *, 0x70) = lvl;
                    FLD(obj, u8 *, 0x74) = rec;
                    FLD(obj, void *, 0x9C) = func_80052EC0;
                    FLD(obj, s32, 0x64) = 0xC8;
                    FLD(obj, s32, 0xD8) = 0;
                    old = FLD(p, s32, 0x9C);
                    FLD(p, void *, 0x9C) = func_8004303C;
                    FLD(p, s32, 0x4C) = 0;
                    FLD(p, s32, 0x50) = 0;
                    FLD(p, s32, 0x54) = 0;
                    FLD(p, s32, 0xD8) = old;
                    func_80043328(p, 1, 0x100);
                    break;
                }
            }
        }
    }
    if (found == 0) {
        func_800899DC(D_8000811C, arg1);
    }
    q = FLD(rec, s32 *, 4);
    while (q[0] != -1) {
        if (q[0] == 0) {
            D_8014AA98 = 0;
            break;
        }
        if (q[0] == 1) {
            D_8014AA98 = 1;
            break;
        }
        q += 2;
    }
    D_800AE010 = D_8014AA90;
    return 1;
}

