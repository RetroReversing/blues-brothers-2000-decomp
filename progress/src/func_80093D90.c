typedef unsigned int uInt;
typedef unsigned long uLong;
typedef unsigned char Bytef;
typedef uLong (*check_func)(uLong check, const Bytef *buf, uInt len);
typedef struct z_stream_s {
    Bytef *next_in;
    uInt avail_in;
    uLong total_in;
    Bytef *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    void *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    uLong adler;
    uLong reserved;
} z_stream;
typedef z_stream *z_streamp;
typedef struct inflate_blocks_state {
    int mode;
    uInt sub[4];
    uInt last;
    uInt bitk;
    uLong bitb;
    void *hufts;
    Bytef *window;
    Bytef *end;
    Bytef *read;
    Bytef *write;
    check_func checkfn;
    uLong check;
} inflate_blocks_statef;
void *memcpy(void *, const void *, unsigned int);
#define zmemcpy memcpy
#define Z_OK 0
#define Z_BUF_ERROR (-5)
#define Z_NULL 0

int func_80093D90(inflate_blocks_statef *s, z_streamp z, int r)
{
  uInt n;
  Bytef *p;
  Bytef *q;

  p = z->next_out;
  q = s->read;

  n = (uInt)((q <= s->write ? s->write : s->end) - q);
  if (n > z->avail_out) n = z->avail_out;
  if (n && r == Z_BUF_ERROR) r = Z_OK;

  z->avail_out -= n;
  z->total_out += n;

  if (s->checkfn != Z_NULL)
    z->adler = s->check = (*s->checkfn)(s->check, q, n);

  zmemcpy(p, q, n);
  p += n;
  q += n;

  if (q == s->end)
  {
    q = s->window;
    if (s->write == s->end)
      s->write = s->window;

    n = (uInt)(s->write - q);
    if (n > z->avail_out) n = z->avail_out;
    if (n && r == Z_BUF_ERROR) r = Z_OK;

    z->avail_out -= n;
    z->total_out += n;

    if (s->checkfn != Z_NULL)
      z->adler = s->check = (*s->checkfn)(s->check, q, n);

    zmemcpy(p, q, n);
    p += n;
    q += n;
  }

  z->next_out = p;
  s->read = q;

  return r;
}
