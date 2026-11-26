extern s32 D_800AB9B8;
extern u32 D_800AB9BC;
extern u32 D_800AB9C0;

void func_800230D8(void) {
    u32 var_v1;
    u32 end;

    var_v1 = D_800AB9BC;
    end = D_800AB9C0;
    if (end >= var_v1) {
        do {
            *(s32 *)var_v1 = 0;
            var_v1 += 0x108;
        } while (end >= var_v1);
    }
    D_800AB9B8 = 0;
    D_800AB9C0 = D_800AB9BC;
}
