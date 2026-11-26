extern u8 D_8016AEC8[];
extern s32 D_800B8344;
s32 osRecvMesg(void *, void *, s32);

void func_8007089C(void) {
    s16 *msg;
    s32 done;
    s32 flag;

    done = 0;
    flag = 0;
    msg = NULL;
    do {
        osRecvMesg(D_8016AEC8, &msg, 1);
        switch (*msg) {
        case 1:
            if (flag == 1) {
                done = 1;
            }
            break;
        case 2:
            flag = 1;
            break;
        }
        if (D_800B8344 != 0) {
            done = 0;
        }
    } while (done == 0);
}
