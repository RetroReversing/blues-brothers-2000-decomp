typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    u16 pad10;
    u16 rot;
    u8 pad14[0x88];
    void *f9C;
} Obj;
s16 coss(u16);
s16 sins(u16);
Obj *func_8002E374(s32);
void func_80073FC8(void);
extern u8 *D_800B3964;

void func_800773E8(Obj *arg0) {
    s32 in[3];
    s32 out[3];
    Obj *o;
    f32 *m;

    o = func_8002E374(*(s32 *)(D_800B3964 + 0x6C));
    o->x = arg0->x;
    o->y = arg0->y + 200.0f;
    o->z = arg0->z;
    m = *(f32 **)((u8 *)arg0 + 0x8C);
    in[0] = m[12];
    in[1] = m[13];
    in[2] = m[14];
    out[0] = ((in[0] * coss(arg0->rot)) >> 15) + ((in[2] * sins(arg0->rot)) >> 15);
    out[2] = -((in[0] * sins(arg0->rot)) >> 15) + ((in[2] * coss(arg0->rot)) >> 15);
    out[1] = in[1];
    o->x = arg0->x + out[0];
    o->y = arg0->y + out[1];
    o->z = arg0->z + out[2];
    o->f9C = func_80073FC8;
}
