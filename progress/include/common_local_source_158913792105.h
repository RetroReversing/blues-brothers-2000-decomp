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
extern void func_8000A110(void*);
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
extern s32 func_80006A98(s32);
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



/* split from kernel_022.c - 2026-06-10 kernel ROM-order relayout */





#ifndef FW
#define FW(p, o) (*(s32 *)((char *)(p) + (o)))
#endif
extern void *__rmonGetTCB(s32);
extern void __rmonSendReply();

/* __rmonGetGRegisters = __rmonGetGRegisters-style register FETCH (libultra rmon),
 * IDO 7.1 -O1: read the thread context's 64-bit GPRs (low words) into a
 * 0xA4-byte reply, copy the 3 special registers, send it (jal func_800073F8
 * = __rmonMaskIdleThreadInts at our 0x6FF8; jal func_800077DC = __rmonGetTCB at our
 * 0x73DC). Returns -2 on a non-CPU request or a missing thread.
 * EXACT 2026-10-20 (agent-g run 112; was NM 88.9). The "alt entries"
 * func_80008EA0/ED0/FB0 (alabels in the .s, now dropped) are not entries:
 * kernel jal targets sit 0x400 above our numbering. What fixed the frame:
 * - -O1 frame layout is DECLARATION ORDER, top-down, and every `register`
 *   local also takes a ghost slot at its declaration position: msg first
 *   (ghost at the top), then hdr, ctx, src, and `register i` LAST (ghost at
 *   the bottom). That is the target's hdr@0x30 / ctx@0x2C / src@0x28.
 * - the tail stores go through `*(s32 *)((char *)&hdr + K)`: &hdr is
 *   rematerialized per store and ctx reloaded per read (the stores may alias
 *   it);
 * - the -2 for a non-CPU request is an `else { return -2; }` arm and the
 *   send is in the common tail (block order). */
s32 __rmonGetGRegisters(void *arg0) ;
                             
            
               
                            
              
                            
               
                            
                                                                                                                                 
          
                  
             
                   

                    
                             
                 
                              
                                    
                          
                      
         
                                      
                                    
                                   
                  
         
                                      
                                       
                                   
                  
         
                                           
                                        
                                        
                       
            
                  
     
                                 
             
 

/* __rmonSetGRegisters = the matching register STORE (inverse of 8E98), IDO 7.1
 * -O1: write the request's GPRs into the thread context as sign-extended
 * 64-bit values, copy the 3 special registers, send a 0x10 ack.
 * EXACT 2026-10-20 (agent-g run 112; was NM 83.5) with the same recipe as
 * 8E98 (decl order msg, hdr, ctx, p, `register i` last; else-return arm;
 * header filled in the tail as id, tag, zero). */
s32 __rmonSetGRegisters(void *arg0) ;
                             
                                                                    
                  
           
                   

                              
                                    
                          
                      
         
                                    
                                    
                                 
                
         
                                    
                                       
                                 
                
         
                                       
                                    
                                    
            
                  
     
                    
                             
                 
                                 
             
 
