void sendCommand(s32, s32);
void actorSetAnim(void *, s32, s32, s32);
void func_8005EB70(void *);
int abs(int);
extern s32 D_80140240;
typedef struct { char pad[4]; f32 x, y, z; char p2[0x40]; f32 x50; char p3[0x7C]; s32 xD0; char p4[0x1C]; s32 xF0; } O;
s32 func_8005EEDC(O *arg0, O *arg1) {
    s32 dx, dy, dz;
    dx = arg0->x - arg1->x;
    dy = arg0->y - arg1->y;
    dz = arg0->z - arg1->z;
    if (dy > 0 && arg1->xD0 != 0xE3 && abs(dx) < 0x4B && abs(dz) < 0x4B && arg0->xD0 == 5 && arg0->x50 < 0.0f && dy < 0x118) {
        arg0->x50 = D_80140240;
        arg0->y += 1.0f;
        actorSetAnim(arg0, 5, 0x100, dy);
        sendCommand(0xC, 0x80);
        sendCommand(8, 2);
        func_8005EB70(arg1);
        arg1->xF0 = 0xFF;
        return 1;
    }
    return 0;
}
