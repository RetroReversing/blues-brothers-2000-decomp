typedef struct Ent234F4 {
    s32 flags;
    u8 pad_4[0x98];
    void (*fn)(struct Ent234F4 *);
    u8 pad_A0[0x68];
} Ent234F4;

void func_8001FF64(Ent234F4 *);
void func_80048F5C(void);
extern s32 D_800AB9B4;
extern Ent234F4 *D_800AB9BC;
extern Ent234F4 *D_800AB9C0;
extern s32 D_800AB9C8;
extern s32 D_800B9C7C;

void func_800234F4(void) {
    Ent234F4 *p;

    func_80048F5C();
    if (D_800AB9B4 != 0) {
        for (p = D_800AB9BC; p < D_800AB9C0; p++) {
            if (p->flags & 0x8000) {
                if (p->flags == 0x8001) {
                    func_8001FF64(p);
                } else {
                    p->fn(p);
                    if (D_800B9C7C != 0) {
                        return;
                    }
                }
            }
        }
    } else {
        for (p = D_800AB9BC; p < D_800AB9C0; p++) {
            if (p->flags != 0 && !(p->flags & D_800AB9C8)) {
                p->fn(p);
                if (D_800B9C7C != 0) {
                    return;
                }
            }
        }
    }
}
