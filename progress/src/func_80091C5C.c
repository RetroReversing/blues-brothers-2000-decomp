typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef Byte Bytef;
typedef uInt uIntf;

typedef struct z_stream_s {
    Bytef *next_in;
    uInt avail_in;
    uLong total_in;
    Bytef *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    void *state;
    void *(*zalloc)(void *, uInt, uInt);
    void (*zfree)(void *, void *);
    void *opaque;
} z_stream;
typedef z_stream *z_streamp;

typedef struct inflate_huft_s inflate_huft;
struct inflate_huft_s {
    union {
        struct {
            Byte Exop;
            Byte Bits;
        } what;
        Bytef *pad;
    } word;
    union {
        uInt Base;
        inflate_huft *Next;
    } more;
};

typedef struct inflate_codes_state inflate_codes_statef;

typedef enum {
    TYPE, LENS, STORED, TABLE, BTREE, DTREE, CODES, DRY, DONE, BAD
} inflate_block_mode;

typedef struct inflate_blocks_state {
    inflate_block_mode mode;
    union {
        uInt left;
        struct {
            uInt table;
            uInt index;
            uIntf *blens;
            uInt bb;
            inflate_huft *tb;
        } trees;
        struct {
            inflate_huft *tl;
            inflate_huft *td;
            inflate_codes_statef *codes;
        } decode;
    } sub;
    uInt last;
    uInt bitk;
    uLong bitb;
    Bytef *window;
    Bytef *end;
    Bytef *read;
    Bytef *write;
} inflate_blocks_statef;

#define Z_OK 0
#define Z_STREAM_END 1
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR (-3)
#define Z_MEM_ERROR (-4)
#define Z_NULL 0

extern uInt D_800BA950[];
#define inflate_mask D_800BA950
extern uInt D_80009E80[];
#define border D_80009E80
extern char D_80009ECC[];
extern char D_80009EE0[];
extern char D_80009F00[];
extern char D_80009F24[];

void func_8008A0C4(void);
int func_80093D90(inflate_blocks_statef *, z_streamp, int);
int func_800929FC(inflate_blocks_statef *, z_streamp, int);
inflate_codes_statef *func_80092980(uInt, uInt, inflate_huft *, inflate_huft *, z_streamp);
void func_80093214(inflate_codes_statef *, z_streamp);
int func_80093D08(inflate_huft *, z_streamp);
int func_80093858(uIntf *, uIntf *, inflate_huft **, z_streamp);
int func_80093908(uInt, uInt, uIntf *, uIntf *, uIntf *, inflate_huft **, inflate_huft **, z_streamp);
int func_80093B04(uIntf *, uIntf *, inflate_huft **, inflate_huft **);
void *memcpy(void *, const void *, uInt);
#define inflate_flush func_80093D90
#define inflate_codes func_800929FC
#define inflate_codes_new func_80092980
#define inflate_codes_free func_80093214
#define inflate_trees_free func_80093D08
#define inflate_trees_bits func_80093858
#define inflate_trees_dynamic func_80093908
#define inflate_trees_fixed func_80093B04
#define zmemcpy memcpy
#define ZALLOC(z, items, size) (*((z)->zalloc))((z)->opaque, (items), (size))
#define ZFREE(z, addr) (*((z)->zfree))((z)->opaque, (void *)(addr))

#define UPDBITS {s->bitb=b;s->bitk=k;}
#define UPDIN {z->avail_in=n;z->total_in+=p-z->next_in;z->next_in=p;}
#define UPDOUT {s->write=q;}
#define UPDATE {UPDBITS UPDIN UPDOUT}
#define LEAVE {UPDATE return inflate_flush(s,z,r);}
#define LOADIN {p=z->next_in;n=z->avail_in;b=s->bitb;k=s->bitk;}
#define NEEDBYTE {if(n)r=Z_OK;else LEAVE}
#define NEXTBYTE (n--,*p++)
#define NEEDBITS(j) {while(k<(j)){NEEDBYTE;b|=((uLong)NEXTBYTE)<<k;k+=8;}}
#define DUMPBITS(j) {b>>=(j);k-=(j);}
#define WAVAIL (uInt)(q<s->read?s->read-q-1:s->end-q)
#define LOADOUT {q=s->write;m=(uInt)WAVAIL;}
#define WRAP {if(q==s->end&&s->read!=s->window){q=s->window;m=(uInt)WAVAIL;}}
#define FLUSH {UPDOUT r=inflate_flush(s,z,r); LOADOUT}
#define NEEDOUT {if(m==0){WRAP if(m==0){FLUSH WRAP if(m==0) LEAVE}}r=Z_OK;}
#define LOAD {LOADIN LOADOUT}

