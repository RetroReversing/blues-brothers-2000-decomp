typedef struct O8EDE4 {
    u8 pad0[0xC];
    s32 end;
    u8 pad10[8];
    s32 time;
    u8 pad1C[8];
    f32 out;
    u8 pad28[0xC];
    u8 *ptr;
    u8 pad38[0x34];
    f32 scale;
    f32 val;
    u8 pad74[0x30];
    u16 cnt;
} O8EDE4;
extern f64 D_80009D00;

void func_8008EDE4(O8EDE4 *arg0) {
    u8 b;
    u32 c;
    u8 *p;
    u8 *p2;
    u8 *p3;
    f32 v;
    s32 t;

    do {
        arg0->time += 0x100;
        c = arg0->cnt;
        c--;
        arg0->cnt = c;
        if (!(c & 0xFFFF)) {
            p = arg0->ptr;
            arg0->ptr = p + 1;
            b = *p;
            if (b >= 0x80) {
                v = (f32)((f64)(f32)(b & 0x7F) - D_80009D00);
                arg0->val = v;
                arg0->out = v * arg0->scale;
                p2 = arg0->ptr;
                arg0->ptr = p2 + 1;
                b = *p2;
                if (b >= 0x80) {
                    t = (b & 0x7F) << 8;
                    arg0->cnt = t;
                    p3 = arg0->ptr;
                    arg0->ptr = p3 + 1;
                    arg0->cnt = *p3 + (t + 2);
                } else {
                    arg0->cnt = b + 2;
                }
            } else {
                v = (f32)((f64)(f32)b - D_80009D00);
                arg0->cnt = 1;
                arg0->val = v;
                arg0->out = v * arg0->scale;
            }
        }
    } while (arg0->time - arg0->end < 0);
}
