s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_800BD694;
void func_8000DEB4(void);
void func_8002F604(void);

typedef struct {
    u8 pad0[0x58];
    s32 unk58, unk5C, unk60, unk64, unk68;
    u8 pad6C[4];
    s32 unk70, unk74, unk78, unk7C;
    u8 pad80[0x98 - 0x80];
    void *unk98;
    void *unk9C;
} Obj;
Obj *func_800232B4(s32, s32, s32, s32);

Obj *func_8000DF10(f32 *pos) {
    Obj *p;
    s32 g;

    p = func_800232B4(0x101, pos[1], pos[2], pos[3]);
g = D_800BD694;
p->unk64 = 50;
p->unk98 = func_8002F604;
p->unk9C = func_8000DEB4;
p->unk70 = 50;
p->unk74 = 0;
    p->unk78 = 0xFFFFFF;
    p->unk7C = 0;
    p->unk60 = g;
    p->unk58 = func_800221C0(0, 1, 4, 3, 0, 0, 2, 0);
    p->unk68 = 14;
    p->unk5C = 0xFF;
    return p;
}

