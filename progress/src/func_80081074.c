void func_80081074(f32 *out, f32 *a, f32 *ta, f32 *b, f32 *tb) {
    f32 ax, ay, az, bx, by, bz, tx, ty, tz;
    f32 x, y, z;

    ax = a[0]; bx = b[0]; tx = tb[0];
    x = (bx + 2.0f * ax + tx) - 2.0f * ta[0];
    ay = a[1]; by = b[1]; ty = tb[1];
    y = (by + 2.0f * ay + ty) - 2.0f * ta[1];
    az = a[2]; bz = b[2]; tz = tb[2];
    z = (bz + 2.0f * az + tz) - 2.0f * ta[2];
    out[2] = bx;
    out[3] = ax;
    out[6] = by;
    out[7] = ay;
    out[10] = bz;
    out[11] = az;
    out[0] = x;
    out[4] = y;
    out[8] = z;
    out[1] = ((tx - x * 3.0f) - bx) * 0.5f;
    out[5] = ((ty - y * 3.0f) - by) * 0.5f;
    out[9] = ((tz - z * 3.0f) - bz) * 0.5f;
}
