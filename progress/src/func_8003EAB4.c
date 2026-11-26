typedef struct Hdr {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 b7;
} Hdr;

typedef struct Ent {
    s32 a;
    s32 b;
    s32 c;
} Ent;

typedef struct Dec {
    Hdr *f0;
    void *f4;
    s32 f8;
    s32 fC;
    u8 pad10[0x18 - 0x10];
    s32 f18;
    s32 f1C;
    u8 pad20[0x30 - 0x20];
    u8 *f30;
    s32 f34;
    u8 *f38;
    s32 f3C;
    u8 pad40[0x44 - 0x40];
    Ent *f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
} Dec;

void func_8003E780(char *, ...);
void func_80026C04(void *, s32, s32);
void func_8003F2A4(Dec *);
void animSampleKeys(Dec *, s32);
extern char D_800076C8[];
extern char D_800076FC[];
extern u8 D_800B5DE0[];

void func_8003EAB4(Dec *arg0, Hdr *hdr) {
    s32 unk;
    s32 i;
    u32 v;
    s32 b;

    if (hdr->h0 != 0x100) {
        func_8003E780(D_800076C8, hdr->h0 >> 8, hdr->h0 & 0xFF, 1, 0);
    }
    if (hdr->h4 != arg0->f18) {
        func_8003E780(D_800076FC, hdr->h4, arg0->f18, unk);
    }
    arg0->f0 = hdr;
    if (hdr->b7 & 1) {
        arg0->f4 = (u8 *)hdr + 8;
        arg0->f30 = (u8 *)hdr + 0x10;
    } else {
        arg0->f4 = D_800B5DE0;
        arg0->f30 = (u8 *)hdr + 8;
    }
    arg0->f8 = (hdr->b6 & 0xF) + 1;
    arg0->fC = (hdr->b6 >> 4) + 1;
    arg0->f1C = 0;
    arg0->f34 = 0;
    func_80026C04(arg0->f44, 0, arg0->f18 * sizeof(Ent));
    for (i = 0; i < arg0->f18; i++) {
        if (arg0->f34 < 3) {
            v = (arg0->f30[0] >> arg0->f34) & 0x3F;
        } else {
            v = ((arg0->f30[0] >> arg0->f34) | (arg0->f30[1] << (8 - arg0->f34))) & 0x3F;
        }
        b = arg0->f34;
        arg0->f34 = b + 6;
        if (arg0->f34 >= 8) {
            arg0->f34 = b - 2;
            arg0->f30++;
        }
        arg0->f44[i].a = v >> 5;
        arg0->f44[i].b = (v >> 4) & 1;
        arg0->f44[i].c = v & 0xF;
        if ((v & 0xF) == 0xF) {
            arg0->f44[i].c = 0x11;
        }
    }
    arg0->f58 = -1;
    arg0->f5C = -1;
    arg0->f38 = arg0->f30;
    arg0->f3C = arg0->f34;
    func_8003F2A4(arg0);
    animSampleKeys(arg0, 0);
}
