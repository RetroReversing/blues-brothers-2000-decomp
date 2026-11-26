typedef struct Obj {
    u8 pad0[0x74];
    s32 x74;
    u8 pad78[0x90 - 0x78];
    s32 x90;
    u8 pad94[0x9C - 0x94];
    void *x9C;
    void (*xA0)(struct Obj *);
    u8 padA4[4];
    s32 xA8;
} Obj;

extern void func_800698D4(void);
extern void func_80069858(void);
extern void func_80069998(void);
extern void func_80069934(void);
extern void func_80064808(void);
extern Obj *gCameraRig;
extern Obj *D_800B3964;

void func_80069768(Obj *o) {
    switch (o->x90) {
    case 2:
        o->x9C = func_800698D4;
        break;
    case 3:
        o->x9C = func_80069858;
        break;
    case 4:
        o->x9C = func_80069998;
        break;
    case 1:
        o->x9C = func_80069934;
        break;
    default:
        o->xA0(o);
        gCameraRig->xA8 = 0;
        gCameraRig->x9C = func_80064808;
        return;
    }
    D_800B3964->x74 = 0;
}
