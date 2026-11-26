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
f32 approachF32(f32, f32, f32);
void actorSetAnim(Obj *, s32, s32);
s32 func_80082400(void);
extern s32 gComboDefs[];
extern s32 gCamSpeedScale;
extern s32 gComboBeat;
extern Obj *D_801719A8;
extern Obj *D_801719AC;
extern Rec gComboSlots;
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
    D_80171A30->f4 = approachF32(20.0f, D_80171A30->f4, 4.0f);
    gComboBeat += gCamSpeedScale;
    if (o->f74 + 0x120 < gComboBeat) {
        gComboBeat = 0;
        actorSetAnim(D_801719A8, 0x16B, 0x100);
        D_801719A8->f10 = 0x8000;
        actorSetAnim(D_801719AC, 0x18B, 0x100);
        D_80171A50 = 0;
        D_80171A34 = 0;
        D_801719AC->f10 = 0x4000;
        o->f9C = func_8008662C;
        func_80026C04(&gComboSlots, 0, 0x50);
        gComboSlots.f0 = idx;
        t = gComboDefs[idx * 3];
        gComboSlots.f10 = 0;
        gComboSlots.f11 = 0;
        gComboSlots.f12 = 0;
        gComboSlots.f13 = 0;
        gComboSlots.f14 = 0;
        gComboSlots.f15 = 0;
        gComboSlots.f8 = t;
    }
}
