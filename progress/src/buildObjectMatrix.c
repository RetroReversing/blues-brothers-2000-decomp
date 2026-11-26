typedef struct { s32 x, y, z; } Vec3i;
typedef struct { s16 i[4][4]; u16 f[4][4]; } Mtx;
typedef struct { u32 w0, w1; } Gfx;
typedef struct {
    u8 pad0[0x28];
    f32 pos[3];
    Vec3i scale;
    u8 pad40[0xEC - 0x40];
    Mtx *mtx;
} Obj;

void func_80022720(void);
void func_80024D5C(s32 *out, s32 *a, s32 *b);
void debugPrintf(char *fmt, ...);
extern char D_80000E90[];
extern char D_80000EC4[];
extern s32 D_800AB9A0;
extern s32 D_800B9EB8;
extern Mtx D_800CD530[][2];
extern Gfx *D_80177E18;
extern s32 D_80177E28[];

/* Builds the object's transform (rotation, scale, position) into the next pooled matrix, then queues it for the RSP. Returns the matrix index. */
s32 buildObjectMatrix(Obj *obj, s32 *rot, s32 mul)
{
    s32 buf[9];
    s32 tmp[9];
    s32 sc[3];
    s32 *m;
    s32 *r;
    s32 uniform;
    s16 *ip;
    Mtx *mtx;

    m = buf;
    r = tmp;
    uniform = 0;
    if (obj->pos[0] > 32767.0f) { obj->pos[0] = 32767.0f; func_80022720(); }
    if (obj->pos[1] > 32767.0f) { obj->pos[1] = 32767.0f; func_80022720(); }
    if (obj->pos[2] > 32767.0f) { obj->pos[2] = 32767.0f; func_80022720(); }
    if (obj->pos[0] < -32767.0f) { obj->pos[0] = -32767.0f; func_80022720(); }
    if (obj->pos[1] < -32767.0f) { obj->pos[1] = -32767.0f; func_80022720(); }
    if (obj->pos[2] < -32767.0f) { obj->pos[2] = -32767.0f; func_80022720(); }
    sc[0] = obj->scale.x;
    sc[1] = obj->scale.y;
    sc[2] = obj->scale.z;
    if (sc[0] == sc[1] && sc[0] == sc[2]) {
        uniform = 1;
        r = rot;
    } else {
        r[0] = (rot[0] * sc[0]) >> 8;
        r[1] = (rot[1] * sc[1]) >> 8;
        r[2] = (rot[2] * sc[2]) >> 8;
        r[3] = (rot[3] * sc[0]) >> 8;
        r[4] = (rot[4] * sc[1]) >> 8;
        r[5] = (rot[5] * sc[2]) >> 8;
        r[6] = (rot[6] * sc[0]) >> 8;
        r[7] = (rot[7] * sc[1]) >> 8;
        r[8] = (rot[8] * sc[2]) >> 8;
    }
    if (mul) {
        func_80024D5C(m, D_80177E28, r);
    } else {
        m = r;
    }
    if (uniform) {
        m[0] = (m[0] * sc[0]) >> 8;
        m[1] = (m[1] * sc[1]) >> 8;
        m[2] = (m[2] * sc[2]) >> 8;
        m[3] = (m[3] * sc[0]) >> 8;
        m[4] = (m[4] * sc[1]) >> 8;
        m[5] = (m[5] * sc[2]) >> 8;
        m[6] = (m[6] * sc[0]) >> 8;
        m[7] = (m[7] * sc[1]) >> 8;
        m[8] = (m[8] * sc[2]) >> 8;
    }
    ip = D_800CD530[D_800AB9A0][D_800B9EB8].i[0];
    ip[0] = m[0] >> 15;
    ip[1] = m[3] >> 15;
    ip[2] = m[6] >> 15;
    ip[3] = 0;
    ip[4] = m[1] >> 15;
    ip[5] = m[4] >> 15;
    ip[6] = m[7] >> 15;
    ip[7] = 0;
    ip[8] = m[2] >> 15;
    ip[9] = m[5] >> 15;
    ip[10] = m[8] >> 15;
    ip[11] = 0;
    ip[12] = obj->pos[0];
    ip[13] = obj->pos[1];
    ip[14] = obj->pos[2];
    ip[15] = 1;
    ip += 16;
    ip[0] = m[0] << 1;
    ip[1] = m[3] << 1;
    ip[2] = m[6] << 1;
    ip[3] = 0;
    ip[4] = m[1] << 1;
    ip[5] = m[4] << 1;
    ip[6] = m[7] << 1;
    ip[7] = 0;
    ip[8] = m[2] << 1;
    ip[9] = m[5] << 1;
    ip[10] = m[8] << 1;
    ip[11] = 0;
    ip[12] = 0;
    ip[13] = 0;
    ip[14] = 0;
    ip[15] = 0;
    {
        Gfx *g = D_80177E18++;
        mtx = &D_800CD530[D_800AB9A0][D_800B9EB8];
        D_800AB9A0++;
        g->w0 = 0xDA380003;
        g->w1 = (u32)mtx + 0x80000000;
    }
    obj->mtx = mtx;
    if (D_800AB9A0 >= 420) {
        debugPrintf(D_80000E90, D_800AB9A0, 420, D_80000EC4, 180);
    }
    return D_800AB9A0 - 1;
}
