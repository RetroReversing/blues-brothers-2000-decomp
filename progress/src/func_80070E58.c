void func_80070FC8(char *, char *);
s32 osRecvMesg(void *, s32 *, s32);
extern s32 D_800B8350;

void func_80070E58(char *t) {
    s32 msg = 0;

    for (;;) {
        osRecvMesg(t + 0x74, &msg, 1);
        D_800B8350++;
        switch (msg) {
        case 0x29A:
            func_80070FC8(t, t);
            break;
        case 0x29D:
            func_80070FC8(t, t + 2);
            break;
        }
    }
}
