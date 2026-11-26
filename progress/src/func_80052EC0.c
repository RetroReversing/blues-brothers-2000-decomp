typedef struct Step {
    s32 key;
    s32 x4;
} Step;

typedef struct Seq {
    u8 pad0[4];
    Step *steps;
    s16 count;
    u16 xA;
} Seq;

typedef struct Obj {
    u8 pad0[0x68];
    s32 x68;
    u8 pad6C[8];
    Seq *x74;
    s32 x78;
    s32 x7C;
    u8 pad80[0x98 - 0x80];
    void *x98;
    void *x9C;
    void (*xA0)(struct Obj *);
    u8 padA4[0xC0 - 0xA4];
    s32 xC0;
    u8 padC4[0xD8 - 0xC4];
    void *xD8;
} Obj;

typedef struct Handler {
    s32 key;
    s32 (*fn)(Obj *, s32 *);
} Handler;

extern void func_800899DC(char *);
extern void func_80023078(void);
extern s32 func_8000C43C(void);
extern Obj *func_800232B4(s32, s32, s32, s32);
extern void func_80027030(s32);
extern s32 func_80082400(void);
extern void func_800393F4(void);
extern void func_80054140(void);
extern char D_80008134[];
extern char D_80008144[];
extern Handler D_800B7EA0[];
extern Handler *D_8014AA80;
extern s32 D_8014AA88;
extern s32 D_8014AA90;
extern s32 D_8014AA9C;
extern s32 D_800AE010;
extern Obj *D_800B3960;
extern s32 D_800B5DD4;
extern Obj *D_800BD06C;

void func_80052EC0(Obj *o) {
    Seq *seq;
    s32 *step;

    seq = o->x74;
    if (seq == NULL) {
        func_800899DC(D_80008134);
    }
    step = (s32 *)seq->steps;
    step += o->x78 * 2;
    if (seq->count < o->x78) {
        func_800899DC(D_80008144);
    }
    if (o->xD8 == NULL) {
        o->x98 = (s8 *)&func_80023078 + 8;
        o->x68 = -1;
        for (D_8014AA80 = D_800B7EA0; D_8014AA80->key != -1; D_8014AA80++) {
            if (D_8014AA80->key == *step) {
                o->xD8 = (s8 *)&func_80023078 + 8;
                break;
            }
        }
        if (D_8014AA80->key == -1) {
            D_8014AA80->fn(o, step);
        }
        o->x7C = 0;
    } else if (D_8014AA80->fn(o, step) == 0) {
        o->xD8 = NULL;
        o->x78++;
    }
    if (D_8014AA9C != 0) {
        D_8014AA88 = 0;
        seq->xA++;
        if (func_80082400() == -1 && func_8000C43C() != 0) {
            D_800BD06C->x9C = func_800393F4;
        } else {
            D_800BD06C->x9C = D_800BD06C->xD8;
        }
        D_800B3960->xC0 = 0;
        D_800B3960->x9C = D_800B3960->xD8;
        func_800232B4(1, 0, 0, 0)->x9C = func_80054140;
        D_800B5DD4 = 1;
        D_800AE010 = D_8014AA90;
        func_80027030(1);
        o->xA0(o);
    }
}
