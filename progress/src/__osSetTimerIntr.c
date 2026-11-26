/* identical to __osSetTimerIntr in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in __osSetTimerIntr in V-RALLY-PAL (matched), with its names changed by decompdecomp */
typedef u64 OSTime;
typedef struct OSTimer_s OSTimer;
extern u32 func_800970B0(void);
extern void func_800970D0(u32);
extern u32 func_80097250(void);
extern void func_80098320(u32);
extern u32 D_8017C858;

/* Schedules the next timer interrupt: the compare value is the current count plus tim.
 * Interrupts are masked while the compare register is written. */
void __osSetTimerIntr(OSTime tim)
{
    OSTime newCompare;
    u32 savedMask;

    savedMask = func_800970B0();
    D_8017C858 = func_80097250();
    newCompare = D_8017C858 + tim;
    func_80098320(newCompare);
    func_800970D0(savedMask);
}
