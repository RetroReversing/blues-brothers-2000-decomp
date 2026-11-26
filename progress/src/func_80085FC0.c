typedef struct Obj85b {
    u8 pad0[0x68];
    s32 x68;
    u8 pad6C[0x30];
    void *x9C;
} Obj85b;
s32 func_8002D5CC(Obj85b *);
void func_8008626C(void);
extern Obj85b *D_80171A30;

void func_80085FC0(Obj85b *o) {
    if (func_8002D5CC(o) != 0) {
        o->x9C = func_8008626C;
        D_80171A30->x68 = 0xE;
    }
}
