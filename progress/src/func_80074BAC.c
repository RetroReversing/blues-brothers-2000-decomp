typedef struct Obj { u8 pad[0x98]; void *f98; void *fn; u8 pad2[0x108 - 0xA0]; } Obj;
extern Obj *D_800AB9BC;
extern Obj *D_800AB9C0;
void func_8000DFE4(void);
void func_8001F9A8(void);
void func_80023078(void);

void func_80074BAC(void) {
    Obj *p;

    for (p = D_800AB9BC; p <= D_800AB9C0; p++) {
        if (p->f98 == func_8001F9A8 && p->fn == (s8 *)func_80023078 + 8) {
            p->fn = func_8000DFE4;
        }
    }
}
