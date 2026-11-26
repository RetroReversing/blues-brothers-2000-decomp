typedef void *OSMesg_;
s32 osCreateMesgQueue(void *, void *, s32);
s32 osSetEventMesg(u32, void *, void *);
void osCreateThread(void *, s32, void (*)(void *), void *, void *, s32);
s32 osCreatePiManager(s32, void *, void *, s32);
void osStartThread(void *);
extern u8 D_801811D0[];
extern u8 D_80181380[];
extern u8 D_801853A0[];
extern u64 D_801813A0[];
extern u8 D_801853C0[];
extern u8 D_801853E0[];
void __rmonIOhandler(void);

void __rmonInit(void) {
    osCreateMesgQueue(D_801853E0, D_80181380, 8);
    osSetEventMesg(10, D_801853E0, (void *)2);
    osSetEventMesg(11, D_801853E0, (void *)4);
    osSetEventMesg(12, D_801853E0, (void *)8);
    osSetEventMesg(13, D_801853E0, NULL);
    osCreateThread(D_801811D0, 0, (void (*)(void *))__rmonIOhandler, NULL, D_801813A0 + 0x4000 / sizeof(u64), 0xFF);
    osCreatePiManager(0x96, D_801853C0, D_801853A0, 8);
    osStartThread(D_801811D0);
}


