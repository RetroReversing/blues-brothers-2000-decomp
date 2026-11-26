/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 heapAlloc(M2C_UNK);                         /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800477F0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80047824(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80047864(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80047898();                                /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern s32 D_800B7B0C;
extern M2C_UNK D_800B86C0;
extern M2C_UNK D_800B86CC;
extern M2C_UNK D_8014AA40;
extern M2C_UNK func_80065D2C;
extern M2C_UNK func_8007DEA0;
extern M2C_UNK func_8007ECB0;
extern M2C_UNK func_8007EF74;
extern M2C_UNK func_8007EFD0;

/* Spawns a main actor (type 0x2A) and a linked sub-actor (type 0x77), sets their anim, flags and shared setup, and returns the main actor. */ void *spawnActorPairWithLinks(s32 ownerId) {
    s32 subSetup;
    s32 unusedV0;
    s32 unusedV1;
    void *mainActor;
    void *subActor;

    func_80050460(&func_8007DEA0, &D_8014AA40);
    mainActor = func_80042F00(0x2A, 0, 0, 0);
    actorSetAnim(mainActor, 0x1A7, 0x100);
    func_800852CC(mainActor, ownerId);
    M2C_FIELD(mainActor, s32 *, 0x74) = 0x1A7;
    M2C_FIELD(mainActor, s32 *, 0) = 0x102D;
    M2C_FIELD(mainActor, M2C_UNK **, 0x9C) = &func_8007ECB0;
    subSetup = func_80047898();
    M2C_FIELD(mainActor, s32 *, 0xE8) = subSetup;
    func_80047864(subSetup, 0, 0, -0x78, 0);
    func_80047864(subSetup, 0, 0, -0x78, 0);
    func_80047824(subSetup, 0, 8, 0x28, 0x24);
    func_80047824(subSetup, 0, 8, 0x28, 0x24);
    func_800477F0(subSetup, 0x4B, 0x4B, 0x52);
    func_800477F0(subSetup, 0x4B, 0x4B, 0x52);
    M2C_FIELD(&D_800B86C0, s32 *, 0) = 0x2C;
    M2C_FIELD(&D_800B86C0, s32 *, 4) = 0xD1;
    M2C_FIELD(&D_800B86C0, s32 *, 8) = 0xBD;
    M2C_FIELD(&D_800B86CC, s32 *, 0) = 4;
    M2C_FIELD(&D_800B86CC, s32 *, 4) = 0x14;
    M2C_FIELD(&D_800B86CC, s32 *, 8) = 0x12;
    M2C_FIELD(mainActor, s32 *, 0x8C) = heapAlloc(0x80);
    M2C_FIELD(mainActor, M2C_UNK **, 0x98) = &func_8007EF74;
    M2C_FIELD(mainActor, M2C_UNK **, 0xA0) = &func_80065D2C;
    M2C_FIELD(mainActor, s32 *, 0x58) = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    M2C_FIELD(mainActor, s32 *, 0xFC) = 5;
    M2C_FIELD(mainActor, s32 *, 0x34) = (M2C_FIELD(mainActor, s32 *, 0x34) * 2) / 3;
    M2C_FIELD(mainActor, s32 *, 0x38) = M2C_FIELD(mainActor, s32 *, 0x34);
    M2C_FIELD(mainActor, s32 *, 0x3C) = M2C_FIELD(mainActor, s32 *, 0x34);
    subActor = func_80042F00(0x77, 0, 0, 0);
    M2C_FIELD(subActor, s32 *, 0) = 0x102E;
    M2C_FIELD(mainActor, void **, 0xA8) = subActor;
    M2C_FIELD(subActor, void **, 0xA4) = mainActor;
    actorSetAnim(subActor, 0x1AE, 0x100);
    func_800852CC(subActor, ownerId);
    M2C_FIELD(subActor, s32 *, 0x58) = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    M2C_FIELD(subActor, s32 *, 0x34) = (s32) M2C_FIELD(mainActor, s32 *, 0x34);
    M2C_FIELD(subActor, s32 *, 0x38) = (s32) M2C_FIELD(mainActor, s32 *, 0x34);
    M2C_FIELD(subActor, s32 *, 0x3C) = (s32) M2C_FIELD(mainActor, s32 *, 0x34);
    subSetup = func_80047898();
    M2C_FIELD(subActor, s32 *, 0xE8) = subSetup;
    func_80047864(subSetup, 0, 0x14, 0, -0x78);
    func_80047864(subSetup, 0, 0x14, 0, -0x78);
    func_80047824(subSetup, 0, 0x23, 0x23, 0x23);
    func_80047824(subSetup, 0, 0x23, 0x23, 0x23);
    func_800477F0(subSetup, 0x30, 0x30, 0x30);
    func_800477F0(subSetup, 0x30, 0x30, 0x30);
    M2C_FIELD(subActor, M2C_UNK **, 0x9C) = &func_8007EFD0;
    M2C_FIELD(subActor, s32 *, 0x74) = 0x1AE;
    return mainActor;
}

