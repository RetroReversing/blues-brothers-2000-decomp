#ifndef COMMON_H
#define COMMON_H

#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#endif


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif /* COMMON_H */

#ifndef LIBULTRA_OS_THREAD_H
#define LIBULTRA_OS_THREAD_H

/* libultra OSThread layout (2.0I PR/os.h, references/libreultra), shared by
 * the kernel and game_libs copies. Opt-in header: several older TUs still
 * carry private OSThread typedefs, so do NOT add this to common.h until those
 * are migrated (duplicate typedef = cfe error). Offsets are asserted below
 * with negative-array tricks so a wrong field is a compile error, not a
 * silent byte change. */

#ifndef COMMON_H
#define COMMON_H

#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#endif


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif /* COMMON_H */


typedef s32 OSPri;
typedef s32 OSId;
typedef union { struct { f32 f_odd; f32 f_even; } f; f64 d; } __OSfp;

typedef struct {
    u64 at, v0, v1, a0, a1, a2, a3;           /* 0x00 */
    u64 t0, t1, t2, t3, t4, t5, t6, t7;       /* 0x38 */
    u64 s0, s1, s2, s3, s4, s5, s6, s7;       /* 0x78 */
    u64 t8, t9, gp, sp, s8, ra;               /* 0xB8 */
    u64 lo, hi;                               /* 0xE8 */
    u32 sr, pc, cause, badvaddr, rcp;         /* 0xF8 */
    u32 fpcsr;                                /* 0x10C */
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext; /* size 0x190 */

typedef struct OSThread_s {
    /* 0x00 */ struct OSThread_s *next;
    /* 0x04 */ OSPri priority;
    /* 0x08 */ struct OSThread_s **queue;
    /* 0x0C */ struct OSThread_s *tlnext;
    /* 0x10 */ u16 state;
    /* 0x12 */ u16 flags;
    /* 0x14 */ OSId id;
    /* 0x18 */ int fp;
    /* 0x20 */ __OSThreadContext context;
} OSThread; /* size 0x1B0 */

#define OS_STATE_STOPPED 1
#define OS_STATE_RUNNABLE 2
#define OS_STATE_RUNNING 4
#define OS_STATE_WAITING 8

/* OSThread.flags (ultralib PR/os_exception.h) */
#define OS_FLAG_CPU_BREAK 1 /* break exception has occurred */
#define OS_FLAG_FAULT     2 /* CPU fault has occurred */

#ifndef __cplusplus /* edg (C++ donors) rejects the &((T *)0)->f constant form */
/* compile-time offset checks (array size -1 => error) */
#define OS_THREAD_ASSERT_OFFSET(field, off) \
    typedef char os_thread_assert_##off[(int)&((OSThread *)0)->field == (off) ? 1 : -1]
OS_THREAD_ASSERT_OFFSET(context.a0, 0x38);
OS_THREAD_ASSERT_OFFSET(context.sp, 0xF0);
OS_THREAD_ASSERT_OFFSET(context.ra, 0x100);
OS_THREAD_ASSERT_OFFSET(context.sr, 0x118);
OS_THREAD_ASSERT_OFFSET(context.pc, 0x11C);
OS_THREAD_ASSERT_OFFSET(context.rcp, 0x128);
OS_THREAD_ASSERT_OFFSET(context.fpcsr, 0x12C);
#endif /* !__cplusplus */

#endif /* LIBULTRA_OS_THREAD_H */

#ifndef LIBULTRA_RMON_H
#define LIBULTRA_RMON_H

/* rmon / rdb host-protocol packets (ultralib include/PRinternal/dbgproto.h,
 * references/ultralib). The kernel links the debug libultra's rmon; every
 * dispatchTable command (rmon_dispatchTable, rmoncmds.c) takes a request that
 * starts with a KKHeader and answers with __rmonSendReply(reply, size, type).
 *
 * ultralib spells the byte fields `char`; IDO's char is unsigned, so u8 here
 * is the same type (lbu/sb). Opt-in header: older kernel TUs still carry
 * private per-function packet typedefs (RmonMsg, RmonAck, ...), so do NOT add
 * it to common.h until they are migrated. Offsets and sizes are asserted
 * below (array size -1 => compile error). */

#ifndef COMMON_H
#define COMMON_H

#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#endif


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif /* COMMON_H */


typedef s32 TVid;
typedef u16 TVushort;

#define KK_REV 2
#define KK_CODE_THREAD_STATUS 4

#ifndef OS_STATE_STOPPED
#define OS_STATE_STOPPED 1
#endif

#define KK_TYPE_REQUEST      0
#define KK_TYPE_REPLY        1
#define KK_TYPE_EXCEPTION    2
#define KK_TYPE_THREAD_EXIT  3
#define KK_TYPE_PROCESS_EXIT 4
#define KK_TYPE_CONSOLE      5

#define TV_ERROR_NO_ERROR             0
#define TV_ERROR_ILLEGAL_CALL         -1
#define TV_ERROR_INVALID_ID           -2
#define TV_ERROR_INVALID_TYPE         -3
#define TV_ERROR_OPERATIONS_PROTECTED -4
#define TV_ERROR_INVALID_ADDRESS      -5
#define TV_ERROR_INVALID_PRIORITY     -6
#define TV_ERROR_INVALID_FLAGS        -7
#define TV_ERROR_INVALID_CAPABILITY   -8

/* rmon methods / ids (ultralib include/PRinternal/rmonint.h). Checked against the
 * kernel: __rmonGetThreadStatus stores 0x3E9 for method 1 (RSP) and __rmonListThreads
 * answers object -1 with 0x3EA (CPU), so CPU = 1002, RSP = 1001. */
#define RMON_CPU 0
#define RMON_RSP 1
#define RMON_TID_RSP 1000
#define RMON_PRI_RSP 42
#define RMON_PID_CPU 1002
#define RMON_PID_RSP 1001

typedef struct KKHeader {
    /* 0x00 */ s32 length;
    /* 0x04 */ u8 code;     /* request: dispatchTable index */
    /* 0x05 */ u8 type;     /* KK_TYPE_* (set by __rmonSendHeader) */
    /* 0x06 */ s16 error;   /* TV_ERROR_* */
    /* 0x08 */ u8 rev;      /* KK_REV (set by __rmonSendHeader) */
    /* 0x09 */ u8 method;   /* 0 = CPU, 1 = RSP */
    /* 0x0A */ s16 notused2;
} KKHeader; /* size 0x0C */

typedef struct KKObjs {
    /* 0x00 */ TVushort number;
    /* 0x04 */ TVid objects[1];
} KKObjs; /* size 0x08 */

/* header + one object id (thread / process) */
typedef struct KKObjectRequest {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
} KKObjectRequest; /* size 0x10 */

typedef KKObjectRequest KKObjectEvent;

typedef struct KKObjsEvent {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ KKObjs objs;
} KKObjsEvent; /* size 0x18 */

/* __rmonReadMem request (reply: a KKBufferEvent in __rmonUtilityBuffer) */
typedef struct KKReadRequest {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ u32 addr;
    /* 0x14 */ u32 nbytes;
} KKReadRequest; /* size 0x18 */

typedef struct KKSetBkptRequest {     /* ultralib rmon: set-breakpoint request */
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ u32 addr;
    /* 0x14 */ u32 nbytes;
} KKSetBkptRequest; /* size 0x18 */

/* One breakpoint-table slot (ultralib rmon BREAKINFO, 8 bytes): rmon_breakpoints / rmon_RCPbreakpoints
 * hold 16 each (slot 0 unused; __rmonSetBreak scans slots 1..15, the BREAK code is slot + 0x10).
 * kernel_021.c (__rmonClearBreak side) spells the same layout locally. */
typedef struct BreakInfo {
    /* 0x0 */ u32 *breakAddress;        /* 0 = free */
    /* 0x4 */ u32 oldInstruction;       /* the word the BREAK replaced */
} BreakInfo; /* size 0x8 */

typedef struct KKBkptEvent {          /* ultralib rmon: set-breakpoint reply */
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ s32 bp;                 /* slot index in the breakpoint table */
    /* 0x14 */ u32 instruction;        /* the word the BREAK replaced */
} KKBkptEvent; /* size 0x18 */

typedef struct KKWriteHeader {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ u32 addr;
    /* 0x14 */ u32 nbytes;
} KKWriteHeader; /* size 0x18 */

/* __rmonWriteMem request: the header, then nbytes of data */
typedef struct KKWriteRequest {
    /* 0x00 */ KKWriteHeader writeHeader;
    /* 0x18 */ u8 buffer[1];
} KKWriteRequest;

typedef struct KKBufferEvent {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ u8 buffer[1];
} KKBufferEvent;

#define KK_RUN_SSTEP (1 << 0)
#define KK_RUN_SETPC (1 << 1)

typedef struct KKRun {
    /* 0x00 */ s32 flags;   /* KK_RUN_* */
    /* 0x04 */ u32 vaddr;   /* new PC when KK_RUN_SETPC */
} KKRun; /* size 0x08 */

/* __rmonRunThread request */
typedef struct KKRunThreadRequest {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid tid;
    /* 0x10 */ KKRun actions;
} KKRunThreadRequest; /* size 0x18 */

typedef struct KKRegion {
    /* 0x00 */ u32 vaddr;
    /* 0x04 */ u32 size;
    /* 0x08 */ s16 flags;   /* 1 read, 2 write, 4 execute */
    /* 0x0C */ u32 paddr;
} KKRegion; /* size 0x10 */

/* __rmonGetRegions reply: length = number * sizeof(KKRegion) + sizeof(KKRegionEvent) */
typedef struct KKRegionEvent {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ u32 number;
    /* 0x14 */ KKRegion regions[1];
} KKRegionEvent; /* size 0x24 */

/* __rmonGetRegionCount reply */
typedef struct KKNumberEvent {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ TVid object;
    /* 0x10 */ s32 number;
} KKNumberEvent; /* size 0x14 */

typedef struct KKFaultInfo {
    /* 0x00 */ u32 addr;
    /* 0x04 */ s16 major;
    /* 0x06 */ s16 minor;
} KKFaultInfo; /* size 0x08 */

typedef struct KKThreadStatus {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 why;
    /* 0x06 */ s16 what;
    /* 0x08 */ TVid tid;
    /* 0x0C */ TVid pid;
    /* 0x10 */ u32 instr;
    /* 0x14 */ KKFaultInfo info;
    /* 0x1C */ s32 priority;
    /* 0x20 */ s32 start;
    /* 0x24 */ s32 rv;
    /* 0x28 */ u32 args[6];
} KKThreadStatus; /* size 0x40 */

/* __rmonGetThreadStatus fills one; ThreadStatus / StopThread / RunThread send it */
typedef struct KKStatusEvent {
    /* 0x00 */ KKHeader header;
    /* 0x0C */ KKThreadStatus status;
} KKStatusEvent; /* size 0x4C */

#define RMON_ASSERT(name, cond) typedef char rmon_assert_##name[(cond) ? 1 : -1]
RMON_ASSERT(hdr_code, (int)&((KKHeader *)0)->code == 0x04);
RMON_ASSERT(hdr_error, (int)&((KKHeader *)0)->error == 0x06);
RMON_ASSERT(hdr_rev, (int)&((KKHeader *)0)->rev == 0x08);
RMON_ASSERT(hdr_method, (int)&((KKHeader *)0)->method == 0x09);
RMON_ASSERT(hdr_size, sizeof(KKHeader) == 0x0C);
RMON_ASSERT(objreq_object, (int)&((KKObjectRequest *)0)->object == 0x0C);
RMON_ASSERT(objsev_number, (int)&((KKObjsEvent *)0)->objs.number == 0x10);
RMON_ASSERT(objsev_objects, (int)&((KKObjsEvent *)0)->objs.objects[0] == 0x14);
RMON_ASSERT(objsev_size, sizeof(KKObjsEvent) == 0x18);

RMON_ASSERT(write_buffer, (int)&((KKWriteRequest *)0)->buffer[0] == 0x18);
RMON_ASSERT(bufev_buffer, (int)&((KKBufferEvent *)0)->buffer[0] == 0x10);
RMON_ASSERT(runreq_vaddr, (int)&((KKRunThreadRequest *)0)->actions.vaddr == 0x14);
RMON_ASSERT(region_size, sizeof(KKRegion) == 0x10);
RMON_ASSERT(regev_size, sizeof(KKRegionEvent) == 0x24);
RMON_ASSERT(status_why, (int)&((KKStatusEvent *)0)->status.why == 0x10);
RMON_ASSERT(status_size, sizeof(KKStatusEvent) == 0x4C);

#endif /* LIBULTRA_RMON_H */


/* Forward declarations */
extern s32 __osPiAccessQueue;
extern s32 __osPiAccessQueueEnabled;
extern s32 gUsoErrno;
extern void func_80005DC0(s32*, s32, s32);
extern void func_80005C00(void);
extern void func_80004FE0(s32*, s32*, s32);
extern void func_800053D0(s32*, s32*, s32);
extern s32 __OSGlobalIntMask;
extern s32 func_800066B0(void);
extern void func_800066D0(s32);
extern void func_80003D0C(s32*);
extern void* __osRunningThread;
extern s32 __osRunQueue;
extern s32 piacs_piAccessBuf;
extern s32 func_800009D8(void*, s32, s32, void*);
extern void func_80003FF0(s32, void*);
extern void* func_80003E54(void*);
extern void osStartThread(void*);
extern void func_8000857C(void);
extern void func_8000785C(s32);
extern void func_80008ED0(void);
extern void func_80007760(void);
typedef void (*FuncPtr2)(void*, void*);
extern FuncPtr2 gUsoPrintfHook;
extern s32 sFmt_USO_Version_8000A32C;
extern s32 sStr_3_1_8000A340;
extern s32 gUsoCtx;
extern s32 gFsDeviceTable;
extern s32 __osActiveQueue;
extern s32 func_80002890(s32);
extern void func_8000A0E0(void);
extern void func_80005350(s32, s32);
extern void func_80005400(s32, s32);
extern s32 func_80008430(s32);
extern void func_80009148(s32);
extern void func_80009030(s32, s32);
extern void func_80008498(void);
extern s32 __rmonReadWordAt(s32);
extern void func_800091F0(s32);
typedef struct { s32 pad[3]; s32 position; } FileState;

typedef struct {
    void* mtqueue;
    void* fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    s32** msg;
} OSMesgQueue;

typedef struct Thread {
    s32 field0;
    s32 pri;
    s32 queue;
    s32 pad0C;
    u16 state;
} Thread;

typedef struct { s32 queue; s32 msg; } OSEventState;
extern OSEventState __osEventStateTab[];



/* func_800066B0+func_800066D0 INCLUDE_ASM moved to kernel_017.c on
 * 2026-05-05 to enable the 3-way merge with the parent fragment
 * __rmonReadWordAt. Per
 * feedback_cross_file_fragment_unblock_via_move_then_merge.md: moving
 * just the INCLUDE_ASM (no C body change) is layout-neutral when both
 * .o files reside in adjacent linker-script slots and the destination
 * .o gets exactly the bytes the source loses. Adjacent .ld slots
 * verified: kernel_017.c.o then kernel_018.c.o.
 * 800066D0 caller-entry symbol preserved via undefined_syms_auto.txt
 * (still resolves at 0x800066D0 inside the merged 800066B0 body). */

/* split from kernel_018.c - 2026-06-10 kernel ROM-order relayout */









/* func_80007A98 (old head of this unit) was the body of __rmonStopThread;
 * merged into __rmonStopThread in kernel_034.c (C, exact). */

/* __rmonRunThread - verified structural decode (kernel, 0x294, 165
 * insns, rmon breakpoint / thread-control command handler). rmon
 * family (cf. __rmonListThreads / __rmonGetVRegs; __rmonRcpAtBreak,
 * func_800073F8 = __rmonMaskIdleThreadInts, func_80009C30 = thread list).
 *   s32 __rmonRunThread(RmonMsg *msg) {
 *       switch (msg->0x9) {                        // command kind
 *       case 0:                                    // set/arm break
 *           t = func_80009C30();                   // thread head
 *           while (t->0x4 != -1) {                 // find by id
 *               if (t->0x14 == msg->0xC) break;
 *               t = t->0xC;                         // next
 *           }
 *           if (t->0x4 == -1) return -2;            // not found
 *           if (t->0x10 != 1) return -4;            // bad state
 *           t->0x12 &= ~0x4;                        // clear flag
 *           if (msg->0x10 & 0x2)                    // opt arg
 *               t->0x11C = msg->0x14;
 *           ... (program RCP/HW break via func_80006A50/_80006A98,
 *                __rmonRcpAtBreak; __rmonMaskIdleThreadInts reply) ...
 *           break;
 *       case 1: ...                                 // continue/clear
 *       default: ...
 *       }
 *   }
 * Struct-typing reference: RmonMsg msg - msg->0x9 (9) u8 command
 * kind (0 = arm breakpoint, 1 = another op), msg->0xC (12) target
 * thread id, msg->0x10 (16) flags (bit 1 / 0x2 = "set field"),
 * msg->0x14 (20) the value. Thread-chain node (func_80009C30 head):
 * node->0x4 (4) sentinel (-1 = end), node->0xC (12) next, node->
 * 0x10 (16) s32 state (must be 1 / runnable), node->0x12 (18) u16
 * flags (bit 2 / 0x4 cleared here = clear-pending-break), node->
 * 0x14 (20) thread id, node->0x11C (284) = a programmable break
 * value. Returns -2 (no such thread) / -4 (wrong state). Programs
 * the RCP/CPU breakpoint via func_80006A50/func_80006A98 +
 * __rmonRcpAtBreak, then __rmonMaskIdleThreadInts (func_800073F8). MATCHED
 * byte-exact: cmd/var_s0/var_s1 pinned to s2/s0/s1 via register
 * hints + decl-order (buf/header/sp94 layout), shared SendHeader
 * epilogue (case 0 -> var_s1=1 -> wake), loop compare operand-order
 * (sp94->0xC != node->0x14) fixed temp-register numbering. */
extern void __rmonWriteWordTo(s32, s32);
extern s32 __rmonReadWordAt(s32);
extern s32 __rmonGetBranchTarget(s32, s32, s32);
extern void func_80008498(void);
extern void __rmonRunRCP(void);
extern void __rmonGetExceptionStatus(void *);
extern s32 __rmonSetSingleStep(s32, s32);
extern OSThread *func_80009C30(void); /* __osGetActiveQueue */
extern void osStartThread(void *);
extern u8 D_8001FF78;
/* rmon command dispatch on arg0->unk9. case 0: resume a thread - find it in the
 * chain by id (unk14==arg0->unkC), require it stopped (unk10==1), clear its
 * run-flags (unk12 &= ~3), optionally set the resume PC (unk11C) / validate via
 * func_80008C48, ack (0x10 header), wake it (func_8000A110), return 1. case 1:
 * RCP single-step - arm/disarm the RCP break (func_80006A50 / func_8000898C /
 * __rmonRcpAtBreak), ack, and if stepping set the temp break
 * (func_80007A98 -> func_80008D0C -> 0x4C reply). default: -4. */
s32 __rmonRunThread(KKRunThreadRequest *arg0) ;
                               
                                
                                
                                    
                       
                  
                              
                        

               
                                  
                  
                                 
                                     
       
                                                                                                           
                                            
                                        
                                             
                                
                 
             
         
                                     
                                       
         
                                                
                                                 
         
                                                                             
                                                 
                                                     
         
                                                                                                          
                                                 
         
                   
              
                  
                                   
                                                 
         
                                                 
                                                                        
         
                                                 
                                                                                                       
                                
             
                            
                                 
                
                                 
                            
         
                                             
                                              
                                
                                                          
                                                 
                                                        
                                
                                                         
         
                 
            
                                             
     

                                         
                                          
                            
                                                      
                      
                              
     
             
 
