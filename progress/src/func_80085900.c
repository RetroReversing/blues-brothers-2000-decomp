typedef struct {
    u16 id;
    u16 sub;
    s32 val;
} Entry;

s32 cameraGetMode(void *);
void func_800899C4(char *, s32);
extern char D_80009AB0[];
extern Entry D_800B99C0[];
void func_800858AC(void);

typedef struct {
    u8 pad0[0x70];
    s32 i70;
    u8 pad74[0xA0 - 0x74];
    void (*cbA0)(void);
    u8 padA4[0xF4 - 0xA4];
    s32 iF4;
} Obj;

s32 func_80085900(Obj *obj) {
    s32 key;
    Entry *e;
    s32 ret;

    e = D_800B99C0;
    key = cameraGetMode(obj);
    for (;;) {
        if (e->id == 0x400) {
            goto end;
        }
        if (e->id == key && e->sub == obj->i70) {
            obj->iF4 = e->val;
            obj->cbA0 = func_800858AC;
            func_800899C4(D_80009AB0, obj->i70);
            return 1;
        }
        e++;
    }
end:
    return 0;
}
