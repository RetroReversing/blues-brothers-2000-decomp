void func_8002854C(u8, s32);
extern s32 gTextPenX;
extern s32 gTextPenY;

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
            if (gTextPenX >= 0x125 || c == 0xA) {
                gTextPenX = 0x1E;
                gTextPenY += 0xA;
            }
            continue;
        }
        break;
    }
}
