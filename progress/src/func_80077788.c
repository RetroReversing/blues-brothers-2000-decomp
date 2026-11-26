void func_8002D858(void *, void *);
s32 animStepKeys(void *);
void func_80043328(void *, s32, s32);
s32 findActor(s32, s32);
s32 func_80023DBC(s32);
void func_80052A30(void);
void func_80052A5C(s32);
s32 func_80052B24(s32, char *, void *);
extern char D_800092C8[];
extern char D_800092D0[];
extern u8 *D_800B3964;

s32 func_80077788(u8 *obj) {
    s32 id = 0xEB1;

    func_8002D858(obj, obj + 0x10);
    if (animStepKeys(obj) != 0) {
        if (*(s32 *) (obj + 0x78) == 5) {
            *(s32 *) (obj + 0x78) = 0;
        } else {
            *(s32 *) (obj + 0x78) = 5;
        }
        func_80043328(obj, *(s32 *) (obj + 0x74) + *(s32 *) (obj + 0x78), 0x100);
    }
    if (*(s32 *) (D_800B3964 + 0x7C) < 2) {
        return 0;
    }
    switch (*(s32 *) (obj + 0x90)) {
        case 0:
            func_80052A5C(0x566);
            if (func_80052B24(func_80023DBC(id), D_800092C8, obj) == 0) {
                func_80052A30();
                return 0;
            }
            *(s32 *) (obj + 0x90) += 1;
            break;
        case 1:
            func_80052A5C(0x565);
            if (func_80052B24(func_80023DBC(id), D_800092D0, obj) != 0) {
                *(s32 *) (obj + 0x90) += 1;
            }
            break;
        case 2:
            if (findActor(0x800, 0) == 0) {
                *(s32 *) (D_800B3964 + 0x7C) += 1;
                return 1;
            }
            break;
    }
    return 0;
}
