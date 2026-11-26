typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef Byte Bytef;

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

typedef struct inflate_blocks_state {
    char pad0[0x1C];
    uInt bitk;
    uLong bitb;
    Bytef *window;
    Bytef *end;
    Bytef *read;
    Bytef *write;
} inflate_blocks_statef;

extern uInt D_800BA950[];
#define inflate_mask D_800BA950
extern char D_8000A2E0[];
extern char D_8000A2F8[];

#define Z_OK 0
#define Z_STREAM_END 1
#define Z_DATA_ERROR (-3)

#define LOADIN {p=z->next_in;n=z->avail_in;b=s->bitb;k=s->bitk;}
#define LOADOUT {q=s->write;m=(uInt)(q<s->read?s->read-q-1:s->end-q);}
#define LOAD {LOADIN LOADOUT}
#define UPDBITS {s->bitb=b;s->bitk=k;}
#define UPDIN {z->avail_in=n;z->total_in+=p-z->next_in;z->next_in=p;}
#define UPDOUT {s->write=q;}
#define UPDATE {UPDBITS UPDIN UPDOUT}
#define NEXTBYTE (n--,*p++)
#define DUMPBITS(j) {b>>=(j);k-=(j);}
#define GRABBITS(j) {while(k<(j)){b|=((uLong)NEXTBYTE)<<k;k+=8;}}
#define UNGRAB {n+=(c=k>>3);p-=c;k&=7;}

int func_80093F30(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_statef *s, z_streamp z)
{
  inflate_huft *t;
  uInt e;
  uLong b;
  uInt k;
  Bytef *p;
  uInt n;
  Bytef *q;
  uInt m;
  uInt ml;
  uInt md;
  uInt c;
  uInt d;
  Bytef *r;

  LOAD

  ml = inflate_mask[bl];
  md = inflate_mask[bd];

  do {
    GRABBITS(20)
    if ((e = (t = tl + ((uInt)b & ml))->exop) == 0)
    {
      DUMPBITS(t->bits)
      *q++ = (Byte)t->base;
      m--;
      continue;
    }
    do {
      DUMPBITS(t->bits)
      if (e & 16)
      {
        e &= 15;
        c = t->base + ((uInt)b & inflate_mask[e]);
        DUMPBITS(e)

        GRABBITS(15);
        e = (t = td + ((uInt)b & md))->exop;
        do {
          DUMPBITS(t->bits)
          if (e & 16)
          {
            e &= 15;
            GRABBITS(e)
            d = t->base + ((uInt)b & inflate_mask[e]);
            DUMPBITS(e)

            m -= c;
            if ((uInt)(q - s->window) >= d)
            {
              r = q - d;
              *q++ = *r++;  c--;
              *q++ = *r++;  c--;
            }
            else
            {
              e = d - (uInt)(q - s->window);
              r = s->end - e;
              if (c > e)
              {
                c -= e;
                do {
                  *q++ = *r++;
                } while (--e);
                r = s->window;
              }
            }
            do {
              *q++ = *r++;
            } while (--c);
            break;
          }
          else if ((e & 64) == 0)
            e = (t = t->next + ((uInt)b & inflate_mask[e]))->exop;
          else
          {
            z->msg = (char*)D_8000A2E0;
            UNGRAB
            UPDATE
            return Z_DATA_ERROR;
          }
        } while (1);
        break;
      }
      if ((e & 64) == 0)
      {
        if ((e = (t = t->next + ((uInt)b & inflate_mask[e]))->exop) == 0)
        {
          DUMPBITS(t->bits)
          *q++ = (Byte)t->base;
          m--;
          break;
        }
      }
      else if (e & 32)
      {
        UNGRAB
        UPDATE
        return Z_STREAM_END;
      }
      else
      {
        z->msg = (char*)D_8000A2F8;
        UNGRAB
        UPDATE
        return Z_DATA_ERROR;
      }
    } while (1);
  } while (m >= 258 && n >= 10);

  UNGRAB
  UPDATE
  return Z_OK;
}
