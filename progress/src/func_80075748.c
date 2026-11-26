#define F(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void *func_80023874(s32, void *);
void func_80075614(void *);
f32 func_8002D858(void *, s32);
s32 func_8002D5CC(void *);
s32 func_80013654(void *);
void func_80043328(void *, s32, s32);
void func_80034F50();
void func_80023078();
void func_8007569C();
extern void *D_800B3960;
extern void *D_800BD06C;

void func_80075748(void *arg0) {
    void *a;
    void *b;
    void *q;

    if (F(arg0, s32 *, 0x7C) == 0) {
        a = func_80023874(0x11E, NULL);
        b = func_80023874(0x11F, NULL);
        if (a != NULL && b != NULL) {
            func_80075614(a);
            F(arg0, s32 *, 0x7C) = 1;
        }
    }
    if (!(func_8002D858(arg0, 0) > 200.0f) && func_8002D5CC(arg0) != 0) {
        F(arg0, s32 *, 0x64) = 0;
        if (func_80023874(0x144, NULL) != NULL && func_80013654(arg0) != 0) {
            F(arg0, s32 *, 0x64) = 200;
            a = func_80023874(0x121, NULL);
            if (a != NULL) {
                f32 z;
                q = D_800B3960;
                F(q, f32 *, 4) = F(a, f32 *, 4);
                F(q, f32 *, 8) = F(a, f32 *, 8);
                z = F(a, f32 *, 0xC);
                F(q, void **, 0x9C) = func_80034F50;
                F(q, void **, 0xA8) = arg0;
                F(q, f32 *, 0xC) = z;
            }
            func_80043328(D_800BD06C, 0xF, 0x100);
            F(D_800BD06C, void **, 0x9C) = (void *)((s8 *)func_80023078 + 8);
            F(arg0, void **, 0x9C) = func_8007569C;
        }
    }
}
