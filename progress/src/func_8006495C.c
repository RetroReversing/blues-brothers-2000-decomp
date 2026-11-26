typedef struct Pos {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
} Pos;

typedef struct Obj495C {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
    char pad10[0x30];
    f32 hx;
    f32 hy;
    f32 hz;
    char pad4C[0x3C];
    s32 off;
    char pad8C[0x10];
    void *fn;
    char padA0[8];
    Pos *link;
} Obj495C;

extern s32 func_8000C43C(void);
extern void func_8001FF64(Obj495C *);
extern s32 func_8002D298(s32, s32, s32);
extern f32 func_8002D340(f32, f32, f32);
extern void func_80034FEC(Obj495C *, s32 *);
extern void func_80036FB8(Obj495C *, s32);
extern void func_80064808();
extern f32 D_80008BDC;
extern f32 D_80008BE0;
extern f32 D_80008BE4;
extern f32 D_80008BE8;
extern f32 D_80008BEC;
extern f32 D_80008BF0;
extern f32 D_80008BF4;
extern f32 D_80008BF8;
extern f32 D_80008BFC;
extern f32 D_80008C00;
extern f32 D_80008C04;
extern f32 D_80008C08;
extern u8 D_800B9EAC[];
extern u8 D_800B9EB0[];
extern u8 D_800B9ECC[];
extern u8 D_800BD06C[];
extern s32 D_800BD278[];
extern s32 D_800BD688[];
extern u8 D_80107040[];

#define CAM (*(Pos **)D_800BD06C)

void func_8006495C(Obj495C *arg0) {
    s32 v[3];
    Pos *link;
    f32 t;
    f32 scale;
    f32 r;
    f32 c;
    f32 k;
    f32 hx;
    f32 u;
    f32 fz;

    if ((*(s32 *)D_80107040) & 2) {
        arg0->off = func_8002D298(-500, arg0->off, (*(s32 *)D_800B9ECC) * 20);
    } else if ((*(s32 *)D_80107040) & 1) {
        arg0->off = func_8002D298(500, arg0->off, (*(s32 *)D_800B9ECC) * 20);
    } else {
        arg0->off = func_8002D298(0, arg0->off, (*(s32 *)D_800B9ECC) * 20);
    }
    do {
    link = arg0->link;
    } while (0);
    if (link != NULL) {
        t = CAM->x;
        k = CAM->z * D_80008BDC;
        v[0] = ((link->x + 2.0f * t) - t * D_80008BDC) * D_80008BE0;
        v[1] = link->y + CAM->y + (f32) arg0->off;
        fz = ((link->z + 2.0f * CAM->z) - k) * D_80008BE0;
    } else {
        v[0] = CAM->x;
        v[1] = CAM->y + D_80008BE4;
        fz = CAM->z;
    }
    v[2] = fz;
    switch (func_8000C43C()) {
    case 5:
        arg0->fn = func_80064808;
        scale = (f32) (D_800BD688[2] - D_800BD278[2]);
        arg0->z = func_8002D340(CAM->z - D_80008BE8, arg0->z, (f32) ((*(s32 *)D_800B9ECC) * 50));
        hx = arg0->hx;
        u = arg0->hy;
        (*(f32 *)D_800B9EB0) = arg0->z / scale;
        arg0->x = hx;
        arg0->y = u;
        (*(f32 *)D_800B9EAC) = arg0->x / (f32) (D_800BD688[0] - D_800BD278[0]);
        break;
    case 0x21:
        arg0->link = NULL;
        arg0->z = func_8002D340(CAM->z - D_80008BEC, arg0->z, (f32) ((*(s32 *)D_800B9ECC) * 450));
        arg0->x = func_8002D340(CAM->x + (f32) arg0->off, arg0->x, (f32) ((*(s32 *)D_800B9ECC) * 450));
        r = func_8002D340(CAM->y + D_80008BF0, arg0->y, (f32) ((*(s32 *)D_800B9ECC) * 450));
        arg0->y = r;
        if (D_80008BF4 < r) {
            arg0->y = D_80008BF4;
        }
        if (v[1] >= 0x19AB) {
            v[1] = 0x19AA;
        }
        if (arg0->x > D_80008BF8) {
            arg0->x = D_80008BF8;
        }
        if (arg0->x < D_80008BFC) {
            arg0->x = D_80008BFC;
        }
        v[0] += arg0->off;
        break;
    case 0x37:
        c = D_80008C00;
        arg0->z = func_8002D340(CAM->z, arg0->z, c);
        arg0->x = func_8002D340(CAM->x + D_80008C04, arg0->x, c);
        arg0->y = func_8002D340(CAM->y + D_80008C08, arg0->y, 50.0f);
        break;
    default:
        arg0->z = arg0->hz;
        arg0->x = arg0->hx;
        arg0->y = arg0->hy;
        break;
    }
    func_80034FEC(arg0, v);
    func_8001FF64(arg0);
    func_80036FB8(arg0, 3);
}
