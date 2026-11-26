void func_8002A360(s32, s32);
f32 approachF32(f32, f32, f32);
f32 func_8002DD60(f32);
void debugPrintf(char *);
void func_80023078(void);
void func_80064F08(void);

typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    char pad10[0x70 - 0x10];
    s32 x70;
    s32 x74;
    char pad78[0x7C - 0x78];
    s32 x7C;
    char pad80[0x88 - 0x80];
    s32 x88;
    s32 x8C;
    s32 x90;
    char pad94[0x9C - 0x94];
    void *x9C;
    char padA0[0xA8 - 0xA0];
    struct Obj *xA8;
    char padAC[0xB8 - 0xAC];
    s32 xB8;
    char padBC[0xC0 - 0xBC];
    s32 xC0;
} Obj;

typedef struct Rec {
    s32 x0;
    s32 x4;
    s32 x8;
} Rec;

extern char D_80008C30[];
extern f32 D_80008C48;
extern u8 D_800B3964[];
extern u8 D_800B5DD4[];
extern Rec gPlatformMaxOffsets[];
extern u8 D_80140214[];

void func_80065260(Obj *arg0) {
    f32 a;
    f32 tgt;
    f32 v;
    f32 d;
    f32 lim;
    Obj *p;

    if (arg0->x7C == 0) {
        a = func_8002DD60(arg0->x8 - (f32)arg0->x8C);
        if (func_8002DD60(arg0->x8 - (f32)arg0->x90) < a) {
            arg0->x88 = -1;
        } else {
            arg0->x88 = 1;
        }
        arg0->x7C = 1;
        arg0->xC0 = 1;
        func_8002A360(0x18, 0);
    }
    if (arg0->x88 == 0) {
        debugPrintf(D_80008C30);
    }
    if (arg0->x88 > 0) {
        tgt = arg0->x90;
    } else {
        tgt = arg0->x8C;
    }
    p = arg0->xA8;
    v = approachF32(tgt, arg0->x8, 10.0f);
    arg0->x8 = v;
    tgt = func_8002DD60(v - tgt);
    if (p != 0) {
        lim = D_80008C48;
        p->x8 = arg0->x8 + (f32)gPlatformMaxOffsets[arg0->xB8].x4;
        p->x4 = approachF32(arg0->x4, p->x4, lim);
        p->xC = approachF32(arg0->xC, p->xC, lim);
    }
    if (tgt == 0.0f) {
        arg0->xC0 = 2;
        arg0->xA8 = 0;
        arg0->x74 = 0;
        *(s32 *)D_800B5DD4 = 1;
        *(s32 *)D_80140214 = 1;
        if (arg0->x70 != 0) {
            arg0->x9C = (u8 *)func_80023078 + 8;
            (*(Obj **)D_800B3964)->xC0 = 2;
            return;
        }
        arg0->x9C = func_80064F08;
    }
}
