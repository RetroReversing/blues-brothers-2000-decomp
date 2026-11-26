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

#define exop word.what.Exop
#define bits word.what.Bits
#define base more.Base
#define next more.Next

typedef enum {
    START, LEN, LENEXT, DIST, DISTEXT, COPY, LIT, WASH, END, BADCODE
} inflate_codes_mode;

typedef struct inflate_codes_state {
    inflate_codes_mode mode;
    uInt len;
    union {
        struct {
            inflate_huft *tree;
            uInt need;
        } code;
        uInt lit;
        struct {
            uInt get;
            uInt dist;
        } copy;
    } sub;
    Byte lbits;
    Byte dbits;
    inflate_huft *ltree;
    inflate_huft *dtree;
} inflate_codes_statef;

typedef struct inflate_blocks_state {
    int mode;
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

extern uInt D_800BA950[];
#define inflate_mask D_800BA950

void func_8008A0C4(void);
int func_80093D90(inflate_blocks_statef *, z_streamp, int);
int func_80093F30(uInt, uInt, inflate_huft *, inflate_huft *, inflate_blocks_statef *, z_streamp);
#define inflate_flush func_80093D90
#define inflate_fast func_80093F30

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
#define OUTBYTE(a) {*q++=(Byte)(a);m--;}
#define LOAD {LOADIN LOADOUT}

int func_800929FC(inflate_blocks_statef *s, z_streamp z, int r) {
    uInt j;
    inflate_huft *t;
    uInt e;
    uLong b;
    uInt k;
    Bytef *p;
    uInt n;
    Bytef *q;
    uInt m;
    Bytef *f;
    inflate_codes_statef *c = s->sub.decode.codes;

    LOAD

    while (1) {
        func_8008A0C4();
        switch (c->mode) {
        case START:
            if (m >= 258 && n >= 10) {
                UPDATE
                r = inflate_fast(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
                LOAD
                if (r != Z_OK) {
                    c->mode = r == Z_STREAM_END ? WASH : BADCODE;
                    break;
                }
            }
            c->sub.code.need = c->lbits;
            c->sub.code.tree = c->ltree;
            c->mode = LEN;
        case LEN:
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((uInt)b & inflate_mask[j]);
            DUMPBITS(t->bits)
            e = (uInt)(t->exop);
            if (e == 0) {
                c->sub.lit = t->base;
                c->mode = LIT;
                break;
            }
            if (e & 16) {
                c->sub.copy.get = e & 15;
                c->len = t->base;
                c->mode = LENEXT;
                break;
            }
            if ((e & 64) == 0) {
                c->sub.code.need = e;
                c->sub.code.tree = t->next;
                break;
            }
            if (e & 32) {
                c->mode = WASH;
                break;
            }
            c->mode = BADCODE;
            z->msg = (char *)"invalid literal/length code";
            r = Z_DATA_ERROR;
            LEAVE
        case LENEXT:
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->len += (uInt)b & inflate_mask[j];
            DUMPBITS(j)
            c->sub.code.need = c->dbits;
            c->sub.code.tree = c->dtree;
            c->mode = DIST;
        case DIST:
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((uInt)b & inflate_mask[j]);
            DUMPBITS(t->bits)
            e = (uInt)(t->exop);
            if (e & 16) {
                c->sub.copy.get = e & 15;
                c->sub.copy.dist = t->base;
                c->mode = DISTEXT;
                break;
            }
            if ((e & 64) == 0) {
                c->sub.code.need = e;
                c->sub.code.tree = t->next;
                break;
            }
            c->mode = BADCODE;
            z->msg = (char *)"invalid distance code";
            r = Z_DATA_ERROR;
            LEAVE
        case DISTEXT:
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->sub.copy.dist += (uInt)b & inflate_mask[j];
            DUMPBITS(j)
            c->mode = COPY;
        case COPY:
            f = (uInt)(q - s->window) < c->sub.copy.dist ?
                s->end - (c->sub.copy.dist - (q - s->window)) :
                q - c->sub.copy.dist;
            while (c->len) {
                NEEDOUT
                OUTBYTE(*f++)
                if (f == s->end)
                    f = s->window;
                c->len--;
            }
            c->mode = START;
            break;
        case LIT:
            NEEDOUT
            OUTBYTE(c->sub.lit)
            c->mode = START;
            break;
        case WASH:
            FLUSH
            if (s->read != s->write)
                LEAVE
            c->mode = END;
        case END:
            r = Z_STREAM_END;
            LEAVE
        case BADCODE:
            r = Z_DATA_ERROR;
            LEAVE
        default:
            r = Z_STREAM_ERROR;
            LEAVE
        }
    }
}
