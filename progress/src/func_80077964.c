s32 findActor(s32, s32);
s32 func_80023DBC(s32);
void animStepKeys(void *);
void func_80052A5C(s32);
s32 func_80052A68(s32, s32 *);
s32 func_80052B24(s32, s32 *, void *);
extern s32 D_800092DC;

typedef struct { u8 pad[0x88]; s32 f88; } ObjU;

s32 func_80077964(ObjU *arg0) {
    s32 h;
    s32 *d;

    d = &D_800092DC;
    if (arg0->f88 == 0) {
        h = func_80023DBC(0xEB1);
        func_80052A5C(0x566);
        if (func_80052A68(h, d) != 0) {
            return 1;
        }
        arg0->f88 = func_80052B24(h, d, arg0);
    }
    animStepKeys(arg0);
    return findActor(0x801, 0) == 0;
}
