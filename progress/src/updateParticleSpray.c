s16 coss(u16);
s16 sins(u16);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
s32 randomRange(s32, s32);
void *heapAlloc(s32);
s32 func_8002D1A0(void);

typedef struct Particle {
    s32 x, y, z;
    s32 vx, vy, vz;
} Particle;

typedef struct ParticleObj {
    char pad0[0x58];
    s32 drawFlags;
    char pad5C[0x68 - 0x5C];
    s32 x68;
    char pad6C[0x84 - 0x6C];
    s32 particleCount;
    s32 spawnIndex;
    char pad8C[0xC4 - 0x8C];
    Particle *particles;
} ParticleObj;

extern s32 gFrameScale;
extern s32 gStickY;

/* Particle spray effect: allocates and seeds the particles on first use, then each
 * frame integrates their positions and respawns the particle at spawnIndex from the
 * analog stick. spawnIndex advances around a ring of 100 slots. */
void updateParticleSpray(ParticleObj *obj) {
    Particle *p;
    s32 i;
    s32 spd;
    s32 a;
    s32 b;

    if (obj->particles == 0) {
        obj->x68 = 13;
        p = heapAlloc(obj->particleCount * sizeof(Particle));
        obj->particles = p;
        for (i = 0; i < obj->particleCount; i++) {
            p[i].x = randomRange(-1000, 1000);
            p[i].y = randomRange(-1000, 1000);
            p[i].z = randomRange(-1000, 1000);
            p[i].vx = 0;
            p[i].vy = 0;
            p[i].vz = 0;
        }
        obj->drawFlags = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
    }
    p = obj->particles;
    for (i = 0; i < obj->particleCount; i++) {
        p[i].x += (p[i].vx * gFrameScale) / 100;
        p[i].y += (p[i].vy * gFrameScale) / 100;
        p[i].z += (p[i].vz * gFrameScale) / 100;
        if (i == obj->spawnIndex) {
            spd = (gStickY * 3000) / 80;
            a = func_8002D1A0();
            b = randomRange(0x2000, 0x2FA0);
            p[i].vx = (((spd * sins(a)) >> 15) * coss(b)) >> 15;
            p[i].vz = (((spd * coss(a)) >> 15) * coss(b)) >> 15;
            p[i].vy = (spd * sins(b)) >> 15;
            p[i].vy = randomRange(100, 200);
            p[i].vx = 0;
            p[i].vz = 0;
            p[i].y = 10;
            p[i].x = randomRange(-100, 100);
            p[i].z = randomRange(-100, 100);
        }
    }
    if (++obj->spawnIndex >= 100) {
        obj->spawnIndex = 0;
    }
}
