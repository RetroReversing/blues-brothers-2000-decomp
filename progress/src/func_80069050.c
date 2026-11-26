typedef struct { f32 x; f32 y; f32 z; f32 w; } ObjP;

s32 func_80069050(ObjP *arg0) {
    if (900.0f < arg0->y) {
        return 1;
    }
    if (arg0->y < -900.0f) {
        return 0;
    }
    if (arg0->w < -500.0f) {
        return 2;
    }
    return 3;
}
