/* identical to osSendMesg in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSendMesg in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef void *OSMesg;
typedef struct OSThread_s OSThread;
struct OSThread_s { struct OSThread_s *next; s32 priority; struct OSThread_s **queue; struct OSThread_s *tlnext; u16 state; };
typedef struct OSMesgQueue_s {
    OSThread    *mtqueue;
    OSThread    *fullqueue;
    s32          validCount;
    s32          first;
    s32          msgCount;
    OSMesg      *msg;
} OSMesgQueue;

extern OSThread *D_800BB240;
extern u32 func_800970B0(void);
extern void func_800970D0(u32);
extern void func_80096DBC(OSThread **);
extern OSThread *__osPopThread(OSThread **);
extern void osStartThread(OSThread *);

/* Sends msg to mq. If the queue is full, OS_MESG_BLOCK (flags == 1) sleeps the
 * running thread until there is room; otherwise returns -1. Wakes a thread
 * waiting to receive. Returns 0 on success. */
/* Sends a message to a queue, blocking or failing when it is full, and wakes a waiting receiver. */ s32 osSendMesg(OSMesgQueue* mq, OSMesg msg, s32 flags) {
    register u32 saveMask;
    register s32 writeIndex;

    saveMask = func_800970B0();

    while ((((  mq  )->validCount)  >= ( mq )->msgCount) ) {
        if (flags == 1 ) {
            D_800BB240->state = (1 << 3) ;
            func_80096DBC(&mq->fullqueue);
        } else {
            func_800970D0(saveMask);
            return -1;
        }
    }

    writeIndex = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[writeIndex] = msg;
    mq->validCount++;

    if (mq->mtqueue->next != 0 ) {
        osStartThread(__osPopThread(&mq->mtqueue));
    }

    func_800970D0(saveMask);
    return 0;
}
