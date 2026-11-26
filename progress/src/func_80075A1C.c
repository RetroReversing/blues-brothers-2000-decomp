typedef struct { f32 x, y, z; } Vec3;
typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj72DA4 {
    s32 kind;
    f32 x, y, z;
    s32 angle;
    u8 pad14[0x40 - 0x14];
    f32 unk40;
    u8 pad44[0x64 - 0x44];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x78 - 0x74];
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x8C - 0x84];
    s32 unk8C;
    u8 pad90[0xA0 - 0x90];
    void (*update)(struct Obj72DA4 *);
    struct Obj72DA4 *parent;
    u8 padA8[0xB8 - 0xA8];
    s32 unkB8;
} Obj72DA4;

s32 func_80024394(s32, s32);
void func_8002ADFC(s32, s32, Obj72DA4 *);
s32 func_8002D5CC(Obj72DA4 *);
void func_8002DAC8(f32 *, f32 *);
void func_8002DB6C(void *, void *, f32);
void func_8002DC84(void *);
void func_8002DD8C(void *, void *, void *, ...);
Obj72DA4 *func_8003B980(Obj72DA4 *);
s32 func_80050144(Obj72DA4 *, s32);
extern s32 D_800B8398[];
extern Obj72DA4 *D_800BD06C;
extern Vec3i D_800F4A00[];
extern Vec3i D_800F6188[];

f32 func_8002D340(f32, f32, f32);
void func_800899DC(char *);
extern char D_800091FC[];
extern Obj72DA4 *D_800B3964;
extern s32 D_800B9ECC;

void func_80075A1C(Obj72DA4 *arg0) {
    f32 sp10[10];
    f32 sp38[10];
    Vec3 sp60;
    Vec3 sp70;
    Vec3 sp80;
    f32 a;
    f32 d;
    f32 v;
    s32 i;
    s32 flag;
    Vec3i *p;
    Vec3i *q;

    flag = 0;
    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        arg0->unk8C = 0;
        arg0->x = arg0->unk40 + 12500.0f;
    }
    switch (arg0->unk8C) {
    case 0:
        arg0->kind = 0x144;
        if (D_800B3964->unk8C != 0) {
            arg0->unk8C++;
        }
        break;
    case 1:
        flag = 1;
        arg0->kind = 0x102;
        v = func_8002D340(arg0->unk40, arg0->x, D_800B9ECC * 12);
        arg0->x = v;
        if (v == arg0->unk40) {
            arg0->unk8C++;
        }
        break;
    case 2:
        if (D_800B3964->unk8C == 0) {
            arg0->unk8C++;
        }
        break;
    case 3:
        v = func_8002D340(arg0->unk40 - 12500.0f, arg0->x, D_800B9ECC * 15);
        flag = 1;
        arg0->x = v;
        if (v == arg0->unk40 - 12500.0f) {
            arg0->unk8C++;
        }
        break;
    case 4:
        arg0->unk7C = 0;
        break;
    default:
        func_800899DC(D_800091FC);
        break;
    }
    if (flag != 0) {
        func_8002DC84(sp38);
        a = arg0->angle;
        a *= 6.283185307179586;
        a *= (1.0 / 65536.0);
        func_8002DB6C(sp10, sp38, a);
        i = arg0->unkB8;
        p = &D_800F6188[i];
        sp60.x = p->x;
        sp60.y = p->y;
        sp60.z = p->z;
        q = &D_800F4A00[i];
        sp70.x = q->x;
        sp70.y = q->y;
        sp70.z = q->z;
        func_8002DD8C(&sp80, sp10, &sp60, i);
        sp60.x = sp80.x;
        sp60.y = sp80.y;
        sp60.z = sp80.z;
        func_8002DD8C(&sp80, sp10, &sp70);
        sp70.x = sp80.x;
        sp70.y = sp80.y;
        sp70.z = sp80.z;
        if (sp70.x < sp60.x) {
            func_8002DAC8(&sp70.x, &sp60.x);
        }
        if (sp70.y < sp60.y) {
            func_8002DAC8(&sp70.y, &sp60.y);
        }
        if (sp70.z < sp60.z) {
            func_8002DAC8(&sp70.z, &sp60.z);
        }
        d = D_800BD06C->x - arg0->x;
        flag = 0;
        if (d > 0.0f) {
            if (sp70.x < d) {
                flag = 1;
            }
        }
        if (d <= 0.0f) {
            if (d < sp60.x) {
                flag++;
            }
        }
        d = D_800BD06C->z - arg0->z;
        if (d > 0.0f) {
            if (sp70.z < d) {
                flag++;
            }
        }
        if (d <= 0.0f) {
            if (d < sp60.z) {
                flag++;
            }
        }
        if (flag == 0 && D_800BD06C->y <= arg0->y + (f32)D_800F6188[arg0->unkB8].y && D_800BD06C->kind == 3) {
            func_8003B980(D_800BD06C);
        }
    }
}
