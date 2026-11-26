typedef struct GfxW {
    u32 w0;
    u32 w1;
} GfxW;

typedef struct {
    s32 w;
    s32 h;
    s32 fmt;
    s32 pad;
    u8 data[1];
} Img;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x5C - 0x1C];
    s32 unk5C;
    s32 unk60;
    u8 pad64[0x70 - 0x64];
    s32 unk70;
} Obj;

Img *getImageAsset(s32);
s32 isObjectInRange(Obj *, s32);
void func_8001F230(Obj *);
void func_80024FE8(s32 *);
void func_80024BE0(s32 *, s32 *, s32);
s32 buildObjectMatrix(Obj *, s32 *, s32);
void drawTextureRect(s32, s32, s32, s32, s32, s32, s32);

extern GfxW *D_80177E18;

#define GFX(a, b) { GfxW *_g = D_80177E18++; _g->w0 = (a); _g->w1 = (b); }
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))

/* Draws a tiled image object: loads its pixel data in strips that fit the
 * texture memory (RDP tile load), and draws each strip as a textured rectangle.
 * Returns 0 if the object is culled. */
s32 drawImageObject(Obj *obj) {
    s32 rotation[10];
    s32 matrix[10];
    s32 halfSize;
    Img *img;
    s32 width;
    s32 height;
    s32 rows;
    s32 dataOffset;
    s32 left;
    s32 right;
    s32 y;
    u8 *data;
    s32 step;
    s32 fmt;

    halfSize = obj->unk70;
    img = getImageAsset(obj->unk60);
    if (isObjectInRange(obj, 30000) == 0) {
        return 0;
    }
    func_8001F230(obj);
    GFX(0xE200001C, 0x504340);
    func_80024FE8(rotation);
    dataOffset = 0;
    func_80024BE0(matrix, rotation, obj->unk18);
    buildObjectMatrix(obj, matrix, 0);
    data = img->data;
    height = img->h;
    left = -(halfSize * 2);
    right = halfSize * 2;
    step = (halfSize * 2) / height;
    fmt = img->fmt;
    width = img->w;
    y = -halfSize;
    if (fmt == 32) {
        while (height > 0) {
            rows = height;
            if (width * height > 0x400) {
                rows = 0x400 / width;
            }
            GFX(0xFD180000, (u32)(data + dataOffset));
            GFX(0xF5180000, 0x07080200);
            GFX(0xE6000000, 0);
            GFX(0xF3000000, 0x07000000 | ((MIN(width * rows - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 4) & 0xFFF));
            GFX(0xE7000000, 0);
            GFX(0xF5180000 | (((((width * 2) + 7) >> 3) & 0x1FF) << 9), 0x80200);
            GFX(0xF2000000, ((((width - 1) << 2) & 0xFFF) << 12) | (((rows - 1) << 2) & 0xFFF));
            drawTextureRect(left, y, right, y + step * rows, width << 6, rows << 6, obj->unk5C); y += step * rows;
            height -= rows;
            dataOffset += width * (rows << 2);
        }
    } else {
        while (height > 0) {
            rows = height;
            if (width * height > 0x800) {
                rows = 0x800 / width;
            }
            GFX(0xFD100000, (u32)(data + dataOffset));
            GFX(0xF5100000, 0x07080200);
            GFX(0xE6000000, 0);
            GFX(0xF3000000, 0x07000000 | ((MIN(width * rows - 1, 0x7FF) & 0xFFF) << 12) | (CALC_DXT(width, 2) & 0xFFF));
            GFX(0xE7000000, 0);
            GFX(0xF5100000 | (((((width * 2) + 7) >> 3) & 0x1FF) << 9), 0x80200);
            GFX(0xF2000000, ((((width - 1) << 2) & 0xFFF) << 12) | (((rows - 1) << 2) & 0xFFF));
            drawTextureRect(left, y, right, y + step * rows, width << 6, rows << 6, obj->unk5C); y += step * rows;
            height -= rows;
            dataOffset += width * (rows << 1);
        }
    }
    return 1;
}
