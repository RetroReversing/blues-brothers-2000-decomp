typedef struct Vec3i {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct Obj {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x30];
    f32 px;
    f32 py;
    f32 pz;
    u8 pad4C[4];
    f32 vy;
    u8 pad54[0x3C];
    s32 landed;
} Obj;

typedef struct Rec {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    s32 angle;
    u8 pad14[0x54];
    s32 key;
    s32 state;
    u8 pad70[0x20];
    s32 carrying;
    u8 pad94[0x14];
    Obj *rider;
    u8 padAC[0xC];
    s32 idx;
    u8 padBC[4];
    s32 hit;
    u8 padC4[0x44];
} Rec;

Rec *func_80023088(s32);
Rec *func_800230B0(s32);
Rec *func_80023874(s32, Rec *);
s32 func_8000C43C(void);
s32 func_8000F8F4(Obj *, Rec *);
s32 func_8000FA40(f32, f32, f32, f32);
s32 func_80016318(Obj *, Rec *, s32);
f32 func_8002DD60(f32);
void func_8003AC08(Obj *, f32, s32);
void func_8003BB90(Obj *);
void func_8003BF98(Obj *);
void func_800433A8(Obj *, s32, s32);
s32 func_800609F8(Rec *);
s32 func_80060C94(Rec *);
s16 func_800944B0(u16);
s16 func_80095F60(u16);
f32 sqrtf(f32);
int abs(int);

extern Vec3i D_800AA1BC[];
extern Obj *D_800BD06C;
extern s32 D_800BD0DC;
extern Rec *D_800BD10C;
extern Vec3i D_800F4A00[];
extern Vec3i D_800F6188[];
extern s32 D_800F7910[];
extern s32 D_80107040;

