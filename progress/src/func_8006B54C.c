s32 func_80011388(void);
s32 findActor(s32, s32);
s32 func_80023DBC(s32);
f32 func_8002D858(void *, void *);
void func_8002E7B8(s32, s32);
void animStepKeys(void);
void func_80052A5C(s32);
void startStoryDialog(s32, void *, void *);
extern s32 D_80008F04;
extern s32 D_80008F1C;
extern s32 D_800B5DD4;
void updateCameraModeState(void);
void func_8003D558(void);

void func_8006B54C(s32 *obj) {
    f32 dist;
    s32 h;

    animStepKeys();
    dist = func_8002D858(obj, obj + 4);
    h = func_80023DBC(0xE2D);
    switch (obj[0x7C / 4]) {
    case 0:
        if (dist < 400.0f) {
            func_80052A5C(0x55F);
            if (func_80011388() == 0) {
                obj[0x7C / 4] = 2;
                startStoryDialog(h, &D_80008F1C, obj);
            } else {
                startStoryDialog(h, &D_80008F04, obj);
                obj[0x7C / 4] = 3;
            }
        }
        break;
    case 1:
    case 2:
        if (findActor(0x800, 0) == 0) {
            obj[0x9C / 4] = (s32)func_8003D558;
            func_8002E7B8(1, 0);
            D_800B5DD4 = 1;
            obj[0x70 / 4] = 2;
        }
        break;
    case 3:
        if (findActor(0x800, 0) == 0) {
            obj[0x78 / 4] = -1;
            obj[0] = 0x101;
            obj[0x9C / 4] = (s32)updateCameraModeState;
        }
        break;
    }
}
