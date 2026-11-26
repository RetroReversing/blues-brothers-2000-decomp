typedef struct { s32 w; s32 h; } Rect;
Rect *func_80023E18(void);
void func_80029738(Rect *, s32, s32, s32, s32);

void func_8003BD74(s32 arg0, f32 x, f32 y, f32 scale) {
    Rect *r;
    f32 dx;
    f32 dy;

    if (arg0 != -1) {
        r = func_80023E18();
        dx = r->w;
        dx = (dx * scale) * 0.5;
        dy = r->h;
        dy = (dy * scale) * 0.5;
        func_80029738(r, x - dx, y - dy, x + dx, y + dy);
    }
}
