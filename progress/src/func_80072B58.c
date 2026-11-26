typedef struct Obj {
    u8 pad0[8];
    f32 f8;
    u8 padC[0x60];
    s32 f6C;
    s32 f70;
    u8 pad74[8];
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    u8 pad90[0x14];
    s32 fA4;
} Obj;
typedef struct Info {
    u8 pad0[0x58];
    s32 f58;
    s32 f5C;
} Info;
s32 func_80024394(s32, s32);
void func_80034F1C(Obj *);
void func_800723EC(void);
Obj *func_800730E0(Obj *);
extern Obj *D_800B3960;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern Obj *D_800BD06C;
extern Info D_8014A928;

void func_80072B58(Obj *o) {
    s32 i;
    s32 n;
    Obj *c;

    if (o->f7C == 0) {
        o->f7C = 1;
        D_800B3970 = 0x96;
        D_800B3974 = 0xB6;
        D_800B3978 = 0xC6;
        o->f6C = 0;
        func_800723EC();
        o->f8C = 0;
        n = D_8014A928.f5C;
        if (D_8014A928.f58 < n) {
            n = D_8014A928.f58;
        }
        for (i = 0; i < n; i += func_80024394(1, 2)) {
            o->f70 = 0x17;
            c = func_800730E0(o);
            c->fA4 = 0;
            c->f88 = i;
            c->f84 = 0x80;
            o->f70 = 0x16;
            c = func_800730E0(o);
            c->fA4 = 0;
            c->f88 = i;
            c->f84 = 0x80;
        }
    }
    if (1000.0f < D_800BD06C->f8) {
        if (o->f6C == 0) {
            o->f6C = 1;
            D_800B3960->f6C = 2;
            func_80034F1C(D_800B3960);
        }
    } else {
        o->f6C = 0;
    }
}
