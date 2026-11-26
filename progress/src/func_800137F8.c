typedef struct Obj { u8 p0[0xD0]; s32 fD0; u8 p1[8]; f32 fDC; } Obj;
extern Obj *gCameraTarget;
s32 func_800137F8(void) {
    s32 r; Obj *o = gCameraTarget; if (o->fD0 != 0x1E) { return 0; } r = 0; if (!(o->fDC < 18.0f)) r = 1; return r;
}
