void func_80027038();
void func_8002710C();
void func_8002713C();
void func_800271D8();
void func_8002889C();
extern s32 D_80000D40;
typedef struct { s32 pad[3]; s32 unkC; } Rec10;
extern Rec10 D_800BD288[];

void func_8001DCAC(void) {
    s32 i;
    s32 row;
    s32 col;

    func_80027038(0);
    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    for (i = 0; i < 0x40; i++) {
        row = i / 16;
        col = i % 16;
        if (D_800BD288[i].unkC != 0) {
            func_8002713C(col * 16 + 0x20, row * 13 + 0x64);
            func_800271D8(D_800BD288[i].unkC);
        } else {
            func_8002713C(col * 16 + 0x20, row * 13 + 0x64);
            func_8002889C(&D_80000D40);
        }
    }
}
