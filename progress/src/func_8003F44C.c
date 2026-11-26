typedef struct {
    u8 pad0[2];
    u16 frames;
    u8 pad4[3];
    u8 flags;
} AnimHdr;

typedef struct {
    f32 base;
    f32 mul;
} AnimScale;

typedef struct {
    s32 pos;
    s32 scl;
    s32 rotBits;
} AnimTrack;

typedef struct {
    s32 v[9];
} Key9;

typedef struct {
    f32 v[9];
} Out9;

typedef struct {
    AnimHdr *hdr;
    AnimScale *scale;
    u8 pad8[0xC - 0x8];
    s32 rotShift;
    u8 pad10[0x14 - 0x10];
    f32 sclMul;
    s32 count;
    u8 pad1C[0x30 - 0x1C];
    u8 *p;
    s32 bit;
    u8 pad38[0x40 - 0x38];
    s32 frame;
    AnimTrack *tracks;
    Key9 *acc;
    Key9 *cur;
} AnimDec;

void func_8003F2A4(AnimDec *);
extern f64 D_80007870;

#define NIBBLE(dst)                                         \
    {                                                       \
        s32 t;                                              \
        if (bit < 5) {                                      \
            t = *p >> bit;                                  \
        } else {                                            \
            t = (*p >> bit) | (p[1] << (8 - bit));          \
        }                                                   \
        dst = t & 0xF;                                      \
    }                                                       \
    bit += 4;                                               \
    if (bit >= 8) {                                         \
        bit -= 8;                                           \
        p++;                                                \
    }

#define ONEBIT(dst)                                         \
    dst = (*p >> bit) & 1;                                  \
    bit += 1;                                               \
    if (bit >= 8) {                                         \
        bit -= 8;                                           \
        p++;                                                \
    }

#define BITS(dst, n)                                                        \
    k = n;                                                                  \
    dst = 0;                                                                \
    sh = 0;                                                                 \
    while (k >= 8) {                                                        \
        if (bit == 0) {                                                     \
            dst |= *p << sh;                                                \
        } else {                                                            \
            dst |= (((*p >> bit) | (p[1] << (8 - bit))) & 0xFF) << sh;      \
        }                                                                   \
        p++;                                                                \
        k -= 8;                                                             \
        sh += 8;                                                            \
    }                                                                       \
    if (k > 0) {                                                            \
        switch (k) {                                                        \
        case 1:                                                             \
            dst |= ((*p >> bit) & 1) << sh;                                 \
            break;                                                          \
        case 2:                                                             \
            if (bit < 7) {                                                  \
                dst |= ((*p >> bit) & 3) << sh;                             \
            } else {                                                        \
                dst |= (((*p >> 7) | (p[1] << 1)) & 3) << sh;               \
            }                                                               \
            break;                                                          \
        case 3:                                                             \
            if (bit < 6) {                                                  \
                dst |= ((*p >> bit) & 7) << sh;                             \
            } else {                                                        \
                dst |= (((*p >> bit) | (p[1] << (8 - bit))) & 7) << sh;     \
            }                                                               \
            break;                                                          \
        case 4:                                                             \
            if (bit < 5) {                                                  \
                dst |= ((*p >> bit) & 0xF) << sh;                           \
            } else {                                                        \
                dst |= (((*p >> bit) | (p[1] << (8 - bit))) & 0xF) << sh;   \
            }                                                               \
            break;                                                          \
        case 5:                                                             \
            if (bit < 4) {                                                  \
                dst |= ((*p >> bit) & 0x1F) << sh;                          \
            } else {                                                        \
                dst |= (((*p >> bit) | (p[1] << (8 - bit))) & 0x1F) << sh;  \
            }                                                               \
            break;                                                          \
        case 6:                                                             \
            if (bit < 3) {                                                  \
                dst |= ((*p >> bit) & 0x3F) << sh;                          \
            } else {                                                        \
                dst |= (((*p >> bit) | (p[1] << (8 - bit))) & 0x3F) << sh;  \
            }                                                               \
            break;                                                          \
        case 7: {                                                           \
            s32 t;                                                          \
            if (bit < 2) {                                                  \
                t = *p >> bit;                                              \
            } else {                                                        \
                t = (*p >> bit) | (p[1] << (8 - bit));                      \
            }                                                               \
            dst |= (t & 0x7F) << sh;                                        \
            break;                                                          \
        }                                                                   \
        }                                                                   \
        bit += k;                                                           \
        if (bit >= 8) {                                                     \
            bit -= 8;                                                       \
            p++;                                                            \
        }                                                                   \
    }

