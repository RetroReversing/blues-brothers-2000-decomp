typedef struct {
    s32 pad0;
    f32 x4;
    f32 y8;
    f32 zC;
    u8 pad10[0x44 - 0x10];
    f32 f44;
    u8 pad48[0x50 - 0x48];
    s32 i50;
    u8 pad54[0x9C - 0x54];
    void (*cb9C)(void);
    u8 padA0[0xB0 - 0xA0];
    s32 iB0;
} Obj;

extern Obj *D_800BD06C;
void func_800131F8(void);

void func_80013308(Obj *obj) {
    s32 dx_1;
    s32 dx_2;
    s32 dz;

    obj->i50 = 0;
    obj->iB0 = 0;
    obj->y8 = obj->f44;
    dx_1 = D_800BD06C->x4 - obj->x4;
    dz = D_800BD06C->zC - obj->zC;
    dx_2 = abs(dx_1);
    if (dx_2 < 201) {
        if (((dz < 0) ? -dz : dz) < 201) {
            obj->cb9C = func_800131F8;
        }
    }
}
