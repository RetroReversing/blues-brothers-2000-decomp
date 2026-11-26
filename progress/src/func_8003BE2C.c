void func_80027038(s32);
void func_8002710C(s32, s32, s32, s32);
void func_80027158(s32, s32);
void func_8003BD74(s32, f32, f32, f32);
extern f32 D_800B9EC4;
extern s32 D_80140244;
typedef struct { char pad[0x40]; f32 x40; f32 x44; f32 x48; } S;
void func_8003BE2C(S *arg0) {
    func_80027038(0);
    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    func_80027158(0xA0, 0x64);
    func_8003BD74(D_80140244, 160.0f, 120.0f, arg0->x40);
 { f32 t; f32 v; f32 d; d = arg0->x44; t = (arg0->x40 - 1.0) * -132.0;
  v = d + D_800B9EC4 * (t - d * 4.0); arg0->x48 = t; arg0->x44 = v; arg0->x40 = arg0->x40 + D_800B9EC4 * v; } }
