/* identical to guLookAtReflectMtx in ARMYMEN SARGE 2 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800BA108 in AIDYN_CHRONICLES (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80085458 in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to guLookAtReflectMtx in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800944E0(void *a0, s32 a1, s32 a2, s32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8, f32 a9, f32 a10);
s32 func_80095530(void *a0, s32 a1);

/* Builds a reflection look-at matrix in a float temp, then converts it to the fixed-point Mtx at mtx. */
void guLookAtReflectMtx(s32 mtx, s32 lookAt, s32 a2, s32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8, f32 a9, f32 a10) {
    s32 buf[16];

    func_800944E0(buf, lookAt, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    func_80095530(buf, mtx);
}
