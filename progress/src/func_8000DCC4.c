typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0xA8];
    s32 fB8;
} Obj;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Rec;
extern Rec gPlatformMaxOffsets[];
extern Rec gPlatformMinOffsets[];

s32 func_8000DCC4(Obj *p, Obj *o) {
    s32 d;

    d = p->x - o->x;
    if (d > 0) {
        if (gPlatformMaxOffsets[o->fB8].a < d) {
            return 0;
        }
    } else if (d < gPlatformMinOffsets[o->fB8].a) {
        return 0;
    }
    d = p->z - o->z;
    if (d > 0) {
        if (gPlatformMaxOffsets[o->fB8].c < d) {
            return 0;
        }
    } else if (d < gPlatformMinOffsets[o->fB8].c) {
        return 0;
    }
    return 1;
}