void func_8003F44C(AnimDec *o, Out9 *out) {
    u8 *p;
    s32 bit;
    s32 n0;
    s32 n1;
    s32 n2;
    s32 j;
    s32 x;
    s32 y;
    s32 z;
    s32 rx;
    s32 ry;
    s32 rz;
    s32 sx;
    s32 sy;
    s32 sz;
    s32 flag;
    s32 mask;
    s32 kr;
    s32 k;
    s32 sh;

    p = o->p;
    bit = o->bit;
    n0 = 0;
    if (o->hdr->flags & 1) {
        NIBBLE(n0);
        if (n0 == 0xF) {
            n0 = 0x11;
        }
    }
    NIBBLE(n1);
    if (n1 == 0xF) {
        n1 = 0x11;
    }
    NIBBLE(n2);
    if (n2 == 0xF) {
        n2 = 0x11;
    }
    for (j = 0; j < o->count; j++) {
        x = y = z = 0;
        if ((o->hdr->flags & 1) && o->tracks[j].pos != 0 && n0 > 0) {
            ONEBIT(flag);
            if (flag != 0) {
                BITS(x, n0);
                if ((x >> (n0 - 1)) & 1) {
                    x |= -(1 << n0);
                }
                BITS(y, n0);
                if ((y >> (n0 - 1)) & 1) {
                    y |= -(1 << n0);
                }
                BITS(z, n0);
                if ((z >> (n0 - 1)) & 1) {
                    z |= -(1 << n0);
                }
            }
        }
        rx = ry = rz = 0;
        if (n1 > 0) {
            kr = n1;
            if (o->tracks[j].rotBits < kr) {
                kr = o->tracks[j].rotBits;
            }
            if (bit < 6) {
                mask = (*p >> bit) & 7;
            } else {
                mask = ((*p >> bit) | (p[1] << (8 - bit))) & 7;
            }
            bit += 3;
            if (bit >= 8) {
                bit -= 8;
                p++;
            }
            if (mask & 1) {
                BITS(rx, kr);
                if ((rx >> (kr - 1)) & 1) {
                    rx |= -(1 << kr);
                }
                if (rx >= 0) {
                    rx += 1;
                }
            }
            if (mask & 2) {
                BITS(ry, kr);
                if ((ry >> (kr - 1)) & 1) {
                    ry |= -(1 << kr);
                }
                if (ry >= 0) {
                    ry += 1;
                }
            }
            if (mask & 4) {
                BITS(rz, kr);
                if ((rz >> (kr - 1)) & 1) {
                    rz |= -(1 << kr);
                }
                if (rz >= 0) {
                    rz += 1;
                }
            }
        }
        sx = sy = sz = 0;
        if (o->tracks[j].scl != 0 && n2 > 0) {
            ONEBIT(flag);
            if (flag != 0) {
                BITS(sx, n2);
                if ((sx >> (n2 - 1)) & 1) {
                    sx |= -(1 << n2);
                }
                BITS(sy, n2);
                if ((sy >> (n2 - 1)) & 1) {
                    sy |= -(1 << n2);
                }
                do {
                    BITS(sz, n2);
                } while (0);
                if ((sz >> (n2 - 1)) & 1) {
                    sz |= -(1 << n2);
                }
            }
        }
        if (o->frame < 2) {
            o->cur[j].v[0] = x;
            do {
                o->cur[j].v[1] = y;
            } while (0);
            o->cur[j].v[2] = z;
            o->cur[j].v[3] = rx;
            o->cur[j].v[4] = ry;
            o->cur[j].v[5] = rz;
            o->cur[j].v[6] = sx;
            o->cur[j].v[7] = sy;
            o->cur[j].v[8] = sz;
        } else {
            o->cur[j].v[0] += x;
            o->cur[j].v[1] += y;
            o->cur[j].v[2] += z;
            o->cur[j].v[3] += rx;
            o->cur[j].v[4] += ry;
            o->cur[j].v[5] += rz;
            o->cur[j].v[6] += sx;
            o->cur[j].v[7] += sy;
            o->cur[j].v[8] += sz;
        }
        o->acc[j].v[0] += o->cur[j].v[0];
        o->acc[j].v[1] += o->cur[j].v[1];
        o->acc[j].v[2] += o->cur[j].v[2];
        o->acc[j].v[3] += o->cur[j].v[3];
        o->acc[j].v[4] += o->cur[j].v[4];
        o->acc[j].v[5] += o->cur[j].v[5];
        o->acc[j].v[6] += o->cur[j].v[6];
        o->acc[j].v[7] += o->cur[j].v[7];
        o->acc[j].v[8] += o->cur[j].v[8];
        if (out != NULL) {
            out[j].v[0] = o->scale->base + o->acc[j].v[0] * o->scale->mul;
            out[j].v[1] = o->scale->base + o->acc[j].v[1] * o->scale->mul;
            out[j].v[2] = o->scale->base + o->acc[j].v[2] * o->scale->mul;
            out[j].v[3] = (f32) o->acc[j].v[3] * D_80007870 / (f32) (1 << o->rotShift);
            out[j].v[4] = (f32) o->acc[j].v[4] * D_80007870 / (f32) (1 << o->rotShift);
            out[j].v[5] = (f32) o->acc[j].v[5] * D_80007870 / (f32) (1 << o->rotShift);
            out[j].v[6] = o->acc[j].v[6] * o->sclMul;
            out[j].v[7] = o->acc[j].v[7] * o->sclMul;
            out[j].v[8] = o->acc[j].v[8] * o->sclMul;
        }
    }
    o->p = p;
    o->bit = bit;
    o->frame++;
    if (o->frame >= o->hdr->frames) {
        func_8003F2A4(o);
    }
}
