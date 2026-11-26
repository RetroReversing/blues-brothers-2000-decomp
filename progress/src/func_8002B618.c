/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
void func_8002B410();
void func_8008D990();
void func_8008DB64();
void func_8008DC24();
extern char D_801078C0[];
extern char D_801091B0[];
extern char D_801183F8[];
extern char D_B096B3E0[];
extern char D_B09745E0[];
extern char D_B0978AA0[];
extern char D_B0BA76E0[];
extern char D_B0D51A50[];
extern char D_B0F43BE0[];
extern char D_B0F45400[];
void func_8002B618(void) {
    func_8002B410(D_B096B3E0, D_801091B0, D_B09745E0 - D_B096B3E0);
    func_8002B410(D_B0F43BE0, D_801078C0, D_B0F45400 - D_B0F43BE0);
    func_8008D990(D_801091B0, D_B0BA76E0);
    func_8008DB64(D_801078C0);
    func_8008DC24(D_801078C0, D_801091B0);
    func_8002B410(D_B096B3E0 + 0x9200, D_801183F8, D_B0978AA0 - (D_B096B3E0 + 0x9200));
    func_8008D990(D_801183F8, D_B0D51A50);
}
