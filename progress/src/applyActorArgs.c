s32 cameraGetMode(void);
void func_8004E8B0(void *, s32);
void func_800168F4(void);
void func_800176D0(void);
void func_800184B8(void);

typedef struct Obj {
    s32 x0;
    char pad4[0x10 - 0x4];
    s32 x10;
    s32 x14;
    s32 x18;
    char pad1C[0x6C - 0x1C];
    s32 x6C;
    s32 x70;
    s32 x74;
    s32 x78;
    s32 x7C;
    s32 x80;
    s32 x84;
    s32 x88;
    s32 x8C;
    s32 x90;
    s32 x94;
    char pad98[0x9C - 0x98];
    void (*fn9C)(void);
} Obj;

extern void (*D_800B7734[])(void);
extern s32 D_800B7DE0[];
extern s32 D_800B7E70[];
extern s32 D_8014A920;
extern s32 D_8014AA20;

/* Applies the argument words selected by the flags bitmask to an actor. Each set bit
 * consumes its argument(s) and sets the matching field; bit 1 picks a state handler
 * from D_800B7734. Returns the argument pointer advanced past the consumed words. */
s32 *applyActorArgs(Obj *obj, s32 flags, s32 *argp) {
    s32 i;
    s32 bit;

    bit = 1;
    for (i = 0; i < 32; i++) {
        if (flags & bit) {
            switch (bit) {
            case 1:
                if (argp[0] > 0) {
                    void (*handler)(void) = D_800B7734[argp[0]];
                    obj->fn9C = handler;
                    if (handler == func_800184B8) {
                        obj->x0 = 0x131;
                    }
                    if (obj->fn9C == func_800176D0) {
                        obj->x0 = 0x131;
                        obj->x70 = 0;
                        obj->fn9C = func_800184B8;
                    }
                    if (obj->fn9C == func_800168F4) {
                        D_8014A920 |= 2;
                    }
                    if (cameraGetMode() == 3 && obj->fn9C == func_800168F4) {
                        s32 v = D_800B7E70[D_8014AA20];
                        D_8014AA20++;
                        obj->x10 = v + 0x8000;
                    }
                }
                break;
            case 2:
                if (argp[0] > 0) {
                    func_8004E8B0(obj, argp[0]);
                }
                break;
            case 4:
                obj->x10 = argp[0];
                obj->x14 = 0;
                obj->x14 = argp[1];
                obj->x18 = 0;
                break;
            case 8:
                obj->x0 = argp[0];
                obj->x70 = argp[0];
                break;
            case 0x10:
                obj->x6C = argp[0];
                break;
            case 0x20:
                obj->x70 = argp[0];
                break;
            case 0x40:
                obj->x74 = argp[0];
                break;
            case 0x80:
                obj->x78 = argp[0];
                break;
            case 0x100:
                obj->x7C = argp[0];
                break;
            case 0x200:
                obj->x80 = argp[0];
                break;
            case 0x400:
                obj->x84 = argp[0];
                break;
            case 0x800:
                obj->x88 = argp[0];
                break;
            case 0x1000:
                obj->x8C = argp[0];
                break;
            case 0x2000:
                obj->x90 = argp[0];
                break;
            case 0x4000:
                obj->x94 = argp[0];
                break;
            }
            argp += D_800B7DE0[i];
        }
        bit <<= 1;
    }
    return argp;
}
