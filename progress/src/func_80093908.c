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

extern uInt D_8000A000[];
extern uInt D_8000A07C[];
extern uInt D_8000A0F8[];
extern uInt D_8000A170[];
extern char D_8000A234[];
extern char D_8000A258[];
extern char D_8000A278[];
extern char D_8000A298[];
extern char D_8000A2B4[];
#define Z_DATA_ERROR (-3)
#define Z_MEM_ERROR (-4)
#define Z_BUF_ERROR (-5)
int func_80093240(uIntf *b, uInt n, uInt s, const uIntf *d, const uIntf *e, inflate_huft **t, uIntf *m, z_streamp zs);
int func_80093D08(inflate_huft *t, z_streamp z);

int func_80093908(uInt nl, uInt nd, uIntf *c, uIntf *bl, uIntf *bd, inflate_huft **tl, inflate_huft **td, z_streamp z)
{
  int r;

  if ((r = func_80093240(c, nl, 257, D_8000A000, D_8000A07C, tl, bl, z)) != Z_OK || *bl == 0)
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char*)D_8000A234;
    else if (r != Z_MEM_ERROR)
    {
      func_80093D08(*tl, z);
      z->msg = (char*)D_8000A258;
      r = Z_DATA_ERROR;
    }
    return r;
  }

  if ((r = func_80093240(c + nl, nd, 0, D_8000A0F8, D_8000A170, td, bd, z)) != Z_OK || (*bd == 0 && nl > 257))
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char*)D_8000A278;
    else if (r == Z_BUF_ERROR) {
      func_80093D08(*td, z);
      z->msg = (char*)D_8000A298;
      r = Z_DATA_ERROR;
    }
    else if (r != Z_MEM_ERROR)
    {
      z->msg = (char*)D_8000A2B4;
      r = Z_DATA_ERROR;
    }
    func_80093D08(*tl, z);
    return r;
  }

  return Z_OK;
}
