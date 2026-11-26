s16 func_80095F60(u16);
void func_80011734(void *);
extern s32 D_800B9EA4;

typedef struct {
    u8 pad0[0x68];
    s32 unk68;
    u8 pad6C[0x10];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x1C];
    void (*unkA0)();
} Obj;

void func_80011CA4(Obj *arg0) {
    s16 s;

    if (arg0->unk80 >= 0x3B7) {
        arg0->unkA0();
    }
    s = func_80095F60(arg0->unk80 * D_800B9EA4);
    arg0->unk80 += 5;
    if ((s >> 9) > 0) {
        arg0->unk68 = arg0->unk7C;
    } else {
        arg0->unk68 = -1;
    }
    func_80011734(arg0);
}
