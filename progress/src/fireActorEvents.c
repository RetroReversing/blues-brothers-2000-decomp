void func_8002ADFC(s32, s32, void *, void *);
extern s32 gCamSpeedScale;
typedef struct { s32 id; f32 t; s32 val; s32 pad; } E;
typedef struct { s32 x0; s32 n; s32 x8; E *e; } L;
typedef struct { char pad[0xC8]; L *l; s32 on; s32 id; char p2[8]; f32 t; } A;
s32 fireActorEvents(A *arg0) {
    L *l; E *e; s32 i; s32 t; f32 a, b;
    t = (s32)arg0->l;
    if (t == 0) return 0;
    l = (L *)t;
    e = l->e;
    t = l->n;
    i = 0;
    if (t > 0) {
        
        do {
            if (arg0->id != e->id) goto off;
            a = arg0->t; b = e->t;
            if (!(b <= a)) goto off;
            if (!(a <= b + (f32)gCamSpeedScale)) goto off;
            if (arg0->on == 0) {
                func_8002ADFC(e->val, l->x8, arg0, l);
                arg0->on = 1;
                return 1;
            }
            goto next;
        off:
            arg0->on = 0;
        next:
            e++; i++;
        } while (i < l->n);
    }
    return 0;
}
