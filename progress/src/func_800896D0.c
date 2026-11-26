typedef struct { u32 w0, w1; } Gfx_;
typedef struct Task { u8 pad[0x58]; } Task;

void func_8002E958(void);
void func_8007CE50(void);
void osWritebackDCacheAll(void);
u32 func_8008990C(void *);
s32 func_8007089C(s32);
void func_80070984(Task *, Gfx_ *, s32, s32, s32);
extern s32 D_800B9E98;
extern s32 D_800B9EC0;
extern Gfx_ *D_80177E18;
extern s32 D_80178138;
extern Gfx_ *D_80178144;
extern Task D_80178180[];
extern s32 D_80178240;
extern u32 D_80178250;
extern u32 D_80178254;
extern u32 D_80178258;
extern u32 D_8017826C;
extern u32 D_80178274;
extern u32 D_80178278;

void func_800896D0(void) {
    Gfx_ *g;
    u32 now;

    func_8002E958();
    func_8007CE50();
    g = D_80177E18++;
    g->w0 = 0xE9000000;
    g->w1 = 0;
    g = D_80177E18++;
    g->w0 = 0xDF000000;
    g->w1 = 0;
    osWritebackDCacheAll();
    D_80178250 = func_8008990C(NULL);
    if (D_800B9E98 == 0) {
        D_800B9E98 = 1;
    } else {
        D_80178240 = func_8007089C(D_800B9E98);
    }
    D_8017826C = D_80178250 - D_80178254;
    now = func_8008990C(NULL);
    D_80178258 = now;
    D_80178274 = now - D_80178254;
    D_80178254 = now;
    D_80178278 = now - D_80178250;
    D_80178138 = (u32)D_80177E18 - (u32)D_80178144;
    func_80070984(&D_80178180[D_800B9EC0], D_80178144, D_80178138, 0, 0x40);
}
