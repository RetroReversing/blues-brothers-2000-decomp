typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u16 unk10;
    u16 unk12;
} Obj;

typedef struct {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x64 - 0x10];
    s32 unk64;
    s32 unk68;
    u8 pad6C[0x70 - 0x6C];
    s32 unk70;
    s32 ch;
    s32 range;
    s32 active;
    u8 pad80[0x84 - 0x80];
    s32 unk84;
    s32 unk88;
    s32 pan;
    s32 vol;
    s32 unk94;
    u8 pad98[0xA0 - 0x98];
    void *cb;
} Snd;

s32 func_80024B0C(s32);
s32 func_80025100(s32, s32);
void func_8002A360(s32, void *);
s16 sins(u16);
void func_8002AFC0(void *);
extern Obj *D_800B3960;
extern Obj *D_800BD06C;
extern s32 D_800B2B60[];

void func_8002AFFC(Snd *o)
{
    s32 ang;
    s32 dist;
    s32 dx, dy, dz;
    s32 pan;
    s32 vol;
    s32 ch;
    s32 t;

    o->unk68 = -1;
    o->cb = (void *)func_8002AFC0;
    ang = func_80025100(D_800B3960->x - o->x, D_800B3960->z - o->z);
    dx = D_800BD06C->x - o->x;
    dy = D_800BD06C->y - o->y;
    dz = D_800BD06C->z - o->z;
    dist = func_80024B0C(dx * dx + dy * dy + dz * dz);
    if (dist < o->range) {
        o->active = 1;
        pan = 0x80 - (sins(D_800B3960->unk12 - ang) >> 8);
        if (pan < 0) {
            pan = 0;
        }
        if (pan > 256) {
            pan = 256;
        }
        vol = ((o->range - dist) << 7) / o->range;
        ch = o->ch;
        o->unk88 = 0;
        o->pan = pan;
        o->unk94 = ch;
        o->unk84 = 0x80 - vol;
        o->vol = ((o->range - dist) << 7) / o->range;
        t = o->vol;
        t = D_800B2B60[ch] < t;
        if (t) {
            o->vol = D_800B2B60[ch];
        }
        func_8002A360(0x11, o);
    } else if (o->active != 0) {
        o->unk94 = -1;
        t = o->unk70 * 100;
        o->unk64 = t;
        func_8002A360(0x11, o);
        o->active = 0;
    }
}
