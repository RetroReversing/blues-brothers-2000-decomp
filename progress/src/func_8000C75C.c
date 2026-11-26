extern s32 D_800BD0E0[];
extern u8 D_800BD1F0[];
void *spawnEffectObj(s32, s32, s32, s32);
s32 getObjPoolStart(s32);
s32 getObjPoolEnd(s32);
void func_8000C614(void);
void func_80011420(void);

typedef struct Ent {
    s32 active;
    u8 pad4[0x6C];
    s32 slot;
    u8 pad74[0x28];
    void (*update)(void);
    u8 padA0[0x68];
} Ent;

void func_8000C75C(void) {
    char *o;
    Ent *p;
    Ent *end;
    Ent *start;

    o = spawnEffectObj(0x101, 0, 0, 0);
    *(void (**)(void))(o + 0x98) = func_8000C614;
    *(s32 *)(o + 0x68) = 0xF;
    *(s32 *)(o + 0x64) = 0x190;
    start = (Ent *)getObjPoolStart(0);
    end = (Ent *)getObjPoolEnd(0);
    do { for (p = start; p <= end; p++) {
        if (p->active != 0 && p->update == func_80011420) {
            *(s32 *)(o + 0x70) += 1;
            if (D_800BD1F0[D_800BD0E0[8] * 10 + p->slot] == 1) {
                *(s32 *)(o + 0x74) += 1;
            }
        }
    } } while (0);
    if (*(s32 *)(o + 0x74) == *(s32 *)(o + 0x70)) {
        (*(void (**)(char *))(o + 0xA0))(o);
    }
}
