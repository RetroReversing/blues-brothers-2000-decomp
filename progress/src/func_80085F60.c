typedef struct Obj85 {
    u8 pad0[0x64];
    s32 x64;
} Obj85;
void *findActor(s32, s32);
s32 tickActorTimer(Obj85 *);
void func_80082494(Obj85 *);

void func_80085F60(Obj85 *o) {
    if (o->x64 > 100) {
        o->x64 = 100;
    }
    if (findActor(0x800, 0) == NULL) {
        if (tickActorTimer(o) != 0) {
            func_80082494(o);
        }
    }
}
