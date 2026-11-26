s32 func_80024970(s32);
s32 func_8002505C(s32);

s32 atan2S16(s32 y, s32 x) {
    s32 k;
    s32 quad;
    s32 a;

    k = 0x80;
    if (y == 0) {
        return (x >> 31) & 0x8000;
    }
    if (x == 0) {
        if (y >= 0) {
            return 0x4000;
        }
        return 0xC000;
    }
    quad = (u32)y >> 31;
    if (x < 0) {
        quad |= 2;
    }
    y = func_80024970(y);
    x = func_80024970(x);
    if (y < x) {
        a = func_8002505C((y * 0x7FFF) / x);
    } else {
        a = 0x4000 - func_8002505C((x * 0x7FFF) / y);
    }
    switch (quad) {
    case 0:
        return a;
    case 1:
        return (k << 9) - a;
    case 2:
        return (k << 8) - a;
    case 3:
        return (k << 8) + a;
    }
    return 0;
}
