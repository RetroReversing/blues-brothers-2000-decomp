s32 func_8000C43C(void);
f32 func_8002D340(f32, f32, f32);
void func_8002D620(void *);
f32 func_8002DD60(f32);
void func_800433A8(void *, s32, s32);
f32 sqrtf(f32);
void func_800340B4(void);
void func_800351D4(void);
void func_800393F4(void);
void func_8004303C(void);
void func_8007CB84(void);

typedef struct Obj {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    char pad10[0x44 - 0x10];
    f32 x44;
    char pad48[0x50 - 0x48];
    s32 x50;
    char pad54[0x74 - 0x54];
    s32 x74;
    char pad78[0x7C - 0x78];
    s32 x7C;
    char pad80[0x8C - 0x80];
    s32 x8C;
    s32 x90;
    char pad94[0x9C - 0x94];
    void (*fn9C)(void);
    char padA0[0xA8 - 0xA0];
    struct Obj *xA8;
} Obj;

extern f64 D_80009578;
extern f64 D_80009580;
extern f32 D_80009588;
extern f32 D_8000958C;
extern Obj *D_800B3960[];
extern u8 D_800B3964[];
extern u8 D_800B9ECC[];
extern u8 D_800BD06C[];
extern u8 D_801700E0[];
extern u8 D_801700E4[];
#define BD (*(Obj **)D_800BD06C)
#define P60 (D_800B3960[0])
#define P64 (*(Obj **)D_800B3964)

void func_8007BE98(Obj *arg0) {
    f32 dx;
    f32 dz;
    f32 dy;
    f32 dist;
    f32 r;
    Obj *bd;
    s32 t;

    dx = arg0->x4 - BD->x4;
    dz = arg0->xC - BD->xC;
    dy = arg0->x8 - BD->x8;
    dist = sqrtf(dx * dx + dz * dz);
    if (arg0->x7C == 0) {
        if (func_8000C43C() == 0x3C) {
            P64->xA8 = arg0;
            arg0->x7C = 1;
            arg0->x90 = 0;
            func_8002D620(arg0);
        }
        return;
    }
    if (arg0->x90 != 0) {
        switch (arg0->x90) {
        case 1:
            if (dist < D_80009578) {
                func_800433A8(BD, 1, 0x100);
                {
                    Obj *b1 = BD;
                b1->fn9C = func_8004303C;
                b1->x0 = 3;
                b1->x50 = 0;
                b1->x90 = 1;
                }
                P60->fn9C = func_800351D4;
                arg0->x90 = 2;
                arg0->x8C = 0x898;
            }
            break;
        case 2:
            arg0->x8 = func_8002D340(arg0->x44 + (f32)arg0->x8C, arg0->x8, (f32)(*(s32 *)D_800B9ECC * 10));
            BD->x8 = arg0->x8 + (f32)*(s32 *)D_801700E4;
            if (arg0->x8 == arg0->x44 + (f32)arg0->x8C) {
                BD->x74 = *(s32 *)D_801700E0;
                BD->fn9C = func_800393F4;
                arg0->x90 = 3;
            }
            break;
        case 3:
            P60->fn9C = func_800340B4;
            if (D_80009580 < dist) {
                arg0->x90 = 4;
            }
            break;
        case 4:
            arg0->x8 = func_8002D340(arg0->x44, arg0->x8, (f32)(*(s32 *)D_800B9ECC * 10));
            if (arg0->x8 == arg0->x44) {
                arg0->x90 = 5;
            }
            break;
        case 5:
            if (func_8002DD60(dy) < D_80009588) {
                arg0->x90 = 1;
            }
            break;
        }
    } else if (P64->x7C == 2 && dist < D_8000958C) {
        bd = BD;
        if (bd->x90 != 0) {
            *(s32 *)D_801700E0 = bd->x74;
            bd->x74 = 0;
            *(s32 *)D_801700E4 = bd->x8 - arg0->x8;
            P64->fn9C = func_8007CB84;
            P64->x7C = 0;
        }
    }
}
