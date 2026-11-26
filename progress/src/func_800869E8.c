typedef struct Obj {
    s32 f0;
    f32 f4;
    u8 pad8[8];
    s32 f10;
    u8 pad14[0x60];
    s32 f74;
    u8 pad78[0x24];
    void *f9C;
} Obj;
typedef struct Rec {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s8 f10, f11, f12, f13, f14, f15;
} Rec;
void func_80023DBC(s32);
void func_80026C04(void *, s32, s32);
f32 func_8002D340(f32, f32, f32);
void func_800433A8(Obj *, s32, s32);
s32 func_80082400(void);
extern s32 D_800B9000[];
extern s32 D_800B9ECC;
extern s32 D_80171980;
extern Obj *D_801719A8;
extern Obj *D_801719AC;
extern Rec D_801719E0;
extern Obj *D_80171A30;
extern s32 D_80171A34;
extern s32 D_80171A50;
void func_8008662C(void);

void func_800869E8(Obj *o) {
    s32 idx;
    s32 t;
    s32 buf[8];

    idx = func_80082400();
    func_80023DBC(0xE33);
    D_80171A30->f4 = func_8002D340(20.0f, D_80171A30->f4, 4.0f);
    D_80171980 += D_800B9ECC;
    if (o->f74 + 0x120 < D_80171980) {
        D_80171980 = 0;
        func_800433A8(D_801719A8, 0x16B, 0x100);
        D_801719A8->f10 = 0x8000;
        func_800433A8(D_801719AC, 0x18B, 0x100);
        D_80171A50 = 0;
        D_80171A34 = 0;
        D_801719AC->f10 = 0x4000;
        o->f9C = func_8008662C;
        func_80026C04(&D_801719E0, 0, 0x50);
        D_801719E0.f0 = idx;
        t = D_800B9000[idx * 3];
        D_801719E0.f10 = 0;
        D_801719E0.f11 = 0;
        D_801719E0.f12 = 0;
        D_801719E0.f13 = 0;
        D_801719E0.f14 = 0;
        D_801719E0.f15 = 0;
        D_801719E0.f8 = t;
    }
}
