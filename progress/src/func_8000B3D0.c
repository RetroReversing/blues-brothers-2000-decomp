s32 func_8000ABE8(u32, u32);
s32 func_8000AC20(u32);
void func_8000AC5C(s32);
void func_8000B1B4(s32);
s32 func_8000BC14(void);
void func_8000BC20(s32);
extern s32 D_800BC768;
extern u8 D_800BC910;
extern u8 D_800BC912;

void func_8000B3D0(void)
{
    s32 cmd;
    s32 run;

    do {
        run = 1;
        while ((cmd = func_8000AC20(0xB1FFFFF0)) == 0) {
            func_8000AC5C(1000);
        }
        if (cmd == 2) {
            func_8000ABE8(0xB1FFFFFC, 0);
            func_8000AC5C(1000);
        } else {
            func_8000ABE8(0xB1FFFFFC, 0x101);
            while (func_8000AC20(0xB1FFFFF0) == cmd) {
                func_8000AC5C(500);
            }
            if (func_8000AC20(0xB1FFFFF0) == 2) {
                func_8000ABE8(0xB1FFFFFC, 0);
            } else {
                switch (cmd) {
                case 16:
                    break;
                case 17:
                    run = 0;
                    break;
                case 18:
                    D_800BC910 = 0;
                    D_800BC912 = 0;
                    D_800BC768 &= ~1;
                    func_8000BC20(func_8000BC14() & ~1);
                    break;
                case 19:
                    D_800BC912 = 0;
                    D_800BC910 = 0;
                    break;
                case 20:
                    D_800BC912 = 0xFF;
                    break;
                case 21:
                    D_800BC912 = 0;
                    break;
                case 22:
                    func_8000ABE8(0xB1FE0000, (D_800BC912 << 24) | (D_800BC910 << 16));
                    break;
                case 23:
                    func_8000B1B4(2);
                    break;
                case 24:
                    func_8000B1B4(1);
                    break;
                }
                func_8000ABE8(0xB1FFFFFC, 0);
                while (func_8000AC20(0xB1FFFFF0) == 1) {
                    func_8000AC5C(500);
                }
            }
        }
    } while (run != 0 || D_800BC912 == 0);
}
