typedef struct { f32 sx, sy, sz, rx, ry, rz, tx, ty, tz; } Xf;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[0x10]; f32 f10, f14, f18, f1C, f20, f24; } Joint;
typedef struct { u8 pad0[0xC]; s16 count; u8 padE[0x14 - 0xE]; Joint *joints; u8 pad18[0x24 - 0x18]; f32 rate; } Anim;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    Anim *anim;
    f32 step;
    s32 count;
    s32 unk1C;
    Xf *buf20;
    s32 unk24;
    s32 unk28;
    Xf *buf2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    V3 *buf44;
    Xf *buf48;
    Xf *buf4C;
    Xf *buf50;
    Xf *buf54;
    s32 unk58;
    s32 unk5C;
} Player;

void *heapAlloc(s32);

extern f32 D_800076B8;
void func_8003E7E4(Player *p, Anim *a) {
    s32 i;
    s32 n;
    s32 m;
    f32 one;

    p->unk0 = 0;
    p->unk4 = 0;
    p->anim = a;
    p->step = 1.0 / a->rate;
    /*__repair_chain_scope*/do { n = a->count;
    p->unk8 = 1; } while (0);
    p->unkC = 9;
    p->unk1C = 0;
    p->unk24 = 0;
    p->unk28 = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk38 = 0;
    p->unk3C = 0;
    p->unk40 = 0;
    p->unk5C = -1;
    p->unk58 = -1;
    /*__repair_chain_scope*/do { p->count = n; } while (0);
    m = n;
    p->buf20 = heapAlloc(m * sizeof(Xf) + m * sizeof(Xf) + m * sizeof(V3) + m * sizeof(Xf) + m * sizeof(Xf) + m * sizeof(Xf) + m * sizeof(Xf));
    p->buf2C = p->buf20 + p->count;
    p->buf44 = (V3 *)(p->buf2C + p->count);
    p->buf48 = (Xf *)(p->buf44 + p->count);
    p->buf4C = p->buf48 + p->count;
    p->buf50 = p->buf4C + p->count;
    p->buf54 = p->buf50 + p->count;
    i = 0;
    if (i < p->count) {
        one = D_800076B8;
        m = 0;
        do {
        p->buf20[i].sx = p->buf20[i].sy = p->buf20[i].sz = one;
        p->buf20[i].rx = ((Joint *)(m + (s32)p->anim->joints))->f1C;
        p->buf20[i].ry = ((Joint *)(m + (s32)p->anim->joints))->f20;
        p->buf20[i].rz = ((Joint *)(m + (s32)p->anim->joints))->f24;
        p->buf20[i].tx = ((Joint *)(m + (s32)p->anim->joints))->f10;
        p->buf20[i].ty = ((Joint *)(m + (s32)p->anim->joints))->f14;
        p->buf20[i].tz = ((Joint *)(m + (s32)p->anim->joints))->f18;
            i++;
            m += sizeof(Joint);
        } while (i < p->count);
    }
}


