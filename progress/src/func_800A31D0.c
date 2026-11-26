typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    u32 transferInfo[24];
} OSPiHandle;

extern OSPiHandle *D_800BC440[];

#define IO_READ(addr) (*(volatile u32 *)((addr) | 0xA0000000))
#define IO_WRITE(addr, data) (*(volatile u32 *)((addr) | 0xA0000000) = (u32)(data))
#define PI_STATUS_REG 0x04600010
#define PI_BSD_DOM1_LAT_REG 0x04600014
#define PI_BSD_DOM1_PWD_REG 0x04600018
#define PI_BSD_DOM1_PGS_REG 0x0460001C
#define PI_BSD_DOM1_RLS_REG 0x04600020
#define PI_BSD_DOM2_LAT_REG 0x04600024
#define PI_BSD_DOM2_PWD_REG 0x04600028
#define PI_BSD_DOM2_PGS_REG 0x0460002C
#define PI_BSD_DOM2_RLS_REG 0x04600030
#define PI_STATUS_IO_BUSY 0x2
#define PI_STATUS_DMA_BUSY 0x1
#define PI_DOMAIN1 0

s32 func_800A31D0(OSPiHandle *pihandle, u32 devAddr, u32 *data) {
    register u32 stat;
    register u32 domain;

    stat = IO_READ(PI_STATUS_REG);
    while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {
        stat = IO_READ(PI_STATUS_REG);
    }
    domain = pihandle->domain;
    if (D_800BC440[domain] != pihandle) {
        OSPiHandle *cHandle = D_800BC440[domain];
        if (domain == PI_DOMAIN1) {
            if (cHandle->latency != pihandle->latency) {
                IO_WRITE(PI_BSD_DOM1_LAT_REG, pihandle->latency);
            }
            if (cHandle->pageSize != pihandle->pageSize) {
                IO_WRITE(PI_BSD_DOM1_PGS_REG, pihandle->pageSize);
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                IO_WRITE(PI_BSD_DOM1_RLS_REG, pihandle->relDuration);
            }
            if (cHandle->pulse != pihandle->pulse) {
                IO_WRITE(PI_BSD_DOM1_PWD_REG, pihandle->pulse);
            }
        } else {
            if (cHandle->latency != pihandle->latency) {
                IO_WRITE(PI_BSD_DOM2_LAT_REG, pihandle->latency);
            }
            if (cHandle->pageSize != pihandle->pageSize) {
                IO_WRITE(PI_BSD_DOM2_PGS_REG, pihandle->pageSize);
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                IO_WRITE(PI_BSD_DOM2_RLS_REG, pihandle->relDuration);
            }
            if (cHandle->pulse != pihandle->pulse) {
                IO_WRITE(PI_BSD_DOM2_PWD_REG, pihandle->pulse);
            }
        }
        D_800BC440[domain] = pihandle;
    }
    *data = IO_READ(pihandle->baseAddress | devAddr);
    return 0;
}
