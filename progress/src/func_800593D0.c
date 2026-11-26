int abs(int);
typedef struct Actor Actor;
struct Actor {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x34 - 0x14];
    s32 unk34;
    u8 pad38[0x64 - 0x38];
    s32 unk64;
    s32 unk68;
    u8 pad6C[0x84 - 0x6C];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
    void (*unkA0)(Actor *);
    u8 padA4[0xD0 - 0xA4];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    s32 unkD8;
    f32 unkDC;
};

s32 func_80024394(s32, s32);
s32 func_80024B0C(s32);
s32 func_80025100(s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
s32 func_8002D204(s32, s32, s32);
s32 func_8002D5CC(Actor *);
void func_8003B980(Actor *);
void func_8003BF98(Actor *);
s32 func_8003C9AC(Actor *, s32, s32, s32);
s32 func_8004303C(Actor *);
void func_80043328(Actor *, s32, s32);
void func_800433A8(Actor *, s32, s32);
void func_8004EB60(Actor *);
void func_80059CA8(Actor *);
s32 func_80083920(Actor *, s32);
void func_8007631C(void);
extern s32 D_800B7FB0;
extern Actor *D_800BD06C;
extern s32 D_8014AAE0;

void func_800593D0(Actor *arg0)
{
    Actor *a = arg0;
    f32 fx, fy, fz;
    s32 dx, dy, dz;
    s32 done;
    s32 r;

    fx = D_800BD06C->x;
    fx -= a->x;
    dx = fx;
    fy = D_800BD06C->y;
    fy -= a->y;
    dy = abs((s32)fy);
    fz = D_800BD06C->z;
    fz -= a->z;
    dz = fz;
    if (dy >= 751) {
        return;
    }
    D_8014AAE0 = func_80024B0C(dx * dx + dz * dz);
    switch (a->unk90) {
    case 0:
        a->unk90 = 1;
        a->unk8C = 0;
        func_800433A8(a, 0x39, 0x100);
        break;
    case 1:
        a->unk68 = -1;
        if (D_8014AAE0 < 1000) {
            func_80043328(a, 0x39, 0x100);
            a->unk68 = 13;
            a->unk90 = 2;
            a->unk8C = 0;
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x18);
        }
        break;
    case 2:
        done = func_8004303C(a);
        a->unk10 = func_8002D204(func_80025100(dx, dz), a->unk10, 0xC00);
        r = func_80083920(a, a->unk90 == 3 && a->unk8C == 1);
        switch (r) {
        case 1:
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x2E);
            func_8002D124();
            func_800433A8(a, 0x3B, 0x100);
            a->unk90 = 3;
            a->unk8C = r;
            return;
        case 2:
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x17);
            func_8002D124();
            func_800433A8(a, 0x3C, 0x100);
            a->unk90 = 3;
            a->unk8C = 0;
            a->unk88 = a->unk34;
            break;
        }
        switch (a->unk8C) {
        case 0:
            if (done) {
                func_80043328(a, 0x3E, 0x100);
                a->unk8C = 1;
            }
            break;
        case 1:
            if (D_8014AAE0 > 1000) {
                func_800433A8(a, 0x3A, 0x100);
                a->unk8C = 2;
                break;
            }
            if (done) {
                func_80043328(a, 0x38, 0x100);
            }
            if (D_8014AAE0 < 1000) {
                if (func_80024394(0, 100) > 50) {
                    func_8002A360(12, 0x80);
                    func_8002A360(8, 0x16);
                    func_800433A8(a, 0x3E, 0x100);
                } else {
                    func_8002A360(12, 0x80);
                    func_8002A360(8, 0x16);
                    func_800433A8(a, 0x3D, 0x100);
                }
                D_800B7FB0 = 0;
                a->unk8C = 3;
            }
            break;
        case 2:
            if (done) {
                a->unk68 = -1;
                a->unk90 = 1;
                a->unk8C = 0;
            }
            break;
        case 3:
            if (D_800B7FB0 == 0 && a->unkD0 == 0x3D && 13.0f <= a->unkDC && a->unkDC <= 19.0f) {
                func_8002A360(12, 0x80);
                func_8002A360(8, 0x2D);
                D_800B7FB0 = 1;
            }
            r = func_80083920(a, a->unk90 == 3 && a->unk8C == 1);
            switch (r) {
            case 1:
                func_8002A360(12, 0x80);
                func_8002A360(8, 0x2E);
                func_8002D124();
                func_800433A8(a, 0x3B, 0x100);
                a->unk90 = 3;
                a->unk8C = r;
                return;
            case 2:
                func_8002A360(12, 0x80);
                func_8002A360(8, 0x17);
                func_8002D124();
                func_800433A8(a, 0x3C, 0x100);
                a->unk90 = 3;
                a->unk8C = 0;
                a->unk88 = a->unk34;
                break;
            }
            if (a->unkD0 == 0x3E && 13.0f <= a->unkDC && a->unkDC <= 15.0f && (u32)(D_8014AAE0 - 176) < 299) {
                if (D_800B7FB0 == 0) {
                    D_800B7FB0 = 1;
                    func_8002A360(12, 0x80);
                    func_8002A360(8, 0x2D);
                }
                if (func_8003C9AC(a, 0, 1, 0) != 0) {
                    func_8003BF98(D_800BD06C);
                    func_80059CA8(a);
                }
                a->unk8C = 4;
            }
            if (a->unkD0 == 0x3D && 13.0f <= a->unkDC && a->unkDC <= 19.0f && (u32)(D_8014AAE0 - 176) < 299) {
                if (D_800B7FB0 == 0) {
                    D_800B7FB0 = 1;
                    func_8002A360(12, 0x80);
                    func_8002A360(8, 0x2D);
                }
                func_8003B980(D_800BD06C);
                a->unk8C = 4;
                break;
            }
            if (done) {
                a->unk8C = 1;
            }
            break;
        case 4:
            if (done) {
                func_80043328(a, 0x38, 0x100);
                a->unk8C = 5;
            }
            break;
        case 5:
            if (a->unk84 == 0) {
                a->unk64 = 200;
                a->unk8C = 6;
            }
            break;
        case 6:
            if (func_8002D5CC(a) != 0) {
                a->unk8C = 1;
            }
            break;
        }
        break;
    case 3:
        done = func_8004303C(a);
        switch (a->unk8C) {
        case 0:
            a->unk9C = func_8007631C;
            a->unkD8 = 0;
            break;
        case 1:
            if (done) {
                func_80043328(a, 0x38, 0x100);
                a->unk90 = 2;
                a->unk8C = 0;
            }
            break;
        }
        break;
    case 4:
        func_8004EB60(a);
        a->unkA0(a);
        break;
    }
}
