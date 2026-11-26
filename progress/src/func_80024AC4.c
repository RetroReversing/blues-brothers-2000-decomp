s32 func_80024AC4(s32 x, s32 s) {
    if (x > 0) { x = -x; x >>= s; x = -x; } else { x >>= s; } return x;
}
