typedef u64 OSTime;
void osCreateMesgQueue(void *, void *, s32);
void osCreateThread(void *, s32, void *, void *, void *, s32);
s32 osSetTimer(void *, OSTime, OSTime, void *, void *);
void osStartThread(void *);
extern u8 D_8013F4F0[];
extern u8 D_8013FAA0[];
extern s32 D_8013FAC0;
extern s32 D_8013FAC4;
extern s32 D_8013FAC8[2];
extern u8 D_8013FAD8[];
extern u8 D_8013FAE8[];
extern u8 D_8013FB08[];
void func_8002CEEC(void *);

void func_8002CDB0(void) {
    D_8013FAC4 = 0;
    D_8013FAC0 = 0;
    D_8013FAC8[0] = 0;
    D_8013FAC8[1] = 0;
    osCreateMesgQueue(D_8013FB08, D_8013FAD8, 4);
    osCreateThread(D_8013F4F0, 5, func_8002CEEC, 0, D_8013FAA0, 0xF);
    osStartThread(D_8013F4F0);
    osSetTimer(D_8013FAE8, 0x11E1A3, 0x11E1A3, D_8013FB08, D_8013FAC8);
}
