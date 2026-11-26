typedef unsigned int uInt;
typedef unsigned long uLong;
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
#define Z_NULL 0
#define Z_OK 0
#define FIXEDH 530

extern int D_800BA940;
extern uInt D_8017C5A0;
extern uInt D_8017C5A4;
extern inflate_huft *D_8017C5A8;
extern inflate_huft *D_8017C5AC;
extern uInt D_8000A000[];
extern uInt D_8000A07C[];
extern uInt D_8000A0F8[];
extern uInt D_8000A170[];
voidpf func_80093AD8(voidpf q, uInt n, uInt s);
int func_80093240(uIntf *b, uInt n, uInt s, const uIntf *d, const uIntf *e, inflate_huft **t, uIntf *m, z_streamp zs);

int func_80093B04(uIntf *bl, uIntf *bd, inflate_huft **tl, inflate_huft **td)
{
  if (!D_800BA940)
  {
    int k;
    unsigned c[288];
    z_stream z;
    int f = FIXEDH;

    z.zalloc = func_80093AD8;
    z.zfree = Z_NULL;
    z.opaque = (voidpf)&f;

    for (k = 0; k < 144; k++)
      c[k] = 8;
    for (; k < 256; k++)
      c[k] = 9;
    for (; k < 280; k++)
      c[k] = 7;
    for (; k < 288; k++)
      c[k] = 8;
    D_8017C5A0 = 7;
    func_80093240(c, 288, 257, D_8000A000, D_8000A07C, &D_8017C5A8, &D_8017C5A0, &z);

    for (k = 0; k < 30; k++)
      c[k] = 5;
    D_8017C5A4 = 5;
    func_80093240(c, 30, 0, D_8000A0F8, D_8000A170, &D_8017C5AC, &D_8017C5A4, &z);

    D_800BA940 = 1;
  }
  *bl = D_8017C5A0;
  *bd = D_8017C5A4;
  *tl = D_8017C5A8;
  *td = D_8017C5AC;
  return Z_OK;
}
