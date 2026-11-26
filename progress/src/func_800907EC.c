typedef struct {
    u32 type;
    u32 flags;
    u64 *ucode_boot;
    u32 ucode_boot_size;
    u64 *ucode;
    u32 ucode_size;
    u64 *ucode_data;
    u32 ucode_data_size;
    u64 *dram_stack;
    u32 dram_stack_size;
    u64 *output_buff;
    u64 *output_buff_size;
    u64 *data_ptr;
    u32 data_size;
    u64 *yield_data_ptr;
    u32 yield_data_size;
} OSTask_t;
typedef struct ScTask {
    struct ScTask *next;
    u32 state;
    u32 flags;
    void *framebuffer;
    OSTask_t t;
    s32 *msgQ;
    void *msg;
} ScTask;
typedef struct { u64 *data; u32 size; u64 *ucode; u64 *ucode_data; } Arg;
s32 *func_800A83C0(s32);
s32 osRecvMesg(s32 *, void *, s32);
s32 osSendMesg(s32 *, void *, s32);
extern u8 D_8008A1B0[];
extern s32 D_8017B2D0;
extern u8 *D_8017B2D4;
extern u8 func_8008A0D4[];

void func_800907EC(Arg *arg0) {
    ScTask task;
    s32 pad[4];
    void *msg[8];

    task.next = 0;
    task.msgQ = (s32 *)(D_8017B2D4 + 0x30);
    task.msg = msg;
    task.flags = 2;
    task.t.data_ptr = arg0->data;
    task.t.data_size = arg0->size;
    task.t.type = 2;
    task.t.ucode_boot = (u64 *)(func_8008A0D4 + 0xC);
    task.t.ucode_boot_size = (s32)D_8008A1B0 - (s32)(func_8008A0D4 + 0xC);
    task.t.flags = 0;
    task.t.ucode = arg0->ucode;
    task.t.ucode_data = arg0->ucode_data;
    task.t.ucode_size = 0x1000;
    task.t.ucode_data_size = 0x800;
    task.t.dram_stack = 0;
    task.t.dram_stack_size = 0;
    task.t.output_buff = 0;
    task.t.output_buff_size = 0;
    task.t.yield_data_ptr = 0;
    task.t.yield_data_size = 0;
    osSendMesg(func_800A83C0(D_8017B2D0), &task, 1);
    osRecvMesg((s32 *)(D_8017B2D4 + 0x30), 0, 1);
}