int func_80091C5C(inflate_blocks_statef *s, z_streamp z, int r) {
    uInt t;
    uLong b;
    uInt k;
    Bytef *p;
    uInt n;
    Bytef *q;
    uInt m;

    LOAD

    while (1) {
        func_8008A0C4();
        switch (s->mode) {
        case TYPE:
            NEEDBITS(3)
            t = (uInt)b & 7;
            s->last = t & 1;
            switch (t >> 1) {
            case 0:
                DUMPBITS(3)
                t = k & 7;
                DUMPBITS(t)
                s->mode = LENS;
                break;
            case 1:
                {
                    uInt bl, bd;
                    inflate_huft *tl, *td;

                    func_8008A0C4();
                    inflate_trees_fixed(&bl, &bd, &tl, &td);
                    s->sub.decode.codes = inflate_codes_new(bl, bd, tl, td, z);
                    if (s->sub.decode.codes == Z_NULL) {
                        r = Z_MEM_ERROR;
                        LEAVE
                    }
                    s->sub.decode.tl = Z_NULL;
                    s->sub.decode.td = Z_NULL;
                }
                DUMPBITS(3)
                s->mode = CODES;
                break;
            case 2:
                DUMPBITS(3)
                s->mode = TABLE;
                break;
            case 3:
                DUMPBITS(3)
                s->mode = BAD;
                z->msg = D_80009ECC;
                r = Z_DATA_ERROR;
                LEAVE
            }
            break;
        case LENS:
            NEEDBITS(32)
            if ((((~b) >> 16) & 0xffff) != (b & 0xffff)) {
                s->mode = BAD;
                z->msg = D_80009EE0;
                r = Z_DATA_ERROR;
                LEAVE
            }
            s->sub.left = (uInt)b & 0xffff;
            b = k = 0;
            s->mode = s->sub.left ? STORED : (s->last ? DRY : TYPE);
            break;
        case STORED:
            if (n == 0)
                LEAVE
            NEEDOUT
            t = s->sub.left;
            if (t > n) t = n;
            if (t > m) t = m;
            zmemcpy(q, p, t);
            p += t;  n -= t;
            q += t;  m -= t;
            if ((s->sub.left -= t) != 0)
                break;
            s->mode = s->last ? DRY : TYPE;
            break;
        case TABLE:
            NEEDBITS(14)
            s->sub.trees.table = t = (uInt)b & 0x3fff;
            if ((t & 0x1f) > 29 || ((t >> 5) & 0x1f) > 29) {
                s->mode = BAD;
                z->msg = D_80009F00;
                r = Z_DATA_ERROR;
                LEAVE
            }
            t = 258 + (t & 0x1f) + ((t >> 5) & 0x1f);
            if ((s->sub.trees.blens = (uIntf *)ZALLOC(z, t, sizeof(uInt))) == Z_NULL) {
                r = Z_MEM_ERROR;
                LEAVE
            }
            DUMPBITS(14)
            s->sub.trees.index = 0;
            s->mode = BTREE;
        case BTREE:
            while (s->sub.trees.index < 4 + (s->sub.trees.table >> 10)) {
                NEEDBITS(3)
                {
                    uInt i = s->sub.trees.index;
                    uInt c = border[i];
                    s->sub.trees.index = i + 1;
                    s->sub.trees.blens[c] = (uInt)b & 7;
                }
                DUMPBITS(3)
            }
            while (s->sub.trees.index < 19)
                {
                    uInt i = s->sub.trees.index;
                    uInt c = border[i];
                    s->sub.trees.index = i + 1;
                    s->sub.trees.blens[c] = 0;
                }
            s->sub.trees.bb = 7;
            func_8008A0C4();
            t = inflate_trees_bits(s->sub.trees.blens, &s->sub.trees.bb, &s->sub.trees.tb, z);
            if (t != Z_OK) {
                ZFREE(z, s->sub.trees.blens);
                r = t;
                if (r == Z_DATA_ERROR)
                    s->mode = BAD;
                LEAVE
            }
            s->sub.trees.index = 0;
            s->mode = DTREE;
        case DTREE:
            while (t = s->sub.trees.table,
                   s->sub.trees.index < 258 + (t & 0x1f) + ((t >> 5) & 0x1f)) {
                inflate_huft *h;
                uInt i, j, c;

                t = s->sub.trees.bb;
                NEEDBITS(t)
                h = s->sub.trees.tb + ((uInt)b & inflate_mask[t]);
                t = h->word.what.Bits;
                c = h->more.Base;
                if (c < 16) {
                    DUMPBITS(t)
                    s->sub.trees.blens[s->sub.trees.index++] = c;
                } else {
                    i = c == 18 ? 7 : c - 14;
                    j = c == 18 ? 11 : 3;
                    NEEDBITS(t + i)
                    DUMPBITS(t)
                    j += (uInt)b & inflate_mask[i];
                    DUMPBITS(i)
                    i = s->sub.trees.index;
                    t = s->sub.trees.table;
                    if (i + j > 258 + (t & 0x1f) + ((t >> 5) & 0x1f) ||
                        (c == 16 && i < 1)) {
                        func_8008A0C4();
                        inflate_trees_free(s->sub.trees.tb, z);
                        ZFREE(z, s->sub.trees.blens);
                        s->mode = BAD;
                        z->msg = D_80009F24;
                        r = Z_DATA_ERROR;
                        LEAVE
                    }
                    c = c == 16 ? s->sub.trees.blens[i - 1] : 0;
                    do {
                        s->sub.trees.blens[i++] = c;
                    } while (--j);
                    s->sub.trees.index = i;
                }
            }
            func_8008A0C4();
            inflate_trees_free(s->sub.trees.tb, z);
            s->sub.trees.tb = Z_NULL;
            {
                uInt bl, bd;
                inflate_huft *tl, *td;
                inflate_codes_statef *c;

                bl = 9;
                bd = 6;
                t = s->sub.trees.table;
                func_8008A0C4();
                t = inflate_trees_dynamic(257 + (t & 0x1f), 1 + ((t >> 5) & 0x1f),
                                          s->sub.trees.blens, &bl, &bd, &tl, &td, z);
                ZFREE(z, s->sub.trees.blens);
                if (t != Z_OK) {
                    if (t == (uInt)Z_DATA_ERROR)
                        s->mode = BAD;
                    r = t;
                    LEAVE
                }
                if ((c = inflate_codes_new(bl, bd, tl, td, z)) == Z_NULL) {
                    inflate_trees_free(td, z);
                    inflate_trees_free(tl, z);
                    r = Z_MEM_ERROR;
                    LEAVE
                }
                s->sub.decode.codes = c;
                s->sub.decode.tl = tl;
                s->sub.decode.td = td;
            }
            s->mode = CODES;
        case CODES:
            UPDATE
            if ((r = inflate_codes(s, z, r)) != Z_STREAM_END)
                return inflate_flush(s, z, r);
            r = Z_OK;
            func_8008A0C4();
            inflate_codes_free(s->sub.decode.codes, z);
            inflate_trees_free(s->sub.decode.td, z);
            inflate_trees_free(s->sub.decode.tl, z);
            LOAD
            if (!s->last) {
                s->mode = TYPE;
                break;
            }
            if (k > 7) {
                k -= 8;
                n++;
                p--;
            }
            s->mode = DRY;
        case DRY:
            FLUSH
            if (s->read != s->write)
                LEAVE
            s->mode = DONE;
        case DONE:
            r = Z_STREAM_END;
            LEAVE
        case BAD:
            r = Z_DATA_ERROR;
            LEAVE
        default:
            r = Z_STREAM_ERROR;
            LEAVE
        }
    }
}
