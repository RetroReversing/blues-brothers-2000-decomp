typedef struct Obj3CE48 {
    u8 pad0[0x64];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    s32 unk74;
    u8 pad78[0x84 - 0x78];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
} Obj3CE48;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x20 - 0x1C];
} Entry3CE48;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} State3CE48;

int abs(int);
void func_8002A360(s32, s32);
s32 approachS32(s32, s32, s32);
s32 tickActorTimer(Obj3CE48 *);
void func_8002E7B8(s32, s32);
void func_8003D3C8(void);
void func_8003D558(void);
extern Entry3CE48 D_800AA134[];
extern s32 D_800AB9B4;
extern s32 D_800B5DD0;
extern s32 D_800B5DD4;
extern s32 gAudioVolume;
extern s32 gFrameScale;
extern s32 gCamSpeedScale;
extern State3CE48 D_800BD0E0;
extern s32 D_800BD274;
extern s32 D_80107040[];
extern s32 gPadPressed[];
extern s32 gStickX[];
extern s32 gStickY[];
extern s32 D_80140228;

/* Selection menu update: the stick moves the selection (up/down change the entry index, left/right change the column); the A button confirms and the B button goes back; the start button opens a sub-screen. Each change plays a menu sound. */
void selectMenuUpdate(Obj3CE48 *menu) {
    s32 changed;
    s32 volume;
    Entry3CE48 *entry;

    changed = 0;
    entry = &D_800AA134[menu->unk90];
    menu->unk70 = approachS32(0xFF, menu->unk70, gCamSpeedScale * 8);
    D_80140228 = 0;
    D_800B5DD4 = 0;
    if (abs(gStickX[0]) < 20) {
        if (abs(gStickY[0]) < 20) {
            menu->unk64 = 0;
        }
    }
    if (tickActorTimer(menu) != 0) {
        menu->unk64 = 0;
        if (gStickY[0] >= 31) {
            changed = 1;
            menu->unk64 = 15;
            menu->unk88--;
        }
        if (gStickY[0] < -30) {
            changed = 1;
            menu->unk64 = 15;
            menu->unk88++;
        }
        if (menu->unk84 <= 0) {
            if (D_80107040[0] & 0x400) {
                changed = 1;
                menu->unk84 = 15;
                menu->unk88++;
            }
            if (D_80107040[0] & 0x800) {
                changed = 1;
                menu->unk84 = 15;
                menu->unk88--;
            }
        } else {
            menu->unk84 -= gFrameScale;
        }
    }
    if (menu->unk88 < 0) {
        changed = 0;
        menu->unk88 = 0;
    }
    if (menu->unk8C == 0) {
        if (menu->unk88 >= entry->unk18) {
            changed = 0;
            menu->unk88 = entry->unk18 - 1;
        }
    } else if (menu->unk88 >= 4) {
        changed = 0;
        menu->unk88 = 3;
    }
    if (changed != 0) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x94);
    }
    if (gPadPressed[0] & 0x8000) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0xA3);
        if (menu->unk8C == 0) {
            D_800BD0E0.unk24 = D_800BD0E0.unk1C;
            if (D_800BD0E0.unk20 != menu->unk90) {
                D_800BD274 = 0x41;
            }
            D_800BD0E0.unk20 = menu->unk90;
            D_800B5DD0 = 1;
            D_800BD0E0.unk1C = menu->unk88;
            menu->unk9C = func_8003D558;
            func_8002E7B8(1, 0);
            D_800B5DD4 = 1;
            menu->unk70 = 0;
            func_8002A360(12, 0x80);
            func_8002A360(8, 0xC);
            func_8002A360(0, gAudioVolume * 327);
        } else {
            menu->unk90 = menu->unk88;
            menu->unk8C = 0;
            menu->unk88 = 0;
        }
    } else if (gPadPressed[0] & 0x4000) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0xA3);
        menu->unk8C = 1;
        menu->unk88 = 0;
    } else if (gPadPressed[0] & 0x1000) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0xA3);
        menu->unk9C = func_8003D3C8;
        D_800AB9B4 = 0;
        D_800B5DD4 = 1;
        volume = gAudioVolume * 327;
        D_80140228 = menu->unk74;
        func_8002A360(0, volume);
    }
}
