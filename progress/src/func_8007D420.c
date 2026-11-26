typedef struct Cred {
    char pad0[0x6C];
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
} Cred;
s32 func_80024380();
s32 func_8002710C();
s32 func_800289A0();
s32 func_8007D6DC();
extern u8 *D_800B8650[];
extern s32 D_80107684;
extern s32 D_8010788C;
extern s32 D_80107890;
extern s32 D_80107898;
extern Cred D_801704E0;

s32 func_8007D420(void) {
    Cred *c;
    u8 *p;
    s32 ch;
    s32 s3;
    s32 s5;
    s32 s6;
    s32 s7;
    s32 fp;
    s32 t;
    s32 v1;
    s32 n;
    char buf[0x20];

    c = &D_801704E0;
    if (c->f7C == 0) {
        c->f7C = 1;
        c->f6C = 0;
        c->f74 = 0;
        c->f78 = 0;
        c->f80 = 0;
        D_80107898 = 0;
    }
    func_8007D6DC();
    p = D_800B8650[c->f6C];
    if (p == 0) {
        return 1;
    }
    c->f70 = 0;
    D_8010788C = 0x1E;
    D_80107890 = 0x1E;
    ch = *p;
    while (ch != 0) {
        switch (func_80024380(c->f74 - c->f70)) {
        case -1:
            s3 = 0;
            break;
        case 0:
            s3 = c->f78;
            break;
        case 1:
            s3 = 0xFF;
            break;
        }
        switch (ch & 0xFF) {
        case 0xF0:
            fp = 0;
            s6 = 0x10;
            s7 = 0xFF;
            s5 = s7;
            D_80107684 = 0;
            p++;
            break;
        case 0xF1:
            fp = 1;
            s7 = 0xFF;
            s5 = s7;
            s6 = s7;
            break;
        case 0xF2:
            D_80107684 = 1;
            break;
        case 0xA:
            D_8010788C = 0x1E;
            c->f70 = c->f70 + 1;
            v1 = D_80107890;
            D_80107890 = v1 + 0xF;
            if ((fp & 0xFF) != 0) {
                D_8010788C = 0x2D;
            }
            if (D_80107684 != 0) {
                D_80107890 = v1 + 0xC;
            }
            D_80107684 = 0;
            break;
        default:
            func_8002710C(s6, s5, s7, s3);
            func_800289A0(ch);
            break;
        }
        p++;
        ch = *p;
    }
    n = (s32) ((f32) c->f78 + 2.0f);
    c->f80 = c->f70;
    c->f78 = n;
    if ((f32) n >= 255.0f) {
        c->f78 = 0;
        c->f74 = c->f74 + 1;
        if (c->f80 + 1 < c->f74) {
            c->f6C = c->f6C + 1;
            c->f70 = 0;
            c->f74 = 0;
            c->f80 = 0;
        }
    }
    return 0;
}
