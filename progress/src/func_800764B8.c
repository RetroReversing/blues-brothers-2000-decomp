s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002ADFC(s32, s32, void *);
s32 func_8002D260(s32);
void actorSetAnim(void *, s32, s32);
s32 func_80076080(void *);
void debugPrintf(char *);
void func_80076464();
typedef struct Obj Obj;
struct Obj *func_80042F00(s32, s32, s32, s32);
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ u8 pad1C[0x34];
    /* 0x50 */ f32 f50;
    /* 0x54 */ u8 pad54[4];
    /* 0x58 */ s32 f58;
    /* 0x5C */ u8 pad5C[8];
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 f68;
    /* 0x6C */ s32 f6C;
    /* 0x70 */ u8 pad70[0xC];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[0x1C];
    /* 0x9C */ void (*f9C)(Obj *);
    /* 0xA0 */ u8 padA0[4];
    /* 0xA4 */ Obj *fA4;
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0xC];
    /* 0xB8 */ s32 fB8;
};
typedef struct { s32 a; s32 h; s32 c; } Rec;
extern char D_80009258[];
extern s32 D_800B7B0C;
extern Obj *gCameraTarget;
extern Rec D_800F4A00[];
extern s32 D_800F7910[];
extern s32 D_80140240;
extern f32 D_801700D0;

void func_800764B8(Obj *arg0) {
    Obj *s;
    f32 dy;
    f32 lim;
    f32 tv;

    s = 0;
    if (arg0->f7C == 0) {
        arg0->f0 = 0x102;
        arg0->f7C = 1;
        arg0->f64 = 0;
    }
    if (func_80076080(arg0) != 0) {
        return;
    }
    lim = D_801700D0;
    dy = gCameraTarget->y - arg0->y;
    tv = D_800F7910[arg0->fB8];
    if (lim < tv && dy < (f32)(D_800F4A00[arg0->fB8].h + 50) && 5.0f < dy) {
        arg0->f64 = 70;
        gCameraTarget->f50 = D_80140240 * 2.12;
        gCameraTarget->y = arg0->y + (f32)D_800F4A00[arg0->fB8].h + 52.0f;
        actorSetAnim(gCameraTarget, 5, 0x100);
        gCameraTarget->f9C(gCameraTarget);
        if (arg0->fA8 == 0) {
            switch (arg0->f6C) {
            case 0:
                s = func_80042F00(0x47, arg0->x, arg0->y, arg0->z);
                if (s != 0) {
                    actorSetAnim(s, 0x14A, 0x100);
                }
                break;
            case 1:
                s = func_80042F00(0x48, arg0->x, arg0->y, arg0->z);
                if (s != 0) {
                    actorSetAnim(s, 0x14B, 0x100);
                }
                break;
            }
            if (s == 0) {
                debugPrintf(D_80009258);
            }
            s->f9C = func_80076464;
            s->fA4 = arg0;
            s->f10 = func_8002D260(arg0->f10 + 0x8000);
            s->f14 = arg0->f14;
            s->f18 = arg0->f18;
            s->f58 = packDrawFlags(0, 1, 0, 3, D_800B7B0C, 0, 1, 0);
            arg0->fA8 = s;
            arg0->f68 = -1;
            func_8002ADFC(0x7F, 4000, arg0);
        }
    }
}
