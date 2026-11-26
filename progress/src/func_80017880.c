typedef struct Obj Obj;
struct Obj {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    s32 angle;
    u8 pad14[0x20];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x18];
    s32 unk58;
    u8 pad5C[8];
    s32 unk64;
    u8 pad68[0x14];
    s32 unk7C;
    u8 pad80[0x14];
    s32 unk94;
    u8 pad98[4];
    void (*handler)(Obj *);
    u8 padA0[0x18];
    s32 unkB8;
    u8 padBC[0x28];
    s32 unkE4;
    u8 padE8[8];
    s32 unkF0;
    u8 padF4[4];
    s32 unkF8;
};
typedef struct {
    s32 unk0;
    s32 count[7];
    s32 index;
} Stats;

s16 sins(u16);
s16 coss(u16);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80023E3C(s32);
s32 func_8002D5CC(Obj *);
f32 func_8002DD60(f32);
Obj *func_80015258(Obj *);
void func_80014C34(Obj *);
void func_80017710(Obj *);
void func_8002AD9C(void);
void func_8000C5B4(void);
extern Obj *D_800BD06C;
extern Stats D_800BD0E0;
extern s32 D_800B9EA4;
extern s32 D_800B9ECC;

void func_80017880(Obj *arg0) {
    f32 dx;
    f32 dy;
    f32 dz;

    arg0->unkF8 |= 1;
    if (arg0->unk7C == 0) {
        arg0->unk58 = func_800221C0(1, 1, 0, 3, 0, 0, 1, 0);
        arg0->unkB8 = 0x95;
        arg0->unkE4 = func_80023E3C(0x95);
        arg0->unk94 /= 4;
        arg0->unk7C = 1;
        arg0->type = 0x101;
    }
    if (func_8002D5CC(arg0) == 0) {
        return;
    }
    arg0->unk64 = 0;
    dx = arg0->x - D_800BD06C->x;
    dz = arg0->z - D_800BD06C->z;
    dy = arg0->y - D_800BD06C->y;
    if (func_8002DD60(dx) < 180.0f && func_8002DD60(dy) < 360.0f && func_8002DD60(dz) < 180.0f) {
        D_800BD0E0.count[D_800BD0E0.index]++;
        if (D_800BD0E0.count[D_800BD0E0.index] % 100 == 0) {
            func_80015258(D_800BD06C)->handler = func_80014C34;
        }
        arg0->unkF0 = 0xFF;
        arg0->handler = func_80017710;
        func_8002AD9C();
        func_8000C5B4();
        return;
    }
    arg0->angle += D_800B9ECC << 9;
    arg0->unk38 = (coss((D_800B9EA4 * 2000) & 0xFFF0) >> 11) + 0x100;
    arg0->unk3C = (sins((D_800B9EA4 * 2000) & 0xFFF0) >> 11) + 0x100;
    arg0->unk34 = (sins((D_800B9EA4 * 2000) & 0xFFF0) >> 11) + 0x100;
}
