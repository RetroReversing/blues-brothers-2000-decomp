typedef struct Obj {
    u8 pad00[0x64];
    s32 x64;
    u8 pad68[8];
    s32 x70;
    u8 pad74[8];
    s32 x7C;
    u8 pad80[0x14];
    s32 x94;
    u8 pad98[4];
    void (*x9C)(void);
} Obj;

Obj *findActor(s32, Obj *);
void setSlotAsset(s32, s32, s32);
s32 tickActorTimer(Obj *);
void func_8007591C(s32, s32);
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
void collidePlayerWithWall(void);

void func_8007209C(Obj *arg0) {
    Obj *p;

    if (arg0->x7C == 0) {
        D_800B3970 = 0x96;
        D_800B3974 = 0xB6;
        D_800B3978 = 0xC6;
        arg0->x7C = 1;
        setSlotAsset(0x20, 0x678, 0);
        for (p = findActor(0x102, NULL); p != NULL; p = findActor(0x102, p)) {
            p->x94 -= 2500;
        }
        for (p = findActor(0x101, NULL); p != NULL; p = findActor(0x101, p)) {
            p->x94 -= 2500;
        }
        p = NULL;
        for (;;) {
            p = findActor(0x131, p);
            if (p == NULL) {
                break;
            }
            p->x9C = collidePlayerWithWall;
        }
    } else {
        func_8007591C(-0x1194, -0x5DC);
        if (tickActorTimer(arg0) != 0) {
            arg0->x64 = 300;
            arg0->x70 = -1;
        }
    }
}
