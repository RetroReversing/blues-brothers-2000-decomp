typedef struct {
    f32 x, y, z;
} Point3;

typedef struct {
    f32 x, y, z, w;
} Vector4;

typedef struct {
    f32 element[4][4];
} Matrix4;

extern char D_80007DC4[];

f32 sqrtf(f32);
f32 __cosf(f32);
f32 func_800247D0(f32, f32);
f32 func_80024984(f32);
f32 func_8004BC74(Matrix4 *);
void func_8004DC38(Matrix4 *, Matrix4 *);
void func_8004DD58(Matrix4 *, Matrix4 *);
void func_800899DC(char *);

void func_8004C020(Matrix4 *mat, f32 *sx, f32 *sy, f32 *sz, f32 *rx, f32 *ry, f32 *rz, f32 *tx, f32 *ty, f32 *tz) {
    Matrix4 locmat;
    Matrix4 pmat;
    Matrix4 invpmat;
    Matrix4 tinvpmat;
    Vector4 prhs;
    Vector4 psol;
    Point3 row[3];
    Point3 pdum3;
    f32 transx;
    f32 transy;
    f32 transz;
    f32 scalex;
    f32 scaley;
    f32 scalez;
    f32 roty;
    f32 rotx;
    f32 rotz;
    s32 i;

    locmat = *mat;
    locmat.element[0][0] /= locmat.element[3][3];
    locmat.element[0][1] /= locmat.element[3][3];
    locmat.element[0][2] /= locmat.element[3][3];
    locmat.element[0][3] /= locmat.element[3][3];
    locmat.element[1][0] /= locmat.element[3][3];
    locmat.element[1][1] /= locmat.element[3][3];
    locmat.element[1][2] /= locmat.element[3][3];
    locmat.element[1][3] /= locmat.element[3][3];
    locmat.element[2][0] /= locmat.element[3][3];
    locmat.element[2][1] /= locmat.element[3][3];
    locmat.element[2][2] /= locmat.element[3][3];
    locmat.element[2][3] /= locmat.element[3][3];
    locmat.element[3][0] /= locmat.element[3][3];
    locmat.element[3][1] /= locmat.element[3][3];
    locmat.element[3][2] /= locmat.element[3][3];
    locmat.element[3][3] /= locmat.element[3][3];
    pmat = locmat;
    pmat.element[0][3] = 0.0f;
    pmat.element[1][3] = 0.0f;
    pmat.element[2][3] = 0.0f;
    pmat.element[3][3] = 1.0f;
    if (func_8004BC74(&pmat) == 0.0) {
        func_800899DC(D_80007DC4);
    }
    if (locmat.element[0][3] != 0 || locmat.element[1][3] != 0 || locmat.element[2][3] != 0) {
        prhs.x = locmat.element[0][3];
        prhs.y = locmat.element[1][3];
        prhs.z = locmat.element[2][3];
        prhs.w = locmat.element[3][3];
        func_8004DC38(&pmat, &invpmat);
        func_8004DD58(&invpmat, &tinvpmat);
        psol.x = (prhs.x * tinvpmat.element[0][0]) + (prhs.y * tinvpmat.element[1][0]) + (prhs.z * tinvpmat.element[2][0]) + (prhs.w * tinvpmat.element[3][0]);
        psol.y = (prhs.x * tinvpmat.element[0][1]) + (prhs.y * tinvpmat.element[1][1]) + (prhs.z * tinvpmat.element[2][1]) + (prhs.w * tinvpmat.element[3][1]);
        psol.z = (prhs.x * tinvpmat.element[0][2]) + (prhs.y * tinvpmat.element[1][2]) + (prhs.z * tinvpmat.element[2][2]) + (prhs.w * tinvpmat.element[3][2]);
        psol.w = (prhs.x * tinvpmat.element[0][3]) + (prhs.y * tinvpmat.element[1][3]) + (prhs.z * tinvpmat.element[2][3]) + (prhs.w * tinvpmat.element[3][3]);
    }
    locmat.element[0][3] = locmat.element[1][3] = locmat.element[2][3] = 0;
    locmat.element[3][3] = 1.0f;
    transx = locmat.element[3][0];
    locmat.element[3][0] = 0;
    transy = locmat.element[3][1];
    locmat.element[3][1] = 0;
    transz = locmat.element[3][2];
    locmat.element[3][2] = 0;
    row[0].x = locmat.element[0][0];
    row[0].y = locmat.element[0][1];
    row[0].z = locmat.element[0][2];
    row[1].x = locmat.element[1][0];
    row[1].y = locmat.element[1][1];
    row[1].z = locmat.element[1][2];
    row[2].x = locmat.element[2][0];
    row[2].y = locmat.element[2][1];
    row[2].z = locmat.element[2][2];

    scalex = sqrtf(row[0].x * row[0].x + row[0].y * row[0].y + row[0].z * row[0].z);
    row[0].x /= scalex;
    row[0].y /= scalex;
    row[0].z /= scalex;

    {
        f32 shear = -(row[0].x * row[1].x + row[0].y * row[1].y + row[0].z * row[1].z);
        row[1].x = row[1].x + row[0].x * shear;
        row[1].y = row[1].y + row[0].y * shear;
        row[1].z = row[1].z + row[0].z * shear;
    }

    scaley = sqrtf(row[1].x * row[1].x + row[1].y * row[1].y + row[1].z * row[1].z);
    row[1].x /= scaley;
    row[1].y /= scaley;
    row[1].z /= scaley;

    {
        f32 shear = -(row[0].x * row[2].x + row[0].y * row[2].y + row[0].z * row[2].z);
        row[2].x = row[2].x + row[0].x * shear;
        row[2].y = row[2].y + row[0].y * shear;
        row[2].z = row[2].z + row[0].z * shear;
    }
    {
        f32 shear = -(row[1].x * row[2].x + row[1].y * row[2].y + row[1].z * row[2].z);
        row[2].x = row[2].x + row[1].x * shear;
        row[2].y = row[2].y + row[1].y * shear;
        row[2].z = row[2].z + row[1].z * shear;
    }

    scalez = sqrtf(row[2].x * row[2].x + row[2].y * row[2].y + row[2].z * row[2].z);
    row[2].x /= scalez;
    row[2].y /= scalez;
    row[2].z /= scalez;

    pdum3.x = row[1].y * row[2].z - row[1].z * row[2].y;
    pdum3.y = row[1].z * row[2].x - row[1].x * row[2].z;
    pdum3.z = row[1].x * row[2].y - row[1].y * row[2].x;
    if (row[0].x * pdum3.x + row[0].y * pdum3.y + row[0].z * pdum3.z < 0.0f) {
        scalex = -scalex;
        scaley = -scaley;
        scalez = -scalez;
        for (i = 0; i < 3; i++) {
            row[i].x = -row[i].x;
        }
    }

    roty = func_80024984(-row[0].z);
    if (__cosf(roty) != 0.0f) {
        rotx = func_800247D0(row[1].z, row[2].z);
        rotz = func_800247D0(row[0].y, row[0].x);
    } else {
        rotx = func_800247D0(row[1].x, row[1].y);
        rotz = 0.0f;
    }
    if (sx != NULL) {
        *sx = scalex;
    }
    if (sy != NULL) {
        *sy = scaley;
    }
    if (sz != NULL) {
        *sz = scalez;
    }
    if (rx != NULL) {
        *rx = rotx;
    }
    if (ry != NULL) {
        *ry = roty;
    }
    if (rz != NULL) {
        *rz = rotz;
    }
    if (tx != NULL) {
        *tx = transx;
    }
    if (ty != NULL) {
        *ty = transy;
    }
    if (tz != NULL) {
        *tz = transz;
    }
}
