typedef struct {
    s32 mode;
    union {
        u32 method;
        struct {
            u32 was;
            u32 need;
        } check;
        u32 marker;
    } sub;
    s32 nowrap;
    u32 wbits;
    void *blocks;
} InflateState910A4;

typedef struct {
    u8 *next_in;
    u32 avail_in;
    u32 total_in;
    u8 *next_out;
    u32 avail_out;
    u32 total_out;
    char *msg;
    InflateState910A4 *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    s32 data_type;
    u32 adler;
    u32 reserved;
} ZStream910A4;

void func_8008A0C4(void);
s32 func_80091C5C(void *, ZStream910A4 *, s32);
void func_80091AD0(void *, ZStream910A4 *, u32 *);

#define NEEDBYTE { if (z->avail_in == 0) return r; if (f != 4) r = 0; }
#define NEXTBYTE (z->avail_in--, z->total_in++, *z->next_in++)

/* Runs the zlib inflate state machine: reads the zlib header, decodes blocks, then checks the Adler-32 trailer. */ s32 zInflate(ZStream910A4 *z, s32 f) {
    s32 r;
    u32 byte;

    if (z == NULL || z->state == NULL || z->next_in == NULL || f < 0) {
        return -2;
    }
    r = -5;
    while (1) {
        func_8008A0C4();
        switch (z->state->mode) {
        case 0:
            NEEDBYTE
            if (((z->state->sub.method = NEXTBYTE) & 0xF) != 8) {
                z->state->mode = 13;
                z->msg = "unknown compression method";
                z->state->sub.marker = 5;
                break;
            }
            if ((z->state->sub.method >> 4) + 8 > z->state->wbits) {
                z->state->mode = 13;
                z->msg = "invalid window size";
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = 1;
        case 1:
            NEEDBYTE
            byte = NEXTBYTE;
            if (((z->state->sub.method << 8) + byte) % 31) {
                z->state->mode = 13;
                z->msg = "incorrect header check";
                z->state->sub.marker = 5;
                break;
            }
            if (!(byte & 0x20)) {
                z->state->mode = 7;
                break;
            }
            z->state->mode = 2;
        case 2:
            NEEDBYTE
            z->state->sub.check.need = (u32)NEXTBYTE << 24;
            z->state->mode = 3;
        case 3:
            NEEDBYTE
            z->state->sub.check.need += (u32)NEXTBYTE << 16;
            z->state->mode = 4;
        case 4:
            NEEDBYTE
            z->state->sub.check.need += (u32)NEXTBYTE << 8;
            z->state->mode = 5;
        case 5:
            NEEDBYTE
            z->state->sub.check.need += (u32)NEXTBYTE;
            z->adler = z->state->sub.check.need;
            z->state->mode = 6;
            return 2;
        case 6:
            z->state->mode = 13;
            z->msg = "need dictionary";
            z->state->sub.marker = 0;
            return -2;
        case 7:
            r = func_80091C5C(z->state->blocks, z, r);
            if (r == -3) {
                z->state->mode = 13;
                z->state->sub.marker = 0;
                break;
            }
            if (r != 1) {
                return (f == 4 && r == 0) ? -5 : r;
            }
            r = 0;
            func_80091AD0(z->state->blocks, z, &z->state->sub.check.was);
            if (z->state->nowrap) {
                z->state->mode = 12;
                break;
            }
            z->state->mode = 8;
            if (f == 4) {
                r = -5;
            }
        case 8:
            NEEDBYTE
            z->state->sub.check.need = (u32)NEXTBYTE << 24;
            z->state->mode = 9;
        case 9:
            NEEDBYTE
            z->state->sub.check.need += (u32)NEXTBYTE << 16;
            z->state->mode = 10;
        case 10:
            NEEDBYTE
            z->state->sub.check.need += (u32)NEXTBYTE << 8;
            z->state->mode = 11;
        case 11:
            NEEDBYTE
            z->state->sub.check.need += (u32)NEXTBYTE;
            if (z->state->sub.check.was != z->state->sub.check.need) {
                z->state->mode = 13;
                z->msg = "incorrect data check";
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = 12;
        case 12:
            return 1;
        case 13:
            return -3;
        default:
            return -2;
        }
    }
}
