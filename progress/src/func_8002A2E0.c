extern u8 D_8013EA28[];
extern u8 D_8013F498[];
extern u8 D_8013F240[];
extern u8 D_8013EA40[];
extern s32 D_8013F410;
extern s32 D_8013F414;
void osCreateMesgQueue(void *, void *, s32);
void osCreateThread(void *, s32, void *, void *, void *, s32);
void osStartThread(void *);
void func_8002A3C8(void *);

void func_8002A2E0(void) {
    D_8013F410 = 0;
    D_8013F414 = 0;
    osCreateMesgQueue(D_8013EA28, D_8013F498, 0x10);
    osCreateThread(D_8013F240, 4, func_8002A3C8, NULL, D_8013EA40 + 0x800, 0xF);
    osStartThread(D_8013F240);
}
