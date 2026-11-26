typedef struct { s32 x, y, z; } Vec3i;

extern s32 D_800B4C28;
extern Vec3i D_800BD278;
extern Vec3i D_800BD688;
extern Vec3i gPlatformMaxOffsets[];
extern Vec3i gPlatformMinOffsets[];

void func_80013870(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_800B4C28 > arg2 + gPlatformMinOffsets[arg0].y) {
        D_800B4C28 = arg2 + gPlatformMinOffsets[arg0].y;
        if (arg2 + gPlatformMinOffsets[arg0].y < D_800B4C28) {
            D_800B4C28 = arg2 + gPlatformMinOffsets[arg0].y;
        }
    }
    if (arg1 + gPlatformMinOffsets[arg0].x < D_800BD278.x) {
        D_800BD278.x = arg1 + gPlatformMinOffsets[arg0].x;
    }
    if (arg1 + gPlatformMaxOffsets[arg0].x > D_800BD688.x) {
        D_800BD688.x = arg1 + gPlatformMaxOffsets[arg0].x;
    }
    if (arg2 + gPlatformMinOffsets[arg0].y < D_800BD278.y) {
        D_800BD278.y = arg2 + gPlatformMinOffsets[arg0].y;
    }
    if (D_800BD688.y < arg2 + gPlatformMaxOffsets[arg0].y) {
        D_800BD688.y = arg2 + gPlatformMaxOffsets[arg0].y;
    }
    if (arg3 + gPlatformMinOffsets[arg0].z < D_800BD278.z) {
        D_800BD278.z = arg3 + gPlatformMinOffsets[arg0].z;
    }
    if (D_800BD688.z < arg3 + gPlatformMaxOffsets[arg0].z) {
        D_800BD688.z = arg3 + gPlatformMaxOffsets[arg0].z;
    }
}
