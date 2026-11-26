/* adapted from similar verified C in func_8001E8B0 in BLUES BROTHERS 2000 (matched), with its names changed by decompdecomp */
typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
} Obj;
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Pt;
extern Obj *gCameraTarget;
extern s32 gSplinePointCount[];
extern Pt *gSplineSrcPoints[];

s32 func_8001E994(void) {
    s32 i;
    s32 j;
    s32 px;
    s32 pz;
    s32 dx;
    s32 dz;
    Pt *p;

    px = gCameraTarget->x;
    pz = gCameraTarget->z;
    for (i = 29; i >= 0; i--) {
        p = gSplineSrcPoints[i];
        if (p != NULL) {
            for (j = 0; j < gSplinePointCount[i]; j++, p++) {
                dx = p->x - px;
                dz = p->z - pz;
                if (dx * dx + dz * dz < 810000) {
                    return 1;
                }
            }
        } else {
            return 0;
        }
    }
    return 0;
}

