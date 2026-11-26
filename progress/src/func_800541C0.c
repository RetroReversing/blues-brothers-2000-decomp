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
    u8 pad9C[4];
    void (*xA0)(struct Obj *);
    u8 padA4[0xD8 - 0xA4];
    void *xD8;
} Obj;

typedef struct Handler {
    s32 key;
    s32 (*fn)(Obj *, s32 *);
} Handler;

extern void debugPrintf(char *);
extern void func_80023078(void);
extern char D_80008134[];
extern char D_80008144[];
extern Handler D_800B7F80[];
extern Handler *D_8014AA84;
extern s32 D_8014AA9C;

void func_800541C0(Obj *o) {
    Seq *seq;
    s32 *step;

    seq = o->x74;
    if (seq == NULL) {
        debugPrintf(D_80008134);
    }
    step = (s32 *)seq->steps;
    step += o->x78 * 2;
    if (seq->count < o->x78) {
        debugPrintf(D_80008144);
    }
    if (o->xD8 == NULL) {
        o->x98 = (s8 *)&func_80023078 + 8;
        o->x68 = -1;
        for (D_8014AA84 = D_800B7F80; D_8014AA84->key != -1; D_8014AA84++) {
            if (D_8014AA84->key == *step) {
                o->xD8 = (s8 *)&func_80023078 + 8;
                break;
            }
        }
        if (D_8014AA84->key == -1) {
            D_8014AA84->fn(o, step);
        }
        o->x7C = 0;
    } else if (D_8014AA84->fn(o, step) == 0) {
        o->xD8 = NULL;
        o->x78++;
    }
    if (D_8014AA9C != 0) {
        seq->xA++;
        o->xA0(o);
    }
}
