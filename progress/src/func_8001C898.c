s32 func_8001B990(s32, s32);
void func_8002A360(s32, s32);
f32 approachF32(f32, f32, f32);
f32 func_8002DD60(f32);
extern void *gCameraTarget;

typedef struct {
    s32 unk0;
    char pad4[4];
    f32 unk8;
    f32 unkC;
    char pad10[0x34];
    f32 unk44;
    char pad48[0x34];
    s32 unk7C;
} Obj8001C898;

void func_8001C898(Obj8001C898 *arg0) {
    f32 y;

    if (func_8001B990(0x100, 4) != 0 && func_8002DD60(arg0->unkC - ((Obj8001C898 *)gCameraTarget)->unkC) < 280.0f) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x72);
        arg0->unk7C = 1;
    }
    if (arg0->unk7C != 0) {
        y = approachF32(arg0->unk44 + 350.0f, arg0->unk8, 5.0f);
        arg0->unk8 = y;
        if (arg0->unk44 + 175.0f < y) {
            arg0->unk0 = 0x101;
        }
    }
}
