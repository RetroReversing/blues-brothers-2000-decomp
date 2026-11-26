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

/* Fast inflate loop: decodes Huffman literal/length and distance codes from the bit buffer and copies matches into the sliding window while there is room for at least 258 output bytes and 10 input bytes; returns Z_OK, Z_STREAM_END or Z_DATA_ERROR. */
int inflateFast(uInt lenBits, uInt distBits, inflate_huft *lenTable, inflate_huft *distTable, inflate_blocks_statef *s, z_streamp z)
{
  inflate_huft *huft;
  uInt extra;
  uLong b;
  uInt k;
  Bytef *p;
  uInt n;
  Bytef *q;
  uInt m;
  uInt lenMask;
  uInt distMask;
  uInt c;
  uInt dist;
  Bytef *src;

  LOAD

  lenMask = inflate_mask[lenBits];
  distMask = inflate_mask[distBits];

  do {
    GRABBITS(20)
    if ((extra = (huft = lenTable + ((uInt)b & lenMask))->exop) == 0)
    {
      DUMPBITS(huft->bits)
      *q++ = (Byte)huft->base;
      m--;
      continue;
    }
    do {
      DUMPBITS(huft->bits)
      if (extra & 16)
      {
        extra &= 15;
        c = huft->base + ((uInt)b & inflate_mask[extra]);
        DUMPBITS(extra)

        GRABBITS(15);
        extra = (huft = distTable + ((uInt)b & distMask))->exop;
        do {
          DUMPBITS(huft->bits)
          if (extra & 16)
          {
            extra &= 15;
            GRABBITS(extra)
            dist = huft->base + ((uInt)b & inflate_mask[extra]);
            DUMPBITS(extra)

            m -= c;
            if ((uInt)(q - s->window) >= dist)
            {
              src = q - dist;
              *q++ = *src++;  c--;
              *q++ = *src++;  c--;
            }
            else
            {
              extra = dist - (uInt)(q - s->window);
              src = s->end - extra;
              if (c > extra)
              {
                c -= extra;
                do {
                  *q++ = *src++;
                } while (--extra);
                src = s->window;
              }
            }
            do {
              *q++ = *src++;
            } while (--c);
            break;
          }
          else if ((extra & 64) == 0)
            extra = (huft = huft->next + ((uInt)b & inflate_mask[extra]))->exop;
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
      if ((extra & 64) == 0)
      {
        if ((extra = (huft = huft->next + ((uInt)b & inflate_mask[extra]))->exop) == 0)
        {
          DUMPBITS(huft->bits)
          *q++ = (Byte)huft->base;
          m--;
          break;
        }
      }
      else if (extra & 32)
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
