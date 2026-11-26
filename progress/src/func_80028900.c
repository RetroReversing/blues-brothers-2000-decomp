void func_8002854C(u8, s32);
extern s32 D_8010788C;
extern s32 D_80107890;

void func_80028900(u8 *arg0) {
    u8 c;
    s32 key;

    key = 1;
    for (;;) {
        c = *arg0;
        arg0++;
        if (c != 0) {
            func_8002854C(c, key);
            key = 0;
            if (D_8010788C >= 0x125 || c == 0xA) {
                D_8010788C = 0x1E;
                D_80107890 += 0xA;
            }
            continue;
        }
        break;
    }
}
