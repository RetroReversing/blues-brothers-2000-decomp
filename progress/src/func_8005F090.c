typedef struct Ent { u8 p0[4]; f32 x; f32 z; u8 p1[0x90]; s32 fn; } Ent;
typedef struct Obj { u8 p0[4]; f32 x; f32 z; u8 p1[0x64]; s32 cnt; u8 p2[4]; u32 hit; } Obj;
extern f32 func_8002DD60(f32);
extern u32 D_800AB9BC;
extern u32 D_800AB9C0;
extern void func_800166BC(void);

void func_8005F090(Obj *arg0) {
    u32 var_s1;
    Ent *e;
    f32 a, b;

    if ((arg0->hit == 0) && (arg0->cnt < 0xB)) {
        var_s1 = D_800AB9BC;
        if (var_s1 < D_800AB9C0) {
            do {
                e = (Ent *) var_s1;
                if (e->fn == (s32) &func_800166BC) {
                    a = func_8002DD60(arg0->x - e->x);
                    b = func_8002DD60(arg0->z - e->z);
                    if ((a < 550.0f) && (b < 500.0f)) {
                        arg0->hit = var_s1;
                        break;
                    }
                }
                var_s1 += 0x108;
            } while (var_s1 < D_800AB9C0);
        }
        arg0->cnt = arg0->cnt + 1;
    }
}
