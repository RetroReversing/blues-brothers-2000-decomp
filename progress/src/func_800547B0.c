s32 func_8001B990(s32, s32);
s32 func_80023DBC(s32);
f32 func_8002D66C(void *, f32, void *);
void func_80052A5C(s32);
s32 func_80052A68(s32, char *);
void func_80052B24(s32, char *, void *);
void func_80058F74(void *, void *);
void func_800548C0(void *);

typedef struct Obj800547B0 {
    char pad0[8];
    f32 unk8;
    char padC[4];
    char unk10[0x58];
    s32 unk68;
    char pad6C[0x34];
    void (*unkA0)(struct Obj800547B0 *);
    char padA4[0x1C];
    s32 unkC0;
} Obj800547B0;

void func_800547B0(Obj800547B0 *arg0) {
    f32 dist;
    s32 id;

    if (func_8001B990(0x100, 0x42) != 0) {
        arg0->unkA0(arg0);
        return;
    }
    dist = func_8002D66C(arg0, 750.0f, arg0->unk10);
    id = func_80023DBC(0xEA5);
    arg0->unk68 = -1;
    if (dist < 750.0f) {
        func_80052A5C(0);
        if (func_80052A68(id, "tomb") == 0) {
            func_80052B24(id, "tomb", arg0);
            func_8001B990(0x200, 0x11);
        }
    }
    if (arg0->unkC0 != 0) {
        arg0->unk68 = 0xD;
        func_80058F74(arg0, func_800548C0);
        arg0->unk8 += 200.0f;
    }
}
