typedef struct ObjM5 {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x70 - 0x10];
    s32 f70;
    u8 pad74[0x7C - 0x74];
    s32 f7C;
    u8 pad80[0x9C - 0x80];
    void *f9C;
} ObjM5;

s32 func_80076080(ObjM5 *);
void animStepKeys(ObjM5 *);
f32 func_8002D858(ObjM5 *, void *);
ObjM5 *func_80023DBC(s32);
void func_80052A5C(s32);
void func_80052B24(ObjM5 *, char *, ObjM5 *);
ObjM5 *findActor(s32, s32);
s32 func_800113D8(s32);
void func_8002E7B8(s32, s32);
s32 cameraGetMode(void);
void func_8003D558(void);
void func_80056834(void);
extern s32 D_800A9548;
extern u8 D_800BCFB8[];
extern char D_800083B4[];
extern char D_800083BC[];
extern char D_800083C4[];
extern char D_800083CC[];
extern char D_800083D4[];

void func_800568B4(ObjM5 *arg0) {
    f32 dist;
    ObjM5 *other;
    ObjM5 *obj;

    if (func_80076080(arg0) != 0) {
        return;
    }
    animStepKeys(arg0);
    dist = func_8002D858(arg0, &arg0->pad10);
    other = func_80023DBC(0xE6F);
    switch (arg0->f7C) {
        case 0:
            if (dist < 1000.0f) {
                func_80052A5C(0x56B);
                func_80052B24(other, D_800083B4, arg0);
                arg0->f7C = 1;
            }
            break;
        case 1:
            if (findActor(0x801, 0) == NULL) {
                if (func_800113D8(0) != 0 && func_800113D8(1) != 0 && func_800113D8(2) != 0 && func_800113D8(3) != 0) {
                    func_80052B24(other, D_800083BC, arg0);
                    arg0->f7C = 2;
                } else {
                    func_80052B24(other, D_800083C4, arg0);
                    arg0->f7C = 3;
                }
            }
            break;
        case 2:
            if (findActor(0x801, 0) == NULL) {
                if ((D_800A9548 & 0xF) == 0xF) {
                    func_80052B24(other, D_800083CC, arg0);
                    arg0->f7C = 4;
                } else {
                    func_80052B24(other, D_800083D4, arg0);
                    arg0->f7C = 3;
                }
            }
            break;
        case 3:
            if (findActor(0x801, 0) == NULL) {
                arg0->f9C = func_8003D558;
                func_8002E7B8(1, 0);
                arg0->f70 = 2;
            }
            break;
        case 4:
            if (findActor(0x801, 0) == NULL) {
                D_800BCFB8[cameraGetMode()] = 1;
                arg0->f9C = func_80056834;
                obj = findActor(0x13C, 0);
                if (obj != NULL) {
                    obj->x = arg0->x;
                    obj->y = arg0->y;
                    obj->z = arg0->z;
                }
            }
            break;
        case 5:
            break;
    }
}
