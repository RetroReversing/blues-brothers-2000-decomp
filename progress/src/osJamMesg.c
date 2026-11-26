/* identical to osJamMesg in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osJamMesg in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef void *OSMesg;
typedef s32 OSPri;

typedef struct OSThread_s {
    struct OSThread_s *next;
    OSPri priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
} OSThread;

typedef struct OSMesgQueue_s {
    OSThread *mtqueue;
    OSThread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;

extern OSThread *D_800BB240;
extern u32 func_800970B0(void);
extern void func_800970D0(u32);
extern void func_80096DBC(OSThread **);
extern OSThread *__osPopThread(OSThread **);
extern void osStartThread(OSThread *);

/* Sends a message to the front of a queue, jamming it in ahead of others. If the queue is full, flag 1 blocks the current thread until there is room; otherwise returns -1. Wakes the first waiting receiver. */
/* Sends a message to the front of a message queue, blocking (flag 1) or failing (-1) when full, and wakes the first waiting receiver. */ s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    register u32 savedInterruptMask;

    savedInterruptMask = func_800970B0();

    while (mq->validCount >= mq->msgCount) {
        if (flag == 1) {
            D_800BB240->state = (1 << 3);
            func_80096DBC(&mq->fullqueue);
        } else {
            func_800970D0(savedInterruptMask);
            return -1;
        }
    }

    mq->first = (mq->first + mq->msgCount - 1) % mq->msgCount;
    mq->msg[mq->first] = msg;
    mq->validCount++;

    if (mq->mtqueue->next != 0) {
        osStartThread(__osPopThread(&mq->mtqueue));
    }

    func_800970D0(savedInterruptMask);
    return 0;
}
