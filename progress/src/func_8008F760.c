typedef struct Voice8F {
    s32 flags;
    s32 x4;
    u8 pad8[0x2C];
    s32 x34;
    s32 x38;
    u8 pad3C[8];
    s32 x44;
    u8 pad48[0x2C];
    void *x74;
    u8 pad78[8];
    s32 x80;
    u8 pad84[4];
    s32 x88;
    s32 x8C;
    u8 pad90[0x42];
    s8 xD2;
    u8 padD3[0x13C - 0xD3];
} Voice8F;

typedef struct Seq8F {
    u8 pad0[4];
    s32 count;
    u8 pad8[4];
    s32 *xC;
    s32 *x10;
    s32 *x14;
    u8 pad18[0xC];
    s32 x24;
    s32 x28;
} Seq8F;

void func_8008F2A8(Voice8F *);
s32 func_8008F3D8(Seq8F *, s32);
void func_8008F5A0(void *, Seq8F *, s32);
extern Voice8F *D_8017B20C;
extern s32 D_8017B220;
extern s32 D_8017B228;

s32 func_8008F760(Seq8F *arg0) {
    s32 count;
    s32 id;
    s32 i;
    Voice8F *v;

    count = arg0->count;
    if (arg0->x28 == 0) {
        arg0->x28 = 1;
        func_8008F5A0(&arg0->xC, arg0, 7);
        func_8008F5A0(arg0->xC, arg0, count);
        func_8008F5A0(arg0->x10, arg0, count);
        func_8008F5A0(arg0->x14, arg0, count);
    }
    id = D_8017B220++;
    v = &D_8017B20C[func_8008F3D8(arg0, -1)];
    func_8008F2A8(v);
    v->xD2 = 1;
    v->x74 = arg0;
    v->flags |= 3;
    v->x4 = v->x80 = arg0->x24;
    v->x44 = id;
    for (i = 0; i < count; i++) {
        if (arg0->xC[i] != 0) {
            v = &D_8017B20C[func_8008F3D8(arg0, i)];
            func_8008F2A8(v);
            v->xD2 = 1;
            v->x74 = arg0;
            v->flags |= 1;
            v->x38 = v->x8C = arg0->x10[i];
            v->x34 = v->x88 = arg0->x14[i];
            v->x4 = v->x80 = arg0->xC[i];
            v->x44 = id;
        }
    }
    D_8017B228 = 0;
    return id;
}
