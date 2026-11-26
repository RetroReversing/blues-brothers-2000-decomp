typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u16 unk10;
    u16 unk12;
} Obj;

s32 func_80024B0C(s32);
s32 func_80025100(s32, s32);
void func_8002A360(s32, s32);
s16 sins(u16);
extern Obj *D_800B3960;
extern Obj *D_800BD06C;
extern s32 D_800B2B60[];

void func_8002ADFC(s32 ch, s32 range, Obj *src) {
    s32 ang;
    s32 dist;
    s32 dx, dy, dz;
    s32 pan;
    s32 vol;

    ang = func_80025100(D_800B3960->x - src->x, D_800B3960->z - src->z);
    dx = D_800BD06C->x - src->x;
    dy = D_800BD06C->y - src->y;
    dz = D_800BD06C->z - src->z;
    dist = func_80024B0C(dx * dx + dy * dy + dz * dz);
    range = range * 5 / 4;
    if (dist < range) {
        pan = 0x80 - (sins(D_800B3960->unk12 - ang) >> 8);
        if (pan < 0) {
            pan = 0;
        }
        if (pan > 256) {
            pan = 256;
        }
        vol = ((range - dist) << 7) / range;
        if (vol < 0) {
            vol = 0;
        }
        if (D_800B2B60[ch] < vol) {
            vol = D_800B2B60[ch];
        }
        func_8002A360(0xB, vol);
        func_8002A360(0xC, pan);
        func_8002A360(7, ch);
    }
}
