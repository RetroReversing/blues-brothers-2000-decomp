typedef struct H8C7C8B { u8 pad0[0x18]; s32 f18; } H8C7C8B;
typedef struct H8C7C8A { u8 pad0[0x74]; H8C7C8B *f74; } H8C7C8A;
extern s32 func_8008C3FC();

u8 *func_8008C7C8(H8C7C8A *arg0, u8 *arg1) {
    u32 v;

    v = *arg1++;
    if (v & 0x80) {
        v &= 0x7F;
        v <<= 8;
        v |= *arg1++;
    }
    func_8008C3FC(arg0, arg0->f74->f18 + v * 7);
    return arg1;
}

