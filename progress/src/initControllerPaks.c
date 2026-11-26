typedef struct { u8 data[0x68]; } OSPfs;
typedef struct { u8 data[0x18]; } OSMesgQueue;
s32 osPfsInitPak(OSMesgQueue *, OSPfs *, s32);
s32 osMotorInit(OSMesgQueue *, OSPfs *, s32);
void func_80025D00(s32);
extern s32 D_800AE154[4];
extern s32 D_800AE164[4];
extern s32 gPakInitWarn;
extern s32 gPakInitError;
extern u8 D_80107050;
extern OSMesgQueue D_80107058;
extern OSPfs D_80107210[4];
extern s32 D_80107620[4];

s32 initControllerPaks(void) {
    s32 ret = 0;
    s32 i;
    s32 err;

    for (i = 0; i < 4; i++) {
        D_800AE154[i] = 0;
        D_80107620[i] = 0;
        D_800AE164[i] = 0;
        if ((D_80107050 >> i) & 1) {
            err = osPfsInitPak(&D_80107058, &D_80107210[i], i);
            if (err == 10 || err == 11) {
                if (i == 0) {
                    if (err == 10) {
                        gPakInitWarn = 1;
                        ret = 3;
                    } else {
                        gPakInitWarn = 0;
                    }
                }
                D_80107050 &= ~(1 << i);
                if (osMotorInit(&D_80107058, &D_80107210[i], i) == 0) {
                    func_80025D00(i);
                    D_800AE154[i] = 1;
                    if (i == 0) {
                        ret = 2;
                        gPakInitWarn = 0;
                    }
                }
            } else if (i == 0) {
                ret = 1;
                gPakInitError = 1;
            }
        }
    }
    return ret;
}
