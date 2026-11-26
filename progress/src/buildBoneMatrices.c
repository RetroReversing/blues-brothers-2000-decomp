typedef f32 MtxF0F10[4][4];
typedef struct { s32 m[4][4]; } Mtx0F10;

typedef struct Xf0F10 {
    f32 scale[3];
    f32 rot[3];
    f32 pos[3];
} Xf0F10;

typedef struct Bone0F10 {
    u8 pad0[6];
    s16 nchild;
    s16 *children;
    u8 padC[4];
    f32 pos[3];
    f32 rot[3];
} Bone0F10;

typedef struct Model0F10 {
    u8 pad0[0xE];
    s16 root;
    u8 pad10[4];
    Bone0F10 *bones;
} Model0F10;

extern f32 sinApprox(f32);
extern f32 __cosf(f32);
extern void guMtxF2L(MtxF0F10 *, Mtx0F10 *);
extern const f32 D_80007878;
extern f32 D_800B5DE8[3][3];

/* Builds the matrix for one bone from its animated or rest transform and its parent's, writes it to out[bone], then recurses into the bone's children. */
void buildBoneMatrices(Model0F10 *model, Xf0F10 *animPose, s32 boneIdx, Xf0F10 *parentXf, f32 (*parentAxes)[3], Mtx0F10 *outMtx) {
    Xf0F10 xf;
    f32 rotM[3][3];
    MtxF0F10 mtx;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;
    s32 c;
    f32 offX;
    f32 offY;
    f32 offZ;

    if (boneIdx < 0) {
        boneIdx = model->root;
    }
    if (parentAxes == NULL) {
        parentAxes = D_800B5DE8;
    }
    xf = *parentXf;
    if (animPose != NULL) {
        xf.scale[0] *= animPose[boneIdx].scale[0];
        xf.scale[1] *= animPose[boneIdx].scale[1];
        xf.scale[2] *= animPose[boneIdx].scale[2];
        xf.rot[0] += animPose[boneIdx].rot[0];
        xf.rot[1] += animPose[boneIdx].rot[1];
        xf.rot[2] += animPose[boneIdx].rot[2];
        tx = animPose[boneIdx].pos[0];
        ty = animPose[boneIdx].pos[1];
        tz = animPose[boneIdx].pos[2];
    } else {
        xf.rot[0] += model->bones[boneIdx].rot[0];
        xf.rot[1] += model->bones[boneIdx].rot[1];
        xf.rot[2] += model->bones[boneIdx].rot[2];
        tx = model->bones[boneIdx].pos[0];
        ty = model->bones[boneIdx].pos[1];
        tz = model->bones[boneIdx].pos[2];
    }
    offX = (tx * parentAxes[0][0] + ty * parentAxes[1][0] + tz * parentAxes[2][0]) * parentXf->scale[0];
    offY = (tx * parentAxes[0][1] + ty * parentAxes[1][1] + tz * parentAxes[2][1]) * parentXf->scale[1];
    offZ = (tx * parentAxes[0][2] + ty * parentAxes[1][2] + tz * parentAxes[2][2]) * parentXf->scale[2];
    xf.pos[0] += offX;
    xf.pos[1] += offY;
    xf.pos[2] += offZ;
    sx = sinApprox(xf.rot[0]);
    cx = __cosf(xf.rot[0]);
    sy = sinApprox(xf.rot[1]);
    cy = __cosf(xf.rot[1]);
    sz = sinApprox(xf.rot[2]);
    cz = __cosf(xf.rot[2]);
    rotM[0][0] = cy * cz;
    rotM[0][1] = cy * sz;
    rotM[0][2] = -sy;
    rotM[1][0] = sx * sy * cz + cx * -sz;
    rotM[1][1] = sx * sy * sz + cx * cz;
    rotM[1][2] = sx * cy;
    rotM[2][0] = cx * sy * cz + -sx * -sz;
    rotM[2][1] = cx * sy * sz + -sx * cz;
    rotM[2][2] = cx * cy;
    mtx[0][0] = rotM[0][0] * xf.scale[0];
    mtx[0][1] = rotM[0][1] * xf.scale[0];
    mtx[0][2] = rotM[0][2] * xf.scale[0];
    mtx[0][3] = 0;
    mtx[1][0] = rotM[1][0] * xf.scale[1];
    mtx[1][1] = rotM[1][1] * xf.scale[1];
    mtx[1][2] = rotM[1][2] * xf.scale[1];
    mtx[1][3] = 0;
    mtx[2][0] = rotM[2][0] * xf.scale[2];
    mtx[2][1] = rotM[2][1] * xf.scale[2];
    mtx[2][2] = rotM[2][2] * xf.scale[2];
    mtx[2][3] = 0;
    mtx[3][0] = xf.pos[0];
    mtx[3][1] = xf.pos[1];
    mtx[3][2] = xf.pos[2];
    mtx[3][3] = D_80007878;
    guMtxF2L(&mtx, &outMtx[boneIdx]);
    for (c = 0; c < model->bones[boneIdx].nchild; c++) {
        buildBoneMatrices(model, animPose, model->bones[boneIdx].children[c], &xf, rotM, outMtx);
    }
}
