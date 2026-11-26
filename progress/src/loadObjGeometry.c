s32 func_80023D58(s32);
s32 func_80023DE0(s32);
u8 *heapAlloc(s32);
void func_80025820(u8 *, s32);
s32 func_80025A00(s32, u8 *);
s32 func_80025AC4(s32);
void func_80026B80(s32, s32, s32);
s32 func_800424FC(s32, s32, u8 *, u8 *);
void func_80048D08(u8 *, s32, s32);
void debugPrintf(void *, ...);
extern s8 D_80000F34[];
extern s32 gObjTriLists[];
extern s32 gObjTriCounts[];
extern s32 D_800F9878[];
extern s32 D_800FA050[];
typedef struct {
    u8 pad0[0x20];
    s32 unk20;
    u8 pad24[4];
    s32 unk28;
} Unk800FA828;
extern Unk800FA828 D_800FA828;
extern s32 D_800FB038[];
typedef struct { u8 pad0[0x20]; s32 unk20; } Hdr;

/* Loads object geometry for the given handle into cache slot `slot`, reusing an existing slot if the handle is already resident. Returns the slot index. */
s32 loadObjGeometry(s32 slot, s32 handleIn, s32 flags) {
    s32 handle;
    s32 i;
    s32 key;
    s32 n;
    s32 n3;
    u8 *buf;
    s32 size;
    s32 end;
    s32 first;
    char sp10[32];
    s32 excess;
    s32 *p9878;
    s32 *p80E8;
    s32 *pA050;
    s32 count;
    s32 total;
    s32 x;
    s32 aligned;
    s32 used;
    handle = handleIn;

    if (func_80023DE0(handle) != 0) {
        key = func_80023D58(handle);
        for (i = 0; i < 0x1F6; i++) {
            if (D_800FB038[i] == key) {
                return i;
            }
        }
    }
    n3 = func_80025AC4(handle);
    size = n3;
    n3 *= 3;
    buf = heapAlloc(size + n3);
    size = func_80025A00(handle, buf);
    D_800FB038[slot] = func_80023D58(handle);
    size = (size & 0x3F) ? (size & ~0x3F) + 0x40 : size;
    *(s32 *)((slot << 2) + (u8 *)D_800FA050) = (s32)(buf + size);
    end = func_800424FC(flags, slot, buf, buf + size);
    x = ((Hdr *)buf)->unk20;
    if (x & 0x3F) {
        first = (x & ~0x3F) + 0x40;
    } else {
        first = x;
    }
    excess = D_800FA050[slot] - first;
    end = (end & 3) ? (end & ~3) + 4 : end;
    p9878 = &D_800F9878[slot];
    *p9878 = end;
    end += gObjTriCounts[slot] * 4;
    p80E8 = &gObjTriLists[slot];
    *p80E8 = end;
    count = gObjTriCounts[slot];
    total = D_800FA828.unk28;
    total += count * 12;
    D_800FA828.unk28 = total;
    count *= 8;
    end += count;
    func_80048D08(buf, *p9878, *p80E8);
    if (n3 < end - (s32)(buf + size)) {
        debugPrintf(D_80000F34);
    }
    if (excess > 0) {
        pA050 = &D_800FA050[slot];
        func_80026B80(first, *pA050, end - *pA050);
        *pA050 -= excess;
        *p9878 -= excess;
        end -= excess;
        *p80E8 -= excess;
    }
    aligned = (end & 0xF) ? (end & ~0xF) + 0x10 : end;
    used = aligned - ((s32)buf);
    func_80025820(buf, used);
    D_800FA828.unk20 += used;
    return slot;
}
