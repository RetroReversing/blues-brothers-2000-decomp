s32 isObjectInRange(void *, s32);
s32 func_8001F0AC(void *, s32);
void func_8001F230(void *);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void setDrawMode(s32);
void func_80022C2C(void *, f32 *, s32);
void func_8002338C(void *);
void func_80027060(s32, s32, s32, s32);
void setRenderState(s32);
void func_8002DAE0(f32 *, f32 *, f32);
void func_8002DB6C(f32 *, f32 *, f32);
void func_8002DBF8(f32 *, f32 *, f32);
void mtxIdentity3(f32 *);
f32 func_8002DD60(f32);
void func_800479B0(s32);
f32 sinApprox(f32);

typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct Obj {
    char pad0[0x10];
    s32 x10;
    s32 x14;
    s32 x18;
    char pad1C[0x28 - 0x1C];
    f32 x28;
    f32 x2C;
    f32 x30;
    char pad34[0x58 - 0x34];
    s32 x58;
    s32 x5C;
    char pad60[0x68 - 0x60];
    s32 x68;
    char pad6C[0x94 - 0x6C];
    s32 x94;
    char pad98[0xB8 - 0x98];
    s32 xB8;
    char padBC[0xE4 - 0xBC];
    u32 xE4;
    s32 xE8;
    char padEC[0xF0 - 0xEC];
    s32 xF0;
    char padF4[0xF8 - 0xF4];
    s32 xF8;
} Obj;

extern f32 D_80000E50;
extern f64 D_80000E58;
extern s32 D_800AB408[];
extern s32 gCamSpeedScale[];
extern u8 D_800BD114[];
extern s32 D_800F7910[];
extern s32 gObjTriCounts[];
extern u8 D_80177E18[];
#define GP (*(GfxW **)D_80177E18)

/* Draws one object if it is on screen: builds its rotation, sets draw mode and a fade or flash, emits the display-list commands, and counts its triangles. */
s32 drawActorModel(Obj *obj) {
    f32 rotA[10];
    f32 rotB[10];
    f32 cullRadius;
    f32 angX;
    f32 angY;
    f32 angZ;
    s32 visible;
    s32 flashTimer;
    s32 param;

    obj->xF8 &= ~4;
    param = obj->x94;
    if (D_800AB408[0] == 0) {
        visible = isObjectInRange(obj, param);
    } else {
        visible = func_8001F0AC(obj, 0x12C0);
    }
    if (visible == 0) {
        return 0;
    }
    cullRadius = D_800F7910[obj->xB8];
    cullRadius /= sinApprox(D_80000E50);
    cullRadius += obj->x30;
    if (cullRadius < 0.0f) {
        return 0;
    }
    if (func_8002DD60(obj->x28) > cullRadius + cullRadius) {
        return 0;
    }
    if (cullRadius < func_8002DD60(obj->x2C)) {
        return 0;
    }
    func_8001F230(obj);
    if (obj->x5C != 0xFF) {
        s32 drawMode;
        s32 fadeAlpha;
        drawMode = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
        fadeAlpha = obj->x5C;
        obj->x68 = 13;
        setDrawMode(drawMode);
        func_80027060(0xFF, 0xFF, 0xFF, fadeAlpha);
        {
            GfxW *_g = GP++;
            _g->w0 = 0xFCFFFFFF;
            _g->w1 = 0xFFFCF67B;
        }
    } else if (obj->xF0 != 0) {
        obj->x68 = 3;
        setDrawMode(obj->x58);
        func_80027060(0xFF, 0xFF, 0xFF, obj->xF0);
        {
            GfxW *_g = GP++;
            _g->w0 = 0xFC35426A;
            _g->w1 = 0x1184FE7F;
        }
    }
    flashTimer = obj->xF0 - gCamSpeedScale[0] * 8;
    obj->xF0 = flashTimer;
    if (flashTimer <= 0) {
        obj->xF0 = 0;
    }
    angX = obj->x10;
    angX *= D_80000E58;
    angY = obj->x14;
    angY *= D_80000E58;
    angZ = obj->x18;
    angZ *= D_80000E58;
    mtxIdentity3(rotA);
    func_8002DB6C(rotB, rotA, angX);
    func_8002DAE0(rotA, rotB, angY);
    func_8002DBF8(rotB, rotA, angZ);
    func_80022C2C(obj, rotB, 1);
    if (obj->xE8 != 0) {
        func_800479B0(obj->xE8);
    }
    {
        GfxW *_g = GP++;
        _g->w0 = 0xDE000000;
        _g->w1 = obj->xE4;
    }
    {
        GfxW *_g = GP++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    setRenderState(-1);
    *(s32 *)D_800BD114 += gObjTriCounts[obj->xB8];
    if (obj->xF8 & 1) {
        func_8002338C(obj);
    }
    obj->xF8 |= 4;
    return 1;
}
