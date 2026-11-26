typedef struct Obj {
    /* 0x00 */ u8 pad0[0x70];
    /* 0x70 */ s32 f70;
    /* 0x74 */ s32 f74;
    /* 0x78 */ u8 pad78[0x10];
    /* 0x88 */ s32 f88;
    /* 0x8C */ u8 pad8C[0xC];
    /* 0x98 */ void *f98;
    /* 0x9C */ void *f9C;
} Obj;
void func_800256A4(s32);
void func_8002A360(s32, s32);
void func_8002E7B8(s32, s32);
s32 func_8003D654(Obj *);
void func_8003D3C8();
void func_8003D558();
void func_8003DD70();
void func_8003E278();
extern s32 D_800AB9B4;
extern s32 D_800B5DCC;
extern s32 D_800B5DD4;
extern s32 D_800B5DD8;
extern s32 D_800B81D8;
extern s32 D_800B9EA4;
extern s32 D_801070A0;
extern s32 D_80140228;
extern s32 D_80140250;

void func_8003DB40(Obj *arg0) {
    s32 moved;

    moved = func_8003D654(arg0);
    if (arg0->f88 < 0) {
        arg0->f88 = 0;
        moved = 0;
    }
    if (arg0->f88 >= D_800B5DD8) {
        arg0->f88 = D_800B5DD8 - 1;
        moved = 0;
    }
    if (moved) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x90);
    }
    if (D_801070A0 & 0x8000) {
        switch (arg0->f88) {
        case 0:
            arg0->f9C = func_8003D3C8;
            D_800AB9B4 = 0;
            D_800B5DD4 = 1;
            D_80140228 = arg0->f74;
            func_800256A4(0x12345678);
            func_8002A360(0, D_800B81D8 * 327);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9C);
            D_800B9EA4 = D_80140250;
            return;
        case 1:
            arg0->f9C = func_8003DD70;
            arg0->f98 = func_8003E278;
            arg0->f88 = 0;
            D_800B5DCC = 2;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xA2);
            break;
        case 2:
            arg0->f9C = func_8003D558;
            func_8002E7B8(1, 0);
            D_800B5DD4 = 1;
            arg0->f70 = 0;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x9D);
            break;
        }
    }
    if (D_801070A0 & 0x1000) {
        arg0->f9C = func_8003D3C8;
        D_800AB9B4 = 0;
        D_800B5DD4 = 1;
        D_80140228 = arg0->f74;
        func_8002A360(0, D_800B81D8 * 327);
        D_800B9EA4 = D_80140250;
    }
}
