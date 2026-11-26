typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj {
    s32 state;          /* 0x00 */
    f32 x04;
    f32 y;              /* 0x08 */
    u8 pad0C[0x38];
    f32 x44;            /* 0x44 */
    u8 pad48[0x34];
    s32 x7C;            /* 0x7C */
    u8 pad80[0x10];
    s32 x90;            /* 0x90 */
    u8 pad94[0x14];
    struct Obj *xA8;    /* 0xA8 */
    u8 padAC[8];
    f32 xB4;            /* 0xB4 */
    s32 xB8;            /* 0xB8 */
} Obj;

f32 func_8002D340(f32, f32, f32);
extern Obj *D_800BD06C;
extern Vec3i D_800F4A00[];
extern s32 D_80140228;

void func_800133C8(Obj *arg0) {
    Obj *p;
    f32 h;

    if (arg0->x7C == 0) {
        arg0->x7C = 1;
        h = arg0->y + D_800F4A00[arg0->xB8].y - 150.0f;
        arg0->xB4 = h;
    }
    p = arg0->xA8;
    h = arg0->xB4;
    if (p == NULL && D_800BD06C->y < h) {
        arg0->state = 0x102;
    } else {
        arg0->state = 0x10E;
    }
    if (arg0->x90 != 0) {
        arg0->y -= 20.0f;
        p = arg0->xA8;
        if (p != NULL && p->state == 3) {
            p->y = arg0->y + D_800F4A00[arg0->xB8].y;
            D_80140228 = 1;
        }
    } else {
        arg0->y = func_8002D340(arg0->x44, arg0->y, 20.0f);
    }
}
