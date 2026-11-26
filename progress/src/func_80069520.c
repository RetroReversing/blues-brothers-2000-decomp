typedef struct Obj { u8 pad[0x7C]; s32 state; u8 pad1[0x9C - 0x80]; void *fn; u8 pad2[0x108 - 0xA0]; } Obj;
extern Obj *D_800AB9BC;
extern Obj *D_800AB9C0;
void func_800694A0(void);

s32 func_80069520(s32 arg0) {
    Obj *p;
    s32 n;

    n = 0;
    for (p = D_800AB9BC; p <= D_800AB9C0; p++) {
        if (p->fn == func_800694A0) {
            if (arg0 != 0) {
                p->state = 4;
            } else {
                p->state = 1;
            }
            n++;
        }
    }
    return n >= 2;
}
