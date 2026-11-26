typedef struct {
    f32 v[9];
} Key3ECB8;

typedef struct {
    u8 pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} Bone3ECB8;

typedef struct {
    u8 pad0[0x14];
    Bone3ECB8 *bones;
} Model3ECB8;

typedef struct {
    u16 unk0;
    u16 count;
} Keys3ECB8;

typedef struct {
    Keys3ECB8 *keys;
    u8 pad4[0x8 - 0x4];
    s32 frameLen;
    u8 padC[0x10 - 0xC];
    Model3ECB8 *model;
    u8 pad14[0x18 - 0x14];
    s32 count;
    f32 time;
    Key3ECB8 *out;
    u8 pad24[0x40 - 0x24];
    s32 cur;
    u8 pad44[0x50 - 0x44];
    Key3ECB8 *buf0;
    Key3ECB8 *buf1;
    s32 key0;
    s32 key1;
} Anim3ECB8;

void func_8003F2A4(Anim3ECB8 *);
void func_8003F44C(Anim3ECB8 *, Key3ECB8 *);

void func_8003ECB8(Anim3ECB8 *arg0, f32 arg1) {
    s32 i;
    s32 k0;
    s32 k1;
    s32 n;
    s32 m;
    f32 f;
    f32 frac;
    f32 inv;
    Key3ECB8 *a;
    Key3ECB8 *b;

    if (arg0->keys == NULL) {
        for (i = 0; i < arg0->count; i++) {
            arg0->out[i].v[0] = arg0->out[i].v[1] = arg0->out[i].v[2] = 1.0f;
            arg0->out[i].v[3] = arg0->model->bones[i].unk1C;
            arg0->out[i].v[4] = arg0->model->bones[i].unk20;
            arg0->out[i].v[5] = arg0->model->bones[i].unk24;
            arg0->out[i].v[6] = arg0->model->bones[i].unk10;
            arg0->out[i].v[7] = arg0->model->bones[i].unk14;
            arg0->out[i].v[8] = arg0->model->bones[i].unk18;
        }
        return;
    }
    k0 = 0;
    if (arg0->keys->count < 2) {
        frac = 0.0f;
        inv = 1.0f;
        k1 = k0;
    } else {
        f = arg1 / arg0->frameLen;
        k0 = f;
        if (f < 0.0) {
            frac = 1.0 - (k0 - f);
            k0--;
        } else {
            frac = f - k0;
        }
        inv = 1.0 - frac;
        if (k0 >= 0) {
            k0 = k0 % (arg0->keys->count - 1);
        } else {
            n = arg0->keys->count;
            m = -k0 % (n - 1) + 1;
            k0 = n - m;
        }
        if (k0 == 0 && frac == 0.0 && arg1 != 0.0) {
            k0 = arg0->keys->count - 1;
        }
        k1 = k0 + 1;
        if (k1 >= arg0->keys->count) {
            k1 = 0;
        }
    }
    if (arg0->key0 == k0) {
        a = arg0->buf0;
    } else if (arg0->key1 == k0) {
        a = arg0->buf1;
    } else {
        if (k0 < arg0->cur) {
            func_8003F2A4(arg0);
        }
        while (arg0->cur != k0) {
            func_8003F44C(arg0, NULL);
        }
        if (arg0->key0 != k1) {
            arg0->key0 = k0;
            func_8003F44C(arg0, arg0->buf0);
            a = arg0->buf0;
        } else {
            arg0->key1 = k0;
            func_8003F44C(arg0, arg0->buf1);
            a = arg0->buf1;
        }
    }
    if (arg0->key0 == k1) {
        b = arg0->buf0;
    } else if (arg0->key1 == k1) {
        b = arg0->buf1;
    } else {
        if (k1 < arg0->cur) {
            func_8003F2A4(arg0);
        }
        while (arg0->cur != k1) {
            func_8003F44C(arg0, NULL);
        }
        if (a != arg0->buf0) {
            arg0->key0 = k1;
            func_8003F44C(arg0, arg0->buf0);
            b = arg0->buf0;
        } else {
            arg0->key1 = k1;
            func_8003F44C(arg0, arg0->buf1);
            b = arg0->buf1;
        }
    }
    for (i = 0; i < arg0->count; i++) {
        arg0->out[i].v[0] = a[i].v[0] * inv + b[i].v[0] * frac;
        arg0->out[i].v[1] = a[i].v[1] * inv + b[i].v[1] * frac;
        arg0->out[i].v[2] = a[i].v[2] * inv + b[i].v[2] * frac;
        arg0->out[i].v[3] = a[i].v[3] * inv + b[i].v[3] * frac;
        arg0->out[i].v[4] = a[i].v[4] * inv + b[i].v[4] * frac;
        arg0->out[i].v[5] = a[i].v[5] * inv + b[i].v[5] * frac;
        arg0->out[i].v[6] = a[i].v[6] * inv + b[i].v[6] * frac;
        arg0->out[i].v[7] = a[i].v[7] * inv + b[i].v[7] * frac;
        arg0->out[i].v[8] = a[i].v[8] * inv + b[i].v[8] * frac;
        arg0->out[i].v[0] = a[i].v[0];
        arg0->out[i].v[1] = a[i].v[1];
        arg0->out[i].v[2] = a[i].v[2];
        arg0->out[i].v[3] = a[i].v[3];
        arg0->out[i].v[4] = a[i].v[4];
        arg0->out[i].v[5] = a[i].v[5];
        arg0->out[i].v[6] = a[i].v[6];
        arg0->out[i].v[7] = a[i].v[7];
        arg0->out[i].v[8] = a[i].v[8];
    }
    arg0->time = (k0 + frac) * arg0->frameLen;
}
