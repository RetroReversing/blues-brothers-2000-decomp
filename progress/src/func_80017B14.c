typedef struct Obj { char pad0[0x18]; s32 f18; char pad1[0x5C-0x1C]; s32 f5C; char pad2[0x70-0x60]; s32 f70;
 char pad3[0x84-0x74]; s32 f84; s32 f88; char pad4[0xA0-0x8C]; void (*fA0)(struct Obj *); char pad5[0xAC-0xA4];
 s32 fAC; f32 fB0; s32 fB4; } Obj;
void func_8002D9B0(Obj *);
void func_8002D9F8(Obj *);
extern s32 gCamSpeedScale;
void func_80017B14(Obj *o) {
    s32 a; s32 lo; s32 lo2;
    o->fAC = 0;
    o->fB4 = 0;
    o->fB0 = -1000.0f;
    func_8002D9F8(o);
    func_8002D9B0(o);
    lo = gCamSpeedScale * o->f88;
    a = o->f5C - (gCamSpeedScale * 3);
    lo2 = o->f84 * gCamSpeedScale;
    o->f5C = a;
    o->f18 += lo;
    o->f70 += lo2;
    if (a <= 0) {
        o->fA0(o);
    }
}
