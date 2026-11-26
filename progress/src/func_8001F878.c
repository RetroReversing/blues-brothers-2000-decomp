typedef struct {
    u32 w0;
    u32 w1;
} Gwords;

typedef union {
    Gwords words;
    long long int force_structure_alignment;
} Gfx;

void func_8001F230(void *);
void func_800226A0(s32);
void func_800226E4(s32);
void buildObjectMatrix(void *, void *, s32);
void func_80024A3C(void *, void *, s32);
void func_80024B58(void *, void *, s32);
void func_80024BE0(void *, void *, s32);
void func_80024FE8(void *);
void setRenderState(s32);
extern s32 D_800AB9B4;
extern Gfx *D_80177E18;

typedef struct { unsigned char pad_0[16]; int field_10; int field_14; int field_18; unsigned char pad_1C[80]; int field_6C; unsigned char pad_70[116]; int field_E4; } __repair_record_arg0;
s32 func_8001F878(void *arg0) {
    u8 sp10[0x28];
    u8 sp38[0x38];

    if (D_800AB9B4 != 0) {
        return 0;
    }
    {
        Gfx *_g = (Gfx *)(D_80177E18++);
        _g->words.w0 = 0xE7000000;
        _g->words.w1 = 0;
    }
    func_8001F230(arg0);
    if (((__repair_record_arg0*)arg0)->field_6C == 0x44444) {
        func_800226A0(0);
    }
    func_80024FE8(sp10);
    func_80024B58(sp38, sp10, ((__repair_record_arg0*)arg0)->field_10);
    func_80024A3C(sp10, sp38, ((__repair_record_arg0*)arg0)->field_14);
    func_80024BE0(sp38, sp10, ((__repair_record_arg0*)arg0)->field_18);
    buildObjectMatrix(arg0, sp38, 0);
    {
        Gfx *_g = (Gfx *)(D_80177E18++);
        _g->words.w0 = 0xDE000000;
        _g->words.w1 = ((__repair_record_arg0*)arg0)->field_E4;
    }
    {
        Gfx *_g = (Gfx *)(D_80177E18++);
        _g->words.w0 = 0xE7000000;
        _g->words.w1 = 0;
    }
    if (((__repair_record_arg0*)arg0)->field_6C == 0x44444) {
        func_800226E4(0);
    }
    setRenderState(-1);
    return 1;
}
