void func_80031B54(void *, s32);
void func_800262FC(s32);
void func_80030C40(void *, s32);
void func_80033A74(void);
extern s32 D_801070A0;

void func_80033344(void *arg0) {
    *(void **)((s8 *)arg0 + 0x98) = func_80033A74;
    func_80031B54(arg0, 2);
    if (D_801070A0 & 0x9000) {
        switch (*(s32 *)((s8 *)arg0 + 0x78)) {
        case 0:
            func_80030C40(arg0, -5);
            break;
        case 1:
            func_800262FC(0);
            func_80030C40(arg0, 3);
            break;
        }
        *(s32 *)((s8 *)arg0 + 0x78) = 0;
    }
}
