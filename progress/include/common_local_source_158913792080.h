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
extern void func_80005400(s32, s32);
extern void func_80009148(s32);
extern void func_80009030(s32, s32);
extern void func_80008498(void);
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


/* __rmonListBreak (rmonbrk.c): rmon dispatchTable[22], returns TV_ERROR_ILLEGAL_CALL */
s32 __rmonListBreak(s32 arg0) ;
              
 


/* __rmonClearBreak = __rmonClearBreak (libultra rmon/rmonbrk.c), IDO 7.1
 * -O1, EXACT. One function [0x8430,0x858C); it used to be four .s pieces
 * across two units (8430+alabel 8454 here, 8498/84AC/84D0 at the head of
 * kernel_022, joined by absolute .L label syms). The jal'd 0x80008454 /
 * 0x80008498 / 0x8000857C are other rmon functions 0x400 lower (kernel
 * jal targets sit 0x400 above our symbol numbering) and stay absolute
 * undefined_syms entries. Callees, real names: 6A98 __rmonReadWordAt,
 * 6A50 __rmonWriteWordTo, 31F0 osWritebackDCache, 5350 osInvalICache,
 * 73F8 __rmonSendReply. rmon_RCPbreakpoints = rspBreakpoints,
 * rmon_breakpoints = breakpoints (16 x {addr, old instruction}). */
typedef struct { u32 *breakAddress; u32 oldInstruction; } BreakInfo;
typedef struct { s32 pad0; u8 code; u8 pad5[4]; u8 method; u8 padA[2]; s32 object; s32 bp; } ClrBkptRequest;
typedef struct { s32 pad0; u8 code; u8 pad5; s16 error; s32 pad8; s32 object; s32 bp; s32 pad14; } BkptReply;
extern BreakInfo D_8001FEF8[];
extern BreakInfo D_8001FE70[];
extern u32 __rmonReadWordAt(u32 *);
extern void __rmonWriteWordTo(u32 *, u32);
extern void func_800031F0(void *, s32);
extern void func_80005350(void *, s32);
extern void __rmonSendReply(void *, s32, s32);

s32 __rmonClearBreak(ClrBkptRequest *req) ;
                                           
                                   
                    
             

                            
                  
     
                           
                                                       
                                        
                      
         
                                                       
                                         
                                                                                
         
            
                                                    
                                        
                      
         
                                         
                                         
                                                                   
                                                       
                                                       
         
     
                                 
                               
                    
                                   
                           
                                   
             
 
