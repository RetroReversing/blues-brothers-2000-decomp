typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x44 - 0x34];
    s32 i44;
    u8 pad48[0x90 - 0x48];
    f32 f90;
    u8 pad94[0x13C - 0x94];
} Rec;

extern s32 D_8017B204;
extern Rec *D_8017B20C;

s32 func_8008D804(s32 id, f32 v) {
    s32 i;
    s32 n;
    Rec *e;

    if (id == 0) {
        return 0;
    }
    n = 0;
    e = D_8017B20C;
    for (i = 0; i < D_8017B204; i++, e++) {
        if (e->i44 == id) {
            e->f30 = v + e->f90;
            n++;
        }
    }
    return n;
}
