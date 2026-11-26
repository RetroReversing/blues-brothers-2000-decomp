typedef struct {
    u32 cmd;
    s32 arg;
} AudioMsg;

typedef struct {
    u8 pad0[0x64];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    u8 pad74[0x80 - 0x74];
    s32 handle;
    s32 volume;
    s32 pitch;
    s32 pan;
    s32 vol2;
    s32 id;
} SfxObj;

extern char D_80001130[];
extern s32 D_801078A0;
extern s32 D_801078A4;
extern s32 D_801078A8;
extern s32 D_801078B0;
extern s32 D_801078B4;
extern s32 D_801078B8;
extern u8 D_801078C0[];
extern s32 D_801183E0;
extern u8 D_801183F8[];
extern u8 D_8011CAB0[];
extern u8 D_8013EA28[];
extern s32 D_800B2B60[];
extern s32 D_800B2ED0[];
extern s32 D_800B3818;
extern s32 D_800B381C;
extern s32 D_800B3820;
extern s32 D_800B3824;
extern s32 D_800B3828;
extern s32 D_800B382C;
extern s32 D_800B3830;
extern s32 D_800B3834;

s32 func_8002B514(void);
void func_8002B618(void);
void func_800899C4(char *, s32);
s32 osRecvMesg(void *, void *, s32);
void MusSetMasterVolume(s32, s32);
void func_8008D618(s32, s32);
void func_8002B4D8(s32, void *);
s32 func_8008D098(void *);
void func_8008D874(s32, s32);
void func_8008DC04(void *);
s32 func_8008D320(s32);
s32 func_8008D3A8(s32, s32, s32, s32, s32);
void func_8008D904(s32, s32);
s32 cameraGetMode(void);
s32 func_8008D6D0(s32);
void func_8008D72C(s32, s32);
void func_8008D790(s32, s32);
s32 tickActorTimer(SfxObj *);
s32 randomRange(s32, s32);
void func_8008D804(s32, f32);
void func_8008DD34(s32);
void func_8008D9D0(void *);
void func_8002ABB8(void);

