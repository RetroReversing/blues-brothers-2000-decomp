typedef unsigned int uInt;
typedef unsigned long uLong;
typedef unsigned char Byte;
typedef unsigned char Bytef;
typedef uInt uIntf;
typedef void *voidpf;
typedef voidpf (*alloc_func)(voidpf opaque, uInt items, uInt size);
typedef void (*free_func)(voidpf opaque, voidpf address);
typedef struct z_stream_s {
    Bytef *next_in;
    uInt avail_in;
    uLong total_in;
    Bytef *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    void *state;
    alloc_func zalloc;
    free_func zfree;
    voidpf opaque;
    int data_type;
    uLong adler;
    uLong reserved;
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

#define Z_NULL 0
#define Z_OK 0
#define Z_DATA_ERROR (-3)
#define Z_MEM_ERROR (-4)
#define Z_BUF_ERROR (-5)
#define BMAX 15
#define N_MAX 288
#define ZALLOC(strm, items, size) (*((strm)->zalloc))((strm)->opaque, (items), (size))

void func_8008A0C4(void);
int func_80093D08(inflate_huft *t, z_streamp z);

/* Builds an inflate Huffman decoding table from code lengths (zlib huft_build). */ int huftBuild(uIntf *codeLengths, uInt numCodes, uInt numSimple, const uIntf *baseValues, const uIntf *extraBits, inflate_huft **t, uIntf *maxBits, z_streamp zs)
{

  uInt a;                       /* counter for codes of length k */
  uInt c[BMAX+1];               /* bit length count table */
  uInt f;                       /* i repeats in table every f entries */
  int g;                        /* maximum code length */
  int h;                        /* table level */
  register uInt i;              /* counter, current code */
  register uInt j;              /* counter */
  register int k;               /* number of bits in current code */
  int l;                        /* bits per table (returned in m) */
  register uIntf *p;            /* pointer into c[], b[], or v[] */
  inflate_huft *q;              /* points to current table */
  struct inflate_huft_s r;      /* table entry for structure assignment */
  inflate_huft *u[BMAX];        /* table stack */
  uInt v[N_MAX];                /* values in order of bit length */
  register int w;               /* bits before this table == (l * h) */
  uInt x[BMAX+1];               /* bit offsets, then code stack */
  uIntf *xp;                    /* pointer into x */
  int y;                        /* number of dummy codes added */
  uInt z;                       /* number of entries in current table */


  /* Generate counts for each bit length */
  p = c;
#define C0 *p++ = 0;
#define C2 C0 C0 C0 C0
#define C4 C2 C2 C2 C2
  C4                            /* clear c[]--assume BMAX+1 is 16 */
  p = codeLengths;  i = numCodes;
  do {
    c[*p++]++;                  /* assume all entries <= BMAX */
  } while (--i);
  if (c[0] == numCodes)                /* null input--all zero length codes */
  {
    *t = (inflate_huft *)Z_NULL;
    *maxBits = 0;
    return Z_OK;
  }


  /* Find minimum and maximum length, bound *m by those */
  l = *maxBits;
  for (j = 1; j <= BMAX; j++)
    if (c[j])
      break;
  k = j;                        /* minimum code length */
  if ((uInt)l < j)
    l = j;
  for (i = BMAX; i; i--)
    if (c[i])
      break;
  g = i;                        /* maximum code length */
  if ((uInt)l > i)
    l = i;
  *maxBits = l;


  /* Adjust last length count to fill out codes, if needed */
  for (y = 1 << j; j < i; j++, y <<= 1)
    if ((y -= c[j]) < 0)
      return Z_DATA_ERROR;
  if ((y -= c[i]) < 0)
    return Z_DATA_ERROR;
  c[i] += y;


  /* Generate starting offsets into the value table for each length */
  x[1] = j = 0;
  p = c + 1;  xp = x + 2;
  while (--i) {                 /* note that i == g from above */
    *xp++ = (j += *p++);
  }


  /* Make a table of values in order of bit lengths */
  p = codeLengths;  i = 0;
  do {
    if ((j = *p++) != 0)
      v[x[j]++] = i;
  } while (++i < numCodes);
  numCodes = x[g];                     /* set n to length of v */


  /* Generate the Huffman codes and for each, make the table entries */
  x[0] = i = 0;                 /* first Huffman code is zero */
  p = v;                        /* grab values in bit order */
  h = -1;                       /* no tables yet--level -1 */
  w = -l;                       /* bits decoded == (l * h) */
  u[0] = (inflate_huft *)Z_NULL;        /* just to keep compilers happy */
  q = (inflate_huft *)Z_NULL;   /* ditto */
  z = 0;                        /* ditto */

  /* go through the bit lengths (k already is bits in shortest code) */
  for (; k <= g; k++)
  {
    a = c[k];
    while (a--)
    {
      /* here i is the Huffman code of length k bits for value *p */
      /* make tables up to required level */
      while (k > w + l)
      {
        func_8008A0C4();
        h++;
        w += l;                 /* previous table always l bits */

        /* compute minimum size table less than or equal to l bits */
        z = (z = g - w) > (uInt)l ? l : z;      /* table size upper limit */
        if ((f = 1 << (j = k - w)) > a + 1)     /* try a k-w bit table */
        {                       /* too few codes for k-w bit table */
          f -= a + 1;           /* deduct codes from patterns left */
          xp = c + k;
          if (j < z)
            while (++j < z)     /* try smaller tables up to z bits */
            {
              if ((f <<= 1) <= *++xp)
                break;          /* enough codes to use up j bits */
              f -= *xp;         /* else deduct codes from patterns */
            }
        }
        z = 1 << j;             /* table entries for j-bit table */

        /* allocate and link in new table */
        if ((q = (inflate_huft *)ZALLOC
             (zs,z + 1,sizeof(inflate_huft))) == Z_NULL)
        {
          if (h)
            func_80093D08(u[0], zs);
          return Z_MEM_ERROR;   /* not enough memory */
        }
        *t = q + 1;             /* link to list for huft_free() */
        *(t = &(q->next)) = Z_NULL;
        u[h] = ++q;             /* table starts after link */

        /* connect to last table, if there is one */
        if (h)
        {
          x[h] = i;             /* save pattern for backing up */
          r.bits = (Byte)l;     /* bits to dump before this table */
          r.exop = (Byte)j;     /* bits in this table */
          r.next = q;           /* pointer to this table */
          j = i >> (w - l);     /* (get around Turbo C bug) */
          u[h-1][j] = r;        /* connect to last table */
        }
      }

      /* set up table entry in r */
      r.bits = (Byte)(k - w);
      if (p >= v + numCodes)
        r.exop = 128 + 64;      /* out of values--invalid code */
      else if (*p < numSimple)
      {
        r.exop = (Byte)(*p < 256 ? 0 : 32 + 64);     /* 256 is end-of-block */
        r.base = *p++;          /* simple code is just the value */
      }
      else
      {
        r.exop = (Byte)(extraBits[*p - numSimple] + 16 + 64);/* non-simple--look up in lists */
        r.base = baseValues[*p++ - numSimple];
      }

      /* fill code-like entries with r */
      f = 1 << (k - w);
      for (j = i >> w; j < z; j += f)
        q[j] = r;

      /* backwards increment the k-bit code i */
      for (j = 1 << (k - 1); i & j; j >>= 1)
        i ^= j;
      i ^= j;

      /* backup over finished tables */
      while ((i & ((1 << w) - 1)) != x[h])
      {
        h--;                    /* don't need to update q */
        w -= l;
      }
    }
  }


  /* Return Z_BUF_ERROR if we were given an incomplete table */
  return y != 0 && g != 1 ? Z_BUF_ERROR : Z_OK;
}
