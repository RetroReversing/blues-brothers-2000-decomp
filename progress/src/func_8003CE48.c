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
extern s32 D_801073B0[];
extern s32 D_801073C0[];
extern s32 D_80140228;

void func_8003CE48(Obj3CE48 *arg0) {
    s32 flag;
    s32 v;
    Entry3CE48 *e;

    flag = 0;
    e = &D_800AA134[arg0->unk90];
    arg0->unk70 = approachS32(0xFF, arg0->unk70, gCamSpeedScale * 8);
    D_80140228 = 0;
    D_800B5DD4 = 0;
    if (abs(D_801073B0[0]) < 20) {
        if (abs(D_801073C0[0]) < 20) {
            arg0->unk64 = 0;
        }
    }
    if (tickActorTimer(arg0) != 0) {
        arg0->unk64 = 0;
        if (D_801073C0[0] >= 31) {
            flag = 1;
            arg0->unk64 = 15;
            arg0->unk88--;
        }
        if (D_801073C0[0] < -30) {
            flag = 1;
            arg0->unk64 = 15;
            arg0->unk88++;
        }
        if (arg0->unk84 <= 0) {
            if (D_80107040[0] & 0x400) {
                flag = 1;
                arg0->unk84 = 15;
                arg0->unk88++;
            }
            if (D_80107040[0] & 0x800) {
                flag = 1;
                arg0->unk84 = 15;
                arg0->unk88--;
            }
        } else {
            arg0->unk84 -= gFrameScale;
        }
    }
    if (arg0->unk88 < 0) {
        flag = 0;
        arg0->unk88 = 0;
    }
    if (arg0->unk8C == 0) {
        if (arg0->unk88 >= e->unk18) {
            flag = 0;
            arg0->unk88 = e->unk18 - 1;
        }
    } else if (arg0->unk88 >= 4) {
        flag = 0;
        arg0->unk88 = 3;
    }
    if (flag != 0) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x94);
    }
    if (gPadPressed[0] & 0x8000) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0xA3);
        if (arg0->unk8C == 0) {
            D_800BD0E0.unk24 = D_800BD0E0.unk1C;
            if (D_800BD0E0.unk20 != arg0->unk90) {
                D_800BD274 = 0x41;
            }
            D_800BD0E0.unk20 = arg0->unk90;
            D_800B5DD0 = 1;
            D_800BD0E0.unk1C = arg0->unk88;
            arg0->unk9C = func_8003D558;
            func_8002E7B8(1, 0);
            D_800B5DD4 = 1;
            arg0->unk70 = 0;
            func_8002A360(12, 0x80);
            func_8002A360(8, 0xC);
            func_8002A360(0, gAudioVolume * 327);
        } else {
            arg0->unk90 = arg0->unk88;
            arg0->unk8C = 0;
            arg0->unk88 = 0;
        }
    } else if (gPadPressed[0] & 0x4000) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0xA3);
        arg0->unk8C = 1;
        arg0->unk88 = 0;
    } else if (gPadPressed[0] & 0x1000) {
        func_8002A360(12, 0x80);
        func_8002A360(8, 0xA3);
        arg0->unk9C = func_8003D3C8;
        D_800AB9B4 = 0;
        D_800B5DD4 = 1;
        v = gAudioVolume * 327;
        D_80140228 = arg0->unk74;
        func_8002A360(0, v);
    }
}
