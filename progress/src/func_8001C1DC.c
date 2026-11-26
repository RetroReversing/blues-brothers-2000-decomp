s32 func_80013784(void *);
s32 func_8001B990(s32, s32);
void func_8002ADFC(s32, s32, void *);
f32 approachF32(f32, f32, f32);
f32 getCameraTargetDist(void *, f32, void *);

typedef struct {
    s32 unk0;
    char pad4[4];
    f32 unk8;
    char padC[0x38];
    f32 unk44;
    char pad48[0x28];
    s32 unk70;
    char pad74[0x1C];
    s32 unk90;
} Obj8001C1DC;

void func_8001C1DC(Obj8001C1DC *arg0) {
    s32 d;

    arg0->unk0 = 0x10E;
    if (func_8001B990(0x100, arg0->unk70) == 0) {
        arg0->unk8 = approachF32(arg0->unk44, arg0->unk8, 5.0f);
    }
    d = getCameraTargetDist(arg0, 200.0f, 0);
    if (arg0->unk90 != 0 && func_80013784(arg0) != 0 && d < 0xC8) {
        arg0->unk8 = arg0->unk44 - 240.0f;
        func_8001B990(0x200, arg0->unk70);
        func_8002ADFC(arg0->unk70 + 0x18, 0xFA0, arg0);
    }
}
