s32 approachS32(s32, s32, s32);
s32 tickActorTimer(void *);
void animStepKeys(void *);
void func_80058F74(void *, void *);
extern f32 D_800B9EC4;
extern s32 gCamSpeedScale;
void func_800548C0(void *);

typedef struct {
    u8 pad0[8];
    f32 y;          /* 0x08 */
    u8 padC[4];
    s32 unk10;      /* 0x10 */
    s32 unk14;      /* 0x14 */
    u8 pad18[0x5C - 0x18];
    s32 unk5C;      /* 0x5C */
    u8 pad60[4];
    s32 unk64;      /* 0x64 */
    u8 pad68[8];
    s32 unk70;      /* 0x70 */
    s32 unk74;      /* 0x74 */
    u8 pad78[4];
    s32 unk7C;      /* 0x7C */
} Obj;

void func_80055130(Obj *arg0) {
    s32 u;
    s32 v;
    s32 k;

    if (arg0->unk7C != 0) {
        arg0->unk74 = 0;
        arg0->unk7C = 0;
        arg0->unk64 = 200;
        return;
    }
    arg0->y += D_800B9EC4 * 100.0f;
    arg0->unk10 += arg0->unk70;
    arg0->unk70 += gCamSpeedScale << 7;
    animStepKeys(arg0);
    arg0->unk5C = approachS32(0x80, arg0->unk5C, gCamSpeedScale * 2);
    if (tickActorTimer(arg0) != 0) {
        arg0->unk14 = 0;
        func_80058F74(arg0, func_800548C0);
    }
}

