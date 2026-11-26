typedef struct {
    s32 length;
    u8 code;
    s8 type;
    s16 error;
    u8 rev;
    u8 method;
    s16 notused;
} KKHeader;
typedef struct {
    KKHeader header;
    s32 object;
} KKObjectRequest;
typedef struct {
    KKHeader header;
    s32 object;
    s32 breakpoint;
} KKClrBkptRequest;
typedef struct {
    KKHeader header;
    s32 object;
    s32 breakpoint;
    u32 pc;
} KKBkptEvent;
typedef struct {
    u32 *breakAddress;
    u32 oldInstruction;
} BREAKINFO;
extern BREAKINFO D_80180FB0[];
extern BREAKINFO D_80181038[];
u32 __rmonReadWordAt(u32 *addr);
void __rmonWriteWordTo(u32 *addr, u32 val);
void osWritebackDCache(void *, s32);
void osInvalICache(void *, s32);

s32 __rmonClearBreak(ClrBkptRequest *req0) {
    register KKClrBkptRequest *request = (KKClrBkptRequest *)req0;
    register BREAKINFO *whichBreak;
    KKBkptEvent reply;
    u32 inst;

    if (request->breakpoint >= 16) {
        return -2;
    }

    if (((KKHeader *)req0)->method == 1) {
        whichBreak = &D_80181038[request->breakpoint];
        if (whichBreak->breakAddress == NULL) {
            return -2;
        }
        inst = __rmonReadWordAt(whichBreak->breakAddress);
        if ((inst & 0xFC00003F) == 0xD) {
            __rmonWriteWordTo(whichBreak->breakAddress, whichBreak->oldInstruction);
        }
    } else {
        whichBreak = &D_80180FB0[request->breakpoint];
        if (whichBreak->breakAddress == NULL) {
            return -2;
        }
        inst = *whichBreak->breakAddress;
        if ((inst & 0xFC00003F) == 0xD) {
            *whichBreak->breakAddress = whichBreak->oldInstruction;
            osWritebackDCache(whichBreak->breakAddress, 4);
            osInvalICache(whichBreak->breakAddress, 4);
        }
    }
    whichBreak->breakAddress = NULL;

    reply.header.code = request->header.code;
    reply.header.error = 0;
    reply.object = request->object;
    reply.breakpoint = request->breakpoint;
    __rmonSendReply(&reply.header, sizeof(reply), 1);
    return 0;
}

