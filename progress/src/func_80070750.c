void osCreateMesgQueue(void *, void *, s32);
s32 osRecvMesg(void *, void *, s32);
void osViSetYScale(f32);
void func_80070EE0(s32, void *, void *);
s32 func_80070E50(s32);
extern u32 D_800B833C;
extern u32 D_800B8340;
extern u8 D_8014AE10[];
extern u8 D_8014AE20[];
extern s32 D_8014AE40;
extern u8 D_8016AEC8[];

void func_80070750(s32 arg0) {
    s16 *msg = NULL;
    u8 n = 0;
    D_800B8340 = 0;
    osCreateMesgQueue(D_8016AEC8, D_8014AE20, 8);
    func_80070EE0(arg0, D_8014AE10, D_8016AEC8);
    D_8014AE40 = func_80070E50(arg0);
    for (;;) {
        osRecvMesg(D_8016AEC8, &msg, 1);

        switch (*msg) {
        case 1:
            if (D_800B833C == 10) {
                n = (n + 1) & 7;
            } else if (D_800B833C < 11) {
                switch (D_800B833C) {
                case 0:
                    if (D_800B8340 < 2) {
                        D_800B8340++;
                    }
                    break;
                case 1:
                    if (D_800B8340 == 0) {
                        D_800B8340 = D_800B833C;
                    }
                    break;
                }
            }
            break;
        case 2:
            D_800B8340--;

            break;
        case 3:
            osViSetYScale(1.0f);
            D_800B8340 += 2;

            break;
        }
    }
}
