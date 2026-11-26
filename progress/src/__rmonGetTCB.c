OSThread *func_800A41F0(void);

RmonThreadNode *__rmonGetTCB(s32 threadNumber) {
    register OSThread *tptr = func_800A41F0();

    if (threadNumber < 1) {
        return NULL;
    }

    while (tptr->priority != -1) {
        if (tptr->id == threadNumber) {
            return (RmonThreadNode *)tptr;
        }
        tptr = tptr->tlnext;
    }

    return NULL;
}

