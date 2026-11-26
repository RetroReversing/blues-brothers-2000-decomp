f32 func_8002D858();
f32 func_8002DD60(f32);
s32 func_8003BF98();
s32 func_80043248();
s32 actorSetAnim();
extern void *gCameraTarget;
extern s32 func_80078D94;
void func_800790B4(void *arg0)
{
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp;

    temp_fs0 = func_8002D858(arg0, 0);
    temp_fs1 = func_8002DD60((*((f32 *) (((s8 *) gCameraTarget) + 8))) - (*((f32 *) (((s8 *) arg0) + 8))));
    if ((*((s32 *) (((s8 *) arg0) + 0x7C))) == 0)
    {
        actorSetAnim(arg0, 0x107, 0x100);
        *((s32 *) (((s8 *) arg0) + 0x7C)) = 1;
        *((s32 *) (((s8 *) arg0) + 0x8C)) = 0;
    }
    temp = *((f32 *) (((s8 *) arg0) + 0xDC));
    if ((8.0f < temp) && ((*((s32 *) (((s8 *) arg0) + 0x8C))) == 0) && (temp_fs0 < 300.0f) && (temp_fs1 < 100.0f))
    {
        func_8003BF98(arg0);
        *((s32 *) (((s8 *) arg0) + 0x8C)) = 1;
    }
    if (func_80043248(arg0))
    {
        *((s32 **) (((s8 *) arg0) + 0x9C)) = &func_80078D94;
        *((s32 *) (((s8 *) arg0) + 0x8C)) = 1;
    }
}
