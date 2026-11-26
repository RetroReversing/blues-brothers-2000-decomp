void func_80026D6C(s32, char *, s32);
void func_80027038(s32);
void setTextColor(s32, s32, s32, s32);
void func_80027158(s32, s32);
void func_80028900(char *);
void func_8002E46C(void);
void func_8002E944(void);
void buildFrameDisplayList(s32);
void func_800896D0(void);
void func_80089814(s32);
void func_800899C4(char *, char *);
void func_80089C00(void);
void func_80089C08(void);
void *memcpy(void *, const void *, u32);
u32 strlen(const char *);
extern char D_80009C8C[];
extern s32 D_800B9EB8;
extern s32 D_80178238;

void debugPrintf(u8 *fmt, ...) {
    char buf[256];
    char *p;
    char *q;
    s32 i;
    s32 *ap;
    s32 c;

    p = buf;
    for (i = 255, q = &buf[255]; i >= 0; i--) {
        *q-- = 0;
    }
    ap = (s32 *)&fmt;
    while (*fmt != 0) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
            case 'C':
            case 'c':
                ap++;
                c = *ap;
                *p++ = c;
                break;
            case 's':
                ap++;
                memcpy(p, (char *)*ap, strlen((char *)*ap) + 1);
                p += strlen(p);
                break;
            case 'd':
                ap++;
                func_80026D6C(*ap, p, 10);
                p += strlen(p);
                break;
            case 'x':
                ap++;
                func_80026D6C(*ap, p, 16);
                p += strlen(p);
                break;
            default:
                ap++;
                break;
            }
            fmt++;
        } else {
            c = *fmt++;
            if (c == '\n') {
                c = ' ';
            }
            if (c == '\r') {
                c = ' ';
            }
            *p++ = c;
        }
    }
    *p = 0;
    func_800899C4(D_80009C8C, buf);
    i = 0;
    D_800B9EB8 ^= 1;
    func_8002E944();
    do {
        buildFrameDisplayList(1);
        i++;
        func_80089814(D_80178238);
        func_80089C00();
        func_80089C08();
        func_8002E46C();
        func_80027038(0);
        func_80027158(30, 20);
        setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
        func_80028900(buf);
        func_800896D0();
    } while (i < 3);
    for (;;) {
    }
}
