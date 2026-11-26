typedef struct Ent8820 {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    char pad10[0xA8];
    s32 room;
    char padBC[0x4C];
} Ent8820;

typedef struct Vec3i8820 {
    s32 x;
    s32 y;
    s32 z;
} Vec3i8820;

typedef struct Vec3f8820 {
    f32 x;
    f32 y;
    f32 z;
} Vec3f8820;

typedef struct Cell8820 {
    u8 pad[6];
    u8 flags;
    u8 pad7;
} Cell8820;

typedef struct Hit8820 {
    Ent8820 *e;
    s16 idx;
} Hit8820;

extern Ent8820 *func_80023088(s32);
extern Ent8820 *func_800230B0(s32);
extern void func_800899DC(u8 *, ...);
extern f32 D_8014A8F8[3];
extern f32 D_8014A908[3];
extern u8 D_800B76A0[];
extern Cell8820 *D_800F80E8[];
extern Vec3i8820 D_800F4A00[];
extern Vec3i8820 D_800F6188[];
extern s32 D_800F90A0[];
extern s8 (*D_800F9878[])[4];
extern Hit8820 D_80140FF8[];
extern u8 D_80007CC0[];

#define COUNT (*(s32 *)D_800B76A0)

void func_80048820(Vec3f8820 *lo, Vec3f8820 *hi, s32 flags) {
    f32 d1[4];
    f32 d2[4];
    s32 mn[4];
    s32 mx[4];
    Ent8820 *e;
    Ent8820 *end;
    Ent8820 *start;
    s32 ok;
    s32 room;
    s32 x0;
    s32 x1;
    s32 z0;
    s32 z1;
    s32 n;
    s32 i;
    s8 (*cell)[4];
    Hit8820 *h;

    D_8014A8F8[0] = lo->x;
    D_8014A908[0] = lo->x;
    D_8014A8F8[1] = lo->y;
    D_8014A908[1] = lo->y;
    D_8014A8F8[2] = lo->z;
    D_8014A908[2] = lo->z;
    COUNT = 0;
    if (hi->x < D_8014A8F8[0]) {
        D_8014A8F8[0] = hi->x;
    }
    if (D_8014A908[0] < hi->x) {
        D_8014A908[0] = hi->x;
    }
    if (hi->y < D_8014A8F8[1]) {
        D_8014A8F8[1] = hi->y;
    }
    if (D_8014A908[1] < hi->y) {
        D_8014A908[1] = hi->y;
    }
    if (hi->z < D_8014A8F8[2]) {
        D_8014A8F8[2] = hi->z;
    }
    if (D_8014A908[2] < hi->z) {
        D_8014A908[2] = hi->z;
    }
    start = func_80023088(0);
    end = func_800230B0(0);
    for (e = start; e <= end; e++) {
        ok = e->type == 0x102;
        if (e->type == 0x105) {
            ok = 1;
        }
        if (flags & 0x10) {
            if (e->type == 0x10E) {
                ok = 1;
            }
        }
        if ((flags & 8) && e->type == 0x13B) {
            ok = 1;
        }
        if (ok == 0) {
            continue;
        }
        if (D_800F80E8[e->room] == NULL) {
            continue;
        }
        d1[0] = lo->x - e->x;
        d1[1] = lo->y - e->y;
        d1[2] = lo->z - e->z;
        d2[0] = hi->x - e->x;
        d2[1] = hi->y - e->y;
        d2[2] = hi->z - e->z;
        if (d1[0] < d2[0]) {
            mn[0] = d1[0];
            mx[0] = d2[0];
        } else {
            mn[0] = d2[0];
            mx[0] = d1[0];
        }
        if (d1[1] < d2[1]) {
            mn[1] = d1[1];
            mx[1] = d2[1];
        } else {
            mx[1] = d1[1];
            mn[1] = d2[1];
        }
        if (d1[2] < d2[2]) {
            mn[2] = d1[2];
            mx[2] = d2[2];
        } else {
            mn[2] = d2[2];
            mx[2] = d1[2];
        }
        room = e->room;
        if (mn[0] > D_800F4A00[room].x) {
            continue;
        }
        if (mx[0] < D_800F6188[room].x) {
            continue;
        }
        if (mn[2] > D_800F4A00[room].z) {
            continue;
        }
        if (mx[2] < D_800F6188[room].z) {
            continue;
        }
        x0 = mn[0] >> 7;
        x1 = mx[0] >> 7;
        z0 = mn[2] >> 7;
        z1 = mx[2] >> 7;
        n = D_800F90A0[room];
        cell = D_800F9878[room];
        for (i = 0; i < n; i++) {
            if (cell[i][1] < x0) {
                continue;
            }
            if (x1 < cell[i][0]) {
                continue;
            }
            if (cell[i][3] < z0) {
                continue;
            }
            if (z1 < cell[i][2]) {
                continue;
            }
            if (D_800F80E8[e->room][i].flags & 0x10) {
                continue;
            }
            h = &D_80140FF8[COUNT];
            h->e = e;
            h->idx = i;
            COUNT++;
        }
        if (COUNT >= 4000) {
            func_800899DC(D_80007CC0);
        }
    }
}
