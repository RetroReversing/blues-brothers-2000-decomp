void func_8002E46C(void);
void func_8008914C(s32);
void func_800896D0(void);
void func_80089814(s32);
s32 func_8008990C(u64 *);
void func_80089C00(void);
void func_80089C08(void);
extern s32 D_800B9E8C;
extern s32 D_800B9E90;
extern s32 D_800B9EA0;
extern s32 D_800B9EA4;
extern f32 D_800B9EC4;
extern s32 D_800B9EC8;
extern s32 D_800B9ECC;
extern u64 D_801771E0;
extern s32 D_80178238;
extern s32 D_80178270;
extern u64 D_80178280;

void func_80088F60(void) {
    s32 t;

    func_800896D0();
    func_8008914C(0);
    func_80089814(D_80178238);
    func_80089C00();
    D_80178280 = D_801771E0;
    t = func_8008990C(&D_801771E0);
    D_800B9E90 = t;
    D_800B9EC4 = (f32)t / 1000.0;
    if (D_800B9EC4 < 0.01) {
        D_800B9EC4 = 0.01f;
    }
    if (0.2 < D_800B9EC4) {
        D_800B9EC4 = 0.2f;
    }
    if (t <= 0) {
        D_800B9E90 = 1;
    }
    D_800B9EC8 = D_800B9E90;
    D_80178270 = (s32)(f32)(1000.0 / (f32)D_800B9E90) + 0.5;
    if (D_800B9E90 > 1000) {
        D_800B9EC8 = 1000;
    }
    D_800B9ECC = (D_800B9EC8 + 8) >> 4;
    if (D_800B9ECC <= 0) {
        D_800B9ECC = 1;
    }
    D_800B9E8C++;
    func_80089C08();
    D_800B9EA0 = D_800B9E90 / 10;
    if (D_800B9EA0 > 10) {
        D_800B9EA0 = 10;
    }
    D_800B9EA4 += D_800B9EA0;
    func_8002E46C();
}
