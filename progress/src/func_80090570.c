typedef struct OSMesgQueue OSMesgQueue;
typedef struct OSPiHandle OSPiHandle;
typedef struct {
    u16 type;
    u8 pri;
    u8 status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct {
    OSIoMesgHdr hdr;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    OSPiHandle *piHandle;
} OSIoMesg;
s32 osEPiStartDma(OSPiHandle *, OSIoMesg *, s32);

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    s32 state;
    u32 addr;
    void *buf;
} Node;

extern u32 D_8017B254;
extern Node *D_8017B290;
extern Node *D_8017B294;
extern OSIoMesg *D_8017B29C;
extern u32 D_8017B2A4;
extern s32 D_8017B2A8;
extern OSMesgQueue D_8017B2B0;
extern OSPiHandle *D_8017B2C8;
extern OSPiHandle *D_8017B2CC;

Node *func_80090570(u32 addr, s32 len) {
    OSPiHandle *h;
    Node *n;
    Node *prev;
    Node *e;
    OSIoMesg *mb;
    u32 end;

    if ((addr & 0xFF000000) == 0xFF000000) {
        h = D_8017B2CC;
        addr &= 0xFFFFFF;
        addr += 0x140000;
    } else {
        if (D_8017B254 & 1) {
            return 0;
        }
        h = D_8017B2C8;
    }
    end = addr + len;
    prev = 0;
    for (n = D_8017B290; n != 0; n = n->next) {
        if (addr < n->addr) {
            break;
        }
        if (n->addr + D_8017B2A4 >= end) {
            return n;
        }
        prev = n;
    }
    e = D_8017B294;
    if (e == 0) {
        return D_8017B290;
    }
    D_8017B294 = e->next;
    if (prev != 0) {
        e->next = prev->next;
        if (e->next != 0) {
            e->next->prev = e;
        }
        e->prev = prev;
        prev->next = e;
    } else {
        e->prev = 0;
        e->next = D_8017B290;
        if (D_8017B290 != 0) {
            D_8017B290->prev = e;
        }
        D_8017B290 = e;
    }
    e->addr = addr & ~1;
    e->state = 2;
    mb = &D_8017B29C[D_8017B2A8++];
    mb->hdr.pri = 0;
    mb->hdr.retQueue = &D_8017B2B0;
    mb->dramAddr = e->buf;
    mb->devAddr = e->addr;
    mb->size = D_8017B2A4;
    osEPiStartDma(h, mb, 0);
    return e;
}
