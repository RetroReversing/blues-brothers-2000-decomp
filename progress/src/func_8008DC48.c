typedef struct { u8 pad0[8]; s32 val; } Inner;
typedef struct {
    u8 pad0[0x44];
    s32 id;             /* 0x44 */
    u8 pad48[0x74 - 0x48];
    Inner *a;           /* 0x74 */
    Inner *b;           /* 0x78 */
    u8 pad7C[0x13C - 0x7C];
} Ent;
extern s32 D_8017B204;
extern Ent *D_8017B20C;

s32 func_8008DC48(s32 id) {
    s32 i;
    Ent *e;
    Inner *q;

    if (id != 0) {
        e = D_8017B20C;
        for (i = 0; i < D_8017B204; i++, e++) {
            if (e->id == id) {
                if (e->a == NULL) {
                    return e->b->val;
                }
                return e->a->val;
            }
        }
    }
    return 0;
}
