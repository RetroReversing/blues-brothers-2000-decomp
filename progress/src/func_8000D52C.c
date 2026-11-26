void func_80012110(void *);
s32 randomRange(s32, s32);
s32 tickActorTimer(void *);
void syncActorPrevPos(void *);
void func_8000D4C4(void *);

typedef struct {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    char pad10[0x30];
    f32 unk40;
    f32 unk44;
    f32 unk48;
    char pad4C[0x18];
    s32 unk64;
    char pad68[0x14];
    s32 unk7C;
    char pad80[0x1C];
    void *unk9C;
} Obj8000D52C;

void func_8000D52C(Obj8000D52C *arg0) {
    s32 i;

    if (arg0->unk7C == 0) {
        syncActorPrevPos(arg0);
        arg0->unk7C = 1;
    }
    arg0->unk4 = arg0->unk40 + randomRange(-0x14, 0x14);
    arg0->unkC = arg0->unk48 + randomRange(-0x14, 0x14);
    if (tickActorTimer(arg0) != 0) {
        arg0->unk64 = 0x64;
        arg0->unk9C = func_8000D4C4;
        arg0->unk4 = arg0->unk40;
        arg0->unkC = arg0->unk48;
        arg0->unk8 = arg0->unk44 + 600.0f;
        for (i = 0; i < randomRange(2, 7); i++) {
            func_80012110(arg0);
        }
    }
}
