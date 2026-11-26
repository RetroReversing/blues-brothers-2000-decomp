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


extern void __rmonSendReply(void*, s32, s32);

typedef struct { s32 pad0; u8 type; char pad5; u16 flags; s32 pad8; s32 id; } RmonHdr16;
typedef struct { s32 pad0; u8 type; char pad5[7]; s32 id; } RmonMsg;

/* __rmonSetFault (rmonmisc.c): rmon dispatchTable[10] */
s32 __rmonSetFault(RmonMsg* msg) ;
                     
                  
                       
                  
                   
                                 
             
 

/* __rmonInit */
extern s32 __rmonMQ;
extern s32 rmon_rmonMsgs;
extern s32 rmon_rmonIOStack;
extern s32 rmon_rmonIOThread;
extern s32 rmon_rmonPiMQ;
extern s32 rmon_rmonPiMsgs;
extern s32 __rmonIOhandler_rt;
extern void func_800053D0(void*, void*, s32);
extern void func_800051E0(s32, void*, s32);
extern void func_80005F10(void*, s32, void*, s32, void*, s32);
extern void func_80005920(s32, void*, void*, s32);
extern void func_8000A110(void*);

void __rmonInit(void) ;
                                                
                                     
                                     
                                     
                                     
                                                                
                                                           
                                                             
                                      
 

/* Halt stub. Keep this after its real neighbors: its offset is 0x128 in
 * this unit (8 modulo 32). IDO aligns the unreachable return to 32 bytes,
 * placing jr ra at function+0x18, exactly as in the ROM. A standalone unit
 * starts at zero and adds eight extra padding bytes before that return.
 * No instruction patching or artificial prefix is needed. */
void __rmonPanic(void) ;
              
     
 
