typedef struct { f32 x, y, z; } Vec3;
typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj72DA4 {
    s32 kind;
    f32 x, y, z;
    s32 angle;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x78 - 0x74];
    s32 unk78;
    u8 pad7C[0x80 - 0x7C];
    s32 unk80;
    u8 pad84[0xA0 - 0x84];
    void (*update)(struct Obj72DA4 *);
    struct Obj72DA4 *parent;
    u8 padA8[0xB8 - 0xA8];
    s32 unkB8;
} Obj72DA4;

s32 randomRange(s32, s32);
void func_8002ADFC(s32, s32, Obj72DA4 *);
s32 tickActorTimer(Obj72DA4 *);
void func_8002DAC8(f32 *, f32 *);
void func_8002DB6C(void *, void *, f32);
void mtxIdentity3(void *);
void mtxTransformVec3(void *, void *, void *, ...);
Obj72DA4 *func_8003B980(Obj72DA4 *);
s32 func_80050144(Obj72DA4 *, s32);
extern s32 D_800B8398[];
extern Obj72DA4 *gCameraTarget;
extern Vec3i gPlatformMaxOffsets[];
extern Vec3i gPlatformMinOffsets[];

void func_80072DA4(Obj72DA4 *arg0) {
    f32 sp10[10];
    f32 sp38[10];
    Vec3 sp60;
    Vec3 sp70;
    Vec3 sp80;
    f32 a;
    f32 d;
    s32 n;
    s32 i;
    Vec3i *p;
    Vec3i *q;

    if (tickActorTimer(arg0) != 0) {
        arg0->unk64 = randomRange(100, 500);
        func_8002ADFC(D_800B8398[arg0->unk78], 3000, arg0);
    }
    if (func_80050144(arg0, arg0->unk70) != 0) {
        if (arg0->parent != NULL) {
            arg0->parent->unk80--;
        }
        arg0->update(arg0);
    }
    mtxIdentity3(sp38);
    a = arg0->angle;
    a *= 6.283185307179586;
    a *= (1.0 / 65536.0);
    func_8002DB6C(sp10, sp38, a);
    i = arg0->unkB8;
    p = &gPlatformMinOffsets[i];
    sp60.x = p->x;
    sp60.y = p->y;
    sp60.z = p->z;
    q = &gPlatformMaxOffsets[i];
    sp70.x = q->x;
    sp70.y = q->y;
    sp70.z = q->z;
    mtxTransformVec3(&sp80, sp10, &sp60, i);
    sp60.x = sp80.x;
    sp60.y = sp80.y;
    sp60.z = sp80.z;
    mtxTransformVec3(&sp80, sp10, &sp70);
    sp70.x = sp80.x;
    sp70.y = sp80.y;
    sp70.z = sp80.z;
    if (sp70.x < sp60.x) {
        func_8002DAC8(&sp70.x, &sp60.x);
    }
    if (sp70.y < sp60.y) {
        func_8002DAC8(&sp70.y, &sp60.y);
    }
    if (sp70.z < sp60.z) {
        func_8002DAC8(&sp70.z, &sp60.z);
    }
    d = gCameraTarget->x - arg0->x;
    n = 0;
    if (d > 0.0f) {
        if (sp70.x < d) {
            n = 1;
        }
    }
    if (d <= 0.0f) {
        if (d < sp60.x) {
            n++;
        }
    }
    d = gCameraTarget->z - arg0->z;
    if (d > 0.0f) {
        if (sp70.z < d) {
            n++;
        }
    }
    if (d <= 0.0f) {
        if (d < sp60.z) {
            n++;
        }
    }
    if (n == 0 && gCameraTarget->y <= arg0->y + (f32)gPlatformMinOffsets[arg0->unkB8].y && gCameraTarget->kind == 3) {
        func_8003B980(gCameraTarget);
    }
}
