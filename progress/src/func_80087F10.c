typedef struct O87F10 {
    u8 pad0[0x58];
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    u8 pad88[0x98 - 0x88];
    void (*f98)(void);
    void (*f9C)(void);
    u8 padA0[0xBC - 0xA0];
    s32 fBC;
} O87F10;
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
O87F10 *func_800232B4(s32, s32, s32, s32);
extern s32 gIntroSpriteAssets[];
void drawBillboardSprite(void);
void updateCharacterSelect(void);

O87F10 *func_80087F10(s32 arg0) {
    O87F10 *o;

    o = func_800232B4(0x101, 0, 0, 0);
o->f98 = drawBillboardSprite;
o->f60 = gIntroSpriteAssets[arg0];
o->fBC = arg0;
o->f70 = 100;
o->f74 = 0;
o->f78 = 0xFFFFFF;
    o->f7C = 1;
    o->f5C = 0xFF;
    o->f58 = packDrawFlags(0, 1, 0, 2, 0, 0, 1, 0);
    o->f68 = 14;
    o->f9C = updateCharacterSelect;
    o->f84 = arg0;
    return o;
}
