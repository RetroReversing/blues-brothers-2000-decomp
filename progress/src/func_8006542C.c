typedef struct ObjL ObjL;
struct ObjL {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    u8 pad14[0x74 - 0x14];
    s32 f74;
    u8 pad78[0x9C - 0x78];
    void *f9C;
    u8 padA0[0xA4 - 0xA0];
    ObjL *fA4;
    u8 padA8[0xC0 - 0xA8];
    s32 fC0;
    u8 padC4[0xD0 - 0xC4];
    s32 fD0;
    u8 padD4[0xDC - 0xD4];
    f32 fDC;
};

void func_800899DC(char *);
void func_80043328(ObjL *, s32, s32);
void func_8004303C(ObjL *);
void func_800433A8(ObjL *, s32, s32);
s32 func_8002D204(s32, s32, s32);
f32 func_8002D340(f32, f32, f32);
void func_8002A360(s32, s32);
s32 func_80043248(ObjL *);
void func_800393F4(void);
extern char D_80008C4C[];
extern s32 D_800B9ECC;

void func_8006542C(ObjL *arg0) {
    ObjL *t;
    s32 done;
    f32 tgt;

    t = arg0->fA4;
    if (t == NULL) {
        func_800899DC(D_80008C4C);
    }
    if (t->fC0 == 1) {
        if (arg0->fD0 != 1) {
            func_80043328(arg0, 1, 0x100);
        }
        func_8004303C(arg0);
    } else if (t->fC0 == 0) {
        if (t->f74 == 0) {
            func_800433A8(arg0, 2, 0x100);
            t->f74 = 1;
        } else {
            arg0->f10 = func_8002D204(0x7FFF, arg0->f10, D_800B9ECC * 100);
            arg0->x = func_8002D340(t->x, arg0->x, 20.0f);
            arg0->y = func_8002D340(t->y + 15.0f, arg0->y, 20.0f);
            arg0->z = func_8002D340(t->z, arg0->z, 20.0f);
            func_8004303C(arg0);
        }
    } else {
        if (t->f74 == 0) {
            func_8002A360(0x19, 0);
            func_80043328(arg0, 0x1A, 0x100);
            t->f74 = 1;
        } else {
            done = func_80043248(arg0);
            tgt = 180.0f;
            if (arg0->fDC > 7.0f) {
                arg0->z = func_8002D340(tgt, arg0->z, D_800B9ECC * 29.0f);
            }
            arg0->y = func_8002D340(t->y, arg0->y, 20.0f);
            if (done != 0) {
                func_800433A8(arg0, 1, 0x100);
                arg0->f9C = func_800393F4;
                arg0->fA4 = NULL;
            }
        }
    }
}
