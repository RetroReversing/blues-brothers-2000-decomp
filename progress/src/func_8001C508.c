typedef struct O1C508 {
    u8 pad0[0xBC];
    s32 fBC;
} O1C508;
s32 func_8001B990(s32, u32);
void func_8001C4A0(void);
O1C508 *func_80023874(s32, s32);
extern s32 D_800BD1DC;

void func_8001C508(void) {
    O1C508 *o;

    D_800BD1DC = 0;
    if (func_8001B990(0x100, 7) != 0) {
        if (func_8001B990(0x100, 6) == 0) {
            func_8001C4A0();
        }
    }
    if (func_8001B990(0x100, 5) != 0) {
        if (func_8001B990(0x100, 7) == 0) {
            func_8001C4A0();
        }
        if (func_8001B990(0x100, 6) == 0) {
            func_8001C4A0();
        }
    }
    if (func_8001B990(0x100, 8) != 0) {
        if (func_8001B990(0x100, 5) == 0) {
            func_8001C4A0();
        }
        if (func_8001B990(0x100, 7) == 0) {
            func_8001C4A0();
        }
        if (func_8001B990(0x100, 6) == 0) {
            func_8001C4A0();
        }
    }
    if (func_8001B990(0x100, 8) != 0) {
        o = func_80023874(0x1000, 0);
        if (o != NULL) {
            o->fBC = 1;
        }
    }
}
