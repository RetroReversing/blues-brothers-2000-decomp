typedef struct {
    s32 type;
    s32 acc;
    s32 n;
    s32 pad;
    u8 b[8];
    s16 h[8];
} Rec;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Info;
typedef struct {
    u8 pad0[0x64];
    s32 timer;
    u8 pad68[0x9C - 0x68];
    void *cb;
    u8 padA0[0xD0 - 0xA0];
    s32 anim;
    u8 padD4[0xDC - 0xD4];
    f32 frame;
} Obj;

s32 func_80024394(s32, s32);
s32 func_8002D5CC(Obj *);
void func_800433A8(Obj *, s32, s32);
s32 func_80082400(void);
s32 func_80082688(s32, s32);
void func_80082F68(s32);
void func_80083354(s32);
void func_80083604(void);
void func_800826B4(Obj *);
extern Info D_800B9000[];
extern s32 D_800B9ECC;
extern s32 D_80171980;
extern s32 D_80171994;
extern Obj *D_801719A8;
extern Obj *D_801719AC;
extern Rec D_801719E0[];

void func_80082990(Obj *o)
{
    s32 snd[2];
    s32 m;
    s32 i;
    s32 any;
    f64 f;

    func_80082400();
    if (D_801719A8->anim == 0x17B) {
        f = *(volatile f32 *)&D_801719A8->frame;
    }
    if (D_801719AC->anim == 0x18B) {
        f = *(volatile f32 *)&D_801719AC->frame;
    }
    D_80171980 += D_800B9ECC;
    m = D_80171980 % 144;
    func_80082F68(0);
    if (D_80171994 != 0) {
        func_80082F68(1);
    } else if (func_8002D5CC(o) != 0) {
        if (func_80024394(0, 100) >= 91) {
            func_80083354(1);
        }
        o->timer = 10;
    }
    if (func_80082688(m, 0x24) == 0) {
        return;
    }
    any = 0;
    for (i = 0; i < 2; i++) {
        if (D_801719E0[i].pad != 0) {
            snd[i] = D_800B9000[D_801719E0[i].type].b;
            if (i != 0) {
                snd[i] += 0x20;
            } else {
                snd[0] += 0x10;
            }
            D_801719E0[i].pad = 0;
            D_801719E0[i].b[0] = 0;
            D_801719E0[i].b[1] = 0;
            D_801719E0[i].b[2] = 0;
            D_801719E0[i].b[3] = 0;
            D_801719E0[i].b[4] = 0;
            D_801719E0[i].b[5] = 0;
            D_801719E0[i].type++;
            if (D_801719E0[i].type >= 12) {
                o->cb = (void *)func_800826B4;
                D_801719E0[i].type = 0;
                o->timer = 100;
            }
            D_801719E0[i].n = D_800B9000[D_801719E0[i].type].a;
            any = 1;
        } else if (i == 0) {
            snd[0] = 0x17B;
        } else {
            snd[i] = 0x18B;
        }
    }
    if (any) {
        func_80083604();
    }
    func_800433A8(D_801719A8, snd[0], 0x100);
    func_800433A8(D_801719AC, snd[1], 0x100);
}
