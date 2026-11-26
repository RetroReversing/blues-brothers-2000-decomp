typedef struct Obj {
    f32 x00;
    f32 x;      /* 0x04 */
    f32 y;      /* 0x08 */
    f32 z;      /* 0x0C */
    s32 angle;  /* 0x10 */
    u8 pad14[0x64];
    s32 floor;  /* 0x78 */
    u8 pad7C[0x20];
    void *x9C;  /* 0x9C */
    u8 padA0[0x20];
    s32 xC0;    /* 0xC0 */
    u8 padC4[0x44];
} Obj;

s16 coss(u16);
s16 sins(u16);
void func_8002DA40(Obj *);
void func_80023078(void);

void func_8001AC3C(Obj *arg0) {
    Obj tmp;

    func_8002DA40(arg0);
    if (arg0->y <= (f32)arg0->floor) {
        arg0->xC0 = 1;
        arg0->y = arg0->floor;
        arg0->x9C = (void *)((u32)func_80023078 + 8);
        tmp.x = arg0->x + ((sins(arg0->angle) * 25) >> 13);
        tmp.y = arg0->y;
        tmp.z = arg0->z + ((coss(arg0->angle) * 25) >> 13);
    }
}
