typedef struct Obj {
    s32 active;
    u8 pad4[0x64];
    s32 key;
    u8 pad6C[0x2C];
    void (*fn)(struct Obj *);
    u8 pad9C[0x6C];
} Obj;
extern Obj *D_800AB9BC;
extern Obj *D_800AB9C0;
Obj *findActor(s32 arg0, Obj *arg1) {
    if (arg1 == NULL) {
        arg1 = D_800AB9BC;
    } else {
        arg1++;
    }
    while (arg1 < D_800AB9C0) {
        if (arg1->active == arg0) {
            return arg1;
        }
        arg1++;
    }
    return NULL;
}
