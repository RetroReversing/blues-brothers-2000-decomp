extern void func_8002710C(s32, s32, s32, s32);
extern void func_8002713C(s32, s32);
extern void func_8002889C(char *);
extern void func_800271D8(s32);
extern char D_80008E7C[];
extern int sprintf(char *, const char *, ...);

void func_8006A494(void *arg0) {
    char buf[16];

    *(s32 *)((char *) arg0 + 0x68) = 0xF;
    func_8002710C(0x60, 0xFF, 0xFF, 0xFF);
    func_8002713C(0x32, 0x4B);
    sprintf(buf, D_80008E7C, (double) *(f32 *)((char *) arg0 + 0x100));
    func_8002889C(buf);
    func_8002713C(0x32, 0x57);
    sprintf(buf, D_80008E7C, (double) *(f32 *)((char *) arg0 + 0x104));
    func_8002889C(buf);
    func_8002713C(0x32, 0x63);
    func_800271D8(*(s32 *)((char *) arg0 + 0x88));
}
