void func_8002444C(void);
void func_8002D620(void *);
s32 func_80043248(void *);
void func_80043328(void *, s32, s32);
s32 func_8007756C(void *);
s32 func_800776D0(void *);
s32 func_80077788(void *);
s32 func_800778F4(void *);
s32 func_80077924(void *);
s32 func_80077964(void *);

typedef struct ObjI {
    u8 pad[0x64];
    s32 f64;
    u8 pad68[0x74 - 0x68];
    s32 f74;
    u32 f78;
    s32 f7C;
    u8 pad80[0x88 - 0x80];
    s32 f88;
    s32 f8C;
    s32 f90;
    u8 pad94[0xBC - 0x94];
    s32 fBC;
    u8 padC0[0xD8 - 0xC0];
    s32 (*fD8)(struct ObjI *);
} ObjI;

extern ObjI *D_800B3964;

void func_800779F8(ObjI *arg0) {
    s32 r;

    r = 0;
    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        arg0->f78 = 4;
        arg0->fD8 = func_80077924;
        arg0->fBC = 0;
        arg0->f64 = 0x12C;
        arg0->f90 = 0;
        func_8002D620(arg0);
    }
    if (arg0->fD8 != NULL) {
        r = arg0->fD8(arg0);
    }
    if (D_800B3964->f88 == 1) {
        r++;
    }
    if (r != 0) {
        arg0->f88 = 0;
        if (D_800B3964->f88 != 0) {
            D_800B3964->f88 = 0;
            arg0->f78 = 2;
            arg0->fD8 = func_80043248;
            arg0->fBC++;
        } else {
            switch (arg0->f78) {
            case 2:
            case 5:
                D_800B3964->f8C = 1;
            case 0:
            case 6:
                arg0->f78 = 1;
                arg0->fD8 = func_8007756C;
                break;
            case 1:
                if (r == 2) {
                    arg0->f78 = 6;
                    arg0->fD8 = func_800776D0;
                } else if (r == 3) {
                    arg0->f78 = 5;
                    arg0->fD8 = func_80077964;
                    arg0->f78 = 6;
                    arg0->fD8 = func_800776D0;
                } else {
                    func_8002444C();
                    arg0->f78 = 0;
                    arg0->fD8 = func_800778F4;
                }
                break;
            case 4:
                arg0->fD8 = func_80077788;
                arg0->f78 = 5;
                break;
            }
        }
        func_80043328(arg0, arg0->f74 + arg0->f78, 0x100);
    }
}
