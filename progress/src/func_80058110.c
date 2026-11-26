typedef struct Obj58 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    u8 pad14[0x48];
    s32 x5C;
    u8 pad60[0x20];
    s32 x80;
    s32 x84;
    s32 x88;
    s32 x8C;
    u32 x90;
    u8 pad94[0xC];
    void (*xA0)(struct Obj58 *);
    u8 padA4[0x14];
    s32 xB8;
    u8 padBC[4];
    s32 xC0;
} Obj58;
typedef struct Ent58 {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0xB0];
    s32 xC0;
    u8 padC4[0x44];
} Ent58;
typedef struct Row58 {
    s32 x0;
    s32 x4;
    s32 x8;
} Row58;
typedef struct Cam58 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
} Cam58;
extern Cam58 *D_800BD06C;
extern Ent58 *D_800AB9BC;
extern Ent58 *D_800AB9C0;
extern Ent58 *D_8014AAC0;
extern Row58 D_800F4A00[];
extern s32 D_800F7910[];
s32 func_8004303C(void);
s32 func_80025100(s32, s32);
s32 func_8002D260(s32);
s32 func_8002D204(s32, s32, s32);
s32 func_80024B0C(s32);
void func_8002A360(s32, s32);
void func_800433A8(Obj58 *, s32, s32);
void func_80043328(Obj58 *, s32, s32);
f32 func_8002DD60(f32);
float sqrtf(float);

void func_80058110(Obj58 *obj) {
    s32 r;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 a;
    s32 b;
    Ent58 *e;
    Row58 *row;
    f32 fx;
    f32 fz;
    f32 lim;
    f32 d;
    f32 k;

    r = func_8004303C();
    switch (obj->x90) {
    case 0:
        obj->x84 = 0;
        obj->x80 = 0;
        obj->xC0 = 0;
        obj->x90 = 1;
        obj->x8C = 0;
        func_800433A8(obj, 0x77, 0x100);
        break;
    case 1:
        dx = obj->x4 - D_800BD06C->x4;
        dz = obj->xC - D_800BD06C->xC;
        obj->x88 = func_8002D260(func_80025100(-dx, -dz));
        obj->x10 = func_8002D204(obj->x88, obj->x10, 0x1000);
        for (e = D_800AB9BC; e <= D_800AB9C0; e++) {
            if (e->x0 != 0x1008) {
                continue;
            }
            dx = obj->x4 - e->x4;
            a = dx * dx;
            dy = obj->x8 - e->x8;
            dz = obj->xC - e->xC;
            b = dz * dz;
            if (func_80024B0C(a + dy * dy + b) < 0xC8) {
                if (obj->x84 == 0) {
                    obj->x90 = 2;
                    obj->x8C = 0;
                    D_8014AAC0 = e;
                    break;
                }
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x15);
            }
            if (func_80024B0C(a + b) < 0x190) {
                if (e->x8 < obj->x8 && !(e->xC0 & 4)) {
                    e->x8 = obj->x8;
                    e->xC0 |= 2;
                }
            }
        }
        if (obj->xC0 & 8) {
            obj->x90 = 3;
            obj->x8C = 0;
        }
        break;
    case 2:
        switch (obj->x8C) {
        case 0:
            obj->x8C = 1;
            obj->x10 = obj->x88 = func_8002D260(func_80025100(-dx, -dz));
            func_800433A8(obj, 0x7B, 0x600);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x3A);
            D_8014AAC0->xC0 |= 1;
            obj->x84 = 1;
            break;
        case 1:
            if (r != 0) {
                func_80043328(obj, 0x7E, 0x100);
                obj->x8C = 2;
            }
            break;
        case 2:
            if (r != 0) {
                obj->x90 = 1;
                obj->x8C = 0;
                func_80043328(obj, 0x77, 0x100);
            }
            break;
        }
        break;
    case 3:
        switch (obj->x8C) {
        case 0:
            func_80043328(obj, 0x7E, 0x100);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x3A);
            obj->x8C = 1;
            break;
        case 1:
            if (r != 0) {
                func_80043328(obj, 0x7E, 0x100);
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x3A);
            }
            break;
        case 2:
            obj->x5C -= 0x18;
            if (obj->x5C < 0) {
                obj->x5C = 0;
                obj->x90 = 4;
            }
            break;
        }
        break;
    case 4:
        obj->xA0(obj);
        break;
    }
    row = &D_800F4A00[obj->xB8];
    if (!(obj->x8 + (f32) row->x4 + 300.0f < D_800BD06C->x8)) {
        fx = obj->x4 - D_800BD06C->x4;
        fz = obj->xC - D_800BD06C->xC;
        lim = (f32) D_800F7910[obj->xB8] / 3.0f;
        if (!(lim < func_8002DD60((f32) dx)) && !(lim < func_8002DD60((f32) dz))) {
            d = sqrtf(fx * fx + fz * fz);
            if (!(lim < d)) {
                k = lim - d;
                D_800BD06C->x4 -= fx * k / d;
                D_800BD06C->xC -= fz * k / d;
            }
        }
    }
}
