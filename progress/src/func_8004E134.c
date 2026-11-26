f32 func_8004E694(s32, s32, s32, f32);
typedef struct { s32 x, y, z; } Pt;
typedef struct Spl {
    /* 0x00 */ u8 pad0[0x70];
    /* 0x70 */ s32 n;
    /* 0x74 */ Pt *pts;
    /* 0x78 */ s32 order;
    /* 0x7C */ s32 flags;
} Spl;
typedef struct { f32 x, y, z; } Vec;

void func_8004E134(Spl *arg0, f32 t, Vec *out) {
    Pt *pts;
    s32 order;
    f32 f;
    s32 i;
    s32 end;
    s32 j;
    f32 w;
    Pt *p;
    s32 start;

    pts = arg0->pts;
    order = arg0->order;
    if (arg0->flags & 1) {
        while (t > 1.0) {
            t -= 1.0;
        }
        while (t < 0.0) {
            t += 1.0;
        }
    } else if (t > 1.0) {
        t = 1.0f;
    } else if (t < 0.0) {
        t = 0.0f;
    }
    f = (f32)(arg0->n - 2) * t;
    if (t == 1.0) {
        out->x = pts[arg0->n - 1].x;
        out->y = pts[arg0->n - 1].y;
        out->z = pts[arg0->n - 1].z;
        return;
    }
    i = f;
    end = i + 5;
    start = i + 2;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    if (end >= arg0->n) {
        end = arg0->n - 1;
    }
    for (j = start; j < end; j++) {
        w = func_8004E694(j, 3, order, f);
        out->x += pts[j].x * w;
        out->y += pts[j].y * w;
        out->z += pts[j].z * w;
    }
}

