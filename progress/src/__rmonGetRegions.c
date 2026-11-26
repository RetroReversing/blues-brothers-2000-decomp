typedef struct {
    s32 length;
    u8 code;
    s8 type;
    s16 error;
    u8 rev;
    u8 method;
    s16 notused;
} KKHeader;
typedef struct {
    KKHeader header;
    s32 object;
} KKObjectRequest;
typedef struct {
    u32 vaddr;
    u32 size;
    s16 flags;
    u32 paddr;
} KKRegion;
typedef struct {
    KKHeader header;
    s32 object;
    s32 number;
    KKRegion regions[1];
} KKRegionEvent;
extern u8 D_801810D0[];
void __rmonSendReply(KKHeader *const block, u32 blockSize, u32 replyType);

s32 __rmonGetRegions(KKHeader *req) {
    KKObjectRequest *request = (KKObjectRequest *)req;
    int numRegions;
    int numBytes;
    KKRegionEvent *reply = (KKRegionEvent *)D_801810D0;

    numRegions = (req->method == 1) ? 2 : 6;
    numBytes = sizeof(KKRegionEvent) + numRegions * sizeof(KKRegion);

    reply->header.length = numBytes;
    reply->header.code = request->header.code;
    reply->header.error = 0;
    reply->object = request->object;
    reply->number = numRegions;

    reply->regions[1].vaddr = 0x04001000; reply->regions[1].size = 0x1000; reply->regions[1].flags = 7; reply->regions[1].paddr = 0x04001000;
    reply->regions[0].vaddr = 0x04000000; reply->regions[0].size = 0x1000; reply->regions[0].flags = 3; reply->regions[0].paddr = 0x04000000;

    if (numRegions > 2) {
        reply->regions[2].vaddr = 0x88200000;
        reply->regions[2].size = 0x6130;
        reply->regions[2].flags = 5;
        reply->regions[2].paddr = 0;

        reply->regions[3].vaddr = 4;
        reply->regions[3].size = 0x200000;
        reply->regions[3].flags = 3;
        reply->regions[3].paddr = 0;

        reply->regions[4].vaddr = 0x04002000;
        reply->regions[4].size = 0x800000;
        reply->regions[4].flags = 3;
        reply->regions[4].paddr = 0;

        reply->regions[5].vaddr = 0x88206130;
        reply->regions[5].size = 0x9000;
        reply->regions[5].flags = 3;
        reply->regions[5].paddr = 0;
    }

    __rmonSendReply(&reply->header, numBytes, 1);
    return 0;
}

