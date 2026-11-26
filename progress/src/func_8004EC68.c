typedef struct {
    s32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0x50 - 0x1C];
    s32 f50;
    u8 pad54[0x68 - 0x54];
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    s32 f90;
    s32 f94;
    u8 pad98[0x9C - 0x98];
    void *f9C;
    u8 padA0[0xB0 - 0xA0];
    s32 fB0;
    u8 padB4[0xF8 - 0xB4];
    s32 fF8;
    u8 padFC[0x108 - 0xFC];
} Obj;

typedef struct {
    u8 kind;
    u8 pad1[0xF - 0x1];
    u8 fF;
} Entry;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Triple;

typedef Obj *(*ObjFn)(Obj *);

void func_80013834(void);
void func_80013870(s32, s32, s32, s32);
void func_800170D8(Entry *, Obj *);
s32 cameraGetMode(void);
s32 func_8001DD94(s32, s32);
Obj *getObjPoolStart(s32);
Obj *getObjPoolEnd(s32);
s32 func_80023D58(s32);
s32 *getImageAsset(s32);
void func_800242A8(s32, s32, s32);
void func_800242DC(s32);
void *heapAlloc(s32);
void syncActorPrevPos(Obj *);
Obj *func_8002E374(s32);
void func_80033BC0(void);
f32 func_800385AC(Obj *);
void func_80046F30(Obj *);
Obj *func_8004E080(s32, s32, s32, s32);
Obj *func_8004E888(Obj *);
void func_8004E8B0(Obj *, s32);
s32 func_8004EB18(s32);
void func_8004EC20(void);
s32 *func_8004F63C(Obj *, s32, s32 *);
s32 *func_8004F984(s32 *, s32);
void func_80088F40(void);
void debugPrintf(char *, s32);
void func_8000F670(void);
void func_800184B8(void);
void func_800340B4(void);
void func_80033F50(void);
Obj *func_80058040(Obj *);
Obj *func_800717A8(Obj *);
Obj *func_80071878(Obj *);
Obj *func_80071970(Obj *);

extern ObjFn D_800B79A4[];
extern s32 D_800B7DE0[];
extern s32 D_800B81D0;
extern Obj *D_800B3960;
extern Obj *gCameraTarget;
extern s32 D_800BD104;
extern s32 gSplinePointCount[];
extern Triple *gSplineSrcPoints[];
extern s32 D_8014AA20;

