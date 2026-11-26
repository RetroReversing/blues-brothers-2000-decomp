typedef struct {
    s32 x;
    s32 y;
    s32 text;
} MenuItem;
typedef struct {
    u8 pad0[0x20];
    s32 page;
} MenuState;
s32 getImageAsset(s32);
void setTextColor(s32, s32, s32, s32);
void drawImage(s32, s32, s32, s32);
void func_800279B4(s32, s32, s32, s32, s32, s32);
extern MenuItem D_800A9598[];
extern s32 D_800AB9B4;
extern MenuState D_800BD0E0;
extern s32 D_800BD168[];
extern u8 D_800BD1F0[];

void func_8001B7C4(s32 *arg0) {
    s32 i;
    MenuItem *item;

    if (D_800AB9B4 == 0 || arg0[0] == 0x8000) {
        setTextColor(0xFF, 0xFF, 0xFF, arg0[0x17]);
        func_800279B4(getImageAsset(arg0[0x18]), 0x100, 0x2A, 0x30, arg0[0x1F] + 0x61, 0);
        for (i = 0; i < 10; i++) {
            if (D_800BD1F0[D_800BD0E0.page * 10 + i] != 0) {
                setTextColor(0xFF, 0xFF, 0, arg0[0x17]);
            } else {
                setTextColor(0x70, 0x70, 0x70, arg0[0x17]);
            }
            drawImage(getImageAsset(D_800BD168[D_800A9598[i].text]), D_800A9598[i].x, D_800A9598[i].y + arg0[0x1F], 0);
        }
    }
}
