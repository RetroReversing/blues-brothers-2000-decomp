typedef struct Obj Obj;
struct Obj {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    s32 angle;
    u8 pad14[0x50];
    s32 unk64;
    u8 pad68[0x10];
    s32 unk78;
    u8 pad7C[0x20];
    void (*handler)(Obj *);
    void (*unkA0)(Obj *);
    u8 padA4[0x18];
    s32 unkBC;
    u8 padC0[0x48];
};

typedef struct {
    u8 id;
    u8 dir;
    u8 flags;
    u8 owner;
    s32 dist;
    s32 x;
    s32 y;
    s32 z;
    s32 angle;
} Spawn;

Obj *func_80023088(s32);
Obj *func_800230B0(s32);
Obj *func_800232B4(s32, s32, s32, s32);
void func_8000F670(Obj *);
void func_80039240(Obj *);
void func_800729C4(Obj *);
extern Spawn D_800AA564[];
extern Obj *gCameraTarget;
extern s32 D_800BD274;

s32 func_8001DD94(s32 arg0) {
    Obj *o;
    Obj *end;
    Obj *start;
    Spawn *r;
    Spawn *best;
    s32 bestDist;
    s32 found;
    u8 dir;

    r = D_800AA564;
    found = 0;
    bestDist = 1000;
    best = r;
    dir = 0;
    start = func_80023088(0);
    end = func_800230B0(0);
    for (o = start; o <= end; o++) {
        if (o->type == 0x13C) {
            o->unkA0(o);
        } else if (o->type == 0x100) {
            o->unkA0(o);
        } else if (o->handler == func_800729C4) {
            o->unkA0(o);
        }
    }
    for (;; r++) {
        u8 flags = r->flags;

        if (flags == 0) {
            break;
        }
        if (r->owner != arg0) {
            continue;
        }
        if (flags & 1) {
            if (r->dist < bestDist) {
                bestDist = r->dist;
                best = r;
            }
            if (r->id == D_800BD274) {
                gCameraTarget->x = r->x;
                gCameraTarget->y = r->y;
                gCameraTarget->z = r->z;
                gCameraTarget->angle = r->angle;
                dir = r->dir;
                if (r->flags & 4) {
                    gCameraTarget->handler = func_80039240;
                }
                if (r->flags & 2) {
                    gCameraTarget->handler = func_80039240;
                }
                found = 1;
            }
        }
        if (r->flags & 2) {
            Obj *n = func_800232B4(0x13C, r->x, r->y, r->z);

            n->angle = r->angle;
            n->handler = func_8000F670;
            n->unk78 = r->dist;
            n->unk64 = 100;
            n->unkBC = r->id;
        }
    }
    if (found == 0) {
        r = best;
        gCameraTarget->x = r->x;
        gCameraTarget->y = r->y;
        gCameraTarget->z = r->z;
        gCameraTarget->angle = r->angle;
        dir = r->dir;
        if (r->flags & 4) {
            gCameraTarget->handler = func_80039240;
        }
        if (r->flags & 2) {
            gCameraTarget->handler = func_80039240;
        }
    }
    return dir << 15;
}
