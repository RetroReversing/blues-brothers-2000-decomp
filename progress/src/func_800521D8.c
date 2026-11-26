s32 func_80043248(void);
void func_800853E8(void *);
void func_80043214(void *);
void func_80023078(void *);
typedef struct {
    u8 pad0[0x9C];
    void *unk9C;
    u8 padA0[0x20];
    s32 unkC0;
    u8 padC4[0x18];
    f32 unkDC;
} Obj;

void func_800521D8(Obj *arg0)
{
    s32 done;

    done = func_80043248();
    func_800853E8(arg0);
    switch (arg0->unkC0) {
    case 2:
        if (done != 0) {
            arg0->unk9C = (void *)((s8 *)&func_80023078 + 8);
            arg0->unkC0 = 1;
        }
        break;
    case 3:
    case 7:
        if (269.0f <= arg0->unkDC) {
            arg0->unkC0 = 7;
            arg0->unkDC = 219.0f;
            func_80043214(arg0);
        }
        break;
    case 5:
    case 6:
        if (done != 0 || 355.0f <= arg0->unkDC) {
            arg0->unkC0 = 6;
            arg0->unkDC = 284.0f;
            func_80043214(arg0);
        }
        break;
    }
}
