/* identical to func_800511FC in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskStartGo in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskStartGo in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskStartGo in ARMYMEN SARGE 2 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8008D12C in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800B9CEC in ALL STAR TENNIS '99 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800C324C in AIDYN_CHRONICLES (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskStartGo in Shadowman (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskStartGo in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskStartGo in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009CBF0(void);
void func_8009CC10(u32 value);

/* Starts the RSP: waits until it is no longer halted or busy, then writes 0x125 to SP_STATUS. */
void osSpTaskStartGo(void) {
    do {

    } while (func_8009CBF0() != 0);
    func_8009CC10(0x125);
}
