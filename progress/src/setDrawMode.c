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

/* Sets up the RDP draw mode for a material from packed flags: combiner and blender modes, texture mode and z mode. Appends the needed display list commands and submits the combiner config. */
void setDrawMode(s32 flags) {
    Cfg220C cfg;
    s32 twoCycle;
    s32 zCmp;
    s32 cc2Bits;
    s32 cc1Bits;
    s32 altCombine;
    s32 texMode;
    s32 zMode;
    GfxW220C *tbl;
    s32 cc1Idx;
    s32 cc2Idx;

    *(s32 *) D_800CD0E4 = 0;
    cfg.mode = 0x205;
    cfg.mode2 = 0;
    D_800BD6B0[1]++;
    twoCycle = flags & 1;
    zCmp = (flags >> 1) & 1;
    cc2Bits = (flags >> 2) & 7;
    cc1Bits = (flags >> 5) & 7;
    altCombine = (flags >> 8) & 1;
    texMode = (flags >> 9) & 7;
    zMode = (flags >> 12) & 3;
    if (twoCycle == 1) {
        cfg.mode = 0x20205;
    }
    if (zCmp == 1) {
        cfg.mode |= 0x200000;
    }
    if (altCombine == 1) {
        cfg.mode2 = 0x100000;
        cfg.mode |= 0x10000;
    }
    cc1Idx = cc1Bits;
    cc2Idx = cc2Bits;
    switch (texMode) {
    case 1:
        *(s32 *) D_800CD0E4 = texMode;
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
        cc1Idx = 4;
        break;
    }
    switch (zMode) {
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
    if (altCombine == 1) {
        if (cc2Idx == 2) {
            cfg.cc1.w0 = 0xFC127FFF;
            cfg.cc1.w1 = 0xFFFFF238;
        } else {
            cfg.cc1 = D_800AB8A8[cc1Idx];
        }
        cfg.cc2 = D_800AB920[cc2Idx];
    } else {
        cfg.cc1 = D_800AB878[cc1Idx];
        cfg.cc2 = D_800AB8F8[cc2Idx];
    }
    if (cc1Idx == 4) {
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
