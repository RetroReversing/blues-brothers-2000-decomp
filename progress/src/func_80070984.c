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
typedef union {
    OSTask_t t;
    long long force_structure_alignment;
} OSTask;
typedef struct OSScTask_s {
    struct OSScTask_s *next;
    u32 state;
    u32 flags;
    void *framebuffer;
    OSTask list;
    void *msgQ;
    void *msg;
} OSScTask;
typedef struct {
    u64 *text;
    u64 *data;
} UcodeEntry;
s32 osSendMesg(void *, void *, s32);
extern u64 D_8008A1B0[];
extern u64 func_8008A0D4[];
extern UcodeEntry D_800B8330[];
extern s32 D_800B8338;
extern s32 D_800B9EC0;
extern u16 D_8014AE18[];
extern void *D_8014AE40;
extern u64 D_8014AE48[];
extern u64 D_8016AE48[];
extern u16 D_8016AEBC[];
extern s32 D_8016AEC0;
extern u8 D_8016AEC8[];
extern u64 D_80176DB8[];
extern u64 D_801771E8[];
extern void *D_80178230[];

void func_80070984(OSScTask *t, u64 *data, s32 size, s32 ucode, s32 flags) {
    t->list.t.type = 1;
    t->list.t.flags = 6;
    t->list.t.data_ptr = data;
    t->list.t.data_size = size;
    t->list.t.ucode_boot = (u64 *) ((u8 *) func_8008A0D4 + 0xC);
    t->list.t.ucode_boot_size = (u8 *) D_8008A1B0 - ((u8 *) func_8008A0D4 + 0xC);
    t->list.t.ucode = D_800B8330[ucode].text;
    t->list.t.ucode_data = D_800B8330[ucode].data;
    t->list.t.ucode_data_size = 0x800;
    t->list.t.dram_stack = D_80176DB8;
    t->list.t.dram_stack_size = 0x400;
    t->list.t.output_buff = D_8014AE48;
    t->list.t.output_buff_size = D_8016AE48;
    t->list.t.yield_data_ptr = D_801771E8;
    t->list.t.yield_data_size = 0xC00;
    t->next = 0;
    t->flags = flags;
    t->msgQ = D_8016AEC8;
    if (flags & 0x40) {
        t->msg = &D_8016AEBC[D_800B9EC0];
    } else {
        t->msg = &D_8014AE18[D_800B9EC0];
    }
    t->framebuffer = D_80178230[D_800B9EC0];
    osSendMesg(D_8014AE40, t, 1);
    if (flags & 0x40) {
        D_800B8338 ^= 1;
        D_800B9EC0 ^= 1;
    }
    D_8016AEC0 = (D_8016AEC0 + 1) & 7;
}
