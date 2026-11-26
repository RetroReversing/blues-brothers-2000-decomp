typedef struct Entry {
    s32 flags;
    s32 bit;
    s32 x;
    s32 y;
} Entry;

extern Entry D_800B8230[8];
extern s32 D_80107040;
extern s32 gStickX;
extern s32 gStickY;

s32 pollMenuInput(s32 arg0) {
    s32 i;
    s32 r = 0;

    for (i = 0; i < 8; i++) {
        if (arg0 & D_800B8230[i].bit) {
            if (D_80107040 & D_800B8230[i].flags) {
                r |= D_800B8230[i].bit;
            }
            if (D_800B8230[i].x > 0 && D_800B8230[i].x < gStickX) {
                r |= D_800B8230[i].bit;
            }
            if (D_800B8230[i].x < 0 && gStickX < D_800B8230[i].x) {
                r |= D_800B8230[i].bit;
            }
            if (D_800B8230[i].y > 0 && D_800B8230[i].y < gStickY) {
                r |= D_800B8230[i].bit;
            }
            if (D_800B8230[i].y < 0 && gStickY < D_800B8230[i].y) {
                r |= D_800B8230[i].bit;
            }
        }
    }
    return r;
}
