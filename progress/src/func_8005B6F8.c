typedef struct Obj {
    s32 type;
    f32 x, y, z;
    u8 pad10[0x54 - 0x10];
    s32 unk54;
    u8 pad58[0x64 - 0x58];
    s32 unk64;
    u8 pad68[0x7C - 0x68];
    s32 unk7C;
    u8 pad80[0x84 - 0x80];
    s32 unk84;
    u8 pad88[0xC0 - 0x88];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    void *unkD8;
    u8 padDC[0xF0 - 0xDC];
    s32 unkF0;
    u8 padF4[0x108 - 0xF4];
} Obj;

Obj *getObjPoolStart(s32);
Obj *getObjPoolEnd(s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
void func_8002D3E4(Obj *, s32);
f32 func_8002DD60(f32);
void func_8003BF98(Obj *);
void func_80043328(Obj *, s32, s32);
void func_8005B218(Obj *);
extern Obj *gCameraTarget;
void func_8005B968(void);
void func_8005BA74(void);

s32 func_8005B6F8(Obj *arg0) {
    Obj *o;
    Obj *end;
    Obj *start;
    f32 dy;
    f32 dx;
    s32 flag;

    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        arg0->unk64 = 700;
        dx = gCameraTarget->x - arg0->x;
        if (0.0f < dx) {
            if (arg0->unkD0 != 0xCC) {
                func_80043328(arg0, 0xCC, 0x100);
            }
        } else {
            if (arg0->unkD0 != 0xCD) {
                func_80043328(arg0, 0xCD, 0x100);
            }
        }
    }
    func_8002D3E4(arg0, 450);
    arg0->unk54 = 0;
    func_8005B218(arg0);
    if (arg0->unk84 != 0) {
        if (arg0->unkD0 == 0xCC) {
            func_80043328(arg0, 0xCD, 0x180);
        } else {
            func_80043328(arg0, 0xCC, 0x180);
        }
    }
    start = getObjPoolStart(0);
    end = getObjPoolEnd(0);
    for (o = start; o <= end; o++) {
        flag = 0;
        if (o->type == 0x129) {
            flag = o->unkC0 != 0x29A;
        }
        if (o->type == 0x100D || flag) {
            dx = o->x - arg0->x;
            dy = o->y - arg0->y;
            if (func_8002DD60(dx) < 250.0f && func_8002DD60(dy) < 500.0f) {
                func_8002D3E4(arg0, 0);
                arg0->unkD8 = func_8005B968;
                arg0->unk7C = 0;
                return;
            }
        }
    }
    if (arg0->unkC0 != 0) {
        arg0->unk7C = 0;
        if (arg0->unkC0 & 1) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xAD);
            func_8002D124();
            func_8003BF98(gCameraTarget);
            arg0->unkD8 = func_8005B968;
            func_8002D3E4(arg0, 0);
        } else {
            arg0->unkD8 = func_8005BA74;
            arg0->unkF0 = 0xFF;
        }
    }
}
