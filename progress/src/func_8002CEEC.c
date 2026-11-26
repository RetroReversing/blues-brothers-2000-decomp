typedef struct Msg2 {
    u32 type;
    s32 arg;
} Msg2;

s32 func_800979F0(void *, void *, s32);
void func_80025E10(s32);
void func_80025D00(s32);
void func_80025CC8(s32);
void func_8002621C(s32);
extern u8 D_8013FB08[];
extern s32 D_80107620[];
extern s32 D_800B38F8[2][10];
extern s32 D_800B38F0;
extern s32 D_800B38F4;
extern s32 D_800B3948;
extern s32 D_800B394C;
extern s32 D_800B3950;
extern s32 D_800B3954;
extern s32 D_800B3958;
extern s32 D_800B395C;

void func_8002CEEC(void) {
    Msg2 *msg;
    s32 arg;

    for (;;) {
        func_800979F0(D_8013FB08, &msg, 1);
        arg = msg->arg;
        switch (msg->type) {
            case 6:
                func_80025E10(0);
                break;
            case 0:
                D_800B395C++;
                if (D_800B394C != 0) {
                    if (--D_800B3950 != 0) {
                        if (D_800B3954 != 0) {
                            if (D_80107620[D_800B3958] != 0) {
                                if (D_800B3948 == 0) {
                                    func_80025D00(D_800B3958);
                                    D_800B3948 = D_800B38F0;
                                } else {
                                    D_800B3948--;
                                }
                            } else {
                                if (D_800B3948 == 0) {
                                    func_80025CC8(D_800B3958);
                                    D_800B3948 = D_800B38F4;
                                } else {
                                    D_800B3948--;
                                }
                            }
                        } else if (D_80107620[D_800B3958] == 0) {
                            func_80025CC8(D_800B3958);
                        }
                    } else {
                        D_800B394C = 0;
                        D_800B3954 = 0;
                        D_800B3950 = 0;
                        D_800B3948 = 0;
                        D_800B38F4 = 0;
                        D_800B38F0 = 0;
                        func_80025D00(D_800B3958);
                    }
                }
                break;
            case 1:
                D_800B38F0 = D_800B38F8[0][arg];
                D_800B38F4 = D_800B38F8[1][arg];
                break;
            case 2:
                D_800B3950 = arg;
                break;
            case 3:
                D_800B3954 = arg;
                break;
            case 4:
                if (D_800B395C >= 21) {
                    func_8002621C(D_800B3958);
                    D_800B395C = 0;
                }
                D_800B394C = 1;
                break;
            case 5:
                D_800B394C = 0;
                D_800B3950 = 0;
                D_800B3954 = 0;
                D_800B38F0 = 0;
                D_800B38F4 = 0;
                func_80025D00(D_800B3958);
                break;
            case 7:
                func_80025D00(D_800B3958);
                if (arg < 0) {
                    arg = 0;
                }
                if (arg >= 4) {
                    arg = 3;
                }
                D_800B3958 = arg;
                break;
        }
    }
}
