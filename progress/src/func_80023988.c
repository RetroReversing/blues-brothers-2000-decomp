typedef struct Obj {
    s32 active;
    u8 pad4[0x64];
    s32 key;
    u8 pad6C[0x2C];
    void (*fn)(struct Obj *);
    s32 x9C;
    u8 padA0[0x68];
} Obj;
extern Obj *D_800AB9BC;
extern Obj *D_800AB9C0;
Obj *func_80023988(s32 arg0, Obj *arg1) {
    if (arg1 == NULL) {
        arg1 = D_800AB9BC;
    } else {
        arg1++;
    }
    while (arg1 < D_800AB9C0) {
        if (arg1->x9C == arg0) {
            return arg1;
        }
        arg1++;
    }
    return NULL;
}
