void func_80043328(void *, s32, s32);
void actorSetAnim(void *, s32, s32);
s32 func_80075008(void *);
extern s32 D_800B83C8;
extern f32 D_801700D0;

typedef struct {
    u8 pad0[0x34];
    s32 unk34, unk38, unk3C;
    u8 pad40[0x74 - 0x40];
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    u8 pad80[0xAC - 0x80];
    f32 unkAC;
    u8 padB0[4];
    s32 unkB4;
    u8 padB8[4];
    s32 unkBC;
} Obj;

void func_8007ABE0(Obj *arg0) {
    s32 t;

    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        actorSetAnim(arg0, 0x8D, 0x100);
        t = arg0->unk34 * 4.5f;
        arg0->unk74 = 0;
        arg0->unkBC = 0;
        arg0->unkB4 = 0;
        D_800B83C8 = 1;
        arg0->unk34 = t;
        arg0->unk38 = t;
        arg0->unk3C = arg0->unk34;
        arg0->unkAC = 0.011f;
    }
    if (func_80075008(arg0) == 0) {
        if (D_801700D0 < 650.0) {
            func_80043328(arg0, 0x8F, 0x109);
        }
        if (D_801700D0 > 750.0f) {
            func_80043328(arg0, 0x8D, 0x109);
        }
    }
}