void func_8002A3C8(void) {
    AudioMsg *msg;
    s32 arg;
    SfxObj *sfx;
    s32 h;
    s32 id;

    id = func_8002B514();
    func_8002B618();
    func_800899C4(D_80001130, id);
    D_801078A4 = -1;
    D_801183E0 = 0;
    D_801078A0 = 0;
    D_801078A8 = 0x80;
    for (;;) {
        osRecvMesg(D_8013EA28, &msg, 1);
        arg = msg->arg;
        switch (msg->cmd) {
        case 0:
            MusSetMasterVolume(2, arg);
            break;
        case 1:
            MusSetMasterVolume(1, arg);
            break;
        case 2:
            MusSetMasterVolume(3, arg);
            break;
        case 3:
            if (arg == D_801078A4) {
                if (D_801078A0 != 0) {
                    break;
                }
                D_801078A0 = func_8008D098(D_8011CAB0);
                func_8008D874(D_801078A0, D_801078A8);
            } else {
                if (D_801078A0 != 0) {
                    func_8008D618(D_801078A0, 0);
                    D_801078A0 = 0;
                }
                func_8002B4D8(arg, D_8011CAB0);
                D_801078A4 = arg;
                D_801078A0 = func_8008D098(D_8011CAB0);
                func_8008D874(D_801078A0, D_801078A8);
            }
            break;
        case 4:
            if (D_801078A0 != 0) {
                func_8008D618(D_801078A0, 0);
                D_801078A0 = 0;
                D_801078A4 = -1;
                D_801078A8 = 0x80;
            }
            break;
        case 5:
            if (arg < 0xDC) {
                func_8008DC04(D_801078C0);
                func_8008D320(arg);
            }
            break;
        case 6:
            if (arg < 0xDC) {
                func_8008DC04(D_801078C0);
                func_8008D904(func_8008D3A8(arg, D_801078B0, D_801078B4, 0, -1), D_800B3818);
                D_800B3818 = 0;
            }
            break;
        case 7:
            if (arg < 0xDC) {
                func_8008DC04(D_801078C0);
                h = func_8008D3A8(arg, D_801078B0, D_801078B4, 0, -1);
                func_8008D904(h, D_800B2ED0[cameraGetMode()]);
            }
            break;
        case 8:
            if (arg < 0xDC) {
                func_8008DC04(D_801078C0);
                h = func_8008D3A8(arg, D_800B2B60[arg], D_801078B4, 0, -1);
                func_8008D904(h, D_800B2ED0[cameraGetMode()]);
                if (arg == 3) {
                    D_800B3830 = h;
                }
            }
            break;
        case 9:
            func_8008DC04(D_801078C0);
            D_801078B8 = func_8008D320(arg);
            break;
        case 10:
            if (D_801078B8 != 0) {
                func_8008D618(D_801078B8, 0);
            }
            break;
        case 11:
            D_801078B0 = arg;
            break;
        case 12:
            D_801078B4 = arg;
            break;
        case 13:
            D_800B3818 = arg;
            break;
        case 14:
            D_801078A8 = arg;
            if (D_801078A0 != 0) {
                func_8008D874(D_801078A0, arg);
            }
            break;
        case 15:
            if (D_801078A0 != 0) {
                func_8008D72C(D_801078A0, arg);
            }
            break;
        case 16:
            if (D_801078A0 != 0) {
                func_8008D790(D_801078A0, arg);
            }
            break;
        case 17:
            sfx = (SfxObj *)arg;
            if (sfx->id != -1) {
                if (sfx->handle == 0) {
                    func_8008DC04(D_801078C0);
                    sfx->handle = func_8008D3A8(sfx->id, sfx->vol2, sfx->pan, 0, -1);
                } else if (func_8008D6D0(sfx->handle) != 0) {
                    func_8008D72C(sfx->handle, sfx->vol2);
                    func_8008D790(sfx->handle, sfx->pan);
                } else if (tickActorTimer(sfx) != 0) {
                    func_8008DC04(D_801078C0);
                    sfx->handle = func_8008D3A8(sfx->id, sfx->vol2, sfx->pan, 0, -1);
                    sfx->unk64 = sfx->unk70 * (randomRange(0, 0x28) + 0x50);
                }
                if (sfx->volume < D_800B2ED0[cameraGetMode()]) {
                    sfx->volume = D_800B2ED0[cameraGetMode()];
                }
                func_8008D904(sfx->handle, sfx->volume);
                func_8008D804(sfx->handle, sfx->pitch / 10);
            } else if (sfx->handle != 0) {
                func_8008D618(sfx->handle, 0);
                sfx->handle = 0;
            }
            break;
        case 18:
            sfx = (SfxObj *)arg;
            if (D_801078A0 != 0) {
                func_8008D72C(D_801078A0, sfx->vol2);
                func_8008D790(D_801078A0, sfx->pan);
                func_8008D904(D_801078A0, sfx->volume);
            }
            break;
        case 19:
            func_8008DC04(D_801078C0);
            D_800B381C = func_8008D320(0x4B);
            func_8008D904(D_800B381C, D_800B2ED0[cameraGetMode()]);
            break;
        case 20:
            if (D_800B381C != 0) {
                func_8008D618(D_800B381C, 0);
                D_800B381C = 0;
            }
            break;
        case 21:
            func_8008DC04(D_801078C0);
            h = func_8008D320(0x2F);
            func_8008D804(h, 10.0f);
            func_8008D904(h, D_800B2ED0[cameraGetMode()]);
            break;
        case 22:
            if (D_800B3834 == 0) {
                func_8008DD34(arg);
                D_800B3834 = arg;
            }
            break;
        case 23:
            if (D_800B3834 != 0) {
                func_8008DD34((s32)func_8002ABB8);
                D_800B3834 = 0;
            }
            break;
        case 24:
            func_8008DC04(D_801078C0);
            D_800B3820 = func_8008D320(0x49);
            func_8008D904(D_800B3820, D_800B2ED0[cameraGetMode()]);
            break;
        case 25:
            if (D_800B3820 != 0) {
                func_8008D618(D_800B3820, 0);
                D_800B3820 = 0;
            }
            break;
        case 26:
            func_8008DC04(D_801078C0);
            D_800B3824 = func_8008D320(0x4F);
            func_8008D904(D_800B3824, D_800B2ED0[cameraGetMode()]);
            break;
        case 27:
            if (D_800B3824 != 0) {
                func_8008D618(D_800B3824, 0);
                D_800B3824 = 0;
            }
            break;
        case 28:
            if (D_800B3828 == 0) {
                func_8002B4D8(arg + 0xB, D_8011CAB0);
                func_8008D9D0(D_801183F8);
                D_800B3828 = func_8008D098(D_8011CAB0);
            }
            break;
        case 29:
            if (D_800B3828 != 0) {
                func_8008D618(D_800B3828, 0);
                D_800B3828 = 0;
            }
            break;
        case 30:
            if (D_800B382C == 0) {
                func_8002B4D8(0xD, D_8011CAB0);
                func_8008D9D0(D_801183F8);
                D_800B382C = func_8008D098(D_8011CAB0);
            }
            break;
        case 31:
            if (D_800B382C != 0) {
                func_8008D618(D_800B382C, 0);
                D_800B382C = 0;
            }
            break;
        case 32:
            if (D_800B3830 != 0) {
                func_8008D618(D_800B3830, 0);
                D_800B3830 = 0;
            }
            break;
        }
    }
}


