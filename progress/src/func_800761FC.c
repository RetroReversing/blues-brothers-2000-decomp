typedef struct Obj { u8 p0[8]; f32 f8; u8 p1[0x90]; void *f9C; } Obj;
extern s32 func_800141B8();
extern s32 func_80014234();
extern Obj *func_800151B8(s32);
extern Obj *func_80015258(s32);
extern s32 func_8002444C();
extern s32 D_800A9540;
extern s32 D_800BD0E0;
extern s32 D_800BD0F4;
extern s32 D_800BD100;
extern void func_80011A38(void);

void func_800761FC(s32 arg0) {
    s32 var_a0;
    Obj *o;

    if (D_800BD0E0 <= 0) {
        func_800141B8();
    }
    if ((D_800BD0E0 < 2) && (func_8002444C() & 3)) {
        o = func_80015258(arg0);
        o->f8 = o->f8 + 200.0f;
        return;
    }
    var_a0 = 1;
    if (D_800BD100 != 0) {
        var_a0 = func_8002444C(1) & 1;
    }
    if (D_800BD0F4 < D_800A9540) {
        if (var_a0 != 0) {
            o = func_800151B8(arg0);
            o->f9C = func_80011A38;
            o->f8 = o->f8 + 200.0f;
            return;
        }
    }
    if ((func_8002444C(var_a0) & 3) == 3) {
        func_80014234(arg0);
        return;
    }
    func_800141B8(arg0);
}
