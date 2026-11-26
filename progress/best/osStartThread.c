/* identical to osStartThread in V-RALLY-PAL (matched), with its names changed by decompdecomp */
typedef s32 OSPri;
typedef s32 OSId;

typedef struct OSThread_s {
    struct OSThread_s    *next;
    OSPri                 priority;
    struct OSThread_s   **queue;
    struct OSThread_s    *tlnext;
    u16                   state;
    u16                   flags;
    OSId                  id;
    int                   fp;
    void                 *thprof;
    u8                    context[0x1A0];
} OSThread;

extern OSThread *D_800BB240;
extern OSThread *D_800A2518;
u32 func_800970B0(void);
void func_800970D0(u32);
void func_80096DBC(OSThread **);
void __osEnqueueThread(OSThread **, OSThread *);
OSThread *__osPopThread(OSThread **);
void func_80096F1C(void);

/* Makes a thread runnable. A stopped thread goes straight onto the run queue; a
   thread that is waiting on a queue is moved to the run queue. If the running
   thread has lower priority than the new head of the run queue, it is preempted.
   Runs with interrupts disabled. */
void func_80097E20(OSThread *thread) {
    register u32 saved_int_mask = func_800970B0();

    switch (thread->state) {
        case (1 << 3):
            thread->state = (1 << 1);
            __osEnqueueThread(&D_800A2518, thread);
            break;
        case (1 << 0):
            if (thread->queue == 0 || thread->queue == &D_800A2518) {
                thread->state = (1 << 1);
                __osEnqueueThread(&D_800A2518, thread);
            } else {
                thread->state = (1 << 3);
                __osEnqueueThread(thread->queue, thread);
                __osEnqueueThread(&D_800A2518, __osPopThread(thread->queue));
            }
            break;
    }

    if (D_800BB240 == 0) {
        func_80096F1C();
    } else if (D_800BB240->priority < D_800A2518->priority) {
        D_800BB240->state = (1 << 1);
        func_80096DBC(&D_800A2518);
    }

    func_800970D0(saved_int_mask);
}
