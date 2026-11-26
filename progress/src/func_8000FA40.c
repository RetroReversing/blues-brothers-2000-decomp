f32 func_8002DD60(f32);

s32 func_8000FA40(f32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    f32 temp_fs1;
    f32 temp_fs0;

    temp_fs1 = func_8002DD60(((arg0 + arg1) - arg2) - arg3);
    temp_fs0 = func_8002DD60(arg0 - arg1);
    if ((temp_fs0 + func_8002DD60(arg2 - arg3)) < temp_fs1)
    {
        return 0;
    }
    return 1;
}
