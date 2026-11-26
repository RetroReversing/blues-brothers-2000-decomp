typedef f32 Mtx4[4][4];

typedef struct ObjT {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x8C - 0x10];
    Mtx4 *f8C;
    u8 pad90[0x9C - 0x90];
    void *f9C;
} ObjT;

void func_800414D0(ObjT *);
void mtxIdentity3(f32 *);
void func_8002DB6C(f32 *, f32 *, f32);
void func_800955C8(Mtx4 *, Mtx4 *);
void mtxTransformVec3(f32 *, f32 *, f32 *);
void func_80034FEC(ObjT *, s32 *);
void updateCameraView(ObjT *);
extern s32 D_80140260[];
extern Mtx4 *D_80140310[];
extern s32 D_800B74E4;
extern ObjT *gCameraRig;

void func_80052514(ObjT *arg0) {
    Mtx4 m0;
    Mtx4 m1;
    f32 v[3];
    f32 out[3];
    f32 q0[10];
    f32 q1[10];
    s32 pos[3];
    Mtx4 *p;

    D_80140260[0] = 0x22;
    D_80140310[0] = &m0;
    D_80140260[1] = 0x23;
    D_80140310[1] = &m1;
    D_800B74E4 = 2;
    func_800414D0(arg0);
    mtxIdentity3(q0);
    func_8002DB6C(q1, q0, 3.1415925f);
    p = arg0->f8C;
    func_800955C8(p++, &m0);
    func_800955C8(p++, &m1);
    p -= 2;
    v[0] = p[0][3][0];
    v[1] = p[0][3][1];
    v[2] = p[0][3][2];
    mtxTransformVec3(out, q1, v);
    gCameraRig->x = arg0->x + out[0];
    gCameraRig->y = arg0->y + out[1];
    gCameraRig->z = arg0->z + out[2];
    p++;
    v[0] = p[0][3][0];
    v[1] = p[0][3][1];
    v[2] = p[0][3][2];
    mtxTransformVec3(out, q1, v);
    out[0] += arg0->x;
    out[1] += arg0->y;
    out[2] += arg0->z;
    pos[0] = out[0];
    pos[1] = out[1];
    pos[2] = out[2];
    func_80034FEC(gCameraRig, pos);
    gCameraRig->f9C = updateCameraView;
}
