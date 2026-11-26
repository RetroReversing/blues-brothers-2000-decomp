extern s32 D_800BD23C;
extern s32 D_80140228;
extern s32 D_801700D8;
extern s32 D_800B4C28;
void func_80023078(void *);
void updateCameraView(void *);
void func_80024348(void);
s32 func_80023E3C(s32);
void func_80023620(s32);
void func_8002369C(s32, s32);
void func_8000C458(void);
void func_80023C64(s32);
void func_80023C58(s32);
void func_80050430(void);
void func_8004EC20(void);
void func_80027030(s32);
void func_80052A5C(s32);
void *findActor(s32, s32);

typedef struct {
    s32 unk0;
    u8 pad4[0x64];
    s32 unk68;
    u8 pad6C[0x2C];
    void *unk98;
    void *unk9C;
    u8 padA0[0x18];
    s32 unkB8;
    u8 padBC[0x28];
    s32 unkE4;
} Obj;

extern Obj *D_800B3960;
extern Obj *D_800B3964;
extern Obj *gCameraTarget;

void func_8000CDF0(void) {
    Obj *o;

    D_800BD23C = 0;
    D_80140228 = 0;
    D_801700D8 = 0x1F40;
    D_800B3964->unk9C = (void *)((s8 *)&func_80023078 + 8);
    D_800B3964->unk98 = (void *)((s8 *)&func_80023078 + 8);
    D_800B3960->unk9C = updateCameraView;
    D_800B3960->unk98 = (void *)((s8 *)&func_80023078 + 8);
    gCameraTarget->unk9C = (void *)((s8 *)&func_80023078 + 8);
    gCameraTarget->unk68 = -1;
    func_80024348();
    D_800B4C28 = 0x7530;
    gCameraTarget->unk0 = 3;
    gCameraTarget->unkB8 = 1;
    gCameraTarget->unkE4 = func_80023E3C(1);
    func_80023620(1);
    func_8002369C(0x100, 0x1031);
    func_8000C458();
    func_80023C64(0x12345678);
    func_80023C64(0x110);
    func_80023C58(0x110);
    func_80050430();
    func_8004EC20();
    func_80027030(1);
    func_80052A5C(0);
    o = findActor(6, 0);
    if (o != NULL) {
        o->unk68 = -1;
    }
}
