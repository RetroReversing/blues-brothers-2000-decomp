typedef struct {
    s32 *codes;
    void (*fn)(void);
    s16 active;
    s16 level;
} Cheat;

typedef struct {
    u8 pad0[0x9C];
    void *state;
} Player14A84;

typedef struct {
    u8 pad0[0x6C];
    s32 timer;
    u8 pad70[0x94 - 0x70];
    s32 pos;
} Input14A84;

void func_8002A360(s32, s32);
void func_800393F4(void);
extern Cheat D_800AA388[];
extern s32 D_800B3968;
extern s32 gFrameScale;
extern Player14A84 *gCameraTarget;
extern s32 gPadPressed;

void func_80014A84(Input14A84 *in) {
    Cheat *c;
    s32 found;
    s32 *pad;
    s32 mode;

    if (gCameraTarget->state == func_800393F4) {
        in->timer -= gFrameScale;
        if (in->timer < 0) {
            if (in->pos != 0) {
                for (c = D_800AA388; c->codes != NULL; c++) {
                    if (c->active != 0 && c->codes[in->pos] == 0 && D_800B3968 >= c->level) {
                        c->fn();
                        func_8002A360(12, 0x80);
                        func_8002A360(8, 0x12);
                    }
                }
            }
            in->timer = 50;
            in->pos = 0;
            for (c = D_800AA388; c->codes != NULL; c++) {
                c->active = 1;
            }
        } else {
            do { mode = gPadPressed; } while (0);
            if (mode != 0) {
            found = 0;
            c = D_800AA388;
            if (c->codes != NULL) {
                pad = &gPadPressed;
                do {
                if (c->active != 0) {
                    if (*pad != c->codes[in->pos]) {
                        c->active = 0;
                    } else {
                        found = 1;
                    }
                }
                    c++;
                } while (c->codes != NULL);
            }
            if (found) {
                in->timer = 50;
                in->pos++;
            }
            }
        }
    }
}
