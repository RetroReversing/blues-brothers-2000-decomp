f32 func_8002DD60(f32, void *);

extern void *gCameraTarget;
extern f64 D_80000808;

s32 func_80013784(void *arg0)
{
    f32 d;

    if ((*((s32 *) (((char *) gCameraTarget) + 0xD0))) == 0x2C)
    {
        d = func_8002DD60((*((f32 *) (((char *) arg0) + 8))) - (*((f32 *) (((char *) gCameraTarget) + 8))), gCameraTarget);
        if ((f64) d < D_80000808)
        {
            return 1;
        }
    }
    return 0;
}
