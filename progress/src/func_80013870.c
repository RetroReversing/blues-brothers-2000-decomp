typedef struct { s32 x, y, z; } Vec3i;

extern s32 D_800B4C28;
extern Vec3i D_800BD278;
extern Vec3i D_800BD688;
extern Vec3i D_800F4A00[];
extern Vec3i D_800F6188[];

void func_80013870(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_800B4C28 > arg2 + D_800F6188[arg0].y) {
        D_800B4C28 = arg2 + D_800F6188[arg0].y;
        if (arg2 + D_800F6188[arg0].y < D_800B4C28) {
            D_800B4C28 = arg2 + D_800F6188[arg0].y;
        }
    }
    if (arg1 + D_800F6188[arg0].x < D_800BD278.x) {
        D_800BD278.x = arg1 + D_800F6188[arg0].x;
    }
    if (arg1 + D_800F4A00[arg0].x > D_800BD688.x) {
        D_800BD688.x = arg1 + D_800F4A00[arg0].x;
    }
    if (arg2 + D_800F6188[arg0].y < D_800BD278.y) {
        D_800BD278.y = arg2 + D_800F6188[arg0].y;
    }
    if (D_800BD688.y < arg2 + D_800F4A00[arg0].y) {
        D_800BD688.y = arg2 + D_800F4A00[arg0].y;
    }
    if (arg3 + D_800F6188[arg0].z < D_800BD278.z) {
        D_800BD278.z = arg3 + D_800F6188[arg0].z;
    }
    if (D_800BD688.z < arg3 + D_800F4A00[arg0].z) {
        D_800BD688.z = arg3 + D_800F4A00[arg0].z;
    }
}
