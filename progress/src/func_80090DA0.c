typedef struct z_stream_s {
    u8 *next_in;
    u32 avail_in;
    u32 total_in;
    u8 *next_out;
    u32 avail_out;
    u32 total_out;
    char *msg;
    void *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    s32 data_type;
    u32 adler;
    u32 reserved;
} z_stream;
extern char D_80009DC0[];
s32 func_80091078(z_stream *strm, const char *version, s32 stream_size);
s32 zInflate(z_stream *strm, s32 flush);
s32 func_80090EB4(z_stream *strm);

s32 func_80090DA0(u8 *dest, u32 *destLen, u8 *source, u32 sourceLen) {
    z_stream stream;
    s32 err;

    stream.next_in = source;
    stream.avail_in = sourceLen;
    if (stream.avail_in != sourceLen) {
        return -5;
    }

    stream.next_out = dest;
    stream.avail_out = *destLen;
    if (stream.avail_out != *destLen) {
        return -5;
    }

    stream.zalloc = 0;
    stream.zfree = 0;

    err = func_80091078(&stream, D_80009DC0, sizeof(z_stream));
    if (err != 0) {
        return err;
    }

    err = zInflate(&stream, 4);
    if (err != 1) {
        func_80090EB4(&stream);
        return err == 0 ? -5 : err;
    }
    *destLen = stream.total_out;

    err = func_80090EB4(&stream);
    return err;
}
