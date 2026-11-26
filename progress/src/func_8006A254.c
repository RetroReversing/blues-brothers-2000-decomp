typedef struct {
    s32 state;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x44 - 0x10];
    f32 ground;
    u8 pad48[0x70 - 0x48];
    s32 id;
    u8 pad74[0x90 - 0x74];
    s32 sound;
} Actor;

extern Actor *gCameraTarget;
extern u8 D_800BCFB8[];
extern s32 gCamSpeedScale;
f32 approachF32(f32, f32, f32);
void func_8002ADFC(s32, s32, Actor *);

void func_8006A254(Actor *o)
{
    f32 dx;
    f32 dz;
    f32 dist;
    u8 flag;

    dx = o->x - gCameraTarget->x;
    dz = o->z - gCameraTarget->z;
    dist = sqrtf(dx * dx + dz * dz);
    if (dist < 600.0f) {
        if (o->id == 1) {
            if (D_800BCFB8[2] != 0 && D_800BCFB8[3] != 0 && D_800BCFB8[4] != 0 && D_800BCFB8[5] != 0) {
                o->y = approachF32(o->ground + 450.0f, o->y, gCamSpeedScale * 6);
                if (o->sound == 0) {
                    func_8002ADFC(0x45, 6000, o);
                    o->sound = 1;
                }
            }
        } else if (o->id == 3) {
            if (D_800BCFB8[2] != 0) {
                o->y = approachF32(o->ground + 450.0f, o->y, gCamSpeedScale * 6);
                if (o->sound == 0) {
                    func_8002ADFC(0x45, 6000, o);
                    o->sound = 1;
                }
            }
        } else if (o->id == 4) {
            if (D_800BCFB8[3] != 0) {
                o->y = approachF32(o->ground + 450.0f, o->y, gCamSpeedScale * 6);
                if (o->sound == 0) {
                    func_8002ADFC(0x45, 6000, o);
                    o->sound = 1;
                }
            }
        } else if (o->id == 5) {
            if (D_800BCFB8[4] != 0) {
                o->y = approachF32(o->ground + 450.0f, o->y, gCamSpeedScale * 6);
                if (o->sound == 0) {
                    func_8002ADFC(0x45, 6000, o);
                    o->sound = 1;
                }
            }
        } else {
            if (o->sound == 0) {
                func_8002ADFC(0x45, 6000, o);
                o->sound = 1;
            }
            o->y = approachF32(o->ground + 450.0f, o->y, gCamSpeedScale * 6);
        }
    } else {
        o->y = approachF32(o->ground, o->y, gCamSpeedScale * 6);
        if (o->sound != 0) {
            func_8002ADFC(0x45, 6000, o);
            o->sound = 0;
        }
    }
}
