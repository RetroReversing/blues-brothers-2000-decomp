void func_80024D5C(s32 *, s32 *, s32 *);
extern s32 D_80177E28;

void func_80022EDC(s16 *mtx, s32 *rot, s32 flag, f32 *pos) {
    s32 tmp[9];
    s32 pad[10];
    s32 t[3];
    s32 *m;

    t[0] = pos[0];
    t[1] = pos[1];
    t[2] = pos[2];
    m = tmp;
    if (flag != 0) {
        func_80024D5C(m, &D_80177E28, rot);
    } else {
        m = rot;
    }
    mtx[0] = m[0] >> 15;
    mtx[1] = m[3] >> 15;
    mtx[2] = m[6] >> 15;
    mtx[3] = 0;
    mtx[4] = m[1] >> 15;
    mtx[5] = m[4] >> 15;
    mtx[6] = m[7] >> 15;
    mtx[7] = 0;
    mtx[8] = m[2] >> 15;
    mtx[9] = m[5] >> 15;
    mtx[10] = m[8] >> 15;
    mtx[11] = 0;
    mtx[12] = t[0];
    mtx[13] = t[1];
    mtx[14] = t[2];
    mtx[15] = 1;
    mtx += 16;
    mtx[0] = (m[0] & 0xFFFF) << 1;
    mtx[1] = (m[3] & 0xFFFF) << 1;
    mtx[2] = (m[6] & 0xFFFF) << 1;
    mtx[3] = 0;
    mtx[4] = (m[1] & 0xFFFF) << 1;
    mtx[5] = (m[4] & 0xFFFF) << 1;
    mtx[6] = (m[7] & 0xFFFF) << 1;
    mtx[7] = 0;
    mtx[8] = (m[2] & 0xFFFF) << 1;
    mtx[9] = (m[5] & 0xFFFF) << 1;
    mtx[10] = (m[8] & 0xFFFF) << 1;
    mtx[11] = 0;
    mtx[12] = 0;
    mtx[13] = 0;
    mtx[14] = 0;
    mtx[15] = 0;
}
