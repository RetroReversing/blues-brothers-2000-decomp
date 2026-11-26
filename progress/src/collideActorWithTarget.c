typedef struct Obj67C6C {
    s32 kind;
    f32 x, y, z;
    u8 pad10[2];
    u16 angle;
    u8 pad14[0x50 - 0x14];
    f32 unk50;
    u8 pad54[0xC0 - 0x54];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
} Obj67C6C;

s16 sins(u16);
s16 coss(u16);
s32 isqrtS32(s32);
void func_8002A360(s32, s32);
void actorSetAnim(Obj67C6C *, s32, s32);
f32 sqrtf(f32);
extern Obj67C6C *gCameraTarget;
extern s32 D_80140240;

/* Collision between an actor and the camera target. If the target is above the actor,
 * a close hit on a flagged actor (kind 0xF7/0xF8) launches the target upward with a
 * bounce animation and sound. Otherwise the target is pushed out to a 400-unit radius
 * around the actor's offset point. */
/* Collision between an actor and the camera target. If the target is above the actor and close to a flagged actor (state 0xF7/0xF8), it bounces the target upward and plays the bounce animation. Otherwise it pushes the target out to a 400-unit radius around the actor. */ s32 collideActorWithTarget(Obj67C6C *actor) {
    s32 dy;
    s32 x;
    s32 z;
    s32 dx2;
    s32 dz2;
    f32 t;
    f32 fx;
    f32 fz;
    f32 d;

    dy = gCameraTarget->y - actor->y;
    if (dy > 0) {
        if (actor->unkD0 == 0xF7 || actor->unkD0 == 0xF8) {
            x = actor->x + (f32)(-(sins(actor->angle) * 250) >> 15);
            z = actor->z + (f32)(-(coss(actor->angle) * 250) >> 15);
            dx2 = gCameraTarget->x - (f32)x;
            dz2 = gCameraTarget->z - (f32)z;
            if (isqrtS32(dx2 * dx2 + dz2 * dz2) < 251) {
                if (gCameraTarget->unkD0 >= 43) {
                    actor->unkC0 |= 4;
                }
                if (gCameraTarget->unk50 < 0.0f && dy < 150) {
                    gCameraTarget->unk50 = (D_80140240 * 3) / 2;
                    t = actor->y + 75.0f;
                    if (gCameraTarget->y < t) {
                        gCameraTarget->y = t;
                    }
                    gCameraTarget->y += 1.0f;
                    actorSetAnim(gCameraTarget, 5, 0x100);
                    func_8002A360(12, 0x80);
                    func_8002A360(8, 2);
                    return 0;
                }
            }
        }
        return 0;
    }
    fx = (actor->x - gCameraTarget->x) + (f32)(-(sins(actor->angle) * 150) >> 15);
    fz = (actor->z - gCameraTarget->z) + (f32)(-(coss(actor->angle) * 150) >> 15);
    d = sqrtf(fx * fx + fz * fz);
    if (d <= 400.0f) {
        gCameraTarget->x += fx * (d - 400.0f) / d;
        gCameraTarget->z += fz * (d - 400.0f) / d;
    }
    return 0;
}
