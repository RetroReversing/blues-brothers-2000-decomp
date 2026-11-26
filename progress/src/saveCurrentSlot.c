typedef struct B28 {
    u8 b[0x28];
} B28;

typedef struct W20 {
    s32 w[8];
} W20;

typedef struct B40 {
    u8 b[0x40];
} B40;

typedef struct B21C {
    u8 b[0x21C];
} B21C;

typedef struct Slot {
    char pad0[0x10];
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    B28 x28;
    s32 x50;
    W20 x54;
    B40 x74;
} Slot;

typedef struct Game {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
} Game;

void func_80026C04(void *, s32, s32);
void *memcpy(void *, const void *, unsigned int);
s32 func_800261A0(s32);
void func_80026464(char *, void *, s32);

extern char D_8000128C[];
extern s32 D_800A9548;
extern s32 D_800B81C8;
extern B40 D_800BCFB8;
extern W20 D_800BD0B8;
extern Game D_800BD0E0;
extern B28 D_800BD1F0;
extern u8 gSaveBuffer[];
extern Slot gSaveSlots[];

/* Copies the current game state into the active save slot, then writes the save buffer to the save device. */ void saveCurrentSlot(void) {
    s32 saveSize = 0x300;

    gSaveSlots[D_800B81C8].x18 = D_800BD0E0.x4;
    gSaveSlots[D_800B81C8].x1C = D_800BD0E0.x8;
    gSaveSlots[D_800B81C8].x20 = D_800BD0E0.xC;
    gSaveSlots[D_800B81C8].x24 = D_800BD0E0.x10;
    memcpy(&gSaveSlots[D_800B81C8].x28, &D_800BD1F0, sizeof(B28));
    memcpy(&gSaveSlots[D_800B81C8].x54, &D_800BD0B8, sizeof(W20));
    memcpy(&gSaveSlots[D_800B81C8].x74, &D_800BCFB8, sizeof(B40));
    gSaveSlots[D_800B81C8].x50 = D_800A9548;
    gSaveSlots[D_800B81C8].x10 = D_800BD0E0.x1C;
    gSaveSlots[D_800B81C8].x14 = D_800BD0E0.x20;
    func_80026C04(gSaveBuffer, 0, saveSize);
    memcpy(gSaveBuffer, gSaveSlots, sizeof(Slot) * 3);
    if (func_800261A0(0) != 0) {
        func_80026464(D_8000128C, gSaveBuffer, saveSize);
    }
}
