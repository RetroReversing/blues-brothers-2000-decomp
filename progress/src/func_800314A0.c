void func_80023C58(s32);
void func_80023C64(s32);
void func_8002710C(s32, s32, s32, s32);
void func_8002A360(s32, s32);
s32 func_8002D298(s32, s32, s32);
s32 func_8002D5CC(void *);
void func_80030C40(void *, s32);
extern s32 D_800AE010;
extern s32 D_801070A0;
void func_80023078(void *);
void func_80031934(void *);

typedef struct {
    u8 pad0[0x64];
    s32 unk64;
    u8 pad68[4];
    s32 unk6C;
    u8 pad70[0xC];
    s32 unk7C;
    u8 pad80[0x10];
    s32 unk90;
    s32 unk94;
    void *unk98;
} Obj;

void func_800314A0(Obj *arg0) {
    u64 scratch[4];

    if (arg0->unk7C != 0) {
        arg0->unk94 = 1;
        arg0->unk7C = 0;
        arg0->unk6C = 0;
        arg0->unk98 = func_80031934;
        arg0->unk90 = D_800AE010;
        func_80023C58(0xB9458F);
        D_801070A0 = 0;
        arg0->unk64 = 0x2BC;
    }
    if (arg0->unk94 != 0) {
        arg0->unk6C = func_8002D298(0xFF, arg0->unk6C, 5);
    } else {
        arg0->unk6C = func_8002D298(0, arg0->unk6C, 5);
    }
    if (arg0->unk94 != 0) {
        if (func_8002D5CC(arg0) != 0 || (arg0->unk64 < 0x1F4 && (D_801070A0 & 0x9000))) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9F);
            arg0->unk94 = 0;
        }
        if (arg0->unk94 != 0) {
            return;
        }
    }
    if (arg0->unk6C == 0) {
        arg0->unk98 = (void *)((s8 *)&func_80023078 + 8);
        func_80030C40(arg0, 1);
        func_80023C58(arg0->unk90);
        func_80023C64(0xB9458F);
        func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    }
}
