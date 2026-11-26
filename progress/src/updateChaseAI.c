typedef struct {
    u8 pad0[0x4];
    f32 x;      /* 0x04 */
    f32 y;      /* 0x08 */
    f32 z;      /* 0x0C */
    s32 unk10;  /* 0x10 */
    u8 pad14[0x64 - 0x14];
    s32 unk64;  /* 0x64 */
    u8 pad68[0x70 - 0x68];
    s32 unk70;  /* 0x70 */
    s32 unk74;  /* 0x74 */
    u8 pad78[0xAC - 0x78];
    f32 unkAC;  /* 0xAC */
    f32 unkB0;  /* 0xB0 */
    f32 unkB4;  /* 0xB4 */
    u8 padB8[0xD0 - 0xB8];
    s32 unkD0;  /* 0xD0 */
    u8 padD4[0x104 - 0xD4];
    f32 unk104; /* 0x104 */
} Obj84CCC;

typedef struct {
    u8 pad0[0x88];
    s32 unk88;
    u8 pad8C[0xB4 - 0x8C];
    f32 unkB4;
    u8 padB8[0x100 - 0xB8];
    f32 unk100;
    f32 unk104;
} Cam84CCC;

typedef struct {
    u8 pad0[0x88];
    s32 unk88;
} Flag84CCC;

s16 coss(u16);
s16 sins(u16);
s32 func_8002492C(f32, f32);
s32 approachS32(s32, s32, s32);
f32 func_8002D858(void *, void *);
f32 func_8002DD60(f32);
void func_8002E100(f32 *, f32 *);
s32 animStepKeys(void *);
void func_80043328(void *, s32, s32);
f32 splineClosestT(s32, void *, f32 *, s32);
void func_80081990(void *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
extern Flag84CCC *D_800B3964;
extern s32 gCamSpeedScale;
extern u8 *gCameraTarget;
extern s32 gSplinePointCount[];
extern Cam84CCC *D_8014AAB0;

/* Chases the player when close, otherwise follows the patrol path, steering the object by its turn and climb rates. */
s32 updateChaseAI(Obj84CCC *obj) {
    f32 v[3];
    f32 sp20;
    s32 pathIdx;
    s32 r;
    s32 heading;
    f32 dist;
    f32 dx;
    f32 dz;
    f32 turn;
    f32 lim;
    f32 climb;
    f32 range;
    f32 h;

    pathIdx = obj->unk70;
    func_80081990(&obj->x, pathIdx, obj->unkB4);
    func_80081AC0(v, pathIdx, obj->unkB4);
    func_8002E100(v, v);
    r = animStepKeys(obj);
    dist = func_8002D858(obj, &obj->unk10);
    D_8014AAB0->unkB4 = dist;
    if (dist < 250.0f) {
        D_800B3964->unk88 = 0;
        return 2;
    }
    D_800B3964->unk88 = 1;
    if (dist < 450.0f) {
        D_8014AAB0->unk88 = 2;
        heading = func_8002492C(v[2], v[0]);
        dx = *(f32 *)(gCameraTarget + 4) - obj->x;
        dz = *(f32 *)(gCameraTarget + 0xC) - obj->z;
        turn = coss(heading) * dx + sins(heading) * dz;
        climb = sins(heading) * dx + coss(heading) * dz;
        lim = obj->unkAC * 0.5f;
        turn = turn / 100000.0;
        climb = climb / 10000000.0f;
        if (func_8002DD60(turn) < 11.5f) {
            turn = 0.0f;
            func_80043328(obj, obj->unk74, 0x100);
        } else {
            func_80043328(obj, obj->unk74 + 1, 0x100);
        }
        lim = func_8002DD60(lim);
        if (lim < turn) {
            turn = lim;
        }
        if (turn < -lim) {
            turn = -lim;
        }
        obj->unk10 = approachS32(heading, obj->unk10, gCamSpeedScale << 9);
    } else {
        range = gSplinePointCount[pathIdx];
        func_80043328(obj, obj->unk74 + 2, 0x100);
        h = splineClosestT(pathIdx, gCameraTarget + 4, &sp20, 0);
        D_8014AAB0->unk88 = 3;
        D_8014AAB0->unk100 = h;
        D_8014AAB0->unk104 = sp20;
        if (obj->unk104 < sp20 && func_8002DD60(h - obj->unkB4) < 0.2) {
            if (obj->unkD0 != obj->unk74) {
                func_80043328(obj, obj->unk74, 0x100);
            } else if (r != 0) {
                obj->unk64 = 0;
            }
            return 2;
        }
        heading = func_8002492C(v[0], v[2]);
        obj->unk10 = approachS32(heading, obj->unk10, gCamSpeedScale << 9);
        v[0] = h - obj->unkB4;
        v[2] = range - v[0];
        if (range < v[0]) {
            v[0] -= range;
        }
        if (range < v[2]) {
            v[2] -= range;
        }
        if (v[0] < 0.0f) {
            v[0] += range;
        }
        if (v[2] < 0.0f) {
            v[2] += range;
        }
        if (v[0] < v[2]) {
            turn = v[0];
            obj->unkAC = func_8002DD60(obj->unkAC);
        } else {
            turn = v[2];
            obj->unkAC = -func_8002DD60(obj->unkAC);
        }
        lim = obj->unkAC;
        climb = -obj->unkB0 / 50.0f;
        if (lim < turn) {
            turn = lim;
        }
        if (turn < lim) {
            turn = lim;
        }
    }
    obj->unkB4 += turn;
    obj->unkB0 += climb;
    if (obj->unk104 < obj->unkB0) {
        obj->unkB0 = obj->unk104;
    }
    if (obj->unkB0 < -obj->unk104) {
        obj->unkB0 = -obj->unk104;
    }
    lim = gSplinePointCount[pathIdx];
    if (obj->unkB4 < 0.0f) {
        obj->unkB4 += lim;
    }
    if (lim < obj->unkB4) {
        obj->unkB4 -= lim;
    }
    return 0;
}
