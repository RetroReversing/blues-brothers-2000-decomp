typedef struct Dbg54 {
    u8 pad0[0x6C];
    s32 x6C[11];
    u8 pad98[0x14];
    f32 xAC;
    f32 xB0;
    f32 xB4;
    u8 padB8[0x48];
    f32 x100;
    f32 x104;
} Dbg54;
extern char D_80008260[];
extern char D_80008268[];
s32 sprintf(char *, const char *, ...);
void func_8002710C(s32, s32, s32, s32);
void func_8002713C(s32, s32);
void func_8002889C(char *);

s32 func_80054470(Dbg54 *o) {
    char buf[0x20];
    s32 i;
    s32 y;
    s32 *p;

    func_8002710C(0x60, 0xFF, 0xFF, 0xFF);
    if (o->x100 > 1e-05f) {
        func_8002713C(0x32, 0x32);
        sprintf(buf, D_80008260, o->x100);
        func_8002889C(buf);
    }
    if (o->x104 > 1e-05f) {
        func_8002713C(0x32, 0x3E);
        sprintf(buf, D_80008260, o->x104);
        func_8002889C(buf);
    }
    if (o->xAC > 1e-05f) {
        func_8002713C(0x32, 0x4A);
        sprintf(buf, D_80008260, o->xAC);
        func_8002889C(buf);
    }
    if (o->xB0 > 1e-05f) {
        func_8002713C(0x32, 0x56);
        sprintf(buf, D_80008260, o->xB0);
        func_8002889C(buf);
    }
    if (o->xB4 > 1e-05f) {
        func_8002713C(0x32, 0x62);
        sprintf(buf, D_80008260, o->xB4);
        func_8002889C(buf);
    }
    p = o->x6C;
    for (i = 0; i < 11; i++) {
        func_8002713C(0xD2, 0x32 + i * 12);
        sprintf(buf, D_80008268, i, *p);
        func_8002889C(buf);
        p++;
        
    }
    return 0;
}

