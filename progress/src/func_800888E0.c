void *func_800232B4(s32, s32, s32, s32);
s32 strlen(char *);
extern char *D_800B4D30[];
extern s32 D_8014AA98;
void func_80088778(void);

typedef struct {
    u8 pad0[0x64];
    s32 f64;
    s32 f68;
    u8 pad1[4];
    s32 f70;
    u8 pad2[0x98 - 0x74];
    void (*f98)(void);
} ObjM;

void *func_800888E0(s32 arg0) {
    ObjM *o;

    o = func_800232B4(1, 0, 0, 0);
    o->f98 = func_80088778;
    o->f70 = arg0;
    o->f68 = 0xE;
    o->f64 = strlen(D_800B4D30[o->f70]) * 8;
    D_8014AA98 = 0;
    return o;
}
