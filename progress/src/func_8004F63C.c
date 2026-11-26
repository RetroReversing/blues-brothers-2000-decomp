s32 func_8000C43C(void);
void func_8004E8B0(void *, s32);
void func_800168F4(void);
void func_800176D0(void);
void func_800184B8(void);

typedef struct Obj {
    s32 x0;
    char pad4[0x10 - 0x4];
    s32 x10;
    s32 x14;
    s32 x18;
    char pad1C[0x6C - 0x1C];
    s32 x6C;
    s32 x70;
    s32 x74;
    s32 x78;
    s32 x7C;
    s32 x80;
    s32 x84;
    s32 x88;
    s32 x8C;
    s32 x90;
    s32 x94;
    char pad98[0x9C - 0x98];
    void (*fn9C)(void);
} Obj;

extern void (*D_800B7734[])(void);
extern s32 D_800B7DE0[];
extern s32 D_800B7E70[];
extern s32 D_8014A920;
extern s32 D_8014AA20;

s32 *func_8004F63C(Obj *arg0, s32 flags, s32 *args) {
    s32 i;
    s32 bit;

    bit = 1;
    for (i = 0; i < 32; i++) {
        if (flags & bit) {
            switch (bit) {
            case 1:
                if (args[0] > 0) {
                    void (*fn)(void) = D_800B7734[args[0]];
                    arg0->fn9C = fn;
                    if (fn == func_800184B8) {
                        arg0->x0 = 0x131;
                    }
                    if (arg0->fn9C == func_800176D0) {
                        arg0->x0 = 0x131;
                        arg0->x70 = 0;
                        arg0->fn9C = func_800184B8;
                    }
                    if (arg0->fn9C == func_800168F4) {
                        D_8014A920 |= 2;
                    }
                    if (func_8000C43C() == 3 && arg0->fn9C == func_800168F4) {
                        s32 v = D_800B7E70[D_8014AA20];
                        D_8014AA20++;
                        arg0->x10 = v + 0x8000;
                    }
                }
                break;
            case 2:
                if (args[0] > 0) {
                    func_8004E8B0(arg0, args[0]);
                }
                break;
            case 4:
                arg0->x10 = args[0];
                arg0->x14 = 0;
                arg0->x14 = args[1];
                arg0->x18 = 0;
                break;
            case 8:
                arg0->x0 = args[0];
                arg0->x70 = args[0];
                break;
            case 0x10:
                arg0->x6C = args[0];
                break;
            case 0x20:
                arg0->x70 = args[0];
                break;
            case 0x40:
                arg0->x74 = args[0];
                break;
            case 0x80:
                arg0->x78 = args[0];
                break;
            case 0x100:
                arg0->x7C = args[0];
                break;
            case 0x200:
                arg0->x80 = args[0];
                break;
            case 0x400:
                arg0->x84 = args[0];
                break;
            case 0x800:
                arg0->x88 = args[0];
                break;
            case 0x1000:
                arg0->x8C = args[0];
                break;
            case 0x2000:
                arg0->x90 = args[0];
                break;
            case 0x4000:
                arg0->x94 = args[0];
                break;
            }
            args += D_800B7DE0[i];
        }
        bit <<= 1;
    }
    return args;
}
