typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct Tri {
    u16 v[3];
    u8 flags;
    u8 pad;
} Tri;

typedef struct Obj {
    s32 x0;
    char pad4[0xB8 - 0x4];
    s32 xB8;
    char padBC[0xEC - 0xBC];
    s32 xEC;
    char padF0[0x108 - 0xF0];
} Obj;

Obj *func_80023088(s32);
Obj *func_800230B0(s32);

extern s32 D_800B76A8;
extern Tri *D_800F80E8[];
extern s32 D_800F90A0[];
extern u8 *D_800FA860[];
extern GfxW *D_80177E18;

#define GFX(a, b) { GfxW *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }

void func_80048FF4(s32 mask) {
    Obj *o;
    Obj *end;
    Obj *p;
    Tri *t;
    u8 *vtx;
    s32 i;
    s32 f;

    if ((mask & 3) || ((mask & 0xC) && D_800B76A8 > 0)) {
        GFX(0xE7000000, 0);
        GFX(0xD9D0F9FA, 0);
        GFX(0xD9FFFFFF, 0x200205);
        GFX(0xE3000A01, 0);
        GFX(0xE200001C, 0x504E50);
        GFX(0xFCFFFFFF, 0xFFFDF6FB);
        p = func_80023088(0);
        end = func_800230B0(0);
        for (o = p; o <= end; o++) {
            if (o->x0 == 0x102 && D_800F80E8[o->xB8] != NULL) {
                vtx = D_800FA860[o->xB8];
                GFX(0xDA380003, o->xEC + 0x80000000);
                for (i = 0; i < D_800F90A0[o->xB8]; i++) {
                    t = &D_800F80E8[o->xB8][i];
                    f = t->flags & mask;
                    if (f != 0) {
                        if (f & 8) {
                            GFX(0xFA000000, 0xFFFF3C);
                        } else if (f & 4) {
                            GFX(0xFA000000, 0xFFFF003C);
                        } else if (f & 2) {
                            GFX(0xFA000000, 0xFF00003C);
                        } else if (f & 1) {
                            GFX(0xFA000000, 0xFF3C);
                        } else {
                            GFX(0xFA000000, 0xFFFFFF3C);
                        }
                        GFX(0xFA000000, 0xFF3C);
                        GFX(0x01001002, (u32)(vtx + t->v[0] * 16));
                        GFX(0x01001004, (u32)(vtx + t->v[1] * 16));
                        GFX(0x01001006, (u32)(vtx + t->v[2] * 16));
                        GFX(0x05000204, 0);
                    }
                }
            }
        }
        GFX(0xE7000000, 0);
        GFX(0xFA000000, 0);
        GFX(0xE3000A01, 0);
    }
}

