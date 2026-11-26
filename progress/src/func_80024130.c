typedef struct { u8 pad[0x20]; s32 used; } Heap;
s32 func_80023D58(s32);
s32 func_80023DE0(s32);
s32 heapAlloc(s32);
void func_80025820(s32, s32);
s32 func_80025A00(s32, s32);
s32 func_80025AC4(s32);
s32 func_800424FC(s32, s32, s32, s32);
void debugPrintf(void *);
extern u8 D_80000F34[];
extern s32 gObjTriLists[];
extern s32 D_800F9878[];
extern s32 D_800FA050[];
extern Heap D_800FA828;
extern s32 D_800FB038[];

s32 func_80024130(s32 idx, s32 key, s32 arg2) {
    s32 k = key;
    s32 id;
    s32 i;
    s32 *p;
    s32 base;
    s32 size;
    s32 aligned;
    s32 end;
    s32 r;
    s32 len;
    s32 buf[8];

    if (func_80023DE0(k) != 0) {
        id = func_80023D58(k);
        for (i = 0, p = D_800FB038; i < 502; i++, p++) {
            if (*p == id) {
                return i;
            }
        }
    }
    base = heapAlloc(func_80025AC4(k) + 0xC800);
    size = func_80025A00(k, base);
    D_800FB038[idx] = func_80023D58(k);
    if (size & 0x3F) {
        aligned = (size & ~0x3F) + 0x40;
    } else {
        aligned = size;
    }
    D_800FA050[idx] = end = base + aligned;
    r = func_800424FC(arg2, idx, base, end);
    D_800F9878[idx] = 0;
    gObjTriLists[idx] = 0;
    if (r - end > 0xC800) {
        debugPrintf(D_80000F34);
    }
    len = r - base;
    func_80025820(base, len);
    D_800FA828.used += len;
    return idx;
}
