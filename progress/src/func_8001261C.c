s32 tickActorTimer(void *);
void func_8002DA80(void);
extern f32 D_80000798;
extern s32 D_800BD090[];

typedef struct Obj12 {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ f32 y;
    /* 0x0C */ u8 pad1[0x18 - 0xC];
    /* 0x18 */ s32 u18;
    /* 0x1C */ u8 pad2[0x4C - 0x1C];
    /* 0x4C */ f32 sx;
    /* 0x50 */ f32 u50;
    /* 0x54 */ f32 sz;
    /* 0x58 */ u8 pad3[0x60 - 0x58];
    /* 0x60 */ s32 u60;
    /* 0x64 */ u8 pad4[0x70 - 0x64];
    /* 0x70 */ s32 u70;
    /* 0x74 */ u8 pad5[0x80 - 0x74];
    /* 0x80 */ s32 frame;
    /* 0x84 */ s32 timer;
    /* 0x88 */ u8 pad6[0xA0 - 0x88];
    /* 0xA0 */ void (*fn)(struct Obj12 *);
} Obj12;

void func_8001261C(Obj12 *arg0) {
    s32 f;

    arg0->u18 += 0x100;
    arg0->sx = (arg0->sx * 69.0f) / 100.0f;
    arg0->sz = (arg0->sz * 69.0f) / 100.0f;
    func_8002DA80();
    f = arg0->frame;
    arg0->u70++;
    arg0->timer--;
    if (arg0->timer <= 0) {
        arg0->timer = 2;
        arg0->frame++;
    }
    if (f < 0) {
        f = 0;
    }
    if (f >= 9) {
        f = 8;
    }
    arg0->u60 = D_800BD090[f];
    arg0->y += 2.0f;
    if (arg0->frame >= 11 || tickActorTimer(arg0) != 0) {
        arg0->fn(arg0);
    }
}
