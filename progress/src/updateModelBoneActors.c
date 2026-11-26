typedef struct { s32 m[4][4]; } Mtx5E34;
typedef f32 MtxF5E34[4][4];

typedef struct Model5E34 {
    u8 pad0[0xC];
    s16 count;
    u8 padE[0x16];
    f32 scale;
} Model5E34;

typedef struct Obj5E34 {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 rx;
    s32 ry;
    s32 rz;
    u8 pad1C[0xC];
    u8 o28[0xC];
    s32 sx;
    s32 sy;
    s32 sz;
    u8 pad40[0x78];
    s32 kind;
    u8 padBC[8];
    Mtx5E34 *mtx;
    u8 padC8[0x18];
    struct { u8 pad[0x20]; s32 v20; } *anim;
} Obj5E34;

typedef struct Pos5E34 {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
} Pos5E34;

extern s32 coss(u16);
extern s32 sins(u16);
extern Pos5E34 *func_80012718(Obj5E34 *);
extern void func_80022EDC(Mtx5E34 *, s32 *, s32, void *);
extern Model5E34 *getImageAsset(s32);
extern void func_80024A3C(s32 *, s32 *, s32);
extern void func_80024B58(s32 *, s32 *, s32);
extern void func_80024BE0(s32 *, s32 *, s32);
extern void func_80024FE8(s32 *);
extern void syncActorPrevPos(Pos5E34 *);
extern void buildBoneMatrices(Model5E34 *, s32, s32, f32 *, s32, Mtx5E34 *);
extern Pos5E34 *func_80085650(s32);
extern void guMtxCatL(Mtx5E34 *, Mtx5E34 *, Mtx5E34 *);
extern void guMtxL2F(MtxF5E34 *, Mtx5E34 *);
extern f64 D_80007A10;
extern s32 D_800B74E4[];
extern s32 D_800B83C8[];
extern s32 D_800B9EB8[];
extern s32 D_800FB038[];
extern s32 D_80140260[];
extern Mtx5E34 *D_80140310[];

/* Builds the bone matrices for an object's model, then moves an actor to each bone's world position. Bones are written to the object's matrix buffer, and the matrix list used by the renderer is filled in. */
s32 updateModelBoneActors(Obj5E34 *obj) {
    Mtx5E34 rotMtx;
    f32 boneScale[9];
    s32 pos[3];
    s32 rot[3];
    s32 rotA[10];
    s32 rotB[10];
    Mtx5E34 boneMtx[38];
    MtxF5E34 boneMtxF[38];
    void *anim;
    Mtx5E34 *mtxBuf;
    Model5E34 *model;
    s32 boneCount;
    s32 drawCount;
    s32 i;
    s32 j;
    s16 cosv;
    s16 sinv;
    MtxF5E34 *mfPtr;
    Pos5E34 *actor;

    anim = obj->anim;
    mtxBuf = obj->mtx;
    if (anim == NULL || mtxBuf == NULL) {
        return 0;
    }
    model = getImageAsset(D_800FB038[obj->kind]);
    boneCount = model->count;
    func_80024FE8(rotA);
    func_80024B58(rotB, rotA, obj->rx);
    func_80024A3C(rotA, rotB, -obj->ry);
    func_80024BE0(rotB, rotA, -obj->rz);
    func_80022EDC(&rotMtx, rotB, 1, obj->o28);
    boneScale[0] = model->scale;
    boneScale[1] = model->scale;
    boneScale[2] = model->scale;
    boneScale[0] *= obj->sx;
    boneScale[1] *= obj->sy;
    boneScale[2] *= obj->sz;
    boneScale[3] = 0;
    boneScale[4] = 0;
    boneScale[5] = 0;
    boneScale[6] = 0;
    boneScale[7] = 0;
    boneScale[8] = 0;
    boneScale[0] *= D_80007A10;
    boneScale[1] *= D_80007A10;
    boneScale[2] *= D_80007A10;
    buildBoneMatrices(model, ((s32 *) anim)[8], -1, boneScale, 0, &mtxBuf[boneCount * D_800B9EB8[0]]);
    drawCount = boneCount;
    if (drawCount >= 38) {
        drawCount = 37;
    }
    D_800B74E4[0] = drawCount;
    for (i = 0; i < drawCount; i++) {
        D_80140260[i] = i;
        D_80140310[i] = &boneMtx[i];
    }
    for (i = 0; i < drawCount; i++) {
        for (j = 0; j < D_800B74E4[0]; j++) {
            if (D_80140260[j] == i) {
                break;
            }
        }
        if (j < D_800B74E4[0]) {
            *D_80140310[j] = mtxBuf[boneCount * D_800B9EB8[0] + i];
        }
        guMtxCatL(&mtxBuf[boneCount * D_800B9EB8[0] + i], &rotMtx, &mtxBuf[boneCount * D_800B9EB8[0] + i]);
    }
    mfPtr = boneMtxF;
    for (i = 0; i < drawCount; i++) {
        guMtxL2F(&boneMtxF[i], &boneMtx[i]);
        pos[0] = (*mfPtr)[3][0];
        pos[1] = (*mfPtr)[3][1];
        pos[2] = (*mfPtr)[3][2];
        cosv = coss(obj->rx);
        sinv = sins(obj->rx);
        rot[0] = ((pos[0] * cosv) >> 15) + ((pos[2] * sinv) >> 15);
        sinv = sins(obj->rx);
        cosv = coss(obj->rx);
        rot[1] = pos[1];
        rot[2] = -((pos[0] * sinv) >> 15) + ((pos[2] * cosv) >> 15);
        if (D_800B83C8[0]) {
            actor = func_80012718(obj);
        } else {
            actor = func_80085650(0);
        }
        actor->x = obj->x + rot[0];
        actor->y = obj->y + rot[1];
        actor->z = obj->z + rot[2];
        syncActorPrevPos(actor);
        mfPtr++;
    }
}
