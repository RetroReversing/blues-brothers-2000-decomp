void *func_80023874(s32, s32);
s32 func_80043248(void *);
typedef struct Obj { u8 pad[0x9C]; void *fn; u8 pad2[0x108 - 0xA0]; } Obj;
extern Obj *D_800AB9BC;
extern Obj *D_800AB9C0;
void func_800690B0(void);
void func_80069270(void);
void func_8007631C(void);

s32 func_80068BF8(void *arg0) {
    Obj *p;
    Obj *end;
    void *t;

    if (*(s32 *)((s8 *)arg0 + 0x88) == 0) {
        p = func_80023874(0x1004, 0);
        if (p != NULL) {
            *(s32 *)((s8 *)p + 0xC0) = 1;
        }

        for (p = D_800AB9BC; p <= D_800AB9C0; p++) {
            if (p->fn == func_800690B0) {
                p->fn = func_80069270;
            }
        }
        *(s32 *)((s8 *)arg0 + 0x88) = 1;
    }
    if (func_80043248(arg0) != 0) {
        *(void **)((s8 *)arg0 + 0x9C) = func_8007631C;
        *(s32 *)((s8 *)arg0 + 0xD8) = 0;
        return 1;
    }
    return 0;
}
