void *func_800232B4(s32, s32, s32, s32);
s32 randomRange(s32, s32);
extern s32 func_8002AFC0;
extern s32 func_8002AFFC;

typedef struct {
    char pad[0x70];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    char pad84[0x18];
    void *unk9C;
    void *unkA0;
} Obj8002B240;

void *func_8002B240(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Obj8002B240 *o;

    arg4 = arg4 * 5 / 4;
    o = func_800232B4(0x118, arg0, arg1, arg2);
o->unk70 = arg5;
o->unk74 = arg3;
o->unk78 = arg4;
o->unk7C = 0;
o->unk80 = 0;
    o->unk9C = &func_8002AFFC;
    o->unkA0 = &func_8002AFC0;
    if (arg3 == 0xBA) {
        if (o->unk70 < 0xC8) {
            o->unk70 = randomRange(-0x1E, 0x1E) + 0xC8;
        }
    }
    return o;
}
