u32 func_8000AC20(u32);
void func_8000ACE4(u32, u32, u32);
void func_8000ADFC(u32, u32, u32);
void func_8000AF88(u32, u32, u32);
void func_8000B074(u32, u32, u32);
void func_8000B140(u32, u32, u32);
extern u32 D_800A9420[];
extern u32 D_800A9424[];
extern char D_8F0BC5F0[];

void func_8000B1B4(s32 arg0) {
    u32 rom;
    u32 src;
    u32 len;
    u32 n;
    s32 i;
    u32 flags;
    s32 off;
    u32 last;

    rom = 0xB1FE0000;
    src = func_8000AC20(0xB1FFFFF4);
    len = func_8000AC20(0xB1FFFFF8);
    if (src > 0xEFFFFFFF) {
        src += (u32)D_8F0BC5F0;
    }
    while (len != 0) {
        i = 0;
        if (D_800A9420[0] < src) {
            off = 0;
            do {
                off += 8;
                i++;
            } while (*(u32 *)((u8 *)D_800A9420 + off) < src);
        }
        i *= 8;
        last = src - 1;
        n = *(u32 *)((u8 *)D_800A9420 + i) - last;
        if (len < n) {
            n = len;
        }
        flags = *(u32 *)((u8 *)D_800A9424 + i);
        if (!(flags & arg0)) {
            if (arg0 == 1) {
                func_8000B074(rom, 0, n);
            }
        } else if (flags & 4) {
            if (arg0 == 1) {
                func_8000B140(rom, src, n);
            } else {
                func_8000B140(src, rom, n);
            }
        } else if (arg0 == 1) {
            func_8000AF88(rom, src, n);
        } else if (flags & 8) {
            func_8000ADFC(rom, src, n);
        } else {
            func_8000ACE4(rom, src, n);
        }
        rom += n;
        len -= n;
        src += n;
    }
}
