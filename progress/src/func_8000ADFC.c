u32 func_8000AC20(u32);
s32 func_8000ACA4(u32);
void func_8000ADC0(u32, u8);

void func_8000ADFC(u32 src, u32 dst, u32 len) {
    u32 w;

    while (len != 0 && (src & 3) != 0) {
        func_8000ADC0(dst++, func_8000ACA4(src++));
        len--;
    }
    while (len >= 4) {
        w = func_8000AC20(src);
        func_8000ADC0(dst++, w >> 24);
        func_8000ADC0(dst++, w >> 16);
        func_8000ADC0(dst++, w >> 8);
        func_8000ADC0(dst++, w);
        src += 4;
        len -= 4;
    }
    while (len != 0) {
        func_8000ADC0(dst++, func_8000ACA4(src++));
        len--;
    }
}
