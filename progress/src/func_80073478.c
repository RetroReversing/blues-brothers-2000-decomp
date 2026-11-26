typedef struct ObjQ {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x7C - 0x10];
    s32 f7C;
} ObjQ;

ObjQ *func_80023874(s32, s32);
void func_800899DC(char *);
f32 func_8002D340(f32, f32, f32);
void func_80034FEC(ObjQ *, s32 *);
void func_8001FF64(ObjQ *);
extern char D_80009100[];
extern s32 D_800B9ECC;
extern ObjQ *D_800B3964;

void func_80073478(ObjQ *arg0) {
    s32 pos[3];
    ObjQ *t;

    t = func_80023874(0x1023, 0);
    if (t == NULL) {
        t = func_80023874(0x101E, 0);
        if (t == NULL) {
            func_800899DC(D_80009100);
        }
    }
    pos[0] = t->x;
    pos[1] = t->y + 500.0f;
    pos[2] = t->z;
    arg0->z = func_8002D340(t->z - 2000.0f, arg0->z, D_800B9ECC * 10);
    arg0->x = func_8002D340(pos[0], arg0->x, D_800B9ECC * 10);
    arg0->y = func_8002D340(pos[1], arg0->y, D_800B9ECC * 10);
    if (arg0->z == t->z - 2000.0f && arg0->x == pos[0] && arg0->y == pos[1] && D_800B3964->f7C == 1) {
        D_800B3964->f7C = 2;
    }
    func_80034FEC(arg0, pos);
    func_8001FF64(arg0);
}
