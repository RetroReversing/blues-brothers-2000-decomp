typedef struct {
    u8 pad0[8];
    s32 unk8;
} Unk801070A0;

extern s32 D_801070A8;
extern s32 D_80107048;
extern Unk801070A0 D_801070A0;
extern s32 D_800AA1F8;
extern s32 D_800AA1FC;
extern s32 D_800AA200;
extern s32 D_800AA204;
extern char D_800007A4[];
extern char D_800007AC[];

s32 func_8002D5CC(void *arg0);
void func_80027038(s32);
void func_800226A0(s32);
void func_800270A8(s32, s32, s32);
void func_80027158(s32, s32);
void func_8002889C(char *);
void func_800271D8(s32);
void func_8002A360(s32, s32);

void func_80012CD8(void *arg0) {
    s32 held;
    s32 held2;
    s32 other;
    Unk801070A0 *pad;

    if (func_8002D5CC(arg0) != 0) {
        *(s32 *)((u8 *)arg0 + 0x64) = 15;
        if (D_801070A8 & 0x200) {
            D_800AA1F8++;
        }
        if (D_801070A8 & 0x100) {
            D_800AA1F8--;
        }
        if (D_80107048 & 0x800) {
            D_800AA1F8++;
        }
        if (D_80107048 & 0x400) {
            D_800AA1F8--;
        }
        if (D_801070A8 & 2) {
            D_800AA1FC++;
        }
        if (D_801070A8 & 1) {
            D_800AA1FC--;
        }
    }
    if (D_800AA1F8 < 0) {
        D_800AA1F8 = 219;
    }
    if (D_800AA1F8 >= 220) {
        D_800AA1F8 = 0;
    }
    if (D_800AA1FC < 0) {
        D_800AA1FC = 10;
    }
    if (D_800AA1FC >= 11) {
        D_800AA1FC = 0;
    }
    func_80027038(0);
    func_800226A0(0);
    func_800270A8(0x60, 0x60, 0xFF);
    func_80027158(30, 90);
    func_8002889C(D_800007A4);
    func_80027158(120, 90);
    func_800271D8(D_800AA1F8);
    func_80027158(30, 110);
    func_8002889C(D_800007AC);
    func_80027158(120, 110);
    func_800271D8(D_800AA1FC);
    pad = &D_801070A0;
    if (pad->unk8 & 0x8000) {
        func_8002A360(9, D_800AA1F8);
    }
    if (pad->unk8 & 0x4000) {
        func_8002A360(3, D_800AA1FC);
    }
    if (pad->unk8 & 8) {
        func_8002A360(4, 0);
    }
    if (pad->unk8 & 4) {
        func_8002A360(10, 0);
    }
    if (pad->unk8 & 0x20) {
        if (D_800AA200 == 0) {
            func_8002A360(0x1C, 0);
            D_800AA200 = 1;
        } else if (D_800AA200 == 1) {
            func_8002A360(0x1D, 0);
            func_8002A360(0x1C, 1);
            D_800AA200 = 2;
        } else if (D_800AA200 == 2) {
            func_8002A360(0x1D, 0);
            D_800AA200 = 0;
        }
    }
    if (D_801070A8 & 0x10) {
        if (D_800AA204 == 0) {
            func_8002A360(0x1E, 0);
            D_800AA204 = 1;
        } else {
            func_8002A360(0x1F, 0);
            D_800AA204 = 0;
        }
    }
}