s32 func_8000FAC4(Obj *arg0) {
    s32 a[4];
    s32 b[4];
    Vec3i *v;
    Rec *p;
    Rec *end;
    Rec *start;
    s32 d;
    f32 savedY;
    s32 ret;
    s32 k;
    s32 i;
    s32 min;
    s32 ax;
    s32 az;
    s32 sector;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dy2;
    f32 r;
    f32 len;
    f32 ty;
    f32 t;
    f32 y;
    f32 qy;
    f32 lo;
    Vec3i *hi;
    Vec3i *lp;
    f32 y0;

    savedY = arg0->y;
    ret = 0;
    start = func_80023088(0);
    end = func_800230B0(0);
    p = func_80023874(0x12D, 0);
    if (p != 0 && p->key != -1) {
        dx = arg0->x - p->x;
        dz = arg0->z - p->z;
        len = dx * dx + dz * dz;
        y = arg0->y;
        qy = p->y;
        if (len <= 36100.0f) {
            lo = qy + (f32)D_800F6188[p->idx].y;
            ty = qy + (f32)D_800F4A00[p->idx].y;
            if (func_8000FA40(y, arg0->py, lo, ty) != 0) {
                len = sqrtf(len);
                if (arg0->vy <= 0.0f) {
                    arg0->y = ty + ((p->y + 20.0) - ty) * len / 190.0;
                    arg0->vy = 0.0f;
                    if (arg0->landed == 0) {
                        func_8003AC08(arg0, arg0->y, 0);
                    }
                    arg0->landed = 1;
                    return 1;
                }
            }
        }
    }
    for (p = start; p <= end; p++) {
        if (p->type == 0x12A) {
            dx = arg0->x - p->x;
            dy = arg0->y - p->y;
            dz = arg0->z - p->z;
            r = D_800F7910[p->idx] + 100.0;
            if (r < func_8002DD60(dx)) continue;
            if (r < func_8002DD60(dy)) continue;
            if (r < func_8002DD60(dz)) continue;
            len = sqrtf(dx * dx + dy * dy + dz * dz);
            if (r < d) continue;
            arg0->x = p->x + r * dx / len;
            arg0->y = p->y + r * dy / len;
            arg0->z = p->z + r * dz / len;
        }
        if (p->type == 0x12B) {
            p->hit = 0;
            sector = (p->angle + 0x2000) & 0xFFFF;
            dx = p->x - arg0->x;
            dz = p->z - arg0->z;
            sector /= 0x4000;
            if (p->y < arg0->y) continue;
            if (arg0->y + 300.0f < p->y) continue;
            switch (sector) {
            case 0:
                if (func_8002DD60(dx) < 100.0f && arg0->z >= p->z && arg0->z <= p->z + 400.0f) {
                    p->hit = 2;
                    continue;
                }
                break;
            case 1:
                if (func_8002DD60(dz) < 100.0f && arg0->x >= p->x && arg0->x <= p->x + 400.0f) {
                    p->hit = 2;
                    continue;
                }
                break;
            case 2:
                if (func_8002DD60(dx) < 100.0f && arg0->z <= p->z && arg0->z >= p->z - 400.0f) {
                    p->hit = 2;
                    continue;
                }
                break;
            case 3:
                if (func_8002DD60(dz) < 100.0f && arg0->x <= p->x && arg0->x >= p->x - 400.0f) {
                    p->hit = 2;
                    continue;
                }
                break;
            }
        }
        if (p->type == 0x133 && func_80016318(arg0, p, 1) != 0) continue;
        if (p->type == 0x105 && func_80016318(arg0, p, 0) != 0) {
            arg0->landed = 1;
            return 1;
        }
        if (p->type == 0x106 && func_80016318(arg0, p, 0) != 0) {
            arg0->landed = 1;
            return 1;
        }
        if (p->type == 0x129 && func_80016318(arg0, p, 1) != 0) {
            ret = 1;
            if (arg0->y < savedY) {
                arg0->y = savedY;
            } else {
                savedY = arg0->y;
            }
            continue;
        }
        if ((p->type & 0x1000) && func_8000F8F4(arg0, p) != 0) return 1;
        if (p->type == 0x10E) {
            p->carrying = 0;
            p->rider = 0;
            dx = arg0->x - p->x;
            dz = arg0->z - p->z;
            if (func_8002DD60(dx) > 8000.0f) {
                p->state = 2;
                continue;
            }
            if (func_8002DD60(dz) > 8000.0f) {
                p->state = 2;
                continue;
            }
            if (p->angle & 0xFFFF) {
                t = ((s32)(dx * func_800944B0(-(u16)p->angle)) >> 15) + ((s32)(dz * func_80095F60(-(u16)p->angle)) >> 15);
                dz = -((s32)(dx * func_80095F60(-(u16)p->angle)) >> 15) + ((s32)(dz * func_800944B0(-(u16)p->angle)) >> 15);
                dx = t;
            }
            if (dx > 0.0f && dx > D_800F4A00[p->idx].x) {
                p->state = 2;
                continue;
            }
            if (dx <= 0.0f && dx < D_800F6188[p->idx].x) {
                p->state = 2;
                continue;
            }
            if (dz > 0.0f && dz > D_800F4A00[p->idx].z) {
                p->state = 2;
                continue;
            }
            if (dz <= 0.0f && dz < D_800F6188[p->idx].z) {
                p->state = 2;
                continue;
            }
            if (p->y + D_800F4A00[p->idx].y < arg0->y) {
                p->state = 0;
                continue;
            }
            if (arg0->y + 300.0f < p->y + D_800F6188[p->idx].y) {
                p->state = 1;
                continue;
            }
            if (p->state == 2) {
                arg0->x = arg0->px;
                arg0->z = arg0->pz;
                if (arg0->vy > 0.0f) {
                    arg0->vy = 0.0f;
                }
                continue;
            }
            if (p->state == 0 || p->state == 3) {
                arg0->vy = 0.0f;
                p->rider = arg0;
                p->carrying = 1;
                arg0->y = p->y + D_800F4A00[p->idx].y;
                func_8003AC08(arg0, p->y + D_800F4A00[p->idx].y, 0);
                p->state = 3;
                return 1;
            }
            if (arg0->vy > 0.0f) {
                arg0->vy = 0.0f;
            }
            arg0->y = p->y + D_800F6188[p->idx].y - 300.0f;
        }
        if (p->type == 0x142) {
            p->carrying = 0;
            p->rider = 0;
            dx = arg0->x - p->x;
            dz = arg0->z - p->z;
            if (func_8002DD60(dx) > 8000.0f) continue;
            if (func_8002DD60(dz) > 8000.0f) continue;
            if (dx > D_800F4A00[p->idx].x) continue;
            if (dx < D_800F6188[p->idx].x) continue;
            if (dz > D_800F4A00[p->idx].z) continue;
            if (dz < D_800F6188[p->idx].z) continue;
            {
            f32 y0 = p->y;
            dy = arg0->y - y0;
            dy2 = arg0->py - y0;
            }
            if (dy > 0.0f && dy > D_800F4A00[p->idx].y) continue;
            if (dy2 < 0.0f && dy2 + 75.0f < D_800F6188[p->idx].y) continue;
            p->rider = arg0;
            p->carrying = 1;
            arg0->vy = 0.0f;
            arg0->y = p->y + D_800F4A00[p->idx].y;
            func_8003AC08(arg0, p->y + D_800F4A00[p->idx].y, 0);
            return 1;
        }
        if (p->type == 0x138) {
            dx = arg0->x - p->x;
            if (dx > 0.0f && dx > D_800F4A00[p->idx].x) continue;
            if (dx <= 0.0f && dx < D_800F6188[p->idx].x) continue;
            dz = arg0->z - p->z;
            if (dz > 0.0f && dz > D_800F4A00[p->idx].z) continue;
            if (dz <= 0.0f && dz < D_800F6188[p->idx].z) continue;
            if (arg0->y <= p->y) {
                D_800BD0DC = 1;
            } else {
                D_800BD0DC = 0;
            }
        }
        if (p->type == 0x102A) {
            k = func_800609F8(p);
            if (k == 2) return 1;
            if (k == 1) return 0;
        }
        if (func_8000C43C() < 0x10) continue;
        if (p->type == 0x10D) {
            k = func_800609F8(p);
            if (k == 2) return 1;
            if (k == 1) return 0;
        }
        if (p->type == 0x128) {
            k = func_80060C94(p);
            if (k != 0) return 0;
        }
        if (p->type == 0x11D) {
            dy = arg0->y - p->y;
            if (abs((s32)dy) > 200) continue;
            dx = arg0->x - p->x;
            if (abs((s32)dx) > 200) continue;
            dz = arg0->z - p->z;
            if (abs((s32)dz) > 200) continue;
            d = dx * dx + dz * dz + dy;
            if (d > 40000) continue;
            arg0->x = arg0->px;
            arg0->z = arg0->pz;
        }
        if (p->type == 0x104) {
            dy = arg0->y - p->y;
            if (abs((s32)dy) > 300) continue;
            dx = arg0->x - p->x;
            ax = abs((s32)dx);
            if (ax > 300) continue;
            dz = arg0->z - p->z;
            az = abs((s32)dz);
            if (az > 300) continue;
            if (ax < 200 && az < 200 && dy > 100.0f && dy < 300.0f) {
                arg0->y = p->y + 300.0f;
                D_800BD10C = p;
                return 1;
            }
            if (dy > 100.0f) return 0;
            if (D_80107040 & 0x4000) {
                v = D_800AA1BC;
                for (i = 0; i < 4; i++) {
                    f32 ex = arg0->x - (p->x + v[i].x);
                    f32 ez = arg0->z - (p->z + v[i].z);
                    a[i] = ex * ex + ez * ez;
                }
                for (i = 0; i < 4; i++) {
                    b[i] = a[i] + a[(i + 1) & 3];
                }
                min = 0x7FFFFFFF;
                for (i = 0; i < 4; i++) {
                    if (b[i] < min) {
                        min = b[i];
                        k = i;
                    }
                }
                dx = arg0->x - arg0->px;
                dz = arg0->z - arg0->pz;
                switch (k) {
                case 3:
                    if (dx > 0.0f) {
                        p->x += dx;
                        arg0->z = arg0->pz;
                    }
                    break;
                case 2:
                    if (dz < 0.0f) {
                        p->z += dz;
                        arg0->x = arg0->px;
                    }
                    break;
                case 1:
                    if (dx < 0.0f) {
                        p->x += dx;
                        arg0->z = arg0->pz;
                    }
                    break;
                case 0:
                    if (dz > 0.0f) {
                        p->z += dz;
                        arg0->x = arg0->px;
                    }
                    break;
                }
            } else {
                arg0->x = arg0->px;
                arg0->z = arg0->pz;
                return 0;
            }
        }
        if (p->type == 0x10A) {
            dx = arg0->x - p->x;
            if (dx > 0.0f && dx > D_800F4A00[p->idx].x) continue;
            if (dx <= 0.0f && dx < D_800F6188[p->idx].x) continue;
            dz = arg0->z - p->z;
            if (dz > 0.0f && dz > D_800F4A00[p->idx].z) continue;
            if (dz <= 0.0f && dz < D_800F6188[p->idx].z) continue;
            {
            f32 y0 = p->y;
            dy = arg0->y - y0;
            dy2 = arg0->py - y0;
            }
            if (dy > 0.0f && dy > D_800F4A00[p->idx].y) continue;
            if (dy2 < 0.0f && dy2 + 75.0f < D_800F6188[p->idx].y) continue;
            func_8003AC08(arg0, p->y + D_800F4A00[p->idx].y, 1);
            do { D_800BD06C->vy = 3000.0f; } while (0);
            func_800433A8(arg0, 5, 0x100);
            return 1;
        }
        if (p->type == 0x132) {
            dx = arg0->x - p->x;
            if (dx > 0.0f && dx > D_800F4A00[p->idx].x) continue;
            if (dx <= 0.0f && dx < D_800F6188[p->idx].x) continue;
            dz = arg0->z - p->z;
            if (dz > 0.0f && dz > D_800F4A00[p->idx].z) continue;
            if (dz <= 0.0f && dz < D_800F6188[p->idx].z) continue;
            {
            f32 y0 = p->y;
            dy = arg0->y - y0;
            dy2 = arg0->py - y0;
            }
            if (dy > 0.0f && dy > D_800F4A00[p->idx].y) continue;
            if (dy2 < 0.0f && dy2 + 75.0f < D_800F6188[p->idx].y) continue;
            func_8003AC08(arg0, p->y + D_800F4A00[p->idx].y, 1);
            D_800BD06C->vy *= 5.75f;
            func_800433A8(arg0, 5, 0x100);
            return 1;
        }
        if (p->type == 0x119) {
            dx = arg0->x - p->x;
            if (dx > 0.0f && dx > D_800F4A00[p->idx].x) continue;
            if (dx <= 0.0f && dx < D_800F6188[p->idx].x) continue;
            dz = arg0->z - p->z;
            if (dz > 0.0f && dz > D_800F4A00[p->idx].z) continue;
            if (dz <= 0.0f && dz < D_800F6188[p->idx].z) continue;
            if (arg0->y + 400.0f < p->y) {
                func_8003BB90(arg0);
                return 1;
            }
        }
        if (p->type == 0x11A) {
            dx = arg0->x - p->x;
            if (dx > 0.0f && dx > D_800F4A00[p->idx].x) continue;
            if (dx <= 0.0f && dx < D_800F6188[p->idx].x) continue;
            dz = arg0->z - p->z;
            if (dz > 0.0f && dz > D_800F4A00[p->idx].z) continue;
            if (dz <= 0.0f && dz < D_800F6188[p->idx].z) continue;
        }
        if (p->type == 0x11C) {
            dx = arg0->x - p->x;
            if (dx > 0.0f && dx > D_800F4A00[p->idx].x) continue;
            if (dx <= 0.0f && dx < D_800F6188[p->idx].x) continue;
            dz = arg0->z - p->z;
            if (dz > 0.0f && dz > D_800F4A00[p->idx].z) continue;
            if (dz <= 0.0f && dz < D_800F6188[p->idx].z) continue;
            if (abs((s32)(p->y - arg0->y)) < 100) {
                func_8003BF98(arg0);
                return 1;
            }
        }
    }
    return ret;
}
