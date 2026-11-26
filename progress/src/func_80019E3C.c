typedef struct Obj {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    s32 rot;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x5C - 0x1C];
    s32 unk5C;
    u8 pad60[4];
    s32 timer;
    s32 unk68;
    u8 pad6C[4];
    s32 unk70;
    s32 unk74;
    u8 pad78[4];
    u32 state;
    u8 pad80[4];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 pad90[8];
    void *cb98;
    void *cb9C;
    void (*destroy)(struct Obj *);
    u8 padA4[4];
    struct Obj *child;
    u8 padAC[0xC0 - 0xAC];
    s32 unkC0;
    u8 padC4[0x108 - 0xC4];
} Obj;

extern s32 D_800BD000[];
extern s32 D_800BD084;
extern s32 D_800BD050;
extern s32 D_800BCFF8;
extern Obj *gCameraTarget;
extern Obj *gCameraRig;
extern s32 gCamSpeedScale;
extern s32 gFrameScale;
extern char D_80000B40[];
extern char D_80000B54[];
extern s32 D_80000B68;
extern s32 D_80000B78;

s32 tickActorTimer(void);
s32 func_80023D58(s32);
s32 randomRange(s32, s32);
Obj *func_8005B060(Obj *);
void func_80088F40(void);
Obj *func_80017DEC(s32);
void actorSetAnim(Obj *, s32, s32);
void debugPrintf(char *);
Obj *findActor(s32, s32);
Obj *func_800232B4(s32, s32, s32, s32);
s32 approachAngle(s32, s32, s32);
s32 func_8002D260(s32);
s32 func_80023DBC(s32);
void startStoryDialog(s32, void *, Obj *);
void func_8002A360(s32, s32);
f32 sqrtf(f32);
void func_80019A2C(Obj *);
void func_80023078(Obj *);
void func_8003930C(Obj *);
void func_80034F50(Obj *);
void updateCameraView(Obj *);
void func_80019D6C(Obj *);
void func_800340B4(Obj *);

