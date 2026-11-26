typedef struct State {
    u8 pad0[0x6C];
    s32 f6C;
    s32 f70;
    u8 pad74[8];
    s32 f7C;
    u8 pad80[0x14];
    s32 f94;
} State;
void func_8002710C(s32, s32, s32, s32);
void func_80027158(s32, s32);
s32 func_8002D298(s32, s32, s32);
void func_8003CDA0(s32);
void func_8007D6DC(void);
extern State D_801704E0;

s32 func_8007D1FC(void) {
    State *s = &D_801704E0;
    s32 ret = 0;

    if (s->f7C == 0) {
        s->f6C = 0;
        s->f70 = 0;
        s->f94 = 1;
        s->f7C = 1;
    }
    func_8007D6DC();
    func_8002710C(0xC0, 0xC0, 0xC0, s->f6C);
    func_80027158(0xA0, 0x78);
    switch (s->f70) {
    case 0:
        func_8003CDA0(0xAB);
        break;
    case 1:
        func_8003CDA0(0xAC);
        break;
    case 2:
        func_8003CDA0(0xAD);
        break;
    default:
        ret = 1;
        break;
    }
    if (s->f94 != 0) {
        s->f6C = func_8002D298(0xFF, s->f6C, 2);
        if (s->f6C == 0xFF) {
            s->f94 ^= 1;
        }
    } else {
        s->f6C = func_8002D298(0, s->f6C, 2);
        if (s->f6C == 0) {
            s->f94 ^= 1;
            s->f70++;
        }
    }
    return ret;
}
