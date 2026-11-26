typedef struct Chan {
    u8 pad0[4];
    u8 *pdata;
    u8 pad8[4];
    s32 time;
    u8 pad10[0x34 - 0x10];
    s32 x34;
    s32 x38;
    s32 x3C;
    s32 x40;
    s32 handle;
    u8 pad48[0x74 - 0x48];
    s32 id;
    u8 pad78[0x9A - 0x78];
    u16 x9A;
    u8 pad9C[0xAA - 0x9C];
    u16 xAA;
    u16 xAC;
    u8 padAE[0xB7 - 0xAE];
    u8 xB7;
    u8 padB8[0xBB - 0xB8];
    u8 xBB;
    u8 padBC[0xD2 - 0xBC];
    u8 xD2;
    u8 xD3;
    u8 padD4[0x13C - 0xD4];
} Chan;

extern u8 *(*D_800BA650[])(Chan *, u8 *);
void func_8008DAB8(s32);
void func_8008ED20(Chan *);
void func_8008EDE4(Chan *);
s32 func_8008F760(void);
extern s32 D_8017B204;
extern Chan *D_8017B20C;

s32 func_8008D0CC(s32 id, s32 marker)
{
    s32 h;
    Chan *c;
    s32 i;
    u8 *p;
    u8 cmd;
    u8 v;
    u8 b;
    u8 *p2;
    s32 len;
    u8 *q;

    h = func_8008F760();
    c = D_8017B20C;
    for (i = 0; i < D_8017B204; i++, c++) {
        if (c->handle != h || c->id != id || c->pdata == NULL) {
            continue;
        }
    next:
            p = c->pdata;
            cmd = *p;
            if (cmd >= 0x80) {
                if (cmd == 0xAB && p[1] == marker) {
                    goto done;
                }
                c->pdata = D_800BA650[cmd & 0x7F](c, p + 1);
            } else {
                c->pdata = p + 1;
                if (c->xD2 != 0) {
                    c->pdata = p + 2;
                    v = p[1];
                    c->xBB = v;
                    if (v >= 0x80) {
                        c->xBB = v & 0x7F;
                        c->xD2 = 0;
                        c->xD3 = c->xBB;
                    }
                } else {
                    c->xBB = c->xD3;
                }
                if (c->xAC == 0 || c->xB7 != 0) {
                    p2 = c->pdata;
                    c->xB7 = 0;
                    c->pdata = p2 + 1;
                    b = p2[0];
                    if (b < 0x80) {
                        c->x9A = b;
                    } else {
                        c->pdata = p2 + 2;
                        c->x9A = p2[1] + ((b & 0x7F) << 8);
                    }
                } else {
                    c->x9A = c->xAC;
                }
                c->time += c->x9A << 8;
            }
        if (c->pdata != NULL) {
            goto next;
        }
    done:
        c->x3C = c->time;
        if (c->pdata != NULL) {
            p2 = c->pdata;
            len = p2[2];
            q = p2 + 3;
            if (len >= 0x80) {
                len &= 0x7F;
                len <<= 8;
                len |= p2[3];
                q = p2 + 4;
            }
            c->xAA = 0;
            c->x9A = len;
            c->pdata = q;
            c->time -= len << 8;
        }
        c->x40 = c->time;
        if (c->x38 != 0) {
            func_8008ED20(c);
        }
        if (c->x34 != 0) {
            func_8008EDE4(c);
        }
    }
    func_8008DAB8(h);
    return h;
}
