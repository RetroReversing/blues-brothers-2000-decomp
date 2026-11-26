typedef struct {
    u8 pad_0[4];
    f32 x;
    f32 y;
    u8 pad_C[0x90];
    void *fn;
    u8 pad_A0[0x68];
} Ent8005F1B0;

typedef struct {
    u8 pad_0[4];
    f32 x;
    f32 y;
    u8 pad_C[4];
    s32 dir;
} Obj8005F1B0;

f32 func_8002DD60(f32);
extern Ent8005F1B0 *D_800AB9BC;
extern Ent8005F1B0 *D_800AB9C0;
void func_800166BC();

s32 func_8005F1B0(Obj8005F1B0 *arg0) {
    Ent8005F1B0 *p;
    f32 dx;
    f32 ax;
    f32 ay;

    for (p = D_800AB9BC; p < D_800AB9C0; p++) {
        if (p->fn == func_800166BC) {
            dx = arg0->x - p->x;
            ax = func_8002DD60(dx);
            ay = func_8002DD60(arg0->y - p->y);
            if (ax < 250.0f && ay < 500.0f) {
                if (dx > 0.0f) {
                    if (arg0->dir == -0x4000) {
                        return 1;
                    }
                } else if (arg0->dir == 0x4000) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
