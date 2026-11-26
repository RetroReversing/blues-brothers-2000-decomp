typedef struct Obj {
    u8 pad00[0x70];
    s32 x70;
    u8 pad74[0x20];
    s32 x94;
    u8 pad98[0x10];
    s32 xA8;
    f32 speed;  /* 0xAC */
    f32 max;    /* 0xB0 */
    f32 cur;    /* 0xB4 */
} Obj;

f32 func_8002D340(f32, f32, f32);
void func_80034F50(Obj *);
void func_80083830(Obj *);
extern s32 D_800BD06C;
extern s32 D_8014A928[];

void func_800836E4(Obj *arg0) {
    f32 limit = D_8014A928[arg0->x70];

    if (arg0->x94 == 2) {
        arg0->x94 = 0;
        arg0->xA8 = D_800BD06C;
        arg0->speed = arg0->speed - 2.0;
        if (arg0->max < arg0->speed) {
            arg0->speed = arg0->max;
        }
        if (arg0->speed < 0.0f) {
            arg0->speed = 0.0f;
        }
    }
    if (arg0->x94 == 1) {
        arg0->x94 = 0;
        arg0->xA8 = D_800BD06C;
        arg0->speed = arg0->speed + 2.0;
        if (arg0->speed < arg0->max) {
            arg0->speed = arg0->max;
        }
        if (limit - 1.0 <= arg0->speed) {
            arg0->speed = limit - 1.0;
        }
    }
    arg0->cur = func_8002D340(arg0->speed, arg0->cur, 0.04f);
    func_80083830(arg0);
    func_80034F50(arg0);
}
