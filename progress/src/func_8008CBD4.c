typedef struct {
    u8 pad0[0x44];
    s32 i44;
    u8 pad48[0x7C - 0x48];
    s32 i7C;
    u8 pad80[0x13C - 0x80];
} Rec;

typedef struct {
    u8 pad0[0x44];
    s32 i44;
    s32 depth48;
    u8 pad4C[0x78 - 0x4C];
    s32 i78;
    s32 i7C;
    u8 pad80[0x9E - 0x80];
    s16 h9E;
    u8 padA0[0xB0 - 0xA0];
    s16 hB0;
} Obj;

s32 func_8008F68C(s32, s32, s32, s32, s32);
extern s32 D_8017B204;
extern Rec *D_8017B20C;

u8 *func_8008CBD4(Obj *obj, u8 *p) {
    s32 n;
    s32 r;
    s32 i;
    s32 cnt;
    Rec *e;

    n = *p++;
    if (n >= 0x80) {
        n = ((n & 0x7F) << 8) + *p++;
    }
    obj->depth48++;
    r = func_8008F68C(obj->i78, n, obj->h9E, obj->hB0, obj->depth48);
    obj->depth48--;
    if (r != 0) {
        e = D_8017B20C;
        for (i = 0; i < D_8017B204; i++, e++) {
            if (e->i44 == r) {
                e->i44 = obj->i44;
                e->i7C = obj->i7C;
            }
        }
    }
    return p;
}
