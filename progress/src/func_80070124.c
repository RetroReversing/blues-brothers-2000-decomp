s32 func_80023D58(s32);
void func_8006FABC(void);
void func_8006FD58(void);

typedef struct {
    u8 pad[0x64];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    s32 f90;
    u8 pad94[0x9C - 0x94];
    void *f9C;
    u8 padA0[0xBC - 0xA0];
    s32 fBC;
} ObjE;

typedef struct {
    u8 pad[0x1C];
    s32 f1C;
    s32 f20;
} StateE;

extern ObjE *D_800B3960;
extern s32 D_800B4A84;
extern s32 D_800B81E0[];
extern s32 D_800B81F4;
extern StateE D_800BD0E0;
extern s32 D_800BD100;
extern s32 D_80107040[];
extern ObjE *D_8013FB74;

void func_80070124(ObjE *arg0) {
    ObjE *p;

    if (arg0->f7C == 0) {
        arg0->f64 = 0x64;
        arg0->f68 = 0xF;
        arg0->f6C = 0;
        arg0->f7C = 1;
        arg0->f84 = 0;
        arg0->f88 = 0;
        arg0->f90 = 0;
        if (D_800B4A84 == 2) {
            arg0->fBC = D_800BD100 + 1;
            D_800B3960->f9C = func_8006FD58;
            D_800B3960->f70 = 1;
        } else {
            arg0->fBC = 0;
            D_800B3960->f9C = func_8006FABC;
            D_800B3960->f6C = 1;
        }
        D_800B4A84 = 0;
        D_800B3960->f7C = 0;
        D_800B3960->f74 = 0;
    }
    if (arg0->f90 & 0x2000) {
        if (arg0->fBC != 0) {
            D_800BD0E0.f20 = arg0->fBC - 1;
            D_800BD0E0.f1C = 0;
        } else {
            D_800BD0E0.f20 = 3;
            D_800BD0E0.f1C = 0xB;
        }
        D_8013FB74->f78 = 1;
        arg0->f64 = 0x32;
        arg0->f90 = 0;
        D_800B3960->f74 = 0x32;
        return;
    }
    if (arg0->f90 & 0x1000) {
        p = D_800B3960;
        p->f74 = 0;
        if (arg0->f90 & 0x10) {
            arg0->fBC = 0;
            p->f6C = 1;
            p->f9C = func_8006FABC;
            D_800B81F4 = func_80023D58(D_800B81E0[0]);
        } else {
            if (arg0->f90 & 1) {
                arg0->fBC--;
                if (arg0->fBC <= 0) {
                    arg0->fBC = 1;
                }
            }
            if (arg0->f90 & 2) {
                arg0->fBC++;
                if (arg0->fBC >= 5) {
                    arg0->fBC = 4;
                }
            }
        }
        arg0->f64 = 0x32;
        arg0->f90 = 0;
        D_800B3960->f7C = 0;
        D_80107040[0] = 0;
    }
}
