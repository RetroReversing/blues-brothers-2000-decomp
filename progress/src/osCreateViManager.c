/* identical to osCreateViManager in PENNY RACERS (matched), with its names changed by decompdecomp */
typedef s32 OSPri;
typedef s32 OSId;
typedef void *OSMesg;
typedef struct OSThread_s { struct OSThread_s *next; OSPri priority; struct OSThread_s **queue; struct OSThread_s *tlnext; u16 state; u16 flags; OSId id; int fp; void *thprof; u8 context[0x1b0 - 0x24]; } OSThread;
typedef struct OSMesgQueue_s { OSThread *mtqueue; OSThread *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct { u16 type; u8 pri; u8 status; OSMesgQueue *retQueue; } OSIoMesgHdr;
typedef struct { OSIoMesgHdr hdr; void *dramAddr; u32 devAddr; u32 size; void *piHandle; } OSIoMesg;
typedef struct { s32 active; OSThread *thread; OSMesgQueue *cmdQueue; OSMesgQueue *evtQueue; OSMesgQueue *acsQueue; s32 (*dma)(s32, u32, void *, u32); s32 (*edma)(void *, s32, u32, void *, u32); } OSDevMgr;
extern void func_80097F80(void);
extern void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern void func_80097C50(u32, OSMesgQueue *, OSMesg);
extern OSPri func_8009D220(OSThread *);
extern void func_80097CB0(OSThread *, OSPri);
extern u32 func_800970B0(void);
extern void func_80096200(OSThread *, OSId, void (*)(void *), void *, void *, OSPri);
extern void initViManagerContexts(void);
extern void func_80097E20(OSThread *);
extern void func_800970D0(u32);
OSDevMgr __osViDevMgr = { 0 };
u32 __additional_scanline = 0;
static struct { OSThread thread; unsigned char gap[8]; } viThreadStorage;
static unsigned char viThreadStack[4096] __attribute__((aligned(8)));
static OSMesgQueue viEventQueue __attribute__((aligned(8)));
static OSMesg viEventBuf[5] __attribute__((aligned(8)));
static OSIoMesg viRetraceMsg __attribute__((aligned(8)));
static OSIoMesg viCounterMsg __attribute__((aligned(8)));
static void func_8009D088(void *arg);
void osCreateViManager(OSPri pri) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;
    if (__osViDevMgr.active) {
        return;
    }
    func_80097F80();
    osCreateMesgQueue(&viEventQueue, viEventBuf, 5);
    viRetraceMsg.hdr.type = 13;
    viRetraceMsg.hdr.pri = 0;
    viRetraceMsg.hdr.retQueue = 0;
    viCounterMsg.hdr.type = 14;
    viCounterMsg.hdr.pri = 0;
    viCounterMsg.hdr.retQueue = 0;
    func_80097C50(7, &viEventQueue, &viRetraceMsg);
    func_80097C50(3, &viEventQueue, &viCounterMsg);
    oldPri = -1;
    myPri = func_8009D220(0);
    if (myPri < pri) {
        oldPri = myPri;
        func_80097CB0(0, pri);
    }
    savedMask = func_800970B0();
    __osViDevMgr.active = 1;
    __osViDevMgr.thread = &viThreadStorage.thread;
    __osViDevMgr.cmdQueue = &viEventQueue;
    __osViDevMgr.evtQueue = &viEventQueue;
    __osViDevMgr.acsQueue = 0;
    __osViDevMgr.dma = 0;
    __osViDevMgr.edma = 0;
    func_80096200(&viThreadStorage.thread, 0, func_8009D088, &__osViDevMgr, &viThreadStack[4096], pri);
    initViManagerContexts();
    func_80097E20(&viThreadStorage.thread);
    func_800970D0(savedMask);
    if (oldPri != -1) {
        func_80097CB0(0, oldPri);
    }
}
