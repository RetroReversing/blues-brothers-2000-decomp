typedef struct Blk25418 {
    s32 size;
    s32 tag;
} Blk25418;
void func_8002553C(void *, s32);
void func_80025728(s32);
void func_800899DC(void *);
extern s32 D_80001090;
extern s32 D_800AE010;
extern s32 D_800AE130;
extern s32 D_800AE134;
extern s32 D_80106A34;
extern s32 *D_80106A38;
extern s32 D_801858A0;

void *func_80025418(s32 size) {
    s32 *b;
    s32 *n;
    s32 w;
    s32 sz;
    s32 need;

    if (D_800AE130 == 0) {
        D_800AE130 = 1;
        func_8002553C(&D_801858A0, 0x803FFFF0);
    }
    size = (size + 7) & ~7;
    b = D_80106A38;
    D_800AE134 += size;
    D_80106A34 -= size;
    for (;;) {
        sz = b[0];
        w = sz & 1;
        sz &= ~1;

        if (sz < 0) {
            func_80025728(sz);
            func_800899DC(&D_80001090);
            return NULL;
        }
        if (w ) {
            if (sz == size) {
                b[0] = sz;
                b[1] = D_800AE010;
                return b + 2;
            }
            if (sz >= size + 8) {
                n = b;
                b[0] = size;
                b[1] = D_800AE010;
                b = (s32 *)((u8 *)b + (size + 8));
                b[0] = (sz - size - 8) | 1;
                b[1] = 0;
                return n + 2;

            }
        }
        b = (s32 *)((u8 *)b + (sz + 8));
    }
}
