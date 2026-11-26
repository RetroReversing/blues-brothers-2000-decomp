typedef struct Obj47E8 {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 ang;
    u8 pad14[0x50];
    s32 c64;
    u8 pad68[4];
    struct Obj47E8 *who;
    s32 track;
    s32 c74;
    s32 c78;
    u8 pad7C[0x30];
    f32 cAC;
    f32 speed;
    f32 dist;
    u8 padB8[4];
    s32 cBC;
    u8 padC0[0x10];
    s32 cD0;
    u8 padD4[0x2C];
    f32 c100;
    f32 c104;
} Obj47E8;

extern s32 coss(u16);
extern s32 sins(u16);
extern s32 func_8002492C(f32, f32);
extern s32 func_8002D204(s32, s32, s32);
extern s32 func_8002D298(s32, s32, s32);
extern f32 func_8002D858(Obj47E8 *, s32 *);
extern f32 func_8002DD60(f32);
extern void func_8002E100(f32 *, f32 *);
extern s32 func_8004303C(Obj47E8 *);
extern void func_80043328(Obj47E8 *, s32, s32);
extern s32 func_80081188(s32, f32 *, f32 *);
extern void func_80081990(f32 *, s32, f32);
extern void func_80081AC0(f32 *, s32, f32);
extern const f32 D_80009A2C;
extern const f32 D_80009A30;
extern const f64 D_80009A38;
extern const f32 D_80009A40;
extern const f32 D_80009A44;
extern const f32 D_80009A48;
extern const f32 D_80009A4C;
extern const f32 D_80009A50;
extern u8 D_800B9ECC[];
extern u8 D_800BD06C[];
extern s32 D_8014A928[];
extern u8 D_8014AAB0[];

#define P47 (*(Obj47E8 **) D_8014AAB0)
#define CAM47 (*(Obj47E8 **) D_800BD06C)
#define ECC47 (*(s32 *) D_800B9ECC)

s32 func_800847E8(Obj47E8 *o) {
    f32 dir[4];
    s32 ang;
    f32 h;
    s32 tr;
    s32 r5;
    s32 flag;
    s32 sgn;
    f32 turn;
    f32 acc;
    f32 d;
    f32 lim;
    f32 v;
    s16 c;
    s16 s;
    f32 e;

    tr = o->track;
    func_80081990(&o->x, tr, o->dist);
    func_80081AC0(dir, tr, o->dist);
    func_8002E100(dir, dir);
    o->x += o->speed * dir[2];
    o->z -= o->speed * dir[0];
    r5 = func_8004303C(o);
    turn = 0.0f;
    if (P47->who == o) {
        P47->dist = o->dist;
    }
    e = func_8002D858(o, &ang);
    o->ang = func_8002D204(ang, o->ang, ECC47 * 448);
    if (e < D_80009A2C) {
        P47->who = o;
        P47->c78 = 1;
        return 2;
    }
    if (e < D_80009A30) {
        P47->who = o;
        P47->c78 = 2;
        ang = func_8002492C(dir[2], dir[0]);
        func_80043328(o, o->c74 + 1, 0x100);
        d = CAM47->x;
        acc = CAM47->z;
        d -= o->x;
        acc -= o->z;
        c = coss(ang);
        s = sins(ang);
        turn = c * d + s * acc;
        s = sins(ang);
        c = coss(ang);
        acc = s * d + c * acc;
        turn /= D_80009A38;
        d = o->cAC * D_80009A40;
        acc /= D_80009A44;
        o->ang = func_8002D298(ang, o->ang, ECC47 << 9);
    } else {
        func_80043328(o, o->c74 + 2, 0x100);
        d = func_80081188(tr, &CAM47->x, &h);
        if (P47->who == o) {
            P47->c100 = d;
            P47->c104 = h;
            P47->c74 = o->c104;
            P47->speed = func_8002DD60(d - o->dist);
            P47->c78 = 3;
        }
        if (h > o->c104) {
            flag = 0;
            if (func_8002DD60(d - o->dist) < D_80009A48) {
                flag = 1;
                if (P47->who == o) {
                    P47->c78 = 0x29;
                }
            }
            if (o->c104 * D_80009A4C < h) {
                flag = 1;
                if (P47->who == o) {
                    P47->c78 = 0x2A;
                }
            }
            if (flag) {
                if (o->cD0 != o->c74) {
                    func_80043328(o, o->c74, 0x100);
                } else if (r5) {
                    o->c64 = 0;
                }
                return 1;
            }
        }
        v = d - o->dist;
        dir[0] = v;
        if (0.0f < v) {
            o->cAC = func_8002DD60(o->cAC);
            o->cBC = 1;
        } else {
            o->cAC = -func_8002DD60(o->cAC);
            o->cBC = -1;
        }
        d = o->cAC + o->cAC;
        acc = -o->speed / D_80009A50;
    }
    if (d < turn) {
        turn = d;
    }
    if (turn < d) {
        turn = d;
    }
    o->dist += turn;
    o->speed += acc;
    lim = D_8014A928[tr];
    if (o->c104 < o->speed) {
        o->speed = o->c104;
    }
    if (o->speed < -o->c104) {
        o->speed = -o->c104;
    }
    if (lim < o->dist) {
        o->dist = lim;
    }
    if (o->dist < 0.0f) {
        o->dist = 0.0f;
    }
    return 0;
}
