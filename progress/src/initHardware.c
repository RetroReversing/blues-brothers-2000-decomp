typedef struct { u32 w0, w1, w2, w3; } Vec4;
extern void bzero(void *, u32);
extern u32 getCop0Status();
extern void setFpcCsr(u32);
extern void setCop0Status(u32);
extern void func_800976C0();
extern s32 siRawReadIo(u32, u32 *);
extern s32 siRawWriteIo(u32, u32);
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
extern u32 osCounterRate;
extern s32 monitorInstalled;
extern Vec4 excVectorStub;

/* Boot-time hardware setup: CP0/FPU state, exception vector copies, CPU counter
   calibration, and loading the debug monitor from the cartridge when present. */
void initHardware(void) {
    u32 pifStatus;
    u32 cycles = 0;

    setCop0Status(getCop0Status() | 0x20000000);
    setFpcCsr(0x01000800);
    while (siRawReadIo(0x1FC007FC, &pifStatus)) {
    }
    while (siRawWriteIo(0x1FC007FC, pifStatus | 8)) {
    }
    *(Vec4 *) 0x80000000 = excVectorStub;
    *(Vec4 *) 0x80000080 = excVectorStub;
    *(Vec4 *) 0x80000100 = excVectorStub;
    *(Vec4 *) 0x80000180 = excVectorStub;
    osWritebackDCache((void *) 0x80000000, 0x190);
    osInvalICache((void *) 0x80000000, 0x190);
    func_800976C0();
    func_800A1D20(4, &cycles);
    cycles &= ~0xF;
    if (cycles != 0) {
        D_800BB200 = cycles;
    }
    D_800BB200 = func_800A8D90(D_800BB200 * 3, 4);
    if (D_8000030C == 0) {
        bzero(D_8000031C, 0x40);
    }
    if (D_80000300 == 0) {
        osCounterRate = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        osCounterRate = 0x02E6025C;
    } else {
        osCounterRate = 0x02E6D354;
    }
    if (!monitorInstalled) {
        int (*monitorEntry)();
        unsigned int *ramSrc;
        unsigned int *ramDst;
        unsigned int monitorAddr;
        volatile unsigned int *monitorHeader;
        volatile unsigned int *piStatusReg;

        piStatusReg = (unsigned *) 0xBFF08004;
        monitorHeader = (unsigned *) 0xBFF00000;
        if (*monitorHeader != 0x4B4D4300) {
            return;
        }

        ramSrc = (unsigned *) &excVectorStub + 4;
        ramDst = (unsigned *) 0x80000180;
        *ramDst++ = *ramSrc++;
        *ramDst++ = *ramSrc++;
        *ramDst++ = *ramSrc++;
        ramSrc += 2;
        ramDst += 2;
        *ramDst++ = *ramSrc++;
        *ramDst++ = *ramSrc++;
        *ramDst++ = *ramSrc++;

        osWritebackDCache((void *) 0x80000180, 0x24);
        osInvalICache((void *) 0x80000180, 0x24);

        monitorInstalled = 1;

        if ((*piStatusReg & 0x10) == 0) {
            monitorAddr = *(monitorHeader + 1);
            if (monitorAddr != 0xBFF00000) {
                unsigned int *copySrc;
                unsigned int *copyDst = (unsigned int *) (monitorAddr | 0x20000000);
                unsigned int wordsLeft = 0x2000 / 4;

                copySrc = (unsigned int *) 0xBFF00000;

                while (wordsLeft != 0) {
                    *copyDst++ = *copySrc++;
                    wordsLeft--;
                }
            }
            monitorEntry = (int (*)()) (monitorAddr + 8);
            monitorEntry(0x4B4D4300, 0);
        }
    }
}
