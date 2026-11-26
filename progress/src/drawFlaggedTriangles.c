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

Obj *getObjPoolStart(s32);
Obj *getObjPoolEnd(s32);

extern s32 D_800B76A8;
extern Tri *gObjTriLists[];
extern s32 gObjTriCounts[];
extern u8 *gObjVertBases[];
extern GfxW *D_80177E18;

#define GFX(a, b) { GfxW *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }

/* Builds the display list that tints the triangles of type-0x102 objects whose flags match flagMask, one colour per flag bit. */ void drawFlaggedTriangles(s32 flagMask) {
    Obj *obj;
    Obj *poolEnd;
    Obj *poolStart;
    Tri *tri;
    u8 *vtxBase;
    s32 triIdx;
    s32 flagBits;

    if ((flagMask & 3) || ((flagMask & 0xC) && D_800B76A8 > 0)) {
        GFX(0xE7000000, 0);
        GFX(0xD9D0F9FA, 0);
        GFX(0xD9FFFFFF, 0x200205);
        GFX(0xE3000A01, 0);
        GFX(0xE200001C, 0x504E50);
        GFX(0xFCFFFFFF, 0xFFFDF6FB);
        poolStart = getObjPoolStart(0);
        poolEnd = getObjPoolEnd(0);
        for (obj = poolStart; obj <= poolEnd; obj++) {
            if (obj->x0 == 0x102 && gObjTriLists[obj->xB8] != NULL) {
                vtxBase = gObjVertBases[obj->xB8];
                GFX(0xDA380003, obj->xEC + 0x80000000);
                for (triIdx = 0; triIdx < gObjTriCounts[obj->xB8]; triIdx++) {
                    tri = &gObjTriLists[obj->xB8][triIdx];
                    flagBits = tri->flags & flagMask;
                    if (flagBits != 0) {
                        if (flagBits & 8) {
                            GFX(0xFA000000, 0xFFFF3C);
                        } else if (flagBits & 4) {
                            GFX(0xFA000000, 0xFFFF003C);
                        } else if (flagBits & 2) {
                            GFX(0xFA000000, 0xFF00003C);
                        } else if (flagBits & 1) {
                            GFX(0xFA000000, 0xFF3C);
                        } else {
                            GFX(0xFA000000, 0xFFFFFF3C);
                        }
                        GFX(0xFA000000, 0xFF3C);
                        GFX(0x01001002, (u32)(vtxBase + tri->v[0] * 16));
                        GFX(0x01001004, (u32)(vtxBase + tri->v[1] * 16));
                        GFX(0x01001006, (u32)(vtxBase + tri->v[2] * 16));
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

