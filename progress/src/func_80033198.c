typedef struct O33198 {
    u8 pad0[0x78];
    s32 f78;
    u8 pad7C[0x98 - 0x7C];
    void (*f98)(void);
} O33198;
void func_800262FC(s32);
void func_80030C40(O33198 *, s32);
void func_80031B54(O33198 *, s32);
extern s32 gPadPressed;
void func_80033818(void);

void func_80033198(O33198 *arg0) {
    arg0->f98 = func_80033818;
    func_80031B54(arg0, 3);
    if (gPadPressed & 0x9000) {
        switch (arg0->f78) {
        case 0:
            func_80030C40(arg0, -2);
            break;
        case 1:
            func_80030C40(arg0, 1);
            break;
        case 2:
            func_800262FC(0);
            func_80030C40(arg0, 6);
            break;
        }
        arg0->f78 = 0;
    }
}
