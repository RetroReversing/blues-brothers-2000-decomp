/* identical to __osDevMgrMain in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to __osDevMgrMain in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to __osDevMgrMain in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to __osDevMgrMain in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to __osDevMgrMain in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef struct OSMesgQueue_s OSMesgQueue;
typedef void *OSMesg;
typedef s32 OSPri;
typedef s32 OSId;
typedef struct OSThread_s OSThread;
extern void     osYieldThread(void);
extern s32      osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32      osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern void     __osSetGlobalIntMask(u32);
extern void     __osResetGlobalIntMask(u32);
extern s32 func_800A3320 (struct OSPiHandle_s *, u32 , u32);
extern s32 func_800A31D0 (struct OSPiHandle_s *, u32 , u32 *);

typedef struct {
    u32      errStatus;
    void    *dramAddr;
    void    *C2Addr;
    u32      sectorSize;
    u32      C1ErrNum;
    u32      C1ErrSector[4];
} __OSBlockInfo;

typedef struct {
    u32             cmdType;
    u16             transferMode;
    u16             blockNum;
    s32             sectorNum;
    u32             devAddr;
    u32             bmCtlShadow;
    u32             seqCtlShadow;
    __OSBlockInfo   block[2];
} __OSTranxInfo;

typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8                   type;
    u8                   latency;
    u8                   pageSize;
    u8                   relDuration;
    u8                   pulse;
    u8                   domain;
    u32                  baseAddress;
    u32                  speed;
    __OSTranxInfo        transferInfo;
} OSPiHandle;

typedef struct {
    u16          type;
    u8           pri;
    u8           status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct {
    OSIoMesgHdr  hdr;
    void        *dramAddr;
    u32          devAddr;
    u32          size;
    OSPiHandle  *piHandle;
} OSIoMesg;

typedef struct {
    s32          active;
    OSThread    *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32         (*dma)(s32, u32, void *, u32);
    s32         (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;

/* Register addresses and bits used by the 64DD (LeoDisk) block-transfer path. */
#define PI_STATUS_REG_ADDR   (0x04600000 + 0x10)
#define PI_STATUS_CLR_INTR   (1 << 1)
#define LEO_STATUS_REG       (0x05000000 + 0x508)
#define LEO_BM_CTL_REG       (0x05000000 + 0x510)
#define LEO_INTR_MASK       0x00100401
#define LEO_ERR_SECTOR_SKIP  29
#define LEO_BM_CTL_RESET     0x10000000
#define LEO_BM_CTL_STOP      0x01000000
#define LEO_BM_CTL_FAST      0x80000000
#define LEO_BM_STAT_BUSY     0x02000000
#define OS_MESG_TYPE_LOOPBACK  (10 + 0)
#define OS_MESG_TYPE_DMAREAD   (10 + 1)
#define OS_MESG_TYPE_DMAWRITE  (10 + 2)
#define OS_MESG_TYPE_EDMAREAD  (10 + 5)
#define OS_MESG_TYPE_EDMAWRITE (10 + 6)

/* Device manager thread: takes PI requests off the command queue. 64DD (type 2) block
   transfers run here, with retries and the access-queue handshake; everything else goes
   through the dma/edma hooks of the device manager. Replies go to each request's queue. */
