s32 func_80043248(void *arg0);
void func_800761FC(void *arg0);
void func_80057018(void);

void func_800571B0(void *arg0)
{
    s32 temp;

    temp = func_80043248(arg0);
    *(s32 *) arg0 = 0x101;
    if (temp != 0) {
        func_800761FC(arg0);
        *(void **)((s8 *) arg0 + 0x9C) = (void *) ((s8 *) func_80057018 + 8);
    }
}