void func_80019E3C(Obj *obj) {
    Obj tmp;
    Obj *o;
    Obj *found;
    f32 dx;
    f32 dz;
    f32 dist;

    if (tickActorTimer() != 0) {
        obj->timer = 0;
    }
    switch (obj->state) {
    case 0:
        D_800BD000[0] = func_80023D58(0x1D5);
        D_800BD000[1] = func_80023D58(0x1D6);
        D_800BD000[2] = func_80023D58(0x1D7);
        D_800BD000[3] = func_80023D58(0x1D8);
        D_800BD000[4] = func_80023D58(0x1D9);
        D_800BD000[5] = func_80023D58(0x1DA);
        D_800BD000[6] = func_80023D58(0x1DB);
        D_800BD000[7] = func_80023D58(0x1DC);
        D_800BD000[8] = func_80023D58(0x1DD);
        D_800BD000[9] = func_80023D58(0x1DE);
        D_800BD084 = func_80023D58(0x1D3);
        D_800BD050 = func_80023D58(0x1D4);
        D_800BCFF8 = func_80023D58(0x18E);
        obj->state = 1;
        obj->unk74 = 0;
        obj->unk70 = 0;
        obj->unk84 = 0;
        obj->unkC0 = 0;
        obj->child = NULL;
        obj->unk8C = 6;
        do {
            obj->unk8C = randomRange(1, 8);
        } while (obj->unk8C == 6);
        o = func_8005B060(obj);
        o->destroy(o);
        func_80088F40();
        found = func_80017DEC(0);
        if (found != NULL) {
            gCameraTarget->rot = -0x4000;
            gCameraTarget->cb9C = func_8003930C;
            gCameraTarget->timer = 200;
            actorSetAnim(gCameraTarget, 2, 0x100);
            gCameraRig->x = found->x;
            gCameraRig->y = found->y;
            gCameraRig->z = found->z;
            gCameraRig->cb9C = func_80034F50;
            gCameraRig->child = NULL;
        } else {
            debugPrintf(D_80000B40);
        }
        break;
    case 1:
        if (findActor(0x800, 0) != NULL) {
            obj->state++;
            found = func_800232B4(0x101, 0, 0, 0);
            obj->child = found;
            found->unk68 = -1;
            found->cb98 = func_80019A2C;
            found->cb9C = (void *)((u8 *)func_80023078 + 8);
            found->timer = 100;
            found->unk5C = 0;
            obj->unk8C = 6000;
        }
        break;
    case 2:
        obj->unk8C = 6000;
        if (findActor(0x800, 0) == NULL) {
            found = findActor(0x134, 0);
            if (found != NULL) {
                gCameraTarget->x = found->x;
                gCameraTarget->y = found->y;
                gCameraTarget->z = found->z;
                found->unk68 = 3;
                found->cb9C = (void *)((u8 *)func_80023078 + 8);
            }
            obj->state++;
            o = findActor(0x120, 0);
            if (o == NULL) {
                debugPrintf(D_80000B54);
            }
            gCameraRig->x = o->x;
            gCameraRig->y = o->y;
            gCameraRig->z = o->z;
            gCameraRig->rot = o->rot;
            gCameraRig->unk14 = o->unk14;
            gCameraRig->rot = -0x4000;
            gCameraRig->unk18 = 0;
            gCameraRig->x = 2835.0f;
            gCameraRig->y = 500.0f;
            gCameraRig->z = -6.0f;
            gCameraRig->cb9C = updateCameraView;
            gCameraRig->unk14 = 0;
            obj->child->unk68 = 13;
            obj->timer = -1;
        }
        break;
    case 3:
        found = findActor(0x1013, 0);
        if (found != NULL) {
            obj->timer = 500;
            gCameraRig->cb9C = func_80019D6C;
            gCameraRig->child = found;
        } else {
            gCameraRig->rot = -0x4000;
            gCameraRig->unk18 = 0;
            gCameraRig->unk14 = 0;
            gCameraRig->x = 2835.0f;
            gCameraRig->y = 500.0f;
            gCameraRig->z = -6.0f;
            gCameraRig->cb9C = updateCameraView;
        }
        if (found == NULL) {
            if (obj->timer <= 0) {
                o = findActor(0x120, 0);
                if (o == NULL) {
                    debugPrintf(D_80000B54);
                }
                gCameraRig->x = o->x;
                gCameraRig->y = o->y;
                gCameraRig->z = o->z;
                gCameraRig->rot = -0x4000;
                gCameraRig->x = 2835.0f;
                gCameraRig->unk18 = 0;
                gCameraRig->unk14 = 0;
                gCameraRig->y = 500.0f;
                gCameraRig->cb9C = updateCameraView;
                gCameraRig->z = -6.0f;
                found = findActor(0x134, 0);
                if (found != NULL) {
                    gCameraTarget->x = found->x;
                    gCameraTarget->y = found->y;
                    gCameraTarget->z = found->z;
                }
                if (obj->unk84 == 3) {
                    obj->unk84 = 4;
                    obj->state++;
                } else {
                    o = func_80017DEC(randomRange(5, 8));
                    if (o == NULL) {
                        o = &tmp;
                        o->x = -1911.0f;
                        o->y = 3.0f;
                        o->z = obj->unk84 * 200 - 0x260;
                    }
                    func_8005B060(o);
                    obj->unk84++;
                }
            }
        }
        if (found != NULL) {
            if (obj->unk74 != 0) {
                found->rot = approachAngle(func_8002D260(((obj->unk88 - 2) & 7) << 13), found->rot, gCamSpeedScale << 10);
                obj->unk74 = 0;
            }
        }
        found = findActor(0x134, 0);
        if (found != NULL) {
            dx = gCameraTarget->x - found->x;
            dz = gCameraTarget->z - found->z;
            dist = sqrtf(dx * dx + dz * dz);
            if (350.0f < dist) {
                gCameraTarget->x = dx * 350.0f / dist + found->x;
                gCameraTarget->z = dz * 350.0f / dist + found->z;
            }
            if (obj->unk70 == 0) {
                obj->unk8C -= gFrameScale;
            }
            if (obj->unk8C < 0) {
                obj->unk8C = 0;
            }
            if (obj->unk8C <= 0) {
                obj->state = 6;
            }
        }
        break;
    case 4:
        if (obj->child != NULL) {
            found = obj->child;
            found->destroy(found);
            obj->child = NULL;
        }
        gCameraRig->cb9C = func_800340B4;
        startStoryDialog(func_80023DBC(0xE21), &D_80000B68, obj);
        obj->state++;
        break;
    case 5:
        gCameraRig->cb9C = func_800340B4;
        obj->state = 99;
        break;
    case 6:
        func_8002A360(12, 0x80);
        func_8002A360(8, 0x54);
        obj->child->unk68 = -1;
        startStoryDialog(func_80023DBC(0xE21), &D_80000B78, obj);
        found = findActor(0x1013, 0);
        if (found != NULL) {
            found->destroy(found);
        }
        obj->unk84 = 0;
        obj->state++;
        break;
    case 7:
        if (findActor(0x801, 0) == NULL) {
            obj->state = 2;
        }
        break;
    }
}
