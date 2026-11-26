typedef struct {
    s32 type;
    s32 ptr;
} Item;

typedef struct {
    s32 p0;
    Item *items;
    s16 n;
} Group;

typedef struct {
    u8 done;
    u8 pad1[3];
    s16 n;
    s16 pad6;
    Group *groups;
} Hdr;

void func_80053EF0(Hdr *h) {
    s32 i, j;
    s32 base;
    Group *g;
    Item *it;

    if (h->done != 0x21) {
        base = (s32)h;
        if (h->groups != NULL) {
            h->groups = (Group *)((s32)h->groups + base);
            for (i = 0, g = h->groups; i < h->n; g++, i++) {
                g->p0 += base;
                g->items = (Item *)((s32)g->items + base);
                for (j = 0, it = g->items; j < g->n; it++, j++) {
                    if (it->type < 2) {
                        it->ptr += base;
                    }
                }
            }
        }
        h->done = 0x21;
    }
}