/* Device manager thread: takes PI requests off the command queue, runs 64DD block transfers with retries, and forwards DMA/EDMA requests through the device hooks. */ /* Device manager thread: services PI requests from the command queue, running 64DD block transfers with retries and DMA/EDMA requests through the device hooks. */ void __osDevMgrMain(void* threadArg) {
    OSIoMesg* ioMsg;
    OSMesg eventMsg;
    OSMesg acsMsg;
    s32 result;
    OSDevMgr* devMgr;
    s32 retryRead = 0;

    devMgr = (OSDevMgr*)threadArg;
    ioMsg = 0;
    result = 0;

    while (1) {
        osRecvMesg(devMgr->cmdQueue, (OSMesg)&ioMsg, 1);

        if (ioMsg->piHandle != 0 && ioMsg->piHandle->type == 2 &&
            (ioMsg->piHandle->transferInfo.cmdType == 0 ||
             ioMsg->piHandle->transferInfo.cmdType == 1)) {
            __OSBlockInfo* blockInfo;
            __OSTranxInfo* info;
            info = &ioMsg->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];
            info->sectorNum = -1;

            if (info->transferMode != 3) {
                blockInfo->dramAddr = (void*)((u32)blockInfo->dramAddr - blockInfo->sectorSize);
            }

            if (info->transferMode == 2 && ioMsg->piHandle->transferInfo.cmdType == 0) {
                retryRead = 1;
            } else {
                retryRead = 0;
            }

            osRecvMesg(devMgr->acsQueue, &acsMsg, 1);
            __osResetGlobalIntMask(LEO_INTR_MASK);
            func_800A3320(ioMsg->piHandle, LEO_BM_CTL_REG, (info->bmCtlShadow | LEO_BM_CTL_FAST));

        readblock1:
            osRecvMesg(devMgr->evtQueue, &eventMsg, 1);
            info = &ioMsg->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];

            if (blockInfo->errStatus == LEO_ERR_SECTOR_SKIP) {
                u32 piStat;
                func_800A3320(ioMsg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow | LEO_BM_CTL_RESET);
                func_800A3320(ioMsg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow);
                func_800A31D0(ioMsg->piHandle, LEO_STATUS_REG, &piStat);

                if (piStat & LEO_BM_STAT_BUSY) {
                    func_800A3320(ioMsg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow | LEO_BM_CTL_STOP);
                }

                blockInfo->errStatus = 4;
                (*(volatile u32 *)((u32)(PI_STATUS_REG_ADDR) | 0xA0000000) = (u32)(PI_STATUS_CLR_INTR));
                __osSetGlobalIntMask(LEO_INTR_MASK | 0x00000800);
            }

            osSendMesg(ioMsg->hdr.retQueue, ioMsg, 0);

            if (retryRead == 1 && ioMsg->piHandle->transferInfo.block[0].errStatus == 0) {
                retryRead = 0;
                goto readblock1;
            }

            osSendMesg(devMgr->acsQueue, 0, 0);
            if (ioMsg->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
        } else {
            switch (ioMsg->hdr.type) {
                case OS_MESG_TYPE_DMAREAD:
                    osRecvMesg(devMgr->acsQueue, &acsMsg, 1);
                    result = devMgr->dma(0, ioMsg->devAddr, ioMsg->dramAddr, ioMsg->size);
                    break;
                case OS_MESG_TYPE_DMAWRITE:
                    osRecvMesg(devMgr->acsQueue, &acsMsg, 1);
                    result = devMgr->dma(1, ioMsg->devAddr, ioMsg->dramAddr, ioMsg->size);
                    break;
                case OS_MESG_TYPE_EDMAREAD:
                    osRecvMesg(devMgr->acsQueue, &acsMsg, 1);
                    result = devMgr->edma(ioMsg->piHandle, 0, ioMsg->devAddr, ioMsg->dramAddr, ioMsg->size);
                    break;
                case OS_MESG_TYPE_EDMAWRITE:
                    osRecvMesg(devMgr->acsQueue, &acsMsg, 1);
                    result = devMgr->edma(ioMsg->piHandle, 1, ioMsg->devAddr, ioMsg->dramAddr, ioMsg->size);
                    break;
                case OS_MESG_TYPE_LOOPBACK:
                    osSendMesg(ioMsg->hdr.retQueue, ioMsg, 0);
                    result = -1;
                    break;
                default:
                    result = -1;
                    break;
            }

            if (result == 0) {
                osRecvMesg(devMgr->evtQueue, &eventMsg, 1);
                osSendMesg(ioMsg->hdr.retQueue, ioMsg, 0);
                osSendMesg(devMgr->acsQueue, 0, 0);
            }
        }
    }
}
