s32 func_800261A0(s32);
s32 func_800266B8(char *, void *, s32);
void func_80026C04(void *, s32, s32);
void func_80033B00(void *);
extern char D_8000128C[];
extern s32 D_800B49A0;
extern char gSaveBuffer[];
extern char gSaveSlots[];

typedef struct {
    u8 data[0x21C];
} SaveBlock;

char *func_80032830(void) {
    D_800B49A0 = 0;
    func_80026C04(gSaveBuffer, 0, 0x400);
    if (func_800261A0(0) != 0) {
        if (func_800266B8(D_8000128C, gSaveBuffer, 0x300) != 0) {
            func_80033B00(gSaveBuffer);
            D_800B49A0 = 1;
        }
        *(SaveBlock *)gSaveSlots = *(SaveBlock *)gSaveBuffer;
    }
    return gSaveBuffer;
}
