typedef struct ObjZ ObjZ;
struct ObjZ {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    u8 pad14[0x34 - 0x14];
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 pad40[0x44 - 0x40];
    f32 f44;
    u8 pad48[0x6C - 0x48];
    s32 f6C;
    u8 pad70[0x84 - 0x70];
    s32 f84;
    u8 pad88[0xA0 - 0x88];
    void (*fA0)(ObjZ *);
};

void func_8003CBA8(void);
s16 func_80095F60(u16);
s16 func_800944B0(u16);
typedef struct { s32 count; } Cnt;
extern Cnt D_800BD0E0;
extern ObjZ *gCameraTarget;

void func_80014C34(ObjZ *arg0) {
    s32 r;

    if (arg0->f6C == 0) {
        arg0->f6C = 1;
        D_800BD0E0.count++;
        func_8003CBA8();
    }
    arg0->y = arg0->f44 + 300.0f + (f32)((func_80095F60(arg0->f84) * 75) >> 13);
    r = (func_80095F60(arg0->f84) * 25) >> 11;
    arg0->x = gCameraTarget->x + (f32)((r * func_800944B0(arg0->f10)) >> 15);
    {
        s32 t = r * func_80095F60(arg0->f10);
        arg0->z = gCameraTarget->z + (f32)(t >> 15);
        arg0->f10 += 0x2000;
        arg0->f84 += 0x400;
    }
    arg0->f34 = (0x8000 - arg0->f84) / 128;
    arg0->f38 = (0x8000 - arg0->f84) / 128;
    arg0->f3C = (0x8000 - arg0->f84) / 128;
    if (arg0->f84 > 0x7FFF) {
        arg0->fA0(arg0);
    }
}
