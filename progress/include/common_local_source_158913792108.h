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


extern void* __rmonGetTCB(s32 id);
extern void __rmonCopyWords(void* dst, void* src, s32 n);
extern void __rmonSendReply(void* hdr, s32 size, s32 flags);
extern void func_80007A98(s32 a, s32 b, void* buf);
extern void func_80008D0C(void* buf);

typedef struct { s32 pad0; u8 type; char pad5; s16 flags; s32 data[17]; } RmonBuf76;

typedef struct {
    s32  pad_00;
    u8   type;
    char pad_05;
    s16  flags;
    char pad_08[0x14];
    s32  field_1C;
    char pad_20[4];
    s16  field_24;
    s16  field_26;
    char pad_28[0x24];
} RmonBuf76B;

typedef struct {
    char pad_00[4];
    u8   field_04;
    char pad_05[4];
    u8   field_09;
    char pad_0A[2];
    s32  field_0C;
    char pad_10[0x80];
    s32  field_90;
} RmonMsg91FC;

typedef struct {
    char pad_00[4];
    u8   type;
    char pad_05;
    s16  flags;
    char pad_08[4];
    s32  field_0C;
} RmonHdr16;

typedef struct {
    char pad_00[4];
    u8   type;
    char pad_05;
    s16  flags;
    char pad_08[4];
    s32  field_0C;
    char pad_10[0x80];
    s32  field_90;
} RmonPkt98;

/* split from kernel_054.c - 2026-06-10 kernel ROM-order relayout */

/* NOTE: __rmonGetFRegisters is defined BEFORE __rmonSetFRegisters - ROM order
 * (0x9144 then 0x91FC); the old file had them reversed. */

s32 __rmonGetFRegisters(RmonMsg91FC* msg) ;
                            
                
                  
                  
              

            
                             
                  
     
                 
                                                
                   
                  
     
                                                                      
                                      
                           
                  
                               
                                 
             
 


s32 __rmonSetFRegisters(RmonMsg91FC* msg) ;
                            
                  
                  
              

            
                             
                  
     
                 
                                                
                   
                  
     
                                                                   
                                     
                               
                           
                  
                                 
             
 
