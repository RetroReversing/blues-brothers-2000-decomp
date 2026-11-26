void func_800528CC(const void *arg0, const void *arg1, const void *arg2, void *arg3, void *arg4) {
    f32 temp;
    void *p4;

    (*(f32 *)((s8 *)arg3 + 0)) = (*(const f32 *)((s8 *)arg0 + 0));
    (*(f32 *)((s8 *)arg3 + 4)) = (*(const f32 *)((s8 *)arg0 + 4));
    (*(f32 *)((s8 *)arg3 + 8)) = (*(const f32 *)((s8 *)arg0 + 8));
    p4 = arg4;
    arg4 = 0;
    (*(f32 *)((s8 *)p4 + 0)) = (*(const f32 *)((s8 *)arg0 + 0));
    (*(f32 *)((s8 *)p4 + 4)) = (*(const f32 *)((s8 *)arg0 + 4));
    (*(f32 *)((s8 *)p4 + 8)) = (*(const f32 *)((s8 *)arg0 + 8));
    temp = (*(const f32 *)((s8 *)arg1 + 0));
    if (temp < (*(const f32 *)((s8 *)arg3 + 0))) {
        (*(f32 *)((s8 *)arg3 + 0)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg1 + 4));
    if (temp < (*(const f32 *)((s8 *)arg3 + 4))) {
        (*(f32 *)((s8 *)arg3 + 4)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg1 + 8));
    if (temp < (*(const f32 *)((s8 *)arg3 + 8))) {
        (*(f32 *)((s8 *)arg3 + 8)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg2 + 0));
    if (temp < (*(const f32 *)((s8 *)arg3 + 0))) {
        (*(f32 *)((s8 *)arg3 + 0)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg2 + 4));
    if (temp < (*(const f32 *)((s8 *)arg3 + 4))) {
        (*(f32 *)((s8 *)arg3 + 4)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg2 + 8));
    if (temp < (*(const f32 *)((s8 *)arg3 + 8))) {
        (*(f32 *)((s8 *)arg3 + 8)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg1 + 0));
    if ((*(const f32 *)((s8 *)p4 + 0)) < temp) {
        (*(f32 *)((s8 *)p4 + 0)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg1 + 4));
    if ((*(const f32 *)((s8 *)p4 + 4)) < temp) {
        (*(f32 *)((s8 *)p4 + 4)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg1 + 8));
    if ((*(const f32 *)((s8 *)p4 + 8)) < temp) {
        (*(f32 *)((s8 *)p4 + 8)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg2 + 0));
    if ((*(const f32 *)((s8 *)p4 + 0)) < temp) {
        (*(f32 *)((s8 *)p4 + 0)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg2 + 4));
    if ((*(const f32 *)((s8 *)p4 + 4)) < temp) {
        (*(f32 *)((s8 *)p4 + 4)) = temp;
    }
    temp = (*(const f32 *)((s8 *)arg2 + 8));
    if ((*(const f32 *)((s8 *)p4 + 8)) < temp) {
        (*(f32 *)((s8 *)p4 + 8)) = temp;
    }
}
