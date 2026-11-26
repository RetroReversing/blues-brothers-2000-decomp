typedef struct {
    u32 control_flag;
    s32 channels;
    void *sched;
    s32 thread_priority;
    u8 *heap;
    s32 heap_length;
    u8 *ptr;
    u8 *wbk;
    void *default_fxbank;
    s32 fifo_length;
    s32 syn_updates;
    s32 syn_output_rate;
    s32 syn_rsp_cmds;
    s32 syn_retraceCount;
    s32 syn_num_dma_bufs;
    s32 syn_dma_buf_size;
    void *diskrom_handle;
    s32 extra;
} musConfig;
typedef struct {
    u8 *start;
    u8 *end;
    s32 size;
} RomRegion;
void func_8002B410(u8 *, u8 *, s32);
s32 func_8008CDBC(musConfig *);
void func_8008DC38(void *);
extern u8 D_800B380C[];
extern RomRegion D_800B383C[];
extern u8 D_801123C8[];
extern u8 D_80120420[];
extern u8 D_80176730[];
extern u8 D_B09653E0[];
extern u8 D_B096B3E0[];
extern u8 D_B0978AA0[];

void func_8002B514(void) {
    musConfig config;
    s32 i;

    for (i = 0; i < 14; i++) {
        D_800B383C[i].size = D_800B383C[i].end - D_800B383C[i].start;
    }
    func_8002B410(D_B09653E0, D_801123C8, D_B096B3E0 - D_B09653E0);
    config.control_flag = 0;
    config.channels = 20;
    config.sched = D_80176730;
    config.thread_priority = 0x77;
    config.heap = D_80120420;
    config.heap_length = 0x1E5F0;
    config.ptr = D_801123C8;
    config.fifo_length = 0x40;
    config.wbk = D_B0978AA0;
    config.default_fxbank = 0;
    config.syn_output_rate = 22050;
    config.syn_updates = 0x180;
    config.syn_rsp_cmds = 0x1000;
    config.syn_retraceCount = 1;
    config.syn_num_dma_bufs = 0x30;
    config.syn_dma_buf_size = 0x200;
    func_8008DC38(D_800B380C);
    func_8008CDBC(&config);
}
