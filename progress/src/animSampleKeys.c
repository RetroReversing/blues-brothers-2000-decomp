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

/* Samples an animation at a frame: picks the two neighbouring keys, loads them and blends their bone values into the output. */ void animSampleKeys(Anim3ECB8 *anim, f32 frame) {
    s32 i;
    s32 keyA;
    s32 keyB;
    s32 numKeys;
    s32 wrapOffset;
    f32 f;
    f32 blendT;
    f32 invBlendT;
    Key3ECB8 *poseA;
    Key3ECB8 *poseB;

    if (anim->keys == NULL) {
        for (i = 0; i < anim->count; i++) {
            anim->out[i].v[0] = anim->out[i].v[1] = anim->out[i].v[2] = 1.0f;
            anim->out[i].v[3] = anim->model->bones[i].unk1C;
            anim->out[i].v[4] = anim->model->bones[i].unk20;
            anim->out[i].v[5] = anim->model->bones[i].unk24;
            anim->out[i].v[6] = anim->model->bones[i].unk10;
            anim->out[i].v[7] = anim->model->bones[i].unk14;
            anim->out[i].v[8] = anim->model->bones[i].unk18;
        }
        return;
    }
    keyA = 0;
    if (anim->keys->count < 2) {
        blendT = 0.0f;
        invBlendT = 1.0f;
        keyB = keyA;
    } else {
        f = frame / anim->frameLen;
        keyA = f;
        if (f < 0.0) {
            blendT = 1.0 - (keyA - f);
            keyA--;
        } else {
            blendT = f - keyA;
        }
        invBlendT = 1.0 - blendT;
        if (keyA >= 0) {
            keyA = keyA % (anim->keys->count - 1);
        } else {
            numKeys = anim->keys->count;
            wrapOffset = -keyA % (numKeys - 1) + 1;
            keyA = numKeys - wrapOffset;
        }
        if (keyA == 0 && blendT == 0.0 && frame != 0.0) {
            keyA = anim->keys->count - 1;
        }
        keyB = keyA + 1;
        if (keyB >= anim->keys->count) {
            keyB = 0;
        }
    }
    if (anim->key0 == keyA) {
        poseA = anim->buf0;
    } else if (anim->key1 == keyA) {
        poseA = anim->buf1;
    } else {
        if (keyA < anim->cur) {
            func_8003F2A4(anim);
        }
        while (anim->cur != keyA) {
            func_8003F44C(anim, NULL);
        }
        if (anim->key0 != keyB) {
            anim->key0 = keyA;
            func_8003F44C(anim, anim->buf0);
            poseA = anim->buf0;
        } else {
            anim->key1 = keyA;
            func_8003F44C(anim, anim->buf1);
            poseA = anim->buf1;
        }
    }
    if (anim->key0 == keyB) {
        poseB = anim->buf0;
    } else if (anim->key1 == keyB) {
        poseB = anim->buf1;
    } else {
        if (keyB < anim->cur) {
            func_8003F2A4(anim);
        }
        while (anim->cur != keyB) {
            func_8003F44C(anim, NULL);
        }
        if (poseA != anim->buf0) {
            anim->key0 = keyB;
            func_8003F44C(anim, anim->buf0);
            poseB = anim->buf0;
        } else {
            anim->key1 = keyB;
            func_8003F44C(anim, anim->buf1);
            poseB = anim->buf1;
        }
    }
    for (i = 0; i < anim->count; i++) {
        anim->out[i].v[0] = poseA[i].v[0] * invBlendT + poseB[i].v[0] * blendT;
        anim->out[i].v[1] = poseA[i].v[1] * invBlendT + poseB[i].v[1] * blendT;
        anim->out[i].v[2] = poseA[i].v[2] * invBlendT + poseB[i].v[2] * blendT;
        anim->out[i].v[3] = poseA[i].v[3] * invBlendT + poseB[i].v[3] * blendT;
        anim->out[i].v[4] = poseA[i].v[4] * invBlendT + poseB[i].v[4] * blendT;
        anim->out[i].v[5] = poseA[i].v[5] * invBlendT + poseB[i].v[5] * blendT;
        anim->out[i].v[6] = poseA[i].v[6] * invBlendT + poseB[i].v[6] * blendT;
        anim->out[i].v[7] = poseA[i].v[7] * invBlendT + poseB[i].v[7] * blendT;
        anim->out[i].v[8] = poseA[i].v[8] * invBlendT + poseB[i].v[8] * blendT;
        anim->out[i].v[0] = poseA[i].v[0];
        anim->out[i].v[1] = poseA[i].v[1];
        anim->out[i].v[2] = poseA[i].v[2];
        anim->out[i].v[3] = poseA[i].v[3];
        anim->out[i].v[4] = poseA[i].v[4];
        anim->out[i].v[5] = poseA[i].v[5];
        anim->out[i].v[6] = poseA[i].v[6];
        anim->out[i].v[7] = poseA[i].v[7];
        anim->out[i].v[8] = poseA[i].v[8];
    }
    anim->time = (keyA + blendT) * anim->frameLen;
}
