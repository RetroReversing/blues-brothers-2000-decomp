/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

typedef struct Obj { char pad0[0x20]; void *(*alloc)(s32, s32, s32); char pad1[4]; s32 ctx; } Obj;
typedef struct Node { s32 next; char pad[0xC]; s8 a; s8 b; char pad2[2]; s32 c; s32 d; } Node;
void func_80092980(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Obj *arg4) {
    Node *n = arg4->alloc(arg4->ctx, 1, 0x1C);
    if (n != NULL) {
        n->next = 0;
        n->a = arg0;
        n->b = arg1;
        n->c = arg2;
        n->d = arg3;
    }
}
