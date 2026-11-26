typedef struct {
    u8 pad0[0x44];
    s32 i44;
    u8 pad48[0x74 - 0x48];
    s32 *p74;
    s32 *p78;
    u8 pad7C[0x13C - 0x7C];
} Rec;

extern s32 D_8017B204;
extern Rec *D_8017B20C;

s32 func_8008DCB4(s32 id) {
    s32 i;
    Rec *e;

    if (id == 0) {
        return 0;
    }
    e = D_8017B20C;
    for (i = 0; i < D_8017B204; i++, e++) {
        if (e->i44 == id) {
            if (e->p74 != NULL) {
                return e->p74[8];
            }
            return e->p78[5];
        }
    }
    return 0;
}
