s32 func_8000ACA4(s32);
void func_8000AF10(s32, s32);

void func_8000B140(s32 arg0, s32 arg1, s32 arg2) {
    s32 pad[2];
    s32 n = arg2 - 1; if (arg2 != 0) { do { func_8000AF10(arg0++, func_8000ACA4(arg1++) & 0xFF); do { n--; } while (0); } while (n != -1); }
}
