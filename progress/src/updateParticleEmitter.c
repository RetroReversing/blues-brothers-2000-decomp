typedef struct Part13A8 {
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vy;
    s32 vz;
} Part13A8;

typedef struct Obj13A8 {
    u8 pad0[0x58];
    s32 c58;
    u8 pad5C[0xC];
    s32 c68;
    u8 pad6C[8];
    s32 grav;
    s32 speed;
    s32 spread;
    s32 dir;
    s32 count;
    s32 next;
    u8 pad8C[0x38];
    Part13A8 *parts;
} Obj13A8;

extern void *heapAlloc(s32);
extern s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 randomRange(s32, s32);
extern s32 func_8002D1A0(void);
extern s32 sins(u16);
extern s32 coss(u16);
extern u8 gFrameScale[];

/* Particle emitter: allocates the particle array on first use, applies gravity and velocity each frame, and respawns particles in a rotating pattern. */ void updateParticleEmitter(Obj13A8 *o) {
    Part13A8 *part;
    Part13A8 *q;
    s32 idx;
    s32 nextIdx;
    s32 launchSpeed;
    u16 pitch;
    u16 yaw;
    s16 sinv;
    s16 cosv;

    if (o->parts == NULL) {
        o->c68 = 13;
        q = o->parts = heapAlloc(o->count * 24);
        for (idx = 0; idx < o->count; idx++) {
            q[idx].x = 0;
            q[idx].y = 0;
            q[idx].z = 0;
            q[idx].vx = 0;
            q[idx].vy = 0;
            q[idx].vz = 0;
        }
        o->c58 = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
    }
    nextIdx = o->next;
    q = o->parts;
    if (nextIdx == o->count) {
        nextIdx = 0;
    }
    for (idx = 0; idx < o->count; idx++) {
        part = &q[idx];
        part->vy -= o->grav * (*(s32 *)gFrameScale) / 100;
        part->x += part->vx * (*(s32 *)gFrameScale) / 100;
        part->z += part->vz * (*(s32 *)gFrameScale) / 100;
        part->y += part->vy * (*(s32 *)gFrameScale) / 100;
        if (idx == o->next) {
            launchSpeed = o->speed + randomRange(0, 100);
            pitch = func_8002D1A0();
            yaw = randomRange(o->dir - 1000, o->dir + 1000);
            sinv = sins(pitch);
            cosv = coss(yaw);
            part->vx = ((launchSpeed * sinv) >> 15) * cosv >> 15;
            sinv = coss(pitch);
            cosv = coss(yaw);
            part->vz = ((launchSpeed * sinv) >> 15) * cosv >> 15;
            sinv = sins(yaw);
            part->y = 10;
            part->vy = (launchSpeed * sinv) >> 15;
            part->x = randomRange(-o->spread, o->spread);
            part->z = randomRange(-o->spread, o->spread);
        }
        if (idx == nextIdx) {
            launchSpeed = o->speed + randomRange(0, 100);
            pitch = func_8002D1A0();
            yaw = randomRange(o->dir - 1000, o->dir + 1000);
            sinv = sins(pitch);
            cosv = coss(yaw);
            part->vx = ((launchSpeed * sinv) >> 15) * cosv >> 15;
            sinv = coss(pitch);
            cosv = coss(yaw);
            part->vz = ((launchSpeed * sinv) >> 15) * cosv >> 15;
            sinv = sins(yaw);
            part->y = 10;
            part->vy = (launchSpeed * sinv) >> 15;
            part->x = randomRange(-o->spread, o->spread);
            part->z = randomRange(-o->spread, o->spread);
        }
    }
    if (o->count >= 91) {
        o->next += 5;
    } else {
        o->next += 2;
    }
    o->next = o->next % o->count;
}
