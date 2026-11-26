/* identical to osCreateThread in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osCreateThread in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osCreateThread in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef struct {u64 at,v0,v1,a0,a1,a2,a3,t0,t1,t2,t3,t4,t5,t6,t7,s0,s1,s2,s3,s4,s5,s6,s7,t8,t9,gp,sp,s8,ra,lo,hi;u32 sr,pc,cause,badvaddr,rcp,fpcsr;} OSThreadContext;
typedef struct OSThread {struct OSThread *next;s32 priority;struct OSThread **queue;struct OSThread *tlnext;u16 state,flags;s32 id,fp;void *prof;OSThreadContext context;} OSThread;
extern char func_80096F1C[];
extern OSThread *D_800BB23C;
u32 func_800970B0(void);
void func_800970D0(u32);

/* Initialises a thread control block with its id, priority, entry point, argument
 * and stack pointer, sets the initial CPU context (status, RCP and FPU control
 * words), marks it ready (state 1), and links it at the head of the active thread queue
 * with interrupts disabled. */
void osCreateThread(OSThread *thread, s32 id, void (*entry)(void*), void *arg, void *sp, s32 priority)
{
  u32 mask;
  thread->id = id;
  thread->priority = priority;
  thread->next = 0;
  thread->queue = 0;
  thread->context.pc = (u32) entry;
  thread->context.a0 = (s64)(s32) arg;
  thread->context.sp = (s64)(s32) sp - 16;
  thread->context.ra = (u64)(func_80096F1C + 0x17c);
  thread->context.sr = 0xff03;
  thread->context.rcp = 0x3f;
  thread->context.fpcsr = 0x1000800;
  thread->fp = 0;
  thread->state = 1;
  thread->flags = 0;
  mask = func_800970B0();
  thread->tlnext = D_800BB23C;
  D_800BB23C = thread;
  func_800970D0(mask);
}
