typedef struct {
    s32 unk0;
    u8 pad4[0x8 - 0x4];
    f32 unk8;
    u8 padC[0x10 - 0xC];
    s32 unk10;
    u8 pad14[0x50 - 0x14];
    f32 unk50;
    u8 pad54[0x6C - 0x54];
    s32 unk6C;
    u8 pad70[0x84 - 0x70];
    s32 unk84;
    u8 pad88[0x90 - 0x88];
    s32 unk90;
    s32 unk94;
    u8 pad98[0x9C - 0x98];
    void *unk9C;
    u8 padA0[0xB0 - 0xA0];
    s32 unkB0;
    u8 padB4[0xB8 - 0xB4];
    s32 unkB8;
    s32 unkBC;
    u8 padC0[0xD0 - 0xC0];
    s32 unkD0;
    u8 padD4[0xF0 - 0xD4];
    s32 unkF0;
} Actor;

void func_80012718(Actor *);
void func_8002A360(s32, s32);
void func_8002ACAC(void);
void func_8002D124(void);
f32 func_8002DD60(f32);
void func_8003A9A8(Actor *, s32);
void func_8003BC40(void);
void func_8003BF98(Actor *);
void func_80043328(Actor *, s32, s32);
void func_800433A8(Actor *, s32, s32);
extern s32 D_800B3838;
extern Actor *D_800B3960;
extern s32 D_800B4CEC[];
extern s32 D_800B4CF8;
extern Actor *D_800BD06C;
extern s32 D_80107040[];
extern s32 D_80140200;
extern s32 D_80140228;
extern s32 D_80140238;
extern s32 D_80140240;
extern f32 D_80140248;

void func_8003AC08(Actor *a, f32 x, s32 flag)
{
    a->unk94 = 0;
    if (flag == 0 && (D_80140248 < -3500.0 || a->unk6C == 1)) {
        a->unk8 = x;
        a->unk50 = 0.0f;
        a->unk84 = 0;
        a->unk90 = 1;
        if (a->unk6C == 1) {
            func_8003BF98(a);
            a->unk6C = 0;
            return;
        }
        func_800433A8(a, 0x15, 0x100);
        func_80012718(a);
        func_80012718(a);
        func_80012718(a);
        func_80012718(a);
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x83);
        func_8002D124();
        D_800B3960->unk6C = 0;
        a->unk6C = 0;
        return;
    }
    if (a->unk6C == 2) {
        a->unk90 = 1;
        a->unk8 = x;
        a->unk6C = 0;
        a->unk50 = 0.0f;
        a->unk84 = 0;
        D_800BD06C->unkF0 = 0xFF;
        D_800BD06C->unk10 = D_800B3960->unk10 + 0x8000;
        func_800433A8(D_800BD06C, 0x1A, 0x100);
        D_800BD06C->unk9C = func_8003BC40;
        D_800BD06C->unkF0 = 0xFF;
        D_800BD06C->unk0 = 0x101;
        func_8002D124();
        return;
    }
    a->unk50 = 0.0f;
    switch (a->unkD0) {
    case 43:
        if ((D_800B4CF8 & 8) && (D_80107040[0] & 0x4000)) {
            if (D_80140238 >= 2) {
                func_80043328(a, 0x2C, 0x100);
                a->unk8 = x;
                a->unk50 = 0.0f;
                a->unk84 = 0;
                a->unk90 = 1;
                a->unk94 = 0;
                D_80140228 = 1;
                func_80012718(a);
                func_80012718(a);
                func_80012718(a);
                func_80012718(a);
                func_8002A360(12, 0x80);
                func_8002A360(8, 0x84);
                func_8002D124();
            } else {
                func_80043328(a, 0x2D, 0x100);
                a->unk8 = x;
                a->unkB0 = 0;
                a->unk50 = D_80140238 * 200 + 2500;
                D_80140238++;
                func_80012718(a);
                func_80012718(a);
                func_80012718(a);
                func_80012718(a);
                func_8002A360(12, 0x80);
                func_8002A360(8, 0x84);
                func_8002D124();
            }
        } else {
            func_80043328(a, 0x2C, 0x100);
            a->unk8 = x;
            a->unk50 = 0.0f;
            a->unk84 = 0;
            a->unk90 = 1;
            a->unk94 = 0;
            D_80140228 = 1;
            func_80012718(a);
            func_80012718(a);
            func_80012718(a);
            func_80012718(a);
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x84);
            func_8002D124();
        }
        break;
    case 16:
        if (flag != 0) {
            a->unk8 = x;
            a->unk50 = D_80140240 * 3 / 2;
            a->unk8 += 1.0f;
            func_800433A8(a, 0x10, 0x100);
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x7B);
            func_8002D124();
            break;
        }
        func_80043328(a, 0x11, 0x100);
        a->unk8 = x;
        a->unk50 = 0.0f;
        a->unk84 = 0;
        a->unk90 = 1;
        a->unk94 = 0;
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x35);
        func_8002D124();
        func_80012718(a);
        func_80012718(a);
        func_80012718(a);
        func_80012718(a);
        break;
    case 5:
        if (flag != 0) {
            a->unk8 = x;
            a->unk50 = 1500.0f;
            a->unk8 += 1.0f;
            func_800433A8(a, 5, 0x100);
            func_8002ACAC();
            break;
        }
        if (a->unkB8 == 6 && func_8002DD60(a->unk50) > 100.0f) {
            a->unk8 = x;
            a->unk50 = func_8002DD60(a->unk50 * 0.5f);
            a->unk8 += 1.0f;
            func_800433A8(a, 5, 0x100);
            func_8002ACAC();
            break;
        }
        a->unk90 = 1;
        a->unk8 = x;
        a->unk50 = 0.0f;
        a->unk84 = 0;
        if (D_80140200 > D_800B4CEC[0]) {
            func_8003A9A8(a, 0);
        } else {
            func_800433A8(a, 0x23, 0x100);
        }
        if (D_800B3838 != 0) {
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x19);
            func_8002D124();
            D_800B3838 = 0;
        } else {
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x34);
            func_8002D124();
        }
        func_80012718(a);
        func_80012718(a);
        func_80012718(a);
        func_80012718(a);
        break;
    case 12:
        a->unk90 = 1;
        a->unk8 = x;
        a->unk50 = 0.0f;
        a->unk84 = 0;
        if (D_80107040[a->unkBC] & 0x8000) {
            func_800433A8(a, 5, 0x100);
            a->unk50 = D_80140240;
            if (a->unkB8 == 6) {
                a->unk50 = D_80140240 * 3 / 2;
            }
            a->unk8 += 1.0f;
            break;
        }
        func_8003A9A8(a, 0);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 44:
    case 45:
    case 46:
    case 47:
    default:
        a->unk8 = x;
        a->unk50 = 0.0f;
        a->unk84 = 0;
        a->unk90 = 1;
        break;
    }
}
