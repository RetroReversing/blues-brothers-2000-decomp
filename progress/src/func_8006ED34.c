s32 tickActorTimer(void *);
s32 func_8006DAE8(s32);
s32 approachS32(s32, s32, s32);
void func_8002A360(s32, s32);
void func_80023C10(s32);
void func_8006DDD4(void *);
extern void *D_800B3960;
extern void *D_800B3964;
extern s32 D_800B82C0[];
extern s32 D_800B82CC[];
extern s32 D_8014ADE0[];
extern char func_80023078[];
void func_80023848();
void func_8006CEF8();
void func_8006FD58();
void func_800768E8();

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

void func_8006ED34(void *arg0) {
    s32 var_s1;
    s32 i;

    var_s1 = 0;
    if (F(arg0, s32, 0x7C) == 0) {
        F(D_800B3960, s32, 0x74) = 2;
        F(arg0, s32, 0x84) = 1;
        F(arg0, void *, 0x98) = func_8006CEF8;
        F(arg0, s32, 0x7C) += 1;
    }
    if (F(arg0, s32, 0x80) == 2) {
        if (tickActorTimer(arg0) != 0) {
            var_s1 = func_8006DAE8(D_800B82C0[F(arg0, s32, 0x84)]);
        }
    }
    if (var_s1 & 1) {
        F(arg0, s32, 0x64) = 0x64;
        F(arg0, s32, 0x84) -= 1;
    }
    if (var_s1 & 2) {
        F(arg0, s32, 0x64) = 0x64;
        F(arg0, s32, 0x84) += 1;
    }
    if (var_s1 & 0x40) {
        F(arg0, s32, 0x64) = 0x64;
        F(arg0, s32, 0x84) -= 1;
    }
    if (var_s1 & 0x80) {
        F(arg0, s32, 0x64) = 0x64;
        F(arg0, s32, 0x84) += 1;
    }
    if (F(arg0, s32, 0x84) >= 2) {
        F(arg0, s32, 0x84) = 2;
    }
    if (F(arg0, s32, 0x84) < 0) {
        F(arg0, s32, 0x84) = 0;
    }
    if (F(arg0, s32, 0x84) != F(arg0, s32, 0x74)) {
        F(arg0, s32, 0x74) = F(arg0, s32, 0x84);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xA0);
    }
    {
        void *q = D_800B3964;
        void *p = D_800B3960;
        F(q, s32, 0x84) = F(arg0, s32, 0x84);
        F(D_800B3960, s32, 0x8C) = approachS32(D_800B82CC[F(arg0, s32, 0x84)], F(p, s32, 0x8C), 0x200);
    }
    if (F(arg0, s32, 0x8C) != 0) {
        F(arg0, s32, 0x90) = 0x1001;
        func_8006DDD4(arg0);
        F(D_800B3960, void *, 0x9C) = func_8006FD58;
        F(arg0, s32, 0x64) = 0x64;
        F(arg0, void *, 0x9C) = func_800768E8;
        F(arg0, void *, 0xD8) = func_80023848;
        F(arg0, void *, 0x98) = func_80023078 + 8;
        for (i = 0; i < 5; i++) {
            func_80023C10(D_8014ADE0[i + 4]);
            D_8014ADE0[i + 4] = 0;
        }
    }
}
