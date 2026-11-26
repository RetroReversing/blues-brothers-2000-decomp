s32 func_800A5620(void);
void func_800A5688(void);
u32 __rmonReadWordAt(u32 *addr);
void __rmonWriteWordTo(u32 *addr, u32 data);
extern u32 D_80185400;
extern u32 D_80185404;
extern u32 D_80185408[4];

typedef union {
    u32 everything;
    struct {
        int opcode : 6;
        int base : 5;
        int rt : 5;
        int offset : 16;
    } scalarop;
    struct {
        int opcode : 6;
        int base : 5;
        int rt : 5;
        int size : 5;
        int element : 4;
        int offset : 7;
    } vectorop;
} INSTRUCTION;

static inline void LoadStoreSU(int opcode, int regno) {
    INSTRUCTION inst;

    inst.everything = 0;
    inst.scalarop.opcode = opcode;
    inst.scalarop.rt = regno;
    __rmonWriteWordTo((u32 *) 0x04001000, inst.everything);
    __rmonWriteWordTo((u32 *) 0x04080000, 0);
}

static inline void SetUpForRCPop(int isVector) {
    D_80185400 = __rmonReadWordAt((u32 *) 0x04080000);
    D_80185404 = __rmonReadWordAt((u32 *) 0x04001000);
    D_80185408[0] = __rmonReadWordAt((u32 *) 0x04000000);
    if (isVector) {
        D_80185408[1] = __rmonReadWordAt((u32 *) (0x04000000 + 0x4));
        D_80185408[2] = __rmonReadWordAt((u32 *) (0x04000000 + 0x8));
        D_80185408[3] = __rmonReadWordAt((u32 *) (0x04000000 + 0xC));
    }
}

static inline void CleanupFromRCPop(int isVector) {
    __rmonWriteWordTo((u32 *) 0x04000000, D_80185408[0]);
    if (isVector) {
        __rmonWriteWordTo((u32 *) (0x04000000 + 0x4), D_80185408[1]);
        __rmonWriteWordTo((u32 *) (0x04000000 + 0x8), D_80185408[2]);
        __rmonWriteWordTo((u32 *) (0x04000000 + 0xC), D_80185408[2]);
    }
    __rmonWriteWordTo((u32 *) 0x04001000, D_80185404);
    __rmonWriteWordTo((u32 *) 0x04080000, D_80185400);
}

u32 rmonGetRcpRegister(int regNumber) {
    u32 contents;

    if (func_800A5620()) {
        return 0;
    }

    SetUpForRCPop(0);
    LoadStoreSU(43, regNumber);
    func_800A5688();
    contents = __rmonReadWordAt((u32 *) 0x04000000);
    CleanupFromRCPop(0);

    return contents;
}
