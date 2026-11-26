typedef struct { u32 w0, w1, w2, w3; } Vec4;
extern void bzero(void *, u32);
extern u32 func_80097590();
extern void func_80097620(u32);
extern void func_80097630(u32);
extern void func_800976C0();
extern s32 func_8009D860(u32, u32 *);
extern s32 func_8009D8D0(u32, u32);
extern s32 func_800A1D20(u32, u32 *);
extern u64 func_800A8D90(u64, u64);
extern void osInvalICache(void *, u32);
extern void osWritebackDCache(void *, u32);
extern u32 D_80000180;
extern u32 D_80000184;
extern u32 D_80000188;
extern u32 D_80000194;
extern u32 D_80000198;
extern u32 D_8000019C;
extern u32 D_80000300;
extern u32 D_8000030C;
extern u8 D_8000031C[];
extern u64 D_800BB200;
extern u32 D_800BB208;
extern s32 D_8017C5B0;
extern Vec4 func_800962D0;

void func_80097260(void) {
    u32 pifdata;
    u32 clock = 0;

    func_80097630(func_80097590() | 0x20000000);
    func_80097620(0x01000800);
    while (func_8009D860(0x1FC007FC, &pifdata)) {
    }
    while (func_8009D8D0(0x1FC007FC, pifdata | 8)) {
    }
    *(Vec4 *) 0x80000000 = func_800962D0;
    *(Vec4 *) 0x80000080 = func_800962D0;
    *(Vec4 *) 0x80000100 = func_800962D0;
    *(Vec4 *) 0x80000180 = func_800962D0;
    osWritebackDCache((void *) 0x80000000, 0x190);
    osInvalICache((void *) 0x80000000, 0x190);
    func_800976C0();
    func_800A1D20(4, &clock);
    clock &= ~0xF;
    if (clock != 0) {
        D_800BB200 = clock;
    }
    D_800BB200 = func_800A8D90(D_800BB200 * 3, 4);
    if (D_8000030C == 0) {
        bzero(D_8000031C, 0x40);
    }
    if (D_80000300 == 0) {
        D_800BB208 = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        D_800BB208 = 0x02E6025C;
    } else {
        D_800BB208 = 0x02E6D354;
    }
    if (!D_8017C5B0) {
        int (*fnc)();
        unsigned int *src;
        unsigned int *dst;
        unsigned int monadr;
        volatile unsigned int *mon;
        volatile unsigned int *stat;

        stat = (unsigned *) 0xBFF08004;
        mon = (unsigned *) 0xBFF00000;
        if (*mon != 0x4B4D4300) {
            return;
        }

        src = (unsigned *) &func_800962D0 + 4;
        dst = (unsigned *) 0x80000180;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        src += 2;
        dst += 2;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        osWritebackDCache((void *) 0x80000180, 0x24);
        osInvalICache((void *) 0x80000180, 0x24);

        D_8017C5B0 = 1;

        if ((*stat & 0x10) == 0) {
            monadr = *(mon + 1);
            if (monadr != 0xBFF00000) {
                unsigned int *src;
                unsigned int *dst = (unsigned int *) (monadr | 0x20000000);
                unsigned int ct = 0x2000 / 4;

                src = (unsigned int *) 0xBFF00000;

                while (ct != 0) {
                    *dst++ = *src++;
                    ct--;
                }
            }
            fnc = (int (*)()) (monadr + 8);
            fnc(0x4B4D4300, 0);
        }
    }
}
