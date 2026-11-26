typedef struct Obj {
    s32 active;
    u8 pad4[0x64];
    s32 key;
    u8 pad6C[0x2C];
    void (*fn)(struct Obj *);
    u8 pad9C[0x6C];
} Obj;

void func_80046310(void *, f32, s32);
extern Obj *D_800AB9BC;
extern Obj *D_800AB9C0;
extern u8 *gCameraTarget;
extern s32 D_800DA840;

void func_800233C8(void) {
    s32 i;
    Obj *p;

    for (i = 0; i < 16; i++) {
        if (i == 13 && gCameraTarget != NULL && *(s32 *)(gCameraTarget + 0x68) != -1 && *(s32 *)gCameraTarget == 3 &&
            !(*(s32 *)(gCameraTarget + 0xF8) & 0x40)) {
            func_80046310(gCameraTarget + 4, 125.0f, 0);
            D_800DA840 = 0;
        }
        for (p = D_800AB9BC; p < D_800AB9C0; p++) {
            if (p->active != 0 && p->key == i) {
                p->fn(p);
            }
        }
    }
}
