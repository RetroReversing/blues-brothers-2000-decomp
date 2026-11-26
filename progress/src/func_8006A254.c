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

extern Actor *D_800BD06C;
extern u8 D_800BCFB8[];
extern s32 D_800B9ECC;
f32 func_8002D340(f32, f32, f32);
void func_8002ADFC(s32, s32, Actor *);

void func_8006A254(Actor *o)
{
    f32 dx;
    f32 dz;
    f32 dist;
    u8 flag;

    dx = o->x - D_800BD06C->x;
    dz = o->z - D_800BD06C->z;
    dist = sqrtf(dx * dx + dz * dz);
    if (dist < 600.0f) {
        if (o->id == 1) {
            if (D_800BCFB8[2] != 0 && D_800BCFB8[3] != 0 && D_800BCFB8[4] != 0 && D_800BCFB8[5] != 0) {
                o->y = func_8002D340(o->ground + 450.0f, o->y, D_800B9ECC * 6);
                if (o->sound == 0) {
                    func_8002ADFC(0x45, 6000, o);
                    o->sound = 1;
                }
            }
        } else if (o->id == 3) {
            if (D_800BCFB8[2] != 0) {
                o->y = func_8002D340(o->ground + 450.0f, o->y, D_800B9ECC * 6);
                if (o->sound == 0) {
                    func_8002ADFC(0x45, 6000, o);
                    o->sound = 1;
                }
            }
        } else if (o->id == 4) {
            if (D_800BCFB8[3] != 0) {
                o->y = func_8002D340(o->ground + 450.0f, o->y, D_800B9ECC * 6);
                if (o->sound == 0) {
                    func_8002ADFC(0x45, 6000, o);
                    o->sound = 1;
                }
            }
        } else if (o->id == 5) {
            if (D_800BCFB8[4] != 0) {
                o->y = func_8002D340(o->ground + 450.0f, o->y, D_800B9ECC * 6);
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
            o->y = func_8002D340(o->ground + 450.0f, o->y, D_800B9ECC * 6);
        }
    } else {
        o->y = func_8002D340(o->ground, o->y, D_800B9ECC * 6);
        if (o->sound != 0) {
            func_8002ADFC(0x45, 6000, o);
            o->sound = 0;
        }
    }
}
