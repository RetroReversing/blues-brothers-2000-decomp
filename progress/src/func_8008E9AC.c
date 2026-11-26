typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 pos;
    /* 0x10 */ u8 pad10[0x30];
    /* 0x40 */ s32 start;
    /* 0x44 */ u8 pad44[0x10];
    /* 0x54 */ s32 release;
    /* 0x58 */ f32 attackScale;
    /* 0x5C */ f32 decayScale;
    /* 0x60 */ f32 releaseScale;
    /* 0x64 */ s32 rate;
    /* 0x68 */ u8 pad68[0x57];
    /* 0xBF */ u8 period;
    /* 0xC0 */ u8 base;
    /* 0xC1 */ u8 peak;
    /* 0xC2 */ u8 sustain;
    /* 0xC3 */ u8 state;
    /* 0xC4 */ u8 level;
    /* 0xC5 */ u8 timer;
    /* 0xC6 */ u8 attackTime;
    /* 0xC7 */ u8 decayTime;
    /* 0xC8 */ u8 releaseTime;
    /* 0xC9 */ u8 padC9[4];
    /* 0xCD */ u8 releaseLevel;
} Env;

void func_8008E9AC(Env *e) {
    u8 state;
    s32 t;

    if (e->release - e->pos < 0 && e->state < 4) {
        e->state = 4;
        e->timer = 1;
        e->releaseLevel = e->level;
    }
    if (--e->timer == 0) {
        state = e->state;
        e->timer = e->period;
        switch (state) {
        case 1:
            t = ((u32)(e->pos - e->start) >> 8) * e->rate >> 10;
            if (t < e->attackTime) {
                e->level = e->base + (s32)(e->attackScale * t);
            } else {
                e->state = state + 1;
                e->level = e->peak;
            }
            break;
        case 2:
            t = (((u32)(e->pos - e->start) >> 8) - e->attackTime) * e->rate >> 10;
            if (t < e->decayTime) {
                e->level = e->peak + (s32)(e->decayScale * t);
            } else {
                e->state = state + 1;
                e->level = e->sustain;
            }
            break;
        case 3:
            break;
        case 4:
            t = ((u32)(e->pos - e->release) >> 8) * e->rate >> 10;
            if (t < e->releaseTime) {
                e->level = e->releaseLevel - (s32)(e->releaseScale * t * e->releaseLevel);
            } else {
                e->state = state + 1;
                e->level = 0;
            }
            break;
        }
    }
}
