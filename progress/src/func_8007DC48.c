extern s32 D_800B396C;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
typedef struct { char pad[0x6C]; s32 x6C; char p1[0xC]; s32 x7C; char p2[0x2C]; f32 xAC; s32 xB0; s32 xB4; char p3[8]; s32 xC0; char p4[0x18]; s32 xDC; } O;

void func_8007DC48(O *arg0) {
    if (arg0->x7C == 0) {
        arg0->x7C = 1;
        D_800B3970 = 0x18;
        D_800B3974 = 8;
        D_800B3978 = 0x3C;
        D_800B396C = 0x3D2;
        arg0->xB0 = 0;
        arg0->xB4 = 0;
        arg0->xDC = 0;
        arg0->xC0 = 0;
        arg0->x6C = -1;
        arg0->xAC = 0.05f;
    }
}
