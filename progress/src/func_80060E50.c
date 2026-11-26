typedef struct Obj60 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    u8 pad14[8];
    s32 x1C;
    s32 x20;
    s32 x24;
    u8 pad28[0x18];
    f32 x40;
    u8 pad44[4];
    f32 x48;
    u8 pad4C[0x10];
    s32 x5C;
    u8 pad60[0x24];
    s32 x84;
    s32 x88;
    s32 x8C;
    u32 x90;
    u8 pad94[0xC];
    void (*xA0)(struct Obj60 *);
    u8 padA4[0x2C];
    s32 xD0;
    u8 padD4[8];
    f32 xDC;
    u8 padE0[0x10];
    s32 xF0;
} Obj60;
typedef struct Cam60 {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0xC0];
    s32 xD0;
} Cam60;
extern Cam60 *D_800BD06C;
extern s32 D_8014AB20;
s32 func_80024B0C(s32);
s32 func_80025100(s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
s32 func_8002D204(s32, s32, s32);
s32 func_8002D260(s32);
void func_8002D3E4(Obj60 *, s32);
void func_8002DA80(Obj60 *);
f32 func_8002DD60(f32);
s32 func_8003BF98(Obj60 *);
void func_8004303C(Obj60 *);
s32 func_80043248(Obj60 *);
void func_800433A8(Obj60 *, s32, s32);
void func_80061730(Obj60 *);
s32 func_80061740(Obj60 *);
s32 func_80076080(void);
s16 func_800944B0(u16);
s16 func_80095F60(u16);

void func_80060E50(Obj60 *obj) {
    s32 hx;
    s32 hz;
    s32 cx;
    s32 cz;
    s32 home;
    s32 cam;
    s32 px;
    s32 pz;
    s32 d;
    s32 hit;
    s32 x;
    s32 z;
    s32 done;
    f32 dy;

    if (func_80076080() != 0) {
        return;
    }
    hx = obj->x4 - (f32) obj->x1C;
    hz = obj->xC - (f32) obj->x24;
    home = func_80024B0C(hx * hx + hz * hz);
    cx = (f32) obj->x1C - D_800BD06C->x4;
    cz = (f32) obj->x24 - D_800BD06C->xC;
    cam = func_80024B0C(cx * cx + cz * cz);
    dy = D_800BD06C->x8 - obj->x8;
    switch (obj->x90) {
    case 0:
        obj->x1C = obj->x4;
        obj->x20 = obj->x8;
        obj->x24 = obj->xC;
        func_8002D3E4(obj, 0);
        obj->x90 = 1;
        break;
    case 1:
        func_8004303C(obj);
        if (obj->xD0 != 0x9C) {
            func_800433A8(obj, 0x9C, 0x100);
        }
        obj->x88 = func_8002D260(func_80025100(-cx, -cz));
        obj->x10 = func_8002D204(obj->x88, obj->x10, 0x1000);
        if (D_800BD06C->x0 == 3 && cam < 0x5DC && func_8002DD60(dy) < 400.0f) {
            obj->x40 = D_800BD06C->x4;
            obj->x48 = D_800BD06C->xC;
            obj->x90 = 2;
            obj->x8C = 0;
        }
        break;
    case 2:
        func_8004303C(obj);
        px = obj->x4 - D_800BD06C->x4;
        pz = obj->xC - D_800BD06C->xC;
        D_8014AB20 = func_80024B0C(px * px + pz * pz);
        hit = func_80061740(obj);
        if (hit != 0) {
            if (obj->xF0 == 0) {
                obj->xF0 = 0xFF;
                obj->x84++;
                if (obj->x84 >= 5) {
                    obj->x84 = 0;
                    func_80061730(obj);
                }
                if (hit == 1) {
                    func_8002A360(0xC, 0x80);
                    func_8002A360(8, 0x2E);
                    func_8002D124();
                }
            }
            break;
        }
        switch (obj->x8C) {
        case 0:
            func_8002D3E4(obj, 0x3E8);
            if (obj->xD0 != 0x9D) {
                func_800433A8(obj, 0x9D, 0x100);
            }
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x3C);
            obj->x8C = 1;
            break;
        case 1:
            func_8002DA80(obj);
            x = obj->x4 + (f32) ((func_80095F60(*(u16 *)((u8 *)obj + 0x12)) * 0x87) >> 0xE);
            z = obj->xC + (f32) ((func_800944B0(*(u16 *)((u8 *)obj + 0x12)) * 0x87) >> 0xE);
            px = x - obj->x40;
            pz = z - obj->x48;
            if (func_80024B0C(px * px + pz * pz) < 0x96) {
                func_8002D3E4(obj, 0);
                obj->x8C = 2;
            } else if (home > 0x5DC) {
                func_8002D3E4(obj, 0);
                obj->x8C = 4;
            }
            break;
        case 2:
            x = obj->x4 + (f32) ((func_80095F60(*(u16 *)((u8 *)obj + 0x12)) * 0x87) >> 0xE);
            z = obj->xC + (f32) ((func_800944B0(*(u16 *)((u8 *)obj + 0x12)) * 0x87) >> 0xE);
            px = x - D_800BD06C->x4;
            pz = z - D_800BD06C->xC;
            if (func_80024B0C(px * px + pz * pz) < 0x96) {
                func_800433A8(obj, 0x9E, 0x100);
                obj->x8C = 3;
            } else {
                obj->x8C = 4;
            }
            break;
        case 3:
            x = obj->x4 + (f32) ((func_80095F60(*(u16 *)((u8 *)obj + 0x12)) * 0x87) >> 0xE);
            z = obj->xC + (f32) ((func_800944B0(*(u16 *)((u8 *)obj + 0x12)) * 0x87) >> 0xE);
            px = x - D_800BD06C->x4;
            pz = z - D_800BD06C->xC;
            d = func_80024B0C(px * px + pz * pz);
            if (obj->xDC > 21.0 && obj->xDC < 24.0 && obj->xDC > 22.0 && D_800BD06C->xD0 != 0x16 && d < 0x96) {
                if (func_8003BF98(obj) == 0) {
                    func_800433A8(obj, 0x9D, 0x100);
                    obj->x8C = 5;
                }
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x2D);
            }
            if (d >= 0x96) {
                if (obj->xD0 != 0x9D) {
                    func_800433A8(obj, 0x9D, 0x100);
                }
                obj->x8C = 4;
            }
            break;
        case 4:
            if (cam < 0x5DC) {
                obj->x40 = D_800BD06C->x4;
                obj->x48 = D_800BD06C->xC;
                cx = obj->x4 - D_800BD06C->x4;
                cz = obj->xC - D_800BD06C->xC;
                obj->x10 = obj->x88 = func_8002D260(func_80025100(-cx, -cz));
                obj->x8C = 0;
            } else {
                obj->x8C = 5;
            }
            break;
        case 5:
            obj->x88 = func_8002D260(func_80025100(-hx, -hz));
            obj->x8C = 6;
            break;
        case 6:
            obj->x10 = func_8002D204(obj->x88, obj->x10, 0x1000);
            if (obj->x10 == obj->x88) {
                func_8002D3E4(obj, 0x3E8);
                obj->x8C = 7;
            }
            break;
        case 7:
            func_8002DA80(obj);
            if (home < 0xC8) {
                func_800433A8(obj, 0x9C, 0x100);
                func_8002D3E4(obj, 0);
                obj->x90 = 1;
            }
            break;
        }
        break;
    case 3:
        done = func_80043248(obj);
        switch (obj->x8C) {
        case 0:
            obj->x8C = 1;
            break;
        case 1:
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x3D);
            func_800433A8(obj, 0x9F, 0x100);
            obj->x8C = 2;
            break;
        case 2:
            if (done != 0) {
                obj->x8C = 3;
            }
            break;
        case 3:
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
}
