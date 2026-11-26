typedef struct { f32 x, y, z; } Vec3;
typedef struct Obj349E4 {
    s32 kind;
    f32 x, y, z;
    union { s32 v; struct { u16 hi; u16 lo; } h; } r10;
    union { s32 v; struct { u16 hi; u16 lo; } h; } r14;
    u8 pad18[0x40 - 0x18];
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x6C - 0x4C];
    s32 unk6C;
    u8 pad70[0x74 - 0x70];
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
} Obj349E4;

typedef struct {
    s32 x, y, z;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} State349E4;

s16 sins(u16);
s16 coss(u16);
void func_8001FF64(Obj349E4 *);
s32 func_80024AC4(s32, s32);
s32 func_80024AE8(s32, s32);
s32 func_8002D1C4(s32, s32, s32);
void func_80035A90(Obj349E4 *);
void func_80036CF8(void *, void *, void *, void *);
void func_80048820(void *, void *, s32);
extern Vec3 D_800B4AE4[];
extern s32 D_800B9E88;
extern f32 D_800B9EC4;
extern Obj349E4 *D_800BD06C;
extern State349E4 D_8013FFD8;
extern s32 D_80140030;

void func_800349E4(Obj349E4 *arg0) {
    f32 sp10[4];
    Vec3 d;
    f32 sp30[12];
    Vec3 a;
    Vec3 b;
    u8 sp80[0x90];
    u8 sp110[16];
    u8 sp120[16];

    if (D_800BD06C == NULL) {
        func_8001FF64(arg0);
        return;
    }
    {
        D_8013FFD8.x = arg0->x;
        D_8013FFD8.y = arg0->y;
        D_8013FFD8.z = arg0->z;
        D_8013FFD8.unkC = arg0->r10.v;
        D_8013FFD8.unk10 = arg0->r14.v;
        D_8013FFD8.unk14 = arg0->unk74;
        D_800B9E88 = 100;
        arg0->unk78 += func_80024AC4(arg0->unk7C - arg0->unk78, 3);
        if (arg0->unk78 >= 5001) {
            arg0->unk78 = 5000;
        }
        if (arg0->unk78 < 1000) {
            arg0->unk78 = 1000;
        }
        D_80140030 = func_80024AE8(D_80140030, 1);
        arg0->r10.v = func_8002D1C4(arg0->unk74, arg0->r10.v, 3);
        arg0->r14.v = func_8002D1C4(arg0->unk80, arg0->r14.v, 2);
        d.x = D_800BD06C->x - arg0->unk40;
        d.y = D_800BD06C->y - arg0->unk44;
        d.z = D_800BD06C->z - arg0->unk48;
        d.x *= D_800B4AE4[arg0->unk6C].x * D_800B9EC4;
        d.y *= D_800B4AE4[arg0->unk6C].y * D_800B9EC4;
        d.z *= D_800B4AE4[arg0->unk6C].z * D_800B9EC4;
        arg0->unk40 += d.x;
        arg0->unk44 += d.y;
        arg0->unk48 += d.z;
        arg0->x = arg0->unk40 + ((((-arg0->unk78 * sins(arg0->r10.h.lo)) >> 15) * coss(arg0->r14.h.lo)) >> 15);
        arg0->z = arg0->unk48 + ((((-arg0->unk78 * coss(arg0->r10.h.lo)) >> 15) * coss(arg0->r14.h.lo)) >> 15);
        arg0->y = arg0->unk44 + ((-arg0->unk78 * sins(arg0->r14.h.lo)) >> 15) + 200.0f;
        arg0->x = D_800BD06C->x + ((((-arg0->unk78 * sins(arg0->r10.h.lo)) >> 15) * coss(arg0->r14.h.lo)) >> 15);
        arg0->z = D_800BD06C->z + ((((-arg0->unk78 * coss(arg0->r10.h.lo)) >> 15) * coss(arg0->r14.h.lo)) >> 15);
        arg0->y = D_800BD06C->y + ((-arg0->unk78 * sins(arg0->r14.h.lo)) >> 15) + 200.0f;
        a.x = arg0->x;
        a.y = arg0->y;
        a.z = arg0->z;
        b.x = D_800BD06C->x;
        b.y = D_800BD06C->y + 200.0f;
        b.z = D_800BD06C->z;
        func_80036CF8(sp110, sp120, &a, &b);
        func_80048820(sp110, sp120, 3);
        func_80035A90(arg0);
    }
    func_8001FF64(arg0);
}