s32 func_8004EC68(s32 arg0, s32 arg1) {
    Obj obj;
    s32 base;
    s32 count2;
    s32 count;
    s32 *start;
    s32 n;
    s32 found;
    s32 flags;
    s32 *p;
    s32 *cur;
    Entry *tbl;
    Entry *e;
    Entry *q;
    Obj *o;
    Obj *r;
    s32 i;
    s32 j;
    s32 bit;
    s32 mask;
    s32 idx;
    s32 cnt;
    s32 k;
    s32 *src;
    Triple **slot;
    ObjFn fn;
    s32 t;
    s32 id0;
    s32 t2;
    s32 *cp;
    f32 y;

    n = 0;
    found = 0;
    id0 = 0xA9;
    flags = arg1 & ~0x1C;
    D_8014AA20 = 0;
    obj.f4 = 0;
    obj.f8 = 0;
    obj.fC = 0;
    obj.f0 = 0;
    obj.f6C = 0;
    obj.f70 = 0;
    obj.f74 = 0;
    obj.f78 = 0;
    obj.f7C = 0;
    obj.f80 = 0;
    obj.f84 = 0;
    obj.f88 = 0;
    obj.f8C = 0;
    obj.f90 = 0;
    obj.f94 = 0;
    func_80013834();
    func_8004EC20();
    func_800242DC(func_80023D58(arg0 - 1));
    base = func_80023D58(arg0);
    p = getImageAsset(base);
    count = *p++;
    start = p;
    for (i = 0; i < count; i++) {
        if (p[0] == 3) {
            p = (s32 *)((u8 *)p + (p[2] * 12 + 12));
        } else {
            bit = 1;
            mask = p[5];
            p += 6;
            for (j = 0; j < 32; j++) {
                if (mask & bit) {
                    p += D_800B7DE0[j];
                }
                bit <<= 1;
            }
        }
    }
    count2 = *p;
    tbl = (Entry *)(p + 1);
    p = start;
    for (i = 0; i < count; i++) {
        if (p[0] == 3) {
            p = (s32 *)((u8 *)p + (p[2] * 12 + 12));
        } else {
            mask = p[5];
            bit = 1;
            if ((u32)p[0] < 2) {
                e = &tbl[p[1]];
                e->fF = 0;
                if (p[0] == 0) {
                    e->fF = 0x10;
                }
                if (e->kind == 0x23) {
                    e->fF = 0x12;
                }
                if (e->kind == 0x40) {
                    e->fF = 0;
                }
            }
            p += 6;
            for (j = 0; j < 32; j++) {
                if (mask & bit) {
                    if (bit == 2) {
                        if (func_8004EB18(p[0]) != 0) {
                            e->fF = 0x12;
                        }
                    }
                    p += D_800B7DE0[j];
                }
                bit <<= 1;
            }
        }
    }
    p = (s32 *)tbl;
    for (i = 0; i < count2; i++) {
        e = (Entry *)p;
        t2 = base + 1;
        func_800242A8(id0 + n, i + t2, e->fF);
        n++;
        p = (s32 *)(e + 1);
    }
    p = start;
    for (i = 0; i < count; i++) {
        cur = p;
        obj.f4 = 0;
        obj.f8 = 0;
        obj.fC = 0;
        obj.f0 = 0;
        obj.f6C = 0;
        obj.f70 = 0;
        obj.f74 = 0;
        obj.f78 = 0;
        obj.f7C = 0;
        obj.f80 = 0;
        obj.f84 = 0;
        obj.f88 = 0;
        obj.f8C = 0;
        obj.f90 = 0;
        obj.f94 = 0;
        obj.f10 = 0;
        obj.f14 = 0;
        obj.f18 = 0;
        mask = p[5];
        p += 6;
        o = &obj;
        if (cur[0] == 3) {
            p -= 6;
            idx = cur[1];
            slot = &gSplineSrcPoints[idx];
            cnt = cur[2];
            src = p + 3;
            if (*slot != 0) {
                debugPrintf("path already setup %d", idx);
            }
            *slot = heapAlloc(cnt * 12);
            for (k = 0; k < cnt; k++) {
                gSplineSrcPoints[idx][k].a = src[0];
                gSplineSrcPoints[idx][k].b = src[1];
                gSplineSrcPoints[idx][k].c = src[2];
                src += 3;
            }
            cp = gSplinePointCount;
            cp[idx] = cnt;
            p = (s32 *)((u8 *)p + (cnt * 12 + 12));
        } else {
            if (cur[0] == -1) {
                if (found == 0 || cur[1] == D_800BD104) {
                    o = gCameraTarget;
                    found = 1;
                }
            }
            if (cur[0] == -2) {
                o = func_8002E374(0x82);
                o->f68 = -1;
                o->f9C = func_8000F670;
                o->f78 = cur[1];
                o->f0 = 0x13C;
            }
            if (cur[0] == -3) {
                o = func_8002E374(0x82);
                o->f68 = -1;
                o->f9C = func_800184B8;
                o->f70 = cur[1];
                o->f0 = 0x131;
            }
            if ((u32)cur[0] < 2) {
                o = func_8002E374(id0 + cur[1]);
                o->f0 = 0x102;
                func_80013870(id0 + cur[1], cur[2], cur[3], cur[4]);
                if (tbl[cur[1]].kind == 0x23) {
                    func_8004E8B0(o, 6);
                    t = cameraGetMode();
                    if (t == 0x32 || t == 0x3C) {
                        o->f0 = 0x13B;
                    } else {
                        o->f0 = 0x101;
                    }
                }
                if (tbl[cur[1]].kind == 0x40) {
                    o->f0 = 0x101;
                }
                func_800170D8(&tbl[cur[1]], o);
                e = &tbl[cur[1]];
                if (e->kind == 0x25) {
                    o->fF8 |= 8;
                }
            }
            if (cur[0] == 2) {
                p = func_8004F984(p, mask);
            } else {
                o->f4 = cur[2];
                o->f8 = cur[3];
                o->fC = cur[4];
                syncActorPrevPos(o);
                p = func_8004F63C(o, mask, p);
            }
        }
    }
    p = start;
    for (i = 0; i < count; i++) {
        cur = p;
        obj.f4 = 0;
        obj.f8 = 0;
        obj.fC = 0;
        obj.f0 = 0;
        obj.f6C = 0;
        obj.f70 = 0;
        obj.f74 = 0;
        obj.f78 = 0;
        obj.f7C = 0;
        obj.f80 = 0;
        obj.f84 = 0;
        obj.f88 = 0;
        obj.f8C = 0;
        obj.f90 = 0;
        obj.f94 = 0;
        obj.f10 = 0;
        obj.f14 = 0;
        obj.f18 = 0;
        mask = p[5];
        p += 6;
        o = &obj;
        if (cur[0] == 3) {
            cnt = cur[2];
            p = (s32 *)((u8 *)p + cnt * 12 - 12);
        } else if (cur[0] != 2) {
            p = func_8004F984(p, mask);
        } else {
            fn = func_8004E888;
            if (cur[1] >= 0) {
                fn = D_800B79A4[cur[1]];
            }
            if (fn == func_800717A8) {
                flags |= 4;
            }
            if (fn == func_80071878) {
                flags |= 0x10;
            }
            if (fn == func_80071970) {
                flags |= 8;
            }
            if (fn == func_80058040) {
                flags |= 2;
            }
            o->f4 = cur[2];
            o->f8 = cur[3];
            o->fC = cur[4];
            syncActorPrevPos(o);
            p = func_8004F63C(o, mask, p);
            o->f14 = 0;
            o = fn(o);
            o->f10 = obj.f10;
            o->f14 = obj.f14;
            o->f18 = obj.f18;
            syncActorPrevPos(o);
        }
    }
    gCameraTarget->f50 = 0;
    gCameraTarget->fB0 = 0;
    gCameraTarget->f14 = 0;
    gCameraTarget->f18 = 0;
    if (D_800B81D0 == 0) {
        t = func_8001DD94(cameraGetMode(), D_800BD104 & 0xF);
        D_800B3960->f4 = gCameraTarget->f4;
        D_800B3960->f8 = gCameraTarget->f8 + 500.0f;
        D_800B3960->fC = gCameraTarget->fC;
        D_800B3960->f10 = gCameraTarget->f10 + t;
        syncActorPrevPos(gCameraTarget);
        syncActorPrevPos(D_800B3960);
        func_80088F40();
        if (D_800B3960->f9C == func_800340B4 || D_800B3960->f9C == func_80033F50) {
            func_80033BC0();
        }
        if (cameraGetMode() == 0x24) {
            cp = gSplinePointCount;
            r = func_8004E080(0, cp[0], (s32)gSplineSrcPoints[0], 0);
            r->f94 = 0;
            r->f0 = 0x108;
            func_80046F30(r);
        }
        if (cameraGetMode() != 0x31 && cameraGetMode() != 0x18) {
            for (o = getObjPoolStart(0); o < getObjPoolEnd(0); o++) {
                if (o->f0 < 0x1000 || o->f0 > 0x1030) {
                    continue;
                }
                if (o->f0 == 0x101A || o->f0 == 0x1001 || o->f0 == 0x1008 || o->f0 == 0x100B || o->f0 == 0x1016
                    || o->f0 == 0x101B || o->f0 == 0x135 || o->f0 == 0x1029 || o->f0 == 0x102C || o->f0 == 0x1028
                    || o->f0 == 0x1027) {
                    continue;
                }
                y = func_800385AC(o);
                if (y != -1000000.0) {
                    o->f8 = y;
                }
                syncActorPrevPos(o);
            }
        }
    }
    return flags;
}
