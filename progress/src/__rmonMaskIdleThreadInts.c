OSThread *func_800A41F0(void);

void __rmonMaskIdleThreadInts(void) {
    register OSThread *tptr = func_800A41F0();

    while (tptr->priority != -1) {
        if (tptr->priority == 0) {
            tptr->context.sr &= 0xFFFF00FE;
            tptr->context.sr |= 0x6C01;
            break;
        }
        tptr = tptr->tlnext;
    }
}

