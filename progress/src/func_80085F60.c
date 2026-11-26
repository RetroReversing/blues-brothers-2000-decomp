typedef struct Obj85 {
    u8 pad0[0x64];
    s32 x64;
} Obj85;
void *func_80023874(s32, s32);
s32 func_8002D5CC(Obj85 *);
void func_80082494(Obj85 *);

void func_80085F60(Obj85 *o) {
    if (o->x64 > 100) {
        o->x64 = 100;
    }
    if (func_80023874(0x800, 0) == NULL) {
        if (func_8002D5CC(o) != 0) {
            func_80082494(o);
        }
    }
}
