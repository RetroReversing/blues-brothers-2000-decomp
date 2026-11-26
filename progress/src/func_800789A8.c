s32 func_8002444C(void);
void *func_80042F00(s32, s32, s32, s32);
void actorSetAnim(void *, s32, s32);
void func_80050460(void *, void *);
void *func_80076BF0(s32);
void func_800852CC(void *, s32);
void func_80023848(void);
void func_800784C4(void);
void func_800787E8(void);

typedef struct {
    s32 f0;
    u8 pad[0x7C - 4];
    s32 f7C;
    u8 pad80[0x9C - 0x80];
    void *f9C;
    u8 padA0[0xA8 - 0xA0];
    void *fA8;
} ObjC;

extern ObjC *D_800B3964;
extern char D_8014AA68[];
extern s32 D_801700DC;

ObjC *func_800789A8(s32 arg0) {
    ObjC *o;
    ObjC *sub;
    s32 bit;
    s32 id;

    func_80050460(func_800784C4, D_8014AA68 + 3);
    if (D_800B3964->f7C == 0) {
        o = func_80076BF0(arg0);
        o->f9C = func_80023848;
        D_801700DC = func_8002444C();
        return o;
    }
    bit = D_801700DC & 1;
    D_801700DC >>= 1;
    switch (bit) {
    case 0:
        id = 0x4E;
        break;
    case 1:
        id = 0x79;
        break;
    default:
        goto skip;
    }
    o = func_80042F00(id, 0, 0, 0);
skip:
    actorSetAnim(o, 0x11D, 0x100);
    o->f9C = func_800787E8;
    func_800852CC(o, arg0);
    o->f0 = 0x102F;
    sub = func_80042F00(0x69, 0, 0, 0);
    actorSetAnim(sub, 0x120, 0x100);
    o->fA8 = sub;
    return o;
}
