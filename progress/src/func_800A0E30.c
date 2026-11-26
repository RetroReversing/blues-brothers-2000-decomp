/* identical to func_800A06EC in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80041100 in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8003A9AC (matched), with its names changed by decompdecomp */
typedef struct
{
      u8 dummy;
      u8 txsize;
      u8 rxsize;
      u8 cmd;
      u8 typeh;
      u8 typel;
      u8 status;
      u8 dummy1;
} __OSContRequesFormat;

typedef struct {
    u16 type;
    u8  status;
    u8  errno;
} OSContStatus;

extern u8 D_8017DC10[];
extern u8 D_8017DBBC;

void func_800A0E30(u8 *pattern, OSContStatus *data)
{
    u8 *ptr;
    __OSContRequesFormat requestformat;
    int i;
    u8 bits = 0;

    ptr = D_8017DC10;

    for (i = 0; i < D_8017DBBC; i++, ptr += sizeof(requestformat), data++) {
        requestformat = *((__OSContRequesFormat *)ptr);
        data->errno = ((requestformat.rxsize & 0xC0) >> 4);

        if (data->errno != 0) {
            continue;
        }

        data->type = (requestformat.typel << 8) | requestformat.typeh;
        data->status = requestformat.status;
        bits |= (1 << i);
    }
    *pattern = bits;
}
