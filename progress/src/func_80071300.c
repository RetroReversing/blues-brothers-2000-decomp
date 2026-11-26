typedef struct Pos { u8 p0[4]; f32 x; f32 y; f32 z; } Pos;
typedef struct Cam { u8 p0[0xB8]; s32 fB8; u8 p1[0x28]; s32 fE4; } Cam;
typedef struct Obj Obj;
typedef void (*Fn)(Obj *);
struct Obj { u8 p0[0xA0]; Fn fA0; };
extern s16 coss(s32);
extern Pos *func_80017344(Cam *);
extern s32 func_80023E3C(s32);
extern s32 func_8002D1A0();
extern void func_8002D3E4(Pos *, s32);
extern s32 func_8002D5CC();
extern s16 sins(s32);
extern s32 D_800B8370;
extern Cam *D_800BD06C;

void func_80071300(Obj *arg0) {
    s32 var_s2;
    s32 temp_s0;
    Pos *temp_v0;

    if (func_8002D5CC(arg0) != 0) {
        if (D_800BD06C != NULL) {
            var_s2 = 0;
            D_800BD06C->fB8 = D_800B8370;
            D_800BD06C->fE4 = func_80023E3C(D_800B8370);
            do {
                var_s2 += 1;
                temp_s0 = func_8002D1A0();
                temp_v0 = func_80017344(D_800BD06C);
                temp_s0 = temp_s0 & 0xFFFF;
                temp_v0->y = temp_v0->y + 150.0f;
                temp_v0->x = temp_v0->x + (f32) ((s32) (sins(temp_s0) * 0x19) >> 0xD);
                temp_v0->z = temp_v0->z + (f32) ((s32) (coss(temp_s0) * 0x19) >> 0xD);
                func_8002D3E4(temp_v0, 0x190);
            } while (var_s2 < 8);
        }
        arg0->fA0(arg0);
    }
}
