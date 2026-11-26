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
    s32 tid;
    struct {
        u32 sregs[32];
        u32 sp_dram_addr;
        u32 sp_mem_addr;
        u32 sp_rd_len;
        u32 sp_pc;
        u32 sp_wr_len;
        u32 sp_status;
        u32 sp_dma_full;
        u32 sp_dma_busy;
    } registers;
} KKCpScalarRegsetRequest;
typedef struct {
    KKHeader header;
    s32 object;
} KKObjectEvent;

u32 __rmonReadWordAt(u32 *addr);
void __rmonWriteWordTo(u32 *addr, u32 val);
int func_800A5620(void);
void func_800A5688(void);
void __rmonSendReply(KKHeader *const block, u32 blockSize, u32 replyType);
extern u32 D_80185400;
extern u32 D_80185404;
extern u32 D_80185408;

s32 __rmonSetSRegs(KKHeader *req) {
    register KKCpScalarRegsetRequest *request = (KKCpScalarRegsetRequest *)req;
    KKObjectEvent reply;
    int regno;
    u32 inst;

    if (func_800A5620()) {
        return -4;
    }

    D_80185400 = __rmonReadWordAt((u32 *)0x04080000);
    D_80185404 = __rmonReadWordAt((u32 *)0x04001000);
    D_80185408 = __rmonReadWordAt((u32 *)0x04000000);
    for (regno = 0; regno < 32; regno++) {
        __rmonWriteWordTo((u32 *)0x04000000, request->registers.sregs[regno]);
        inst = 0x8C000000;
        inst |= (regno & 0x1F) << 16;
        __rmonWriteWordTo((u32 *)0x04001000, inst);
        __rmonWriteWordTo((u32 *)0x04080000, 0);
        func_800A5688();
    }
    __rmonWriteWordTo((u32 *)0x04000000, D_80185408);
    __rmonWriteWordTo((u32 *)0x04001000, D_80185404);
    __rmonWriteWordTo((u32 *)0x04080000, D_80185400);

    __rmonWriteWordTo((u32 *)0x04040004, request->registers.sp_dram_addr);
    __rmonWriteWordTo((u32 *)0x04040000, request->registers.sp_mem_addr);
    __rmonWriteWordTo((u32 *)0x04080000, request->registers.sp_pc & 0xFFF);
    __rmonWriteWordTo((u32 *)0x0404000C, request->registers.sp_wr_len);
    __rmonWriteWordTo((u32 *)0x04040010, request->registers.sp_status);

    reply.object = request->tid;
    reply.header.code = request->header.code;
    reply.header.error = 0;
    __rmonSendReply(&reply.header, sizeof(reply), 1);
    return 0;
}

