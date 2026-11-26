typedef struct Obj {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s32 f80;
    /* 0x84 */ u8 pad84[0x38];
    /* 0xBC */ s32 fBC;
} Obj;
typedef struct { s32 id; s32 flags; s32 c; } Rec;
s32 func_80023D58(s32);
s32 getImageAsset(s32);
void setTextColor(s32, s32, s32, s32);
void drawImage(s32, s32, s32, s32);
void func_8006D8E0(s32 *);
s32 func_8006DAA0(s32);
extern Obj *D_800B3964;
extern s32 D_800B81E0[];
extern Rec D_800B81F4[];
extern s32 D_8014ADE0[];

s32 func_8006F0C0(Obj *arg0) {
    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    if (arg0->fBC == 0) {
        drawImage(getImageAsset(D_800B81F4[0].id), 0x1E, 0x14, 0);
    } else if (D_800B81F4[1].id != 0) {
        drawImage(getImageAsset(D_800B81F4[1].id), 0x30, 0x18, 0);
    } else {
        D_800B81F4[1].id = func_80023D58(D_800B81E0[D_800B3964->fBC]);
    }
    func_8006D8E0(&arg0->f80);
    setTextColor(0xFF, 0xFF, 0xFF, arg0->f80);
    if (D_800B81F4[arg0->fBC].flags & 1) {
        drawImage(getImageAsset(D_8014ADE0[2]), 0x6E, 0x82, 0);
    }
    if (D_800B81F4[arg0->fBC].flags & 2) {
        drawImage(getImageAsset(D_8014ADE0[3]), 0xAA, 0x82, 0);
    }
    if (func_8006DAA0(arg0->fBC) != 0) {
        drawImage(getImageAsset(D_8014ADE0[0]), 0x5E, 0xBE, 0);
        drawImage(getImageAsset(D_8014ADE0[1]), 0xAA, 0xBE, 0);
    }
    return 0;
}
