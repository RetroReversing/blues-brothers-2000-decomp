typedef struct {
    s16 type;
    s32 ch;
} RumbleMsg;
typedef struct {
    u8 pad[0x68];
} OSPfs;
s32 osRecvMesg(void *, void *, s32);
s32 osMotorInit(void *, OSPfs *, s32);
s32 func_800A14C0(OSPfs *);
s32 func_800A1680(OSPfs *);
void func_80025B64(void);
void func_80025BA0(void);
extern s32 D_800AE154[];
extern u8 D_80107058[];
extern OSPfs D_80107210[];
extern u8 D_801075E0[];
extern s32 D_80107620[];

void func_80025BC8(void) {
    RumbleMsg *msg;
    s32 type;
    s32 ch;

    for (;;) {
        osRecvMesg(D_801075E0, &msg, 1);
        func_80025B64();
        type = msg->type;
        ch = msg->ch;
        if (type != 0) {
            if (type == 1 && D_800AE154[ch] != 0 && func_800A1680(&D_80107210[ch]) == 0) {
                D_80107620[ch] = type;
            }
        } else if (D_800AE154[ch] != 0) {
            osMotorInit(D_80107058, &D_80107210[ch], ch);
            if (func_800A14C0(&D_80107210[ch]) == 0) {
                D_80107620[ch] = 0;
            }
        }
        func_80025BA0();
    }
}
