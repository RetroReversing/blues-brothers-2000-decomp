typedef struct Vtx16 {
    s16 x;
    s16 y;
    s16 z;
    char pad[10];
} Vtx16;

typedef struct Tri {
    u16 v[3];
    u8 flags;
    u8 x7;
} Tri;

typedef struct {
    u8 pad0[8];
    s16 val;
    u8 padA[2];
} Mat;

typedef struct {
    u8 pad0[0x18];
    Mat *mats;
    Vtx16 *verts;
    u8 *cmds;
} Model;

void setupCollisionTri(Vtx16 *verts, s32 *idx, s8 *box, Tri *tri);
void debugPrintf(const char *);
extern s32 D_80140FF0;

void func_80048D08(Model *m, s8 (*box)[4], Tri *tri)
{
    u8 *p;
    Mat *mats;
    s32 base;
    s32 n;
    s32 idx[3];
    u16 w;

    base = 0;
    n = 0;
    p = m->cmds;
    mats = m->mats;
    while (*p != 0xFF) {
        switch (*p) {
        case 0:
            p += 3;
            break;
        case 1:
            base += n;
            n = p[1] & 0x3F;
            p += 2;
            break;
        case 2:
        case 3:
            p += 6;
            break;
        case 4:
            w = (p[1] << 8) | p[2];
            idx[0] = (w & 0x1F) + base;
            w >>= 5;
            idx[1] = (w & 0x1F) + base;
            w >>= 5;
            idx[2] = (w & 0x1F) + base;
            setupCollisionTri(m->verts, idx, *box++, tri++);
            p += 3;
            break;
        case 5:
            w = p[2] | (p[1] << 8);
            idx[0] = (w & 0x1F) + base;
            w >>= 5;
            idx[1] = (w & 0x1F) + base;
            w >>= 5;
            idx[2] = (w & 0x1F) + base;
            setupCollisionTri(m->verts, idx, *box++, tri++);
            w = p[4] | (p[3] << 8);
            idx[0] = (w & 0x1F) + base;
            w >>= 5;
            idx[1] = (w & 0x1F) + base;
            w >>= 5;
            idx[2] = (w & 0x1F) + base;
            setupCollisionTri(m->verts, idx, *box++, tri++);
            p += 5;
            break;
        case 6:
            w = p[2];
            D_80140FF0 = w;
            D_80140FF0 = mats[w].val;
            p += 8;
            break;
        default:
            debugPrintf("RSP decode error");
            break;
        }
    }
}
