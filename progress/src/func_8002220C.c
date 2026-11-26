typedef struct { u32 w0; u32 w1; } GfxW220C;

typedef struct Cfg220C {
    GfxW220C cc1;
    GfxW220C cc2;
    u32 mode;
    u32 mode2;
    u32 pad[2];
} Cfg220C;

extern void func_80022100(Cfg220C *);
extern s32 D_800BD6B0[];
extern u8 D_800CD0E4[];
extern GfxW220C *D_80177E18;
extern u8 D_800AB99E[];
extern u8 D_800AB410[];
extern GfxW220C D_800AB878[];
extern GfxW220C D_800AB8A8[];
extern GfxW220C D_800AB8F8[];
extern GfxW220C D_800AB920[];

#define CMD(a, b) { GfxW220C *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }

void func_8002220C(s32 flags) {
    Cfg220C cfg;
    s32 b0;
    s32 b1;
    s32 c;
    s32 a;
    s32 b8;
    s32 m;
    s32 z;
    GfxW220C *tbl;
    s32 i1;
    s32 i2;

    *(s32 *) D_800CD0E4 = 0;
    cfg.mode = 0x205;
    cfg.mode2 = 0;
    D_800BD6B0[1]++;
    b0 = flags & 1;
    b1 = (flags >> 1) & 1;
    c = (flags >> 2) & 7;
    a = (flags >> 5) & 7;
    b8 = (flags >> 8) & 1;
    m = (flags >> 9) & 7;
    z = (flags >> 12) & 3;
    if (b0 == 1) {
        cfg.mode = 0x20205;
    }
    if (b1 == 1) {
        cfg.mode |= 0x200000;
    }
    if (b8 == 1) {
        cfg.mode2 = 0x100000;
        cfg.mode |= 0x10000;
    }
    i1 = a;
    i2 = c;
    switch (m) {
    case 1:
        *(s32 *) D_800CD0E4 = m;
        cfg.mode |= 0xC0000;
        CMD(0xE3000C00, 0x80000);
        CMD(0xE3000F00, 0);
        CMD(0xE3001201, 0x2000);
        CMD(0xD7000002, (*(u16 *) D_800AB99E << 16) | *(u16 *) D_800AB99E);
        break;
    case 2:
        cfg.mode |= 0x40000;
        CMD(0xD7000002, 0x07C007C0);
        CMD(0xFA000000, 0xFFFF80FF);
        CMD(0xE3000F00, 0);
        CMD(0xFD900000, (u32) D_800AB410);
        CMD(0xF5900000, 0x07014050);
        CMD(0xE6000000, 0);
        CMD(0xF3000000, 0x071FF200);
        CMD(0xE7000000, 0);
        CMD(0xF5880800, 0x00014050);
        CMD(0xF2000000, 0x0007C07C);
        i1 = 4;
        break;
    }
    switch (z) {
    case 1:
        CMD(0xE3001801, 0);
        break;
    case 0:
        CMD(0xE3001801, 0x40);
        break;
    case 2:
        CMD(0xE3001801, 0x80);
        break;
    case 3:
        CMD(0xE3001801, 0xC0);
        break;
    }
    if (b8 == 1) {
        if (i2 == 2) {
            cfg.cc1.w0 = 0xFC127FFF;
            cfg.cc1.w1 = 0xFFFFF238;
        } else {
            cfg.cc1 = D_800AB8A8[i1];
        }
        cfg.cc2 = D_800AB920[i2];
    } else {
        cfg.cc1 = D_800AB878[i1];
        cfg.cc2 = D_800AB8F8[i2];
    }
    if (i1 == 4) {
        cfg.cc1.w0 = 0xFCFFFFFF;
        cfg.cc1.w1 = 0xFFFCF67B;
        do {
        } while (0);
        cfg.cc1.w0 = 0xFC30FE61;
        cfg.cc1.w1 = 0x44FE793C;
        cfg.cc2 = D_800AB8F8[0];
        cfg.cc1.w0 = 0xFC30FE61;
        cfg.cc1.w1 = 0x44FE793C;
        cfg.cc2 = D_800AB8F8[0];
    }
    func_80022100(&cfg);
}
