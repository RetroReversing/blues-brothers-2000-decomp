typedef struct Rec { char pad[0x7C]; s32 f7C; char pad2[0x1C]; void *f9C; char pad3[0x108 - 0xA0]; } Rec;
typedef struct Obj { char pad[0x5C]; s32 f5C; char pad2[0x40]; void (*fA0)(struct Obj *); } Obj;
extern Rec *D_800AB9BC;
extern Rec *D_800AB9C0;
void func_8006982C(void);
void func_80069858(Obj *o) {
    Rec *p;
    o->f5C -= 6;
    if (o->f5C < 6) {
        for (p = D_800AB9BC; p <= D_800AB9C0; p++) {
            if (p->f9C == func_8006982C) p->f7C = 1;
        }
        o->fA0(o);
    }
}
