typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;
s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
void __rmonInit(void);
void __rmonHitBreak(void);
void __rmonHitSpBreak(void);
void __rmonHitCpuFault(void);

extern s32 D_800BC540;
extern OSMesgQueue D_801853E0;
extern volatile u32 D_80185420;
extern u32 D_80185430[];
extern u8 D_80185890;
extern u8 D_80185891;
extern s32 D_80185894;
extern void *D_80185898;

void rmonMain(void *arg) {
    OSMesg work;

    D_80185890 = D_80185891 = D_80185420 = 0;

    __rmonInit();
    D_800BC540 = 1;

    for (D_80185894 = 0, D_80185898 = (void *)D_80185430;;) {
        osRecvMesg(&D_801853E0, &work, 1);

        D_80185420 |= (u32)work;

        if (D_80185420 & 2) {
            D_80185420 &= ~2;
            __rmonHitBreak();
        }
        if (D_80185420 & 4) {
            D_80185420 &= ~4;
            __rmonHitSpBreak();
        }
        if (D_80185420 & 8) {
            D_80185420 &= ~8;
            __rmonHitCpuFault();
        }
        if (D_80185420 & 0x10) {
            D_80185420;
            D_80185420 &= (u8)~0x10;
        }
        if (D_80185420 & 0x20) {
            D_80185420;
            D_80185420 &= (u8)~0x20;
        }
    }
}
