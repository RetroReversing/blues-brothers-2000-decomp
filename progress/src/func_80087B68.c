typedef struct { f32 x, y, z; } Vec3;
typedef struct Obj87B68 {
    s32 kind;
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x84 - 0x74];
    s32 unk84;
    u8 pad88[0xA8 - 0x88];
    struct Obj87B68 *unkA8;
    u8 padAC[0xBC - 0xAC];
    s32 unkBC;
    s32 unkC0;
    u8 padC4[0xE8 - 0xC4];
    s32 unkE8;
} Obj87B68;

void func_8002A360(s32, s32);
s32 tickActorTimer(Obj87B68 *);
void func_8002D604(Obj87B68 *);
void func_80047824(s32, s32, s32, s32, s32);
void func_80047864(s32, s32, s32, s32, s32);
extern Vec3 D_800B9B60[];
extern s32 gPadPressed[];
extern s32 gStickX[];
extern Obj87B68 *gIntroActors[];

void func_80087B68(Obj87B68 *arg0) {
    s32 v;
    s32 n;
    Obj87B68 *p;

    if (arg0->unkC0 == 0) {
        v = gStickX[arg0->unkBC];
        if (v < 0) {
            v = -v;
        }
        if (v < 20) {
            arg0->unk64 = 0;
        }
        if (tickActorTimer(arg0) != 0) {
            arg0->unk64 = 0;
            if ((gPadPressed[arg0->unkBC] & 0x200) || gStickX[arg0->unkBC] < -30) {
            dec:
                arg0->unk84 = (arg0->unk84 - 1) & 3;
                if (arg0->unkA8->unk84 == arg0->unk84) {
                    goto dec;
                }
                arg0->unk64 = 25;
                func_8002A360(12, 0x80);
                func_8002A360(8, 0x9F);
            }
            if ((gPadPressed[arg0->unkBC] & 0x100) || gStickX[arg0->unkBC] >= 31) {
            inc:
                arg0->unk84 = (arg0->unk84 + 1) & 3;
                if (arg0->unkA8->unk84 == arg0->unk84) {
                    goto inc;
                }
                arg0->unk64 = 25;
                func_8002A360(12, 0x80);
                func_8002A360(8, 0xA0);
            }
        }
        arg0->unk70 = 80;
        arg0->unk84 &= 3;
        arg0->x = D_800B9B60[arg0->unk84].x;
        arg0->y = D_800B9B60[arg0->unk84].y + 400.0f;
        arg0->z = D_800B9B60[arg0->unk84].z;
        func_8002D604(arg0);
        func_8002D604(arg0);
        if (gPadPressed[arg0->unkBC] & 0x9000) {
            func_8002A360(12, 0x80);
            func_8002A360(8, 0xA5);
            p = gIntroActors[arg0->unk84];
            arg0->unkC0 = 1;
            func_80047864(p->unkE8, 0, 0, 120, -100);
            func_80047864(p->unkE8, 0, 0, 120, -100);
            if (arg0->unkBC != 0) {
                func_80047824(p->unkE8, 0, 0, 0, 255);
                func_80047824(p->unkE8, 0, 0, 0, 255);
            } else {
                func_80047824(p->unkE8, 0, 255, 0, 0);
                func_80047824(p->unkE8, 0, 255, 0, 0);
            }
            p->unkC0 = 1;
        }
    } else if (arg0->unkC0 == 1) {
        arg0->unk70 = 100;
        arg0->unk10 = 0;
        if (gPadPressed[arg0->unkBC] & 0x9000) {
            func_8002A360(12, 0x80);
            func_8002A360(8, 0x9C);
            p = gIntroActors[arg0->unk84];
            func_80047864(p->unkE8, 0, 100, 0, -100);
            func_80047864(p->unkE8, 0, 100, 0, -100);
            func_80047824(p->unkE8, 0, 255, 255, 255);
            func_80047824(p->unkE8, 0, 255, 255, 255);
            arg0->unkC0 = 0;
            p->unkC0 = 0;
        }
    }
}
