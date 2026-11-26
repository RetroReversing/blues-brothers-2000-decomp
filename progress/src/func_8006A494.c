extern void setTextColor(s32, s32, s32, s32);
extern void setTextPos(s32, s32);
extern void drawText(char *);
extern void drawInt(s32);
extern char D_80008E7C[];
extern int sprintf(char *, const char *, ...);

void func_8006A494(void *arg0) {
    char buf[16];

    *(s32 *)((char *) arg0 + 0x68) = 0xF;
    setTextColor(0x60, 0xFF, 0xFF, 0xFF);
    setTextPos(0x32, 0x4B);
    sprintf(buf, D_80008E7C, (double) *(f32 *)((char *) arg0 + 0x100));
    drawText(buf);
    setTextPos(0x32, 0x57);
    sprintf(buf, D_80008E7C, (double) *(f32 *)((char *) arg0 + 0x104));
    drawText(buf);
    setTextPos(0x32, 0x63);
    drawInt(*(s32 *)((char *) arg0 + 0x88));
}
