extern s32 D_800B9ECC;
void func_800462A0(void *);

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x1C];
    s32 unk5C;
    u8 pad60[0x3C];
    void (*unk9C)(void *);
} Obj;

void func_8005FC64(Obj *arg0) {
    s32 i;
    s32 t;
    s32 u;

    arg0->unk5C -= D_800B9ECC * 5;
    for (i = 0; i < D_800B9ECC; i++) {
        arg0->unk34 *= 0x101;
        arg0->unk3C *= 0x101;
        arg0->unk38 *= 0xFE;
        arg0->unk34 >>= 8;
        arg0->unk38 >>= 8;
        arg0->unk3C >>= 8;
    }
    if (arg0->unk5C <= 0) {
        arg0->unk9C = func_800462A0;
    }
}
