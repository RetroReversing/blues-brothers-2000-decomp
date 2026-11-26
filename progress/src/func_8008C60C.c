/* identical to func_800FDFBC in BATTLETANXGA (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_801892B0 in BATMAN BEYOND RETURN (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8007FC2C in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8009868C in ARMYMENAIRCOMBAT (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80067F18 in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in read_be16_field_aa in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* Reads a big-endian u16 from the stream into obj+0xAA, clears obj+0xAC, and returns the stream past the two bytes. */ /* identical to func_8008D4DC in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_8008C60C in V-RALLY (matched), with its names changed by decompdecomp */

unsigned char *func_8008C60C(char *obj, unsigned char *src) { unsigned int b0 = *src++; unsigned int b1 = *src; *(short *)(obj + 180) = 0; *(short *)(obj + 178) = b1 | (b0 << 8); return src + 1; }
