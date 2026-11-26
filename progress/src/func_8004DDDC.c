void func_8004DDDC(f32 *pos, f32 *target, f32 *vel, f32 accel, f32 scale) {
    f32 d = *target - *pos;
    f32 lim;

    if (d > 0.0) {
        lim = d * scale;
        *vel += accel;
        if (lim < *vel) {
            *vel = lim;
        }
        *pos += *vel;
        if (*target <= *pos) {
            *pos = *target;
            *vel = 0.0f;
        }
    } else {
        lim = d * scale;
        *vel -= accel;
        if (*vel < lim) {
            *vel = lim;
        }
        *pos += *vel;
        if (*pos <= *target) {
            *pos = *target;
            *vel = 0.0f;
        }
    }
}
