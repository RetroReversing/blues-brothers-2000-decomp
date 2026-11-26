typedef s32 TVid;
typedef struct KKHeader {
    s32 length;
    u8 code;
    u8 type;
    s16 error;
    u8 rev;
    u8 method;
    s16 notused2;
} KKHeader;
typedef struct KKObjectRequest {
    KKHeader header;
    TVid object;
} KKObjectRequest;
typedef struct KKSetBkptRequest {
    KKHeader header;
    TVid object;
    u32* addr;
    u32 nbytes;
} KKSetBkptRequest;
typedef struct KKBkptEvent {
    KKHeader header;
    TVid object;
    s32 bp;
    u32 instruction;
} KKBkptEvent;
typedef struct BreakInfo {
    u32* breakAddress;
    u32 oldInstruction;
} BreakInfo;
extern void __rmonSendReply(KKHeader*, s32, s32);
typedef KKObjectRequest KKObjectEvent;
extern u32 __rmonReadWordAt(u32);
extern void __rmonWriteWordTo(u32, u32);
extern s32 __osRdbSend(u8*, u32, u32);
extern void __rmonSendHeader(KKHeader*, s32, s32);
extern void __rmonSendData(char*, u32);
extern s32 func_800A5620(void);
extern void func_800A5688(void);
extern u32 D_80185400;
extern u32 D_80185404;
extern u32 D_80185408;
extern u32 D_8018540C;
extern u32 D_80185410;
extern u32 D_80185414;

s32 __rmonGetVRegs(KKObjectRequest* request) {
    KKObjectEvent reply;
    u8 vregs[0x200];
    s32 i;
    s32 sent;
    s32 size;
    u8* p;
    u32 inst;

    if (func_800A5620() != 0) {
        return -4;
    }
    reply.object = request->object;
    reply.header.code = request->header.code;
    reply.header.error = 0;
    reply.header.length = 0x210;
    size = 0x210;
    p = (u8*)&size;
    sent = 0;
    do {
        sent += __osRdbSend(p + sent, 4 - sent, 8);
    } while (sent < 4);
    __rmonSendHeader(&reply.header, 0x10, 1);
    D_80185400 = __rmonReadWordAt(0x04080000);
    D_80185404 = __rmonReadWordAt(0x04001000);
    D_80185408 = __rmonReadWordAt(0x04000000);
    D_8018540C = __rmonReadWordAt(0x04000004);
    D_80185410 = __rmonReadWordAt(0x04000008);
    D_80185414 = __rmonReadWordAt(0x0400000C);
    for (i = 0; i < 32; i++) {
        inst = 0xE8000000;
        inst |= (i & 0x1F) << 16;
        inst &= 0xFFFF07FF;
        inst |= 0x2000;
        __rmonWriteWordTo(0x04001000, inst);
        __rmonWriteWordTo(0x04080000, 0);
        func_800A5688();
        __rmonSendData((char*)0x04000000, 0x10);
    }
    __rmonWriteWordTo(0x04000000, D_80185408);
    __rmonWriteWordTo(0x04000004, D_8018540C);
    __rmonWriteWordTo(0x04000008, D_80185410);
    __rmonWriteWordTo(0x0400000C, D_80185410);
    __rmonWriteWordTo(0x04001000, D_80185404);
    __rmonWriteWordTo(0x04080000, D_80185400);
    return 0;
}


