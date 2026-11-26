typedef struct Obj {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x38];
    f32 unk48;
    u8 pad4C[0x1C];
    s32 unk68;
    u8 pad6C[4];
    s32 unk70;
    u8 pad74[8];
    s32 unk7C;
    u8 pad80[0x1C];
    void *unk9C;
    void (*unkA0)(struct Obj *);
    u8 padA4[4];
    struct Obj *unkA8;
} Obj;
void actorSetAnim(void *, s32, s32);
Obj *func_8002E374(s32);
void func_8002D858(void *, void *);
s32 func_80043248(void *);
Obj *func_8006B020(void *);
void func_8002A360(s32, s32);
void func_8002D124(void);
s32 func_80023DBC(s32);
s32 func_80052B24(s32, char *, void *);
void func_8001B990(s32, s32);
void func_8006AB80(void *);
void func_80034F50(void *);
void func_8006B0C8(void *);
extern Obj *D_800B3960;
extern s32 D_800B4C28;

void func_8006ABD8(Obj *arg0)
{
    Obj *c;
    Obj *p;

    if (arg0->unk7C == 0) {
        actorSetAnim(arg0, 0x1A6, 0x100);
        arg0->unk7C = 1;
        arg0->unk70 = 0;
        arg0->y = 900.0f;
        c = func_8002E374(0x82);
        p = D_800B3960;
        c->unk68 = -1;
        c->x = arg0->x;
        c->y = arg0->y;
        c->z = arg0->z;
        c->unk9C = func_8006AB80;
        p->unkA8 = c;
        p->unk9C = func_80034F50;
        p->z = p->unk48;
    }
    func_8002D858(arg0, (s8 *)arg0 + 0x10);
    if ((arg0->unk70 = func_80043248(arg0)) != 0) {
        arg0->y = (f32)D_800B4C28;
        c = func_8006B020(arg0);
        actorSetAnim(c, 0xB6, 0x100);
        c->y = (f32)D_800B4C28;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x34);
        func_8002D124();
        if (func_80052B24(func_80023DBC(0xE0F), "cab_caf4", arg0) != 0) {
            c->unk9C = func_8006B0C8;
            func_8001B990(0x200, 0x24);
            arg0->unkA0(arg0);
        }
    }
}
