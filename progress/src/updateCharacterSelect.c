typedef struct { f32 x, y, z; } Vec3;
typedef struct Obj87B68 {
    s32 kind;
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x84 - 0x74];
    s32 unk84;
    u8 pad88[0xA8 - 0x88];
    struct Obj87B68 *unkA8;
    u8 padAC[0xBC - 0xAC];
    s32 unkBC;
    s32 unkC0;
    u8 padC4[0xE8 - 0xC4];
    s32 unkE8;
} Obj87B68;

void sendCommand(s32, s32);
s32 tickActorTimer(Obj87B68 *);
void func_8002D604(Obj87B68 *);
void func_80047824(s32, s32, s32, s32, s32);
void func_80047864(s32, s32, s32, s32, s32);
extern Vec3 gSelectPositions[];
extern s32 gPadPressed[];
extern s32 gStickX[];
extern Obj87B68 *gIntroActors[];

/* Per-frame update for one player's character select: the stick or L/R moves the highlight between the four intro actors; A or Start confirms, tinting the chosen actor (red for player 1, blue for player 2), and a second press un-confirms it. */ /* Per-frame update for one player's character select: the stick (or L/R buttons) moves the highlight between the four intro actors, and A/Start confirms it and swaps the chosen actor into view. */ void updateCharacterSelect(Obj87B68 *selector) {
    s32 stickMag;
    s32 n;
    Obj87B68 *selectedActor;

    if (selector->unkC0 == 0) {
        stickMag = gStickX[selector->unkBC];
        if (stickMag < 0) {
            stickMag = -stickMag;
        }
        if (stickMag < 20) {
            selector->unk64 = 0;
        }
        if (tickActorTimer(selector) != 0) {
            selector->unk64 = 0;
            if ((gPadPressed[selector->unkBC] & 0x200) || gStickX[selector->unkBC] < -30) {
            dec:
                selector->unk84 = (selector->unk84 - 1) & 3;
                if (selector->unkA8->unk84 == selector->unk84) {
                    goto dec;
                }
                selector->unk64 = 25;
                sendCommand(12, 0x80);
                sendCommand(8, 0x9F);
            }
            if ((gPadPressed[selector->unkBC] & 0x100) || gStickX[selector->unkBC] >= 31) {
            inc:
                selector->unk84 = (selector->unk84 + 1) & 3;
                if (selector->unkA8->unk84 == selector->unk84) {
                    goto inc;
                }
                selector->unk64 = 25;
                sendCommand(12, 0x80);
                sendCommand(8, 0xA0);
            }
        }
        selector->unk70 = 80;
        selector->unk84 &= 3;
        selector->x = gSelectPositions[selector->unk84].x;
        selector->y = gSelectPositions[selector->unk84].y + 400.0f;
        selector->z = gSelectPositions[selector->unk84].z;
        func_8002D604(selector);
        func_8002D604(selector);
        if (gPadPressed[selector->unkBC] & 0x9000) {
            sendCommand(12, 0x80);
            sendCommand(8, 0xA5);
            selectedActor = gIntroActors[selector->unk84];
            selector->unkC0 = 1;
            func_80047864(selectedActor->unkE8, 0, 0, 120, -100);
            func_80047864(selectedActor->unkE8, 0, 0, 120, -100);
            if (selector->unkBC != 0) {
                func_80047824(selectedActor->unkE8, 0, 0, 0, 255);
                func_80047824(selectedActor->unkE8, 0, 0, 0, 255);
            } else {
                func_80047824(selectedActor->unkE8, 0, 255, 0, 0);
                func_80047824(selectedActor->unkE8, 0, 255, 0, 0);
            }
            selectedActor->unkC0 = 1;
        }
    } else if (selector->unkC0 == 1) {
        selector->unk70 = 100;
        selector->unk10 = 0;
        if (gPadPressed[selector->unkBC] & 0x9000) {
            sendCommand(12, 0x80);
            sendCommand(8, 0x9C);
            selectedActor = gIntroActors[selector->unk84];
            func_80047864(selectedActor->unkE8, 0, 100, 0, -100);
            func_80047864(selectedActor->unkE8, 0, 100, 0, -100);
            func_80047824(selectedActor->unkE8, 0, 255, 255, 255);
            func_80047824(selectedActor->unkE8, 0, 255, 255, 255);
            selector->unkC0 = 0;
            selectedActor->unkC0 = 0;
        }
    }
}
