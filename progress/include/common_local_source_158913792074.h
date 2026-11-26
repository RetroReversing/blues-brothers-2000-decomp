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


/* 2026-06-10 kernel-relayout: kernel_051 (__rmonSendFault), kernel_050
 * (__rmonIOflush), kernel_052 (__rmonIOputw) and kernel_055
 * (__rmonIOhandler) merged into ONE unit in ROM order [0x50C0..0x52C0).
 * They are one original TU: the functions are back-to-back with NO
 * inter-fn padding (separate .o files would 16-align each), and
 * __rmonIOhandler's unreachable epilogue is 32-byte-aligned by IDO from
 * the TU-relative offset — it only lands pad-free when the function
 * sits at TU offset 0x130, i.e. after the other three. */

extern s32 rmon_IOmq;
extern s32 rmon_IOmsgs;
extern u8 rmonRdbReadBuf;
extern void* __osRdb_DbgRead_Buf;
extern void func_800053D0(s32*, s32*, s32);
extern void func_800051E0(s32, s32*, s32);
extern void func_80004FE0(s32*, s32*, s32);
extern void func_800069BC(u8*);
extern s32 __osRdbSend(void*, s32, s32);

/* Receive 0x1B0 bytes into arg0 buffer via repeated func_800066F0 calls.
 * The unused float local (`dummy = 0.0f`) is preserved from the original
 * — IDO emits the mtc1+swc1 even though the value is never read. */
void __rmonSendFault(void* arg0) ;
              
            
                  
                 
             
                  
        
                                                                                      
                          
                                     
 

/* Polls func_800066F0 until it returns a positive value. Used to wait
 * for a single byte of host I/O. */
void __rmonIOflush(void) ;
                  
            
                  
        
                                                       
                          
                             
 

/* Receive 4 bytes from host I/O into the caller's arg0 stack slot. */
void __rmonIOputw(s32 arg0) ;
                  
            
                  
                     
        
                                                                           
                          
                            
 

/* __rmonIOhandler (rmonsio.c): rmon I/O thread, runs __rmonExecute per request. */
void __rmonIOhandler(void) ;
              
            

                                               
                                       
                                          
     
                                    
                                   
                                          
              
                                                                       
                                                                     
                                                                  
        
                                                     
                   
                         
              
 
