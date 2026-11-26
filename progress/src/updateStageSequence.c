s32 func_8000C4A0(void);
s32 func_8000C594(void);
void initLevel(void);
void func_8000CDF0(void);
void setupStage(void);
void func_8000D394(void);
void func_80023C10(s32);
s32 func_80023D58(s32);
void sendCommand(s32, s32);
s32 tickActorTimer(void *);
void func_8002E7B8(s32, s32);
void func_80030C40(void *, s32);
void func_80030C6C(void *, void *);
void func_80088ED0(void);
void func_80088F40(void);
void func_8001DCAC(void *);
void func_80023078(void *);
void func_8003130C(void *);
void func_80032BF0(void *);

typedef struct Obj {
    char pad0[0x60];
    s32 x60;
    s32 x64;
    char pad68[0x7C - 0x68];
    s32 x7C;
    s32 x80;
    s32 x84;
    s32 x88;
    s32 x8C;
    s32 x90;
    char pad94[0x98 - 0x94];
    void *x98;
    char pad9C[0xC0 - 0x9C];
    s32 xC0;
} Obj;

extern s32 D_800AB408;
extern s32 D_800B3968;
extern s32 D_800B4A00[];
extern s32 D_800B5DD4;

/* Per-frame stage-entry controller: a small state machine that loads the stage, then steps through its list of entries, loading each one before the next, and finally starts the level. */ void updateStageSequence(Obj *seq) {
    s32 count;

    if (seq->x7C != 0) {
        setupStage();
        seq->x98 = (u8 *)func_80023078 + 8;
        seq->x7C = 0;
        seq->x90 = 0;
        seq->x64 = 3000;
        seq->x8C = 0;
        seq->xC0 = 0;
        seq->x60 = 0;
        func_8002E7B8(0, 0);
        D_800B5DD4 = 1;
    }
    if (seq->xC0 == 0) {
        if (seq->x90 == 2) {
            D_800AB408 = 0;
            D_800B5DD4 = 0;
            seq->x90 = 0;
            sendCommand(4, 0);
            sendCommand(0x1F, 0);
            sendCommand(2, 0);
            func_8000CDF0();
            func_8000D394();
            func_80030C6C(seq, func_8003130C);
            func_80088ED0();
            return;
        }
        if (seq->x90 == 1) {
            sendCommand(4, 0);
            sendCommand(0x1F, 0);
            sendCommand(2, 0);
            D_800B5DD4 = 0;
            seq->x90 = 0;
            seq->x64 = 0;
            seq->xC0 = 1;
        }
        if (seq->x88 != 0 && tickActorTimer(seq) != 0) {
            seq->xC0 = 1;
        }
    }
    switch (seq->xC0) {
    case 1:
        if (tickActorTimer(seq) != 0) {
            if (seq->x88 != 0) {
                count = func_8000C4A0();
            } else {
                count = func_8000C594();
            }
            if (count >= 4) {
                func_8000CDF0();
                func_8000D394();
                func_80030C40(seq, 1);
                return;
            }
            seq->x84 = count * 3;
            seq->x80 = 0;
            sendCommand(4, 0);
            sendCommand(0x1F, 0);
            sendCommand(2, 0);
            func_8000CDF0();
            func_80088F40();
            seq->x64 = 300;
            if (D_800B3968 == 0) {
                seq->x60 = func_80023D58(D_800B4A00[seq->x84 + seq->x80]);
                seq->x98 = func_80032BF0;
                seq->xC0++;
            } else {
                seq->x80 = 6;
                seq->x98 = func_8001DCAC;
                seq->xC0++;
            }
        }
        break;
    case 2:
        if (tickActorTimer(seq) != 0) {
            if (++seq->x80 >= 3) {
                func_80023C10(seq->x60);
                initLevel();
                func_80088F40();
                seq->x64 = 500;
                seq->xC0 = 0;
                seq->x98 = (u8 *)func_80023078 + 8;
                return;
            }
            func_80023C10(seq->x60);
            seq->x60 = func_80023D58(D_800B4A00[seq->x84 + seq->x80]);
            seq->x64 = 300;
        }
        break;
    }
}
