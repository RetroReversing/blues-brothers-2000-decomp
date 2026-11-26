void func_80066280(s32 *a, s32 *b, s32 axis, s32 flag, f32 *v) {
    s32 t;
    s32 half;

    switch (axis) {
    case 0:
    case 0x78:
        t = v[1];
        break;
    case 1:
    case 0x79:
        a += 1;
        t = v[2];
        b += 1;
        break;
    case 2:
    case 0x7A:
        a += 2;
        t = v[3];
        b += 2;
        break;
    default:
        return;
    }
    half = *b - *a;
    half /= 2;
    t -= *a;
    if (flag) {
        if (t < half) {
            *a = half;
        } else {
            *b = half;
        }
    } else {
        if (t < half) {
            *b = half;
        } else {
            *a = half;
        }
    }
}
