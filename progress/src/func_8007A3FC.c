s32 findActor(s32, s32);
s32 func_80023DBC(s32);
f32 getCameraTargetDist(void *, f32, s32);
void animStepKeys(void *);
void func_80052A5C(s32);
s32 func_80052A68(s32, char *);
s32 func_80052B24(s32, char *, void *);
void func_8007A2E8(void *);
extern char D_80009440[];
extern char D_8000944C[];
extern char D_80009458[];
extern f32 D_80009464;
extern u8 *D_800B3964[];
extern s32 D_800B83C4[];
typedef struct { s32 pad0; s32 arr[7]; s32 idx; } BD0E0;
extern BD0E0 D_800BD0E0;
extern s32 D_80107040[];

void func_8007A3FC(u8 *arg0) {
    u8 *other;
    f32 range;
    f32 dist;
    s32 id;
    s32 flag;
    char *name;

    name = D_80009440;
    if (*(s32 *)(arg0 + 0x7C) == 0) {
        other = *(u8 **)(arg0 + 0xA8);
        *(s32 *)(arg0 + 0x7C) = 1;
        if (other != NULL) {
            *(s32 *)(other + 0x10) = *(s32 *)(arg0 + 0x10);
            *(s32 *)(other + 0x68) = 4;
        }
    }
    range = D_80009464;
    dist = getCameraTargetDist(arg0, range, 0);
    flag = 0;
    id = func_80023DBC(D_800B83C4[0]);
    if (dist < range) {
        if (func_80052A68(id, name) == 0 ||
            (*(s32 *)(D_800B3964[0] + 0x7C) != 6 && (D_80107040[0] & 0x4000))) {
            flag = 1;
        }
        if (flag != 0) {
            func_80052A5C(0x568);
            func_80052B24(id, name, arg0);
        }
        if (*(s32 *)(D_800B3964[0] + 0x7C) == 6) {
            func_80052A5C(0x568);
            func_80052B24(id, D_8000944C, arg0);
            do { *(s32 *)(D_800B3964[0] + 0x7C) = 1; } while (0);
        }
        if (D_800BD0E0.arr[D_800BD0E0.idx] >= 10) {
            do { *(s32 *)(D_800B3964[0] + 0x7C) = 2; } while (0);
        } else if (*(s32 *)(arg0 + 0x88) == 0 && findActor(0x800, 0) == 0) {
            func_80052A5C(0x568);
            if (func_80052B24(id, D_80009458, arg0) != 0) {
                *(s32 *)(arg0 + 0x88) = 1;
            }
        }
    } else {
        *(s32 *)(arg0 + 0x88) = 0;
    }
    animStepKeys(arg0);
    animStepKeys(*(void **)(arg0 + 0xA8));
    func_8007A2E8(arg0);
}
