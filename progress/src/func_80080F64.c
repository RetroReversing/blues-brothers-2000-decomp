void func_80080F64(f32 *out, f32 *a, f32 *b) {
    f32 ax, ay, az, bx, by, bz, tx, ty, tz;
    f32 x, y, z;

    ax = a[0]; bx = b[0]; tx = b[3];
    x = (bx + 2.0f * ax + tx) - 2.0f * a[3];
    ay = a[1]; by = b[1]; ty = b[4];
    y = (by + 2.0f * ay + ty) - 2.0f * a[4];
    az = a[2]; bz = b[2]; tz = b[5];
    z = (bz + 2.0f * az + tz) - 2.0f * a[5];
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
