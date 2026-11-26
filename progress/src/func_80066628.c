typedef struct {
    s32 state;
    u8 pad4[4];
    f32 y;
} Player;
s32 findActor(s32, s32);
void func_80052A5C(s32);
s32 func_80052A68(s32, char *);
void *func_80052B24(s32, char *, void *);
extern Player *gCameraTarget;
extern s32 D_800BD0F4;
void *wardenChase(void *);

void *func_80066628(u8 *obj) {
    char *name = "warden_intro";
    s32 id = *(s32 *) (obj + 0xBC);
    void *ret;

    if (D_800BD0F4 <= 0) {
        return 0;
    }
    if (*(void **) (obj + 0x7C) == 0) {
        if (func_80052A68(id, name) != 0) {
            return *(void **) (obj + 0xD8) = wardenChase;
        }
    }
    gCameraTarget->state = 3;
    if (*(s32 *) (obj + 0x90) < 500) {
        ret = *(void **) (obj + 0x7C);
        if (ret == 0) {
            if (gCameraTarget->y < *(f32 *) (obj + 0x8) + 50.0f) {
            func_80052A5C(0x570);
            if (func_80052A68(id, name) == 0) {
                *(void **) (obj + 0x7C) = func_80052B24(id, name, obj);
                goto fail;
            } else {
                *(void **) (obj + 0xD8) = wardenChase;
                *(void **) (obj + 0x7C) = 0;
                return 0;
            }
            }
        }
    } else {
        ret = *(void **) (obj + 0x7C);
    }
    if (ret != 0) {
        if (findActor(0x800, 0) != 0) {
        fail:
            return 0;
        }
        *(void **) (obj + 0x7C) = 0;
        ret = wardenChase;
        *(void **) (obj + 0xD8) = ret;
    }
    return ret;
}
