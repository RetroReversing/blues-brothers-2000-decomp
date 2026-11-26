typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Rec16;
typedef struct {
    u8 pad[0x18];
    s32 f18;
    s32 f1C;
} Rec32;
typedef struct {
    u8 pad[0x1C];
    s32 f1C;
    s32 f20;
    s32 f24;
} State;
s32 func_8000C43C(void);
s32 func_800252D8(void);
s32 func_80025644(void);
void func_8008A074(void *, s32);
extern Rec32 D_800AA134[];
extern State D_800BD0E0;
extern s32 D_800BD100;
extern Rec16 D_800BD288[];
extern s32 D_80178270;

s32 func_8000C4A0(void) {
    D_800BD288[func_8000C43C()].a = D_80178270;
    D_800BD288[func_8000C43C()].b = func_800252D8();
    D_800BD288[func_8000C43C()].c = func_80025644();
    D_800BD288[func_8000C43C()].d++;
    func_8008A074(D_800BD288, 0x400);
    D_800BD0E0.f24 = D_800BD0E0.f1C;
    D_800BD0E0.f1C++;
    if (D_800BD0E0.f1C >= D_800AA134[D_800BD0E0.f20].f18) {
        D_800BD0E0.f20++;
        D_800BD0E0.f1C = 0;
        if (D_800BD0E0.f20 >= 4) {
            D_800BD0E0.f20 = 0;
        }
    }
    return D_800BD100;
}
