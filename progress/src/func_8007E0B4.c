typedef struct Obj {
    u8 pad0[0x68];
    s32 f68;
    u8 pad6C[0x30];
    void *f9C;
    u8 padA0[8];
    struct Obj *fA8;
    u8 padAC[0x14];
    s32 fC0;
    u8 padC4[0x18];
    f32 fDC;
} Obj;
void func_8001B990(s32, s32);
void func_80033DC4(Obj *);
void animStepKeys(Obj *);
extern Obj *D_800B3960;
extern Obj *D_800B3964;
extern char func_80023078[];
void func_800340B4(void);

void func_8007E0B4(Obj *o) {
    f32 x = o->fDC;

    if (x < 110.0f || 122.0f < x) {
        animStepKeys(o);
        animStepKeys(o->fA8);
        return;
    }
    if (D_800B3960->f9C != func_800340B4) {
        func_80033DC4(D_800B3960);
        D_800B3960->f9C = func_800340B4;
        D_800B3960->fC0 = 0;
        D_800B3964->f9C = func_80023078 + 8;
        D_800B3964->fA8 = 0;
        func_8001B990(0x200, 0x26);
        return;
    }
    o->f9C = func_80023078 + 8;
    o->f68 = -1;
    o->fA8->f9C = func_80023078 + 8;
    o->fA8->f68 = -1;
}
