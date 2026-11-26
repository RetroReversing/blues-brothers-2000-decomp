typedef struct Obj {
    u8 p0[4];
    f32 x, y, z;
    s32 f10;
    u8 p14[0x40 - 0x14];
    f32 vx, vy, vz;
    u8 p4c[0x68 - 0x4c];
    s32 f68;
    u8 p6c[4];
    s32 f70;
    u8 p74[8];
    s32 f7c;
    u8 p80[0x8c - 0x80];
    s32 f8c;
    u8 p90[0x9c - 0x90];
    void *f9c;
    u8 pa0[4];
    struct Obj *fa4;
    u8 pa8[0xd8 - 0xa8];
    void *fd8;
    u8 pdc[0xe8 - 0xdc];
    s32 fe8;
} Obj;
extern void *func_80042F00();
extern s32 actorSetAnim();
extern s32 func_8002A360();
extern s32 func_80047898();
extern s32 func_80047864();
extern Obj *gCameraTarget;
extern char func_80023078[];
extern char func_80066B44[];
extern char func_80066CA8[];
extern char func_80066FDC[];

void func_80066EA4(Obj *o) {
    Obj *n;

    if (o->f7c == 0) {
        o->f7c = 1;
        o->fd8 = func_80066FDC;
        o->f9c = func_80066B44;
        o->f70 = 0;
        o->f68 = -1;
        n = func_80042F00(0x65, 0, 0, 0);
        n->x = o->x;
        n->y = o->y;
        n->z = o->z;
        n->vx = o->vx;
        n->vy = o->vy;
        n->vz = o->vz;
        n->f8c = 0;
        n->f10 = o->f10;
        n->fa4 = o;
        n->f9c = func_80066CA8;
        actorSetAnim(n, 0xFF, 0x100);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xD4);
        n->fe8 = func_80047898();
        func_80047864(n->fe8, 0, 0, -0x78, 0);
        func_80047864(n->fe8, 0, 0, -0x78, 0);
        gCameraTarget->f9c = func_80023078 + 8;
    }
}
