s32 func_8000F8F4(s32 arg0, s32 *arg1) {
    s32 ret;
    ret = 0;
    switch (*arg1) {
    case 0x1000:
        ret = func_800552C4(arg1); if (ret == 2) { ret = 1; } else { ret = 0; }
        break;
    case 0x100D:
        switch (cameraGetMode()) {
        case 1:
        case 3:
        case 7:
            func_8005F308(arg1);
            ret = func_8005EEDC(arg0, arg1);
            break;
        default:
            goto def;
        }
        break;
    case 0x1011:
        func_8005ACA4(arg1);
        ret = func_8005AAB4(arg0, arg1);
        break;
    case 0x101E:
        ret = func_80067FB4(arg1);
        break;
    case 0x1023:
        ret = func_80077D88(arg1);
        break;
    case 0x102D:
        ret = func_8007EE88(arg1);
        break;
    case 0x1003:
        ret = func_80079294(arg1); if (ret == 2) { ret = 1; } else { ret = 0; }
        break;
    case 0x1021:
        ret = func_80051D70(arg1); if (ret == 2) { ret = 1; } else { ret = 0; }
        break;
    case 0x1016:
        
        break;
    default:
    def:
        ret = func_800609F8(arg1); if (ret == 2) { ret = 1; } else { ret = 0; }
        break;
    }
    return ret;
}
