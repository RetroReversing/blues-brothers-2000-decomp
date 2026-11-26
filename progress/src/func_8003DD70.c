/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 cameraGetMode();                                /* extern */
s32 sendCommand(s32, s32);                /* extern */
s32 func_8003D654();                                /* extern */
extern s32 D_800AB9B4;
extern s32 D_800B5DCC;
extern s32 D_800B5DD4;
extern s32 gAudioVolume;
extern s32 gPadPressed;
extern s32 D_80140228;
extern s32 func_8003D3C8;
extern s32 updateMainMenu;
extern s32 func_8003DB40;
extern s32 func_8003DEF0;
extern s32 func_8003E0BC;

void func_8003DD70(void *arg0) {
    s32 temp_v1;
    s32 var_a0;
    s32 var_v0;
    s32 temp;
    s32 temp2;
    s32 temp3;

    var_a0 = func_8003D654();
    if ((*(const s32 *)((s8 *)arg0 + 0x88)) < 0) {
        var_a0 = 0;
        { (*(s32 *)((s8 *)arg0 + 0x88)) = 0; }
    }
    temp3 = *(const s32 *)((s8 *)arg0 + 0x88);
    if (D_800B5DCC < temp3) {
        var_a0 = 0;
        { (*(s32 *)((s8 *)arg0 + 0x88)) = (s32) D_800B5DCC; }
    }
    if (var_a0 != 0) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x90);
    }
    temp2 = gPadPressed & 0x8000;
    temp = temp2;
    if (temp) {
        temp_v1 = (*(const s32 *)((s8 *)arg0 + 0x88));
        if (temp_v1 >= 0) {
            if (temp_v1 >= 2)
            {
              if (temp_v1 == 2)
              {
                if (cameraGetMode() == 0x3B) {
                  s32 var_v0_1;
                    { (*(s32 **)((s8 *)arg0 + 0x9C)) = &func_8003DB40; }
                    { (*(s32 **)((s8 *)arg0 + 0x98)) = &func_8003E0BC; }
                    var_v0_1 = 3;
                  D_800B5DCC = var_v0_1;
                } else {
                  s32 var_v0_2;
                    { (*(s32 **)((s8 *)arg0 + 0x9C)) = &updateMainMenu; }
                    { (*(s32 **)((s8 *)arg0 + 0x98)) = &func_8003DEF0; }
                    var_v0_2 = 4;
                  D_800B5DCC = var_v0_2;
                }
                
                { (*(s32 *)((s8 *)arg0 + 0x88)) = 0; }
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x9C);
            }
            }
        }
    }
    if (gPadPressed & 0x4000) {
        { (*(s32 **)((s8 *)arg0 + 0x9C)) = &func_8003D3C8; }
        D_800AB9B4 = 0;
        D_800B5DD4 = 1;
        D_80140228 = (*(const s32 *)((s8 *)arg0 + 0x74));
        { sendCommand(0, gAudioVolume * 0x147); }
    }
}
