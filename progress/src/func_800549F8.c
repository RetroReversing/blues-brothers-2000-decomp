typedef struct ObjS {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    u8 pad14[0x44 - 0x14];
    f32 f44;
    u8 pad48[0x50 - 0x48];
    f32 f50;
    u8 pad54[0x5C - 0x54];
    s32 f5C;
    u8 pad60[0x7C - 0x60];
    s32 f7C;
    u8 pad80[0x84 - 0x80];
    s32 f84;
} ObjS;

void func_80043328(ObjS *, s32, s32);
s32 func_8002D858(ObjS *, s32 *);
s32 func_8002D204(s32, s32, s32);
s32 func_8002D298(s32, s32, s32);
void func_8004303C(ObjS *);
f32 func_8002D340(f32, f32, f32);
void func_8002DA80(ObjS *);
void func_8003BF98(ObjS *);
void func_80058F74(ObjS *, void *);
void func_80054E24(void);
void func_800548C0(void);
extern s32 D_800B9ECC;
extern f32 D_800B9EC4;
extern ObjS *D_800BD06C;

void func_800549F8(ObjS *arg0) {
    s32 ang;
    f32 dist;
    f32 dy;

    if (arg0->f7C != 0) {
        func_80043328(arg0, 0x46, 0x100);
        arg0->f7C = 0;
        arg0->f84 = 0;
        arg0->f50 = 2500.0f;
        return;
    }
    dist = func_8002D858(arg0, &ang);
    arg0->f10 = func_8002D204(ang, arg0->f10, D_800B9ECC << 8);
    arg0->f5C = func_8002D298(0x80, arg0->f5C, D_800B9ECC * 2);
    func_8004303C(arg0);
    arg0->x = func_8002D340(D_800BD06C->x, arg0->x, D_800B9EC4 * 1000.0f);
    arg0->z = func_8002D340(D_800BD06C->z, arg0->z, D_800B9EC4 * 1000.0f);
    arg0->f50 -= D_800B9EC4 * 4000.0;
    func_8002DA80(arg0);
    dy = arg0->y - D_800BD06C->y;
    if (dist < 300.0f && dy < 250.0f && -100.0f < dy) {
        func_8003BF98(D_800BD06C);
        arg0->f5C = 0xFF;
        arg0->f84 = 1;
    }
    if (arg0->y < arg0->f44) {
        arg0->y = arg0->f44;
        if (arg0->f84 != 0) {
            func_80058F74(arg0, func_80054E24);
        } else {
            func_80058F74(arg0, func_800548C0);
        }
    }
}
