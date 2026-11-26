typedef struct Obj Obj;
typedef s32 (*ObjFn)(Obj *);
struct Obj {
    u8 pad0[8];
    f32 unk8;
    u8 padC[0x74 - 0xC];
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    u8 pad80[0x88 - 0x80];
    s32 unk88;
    u8 pad8C[0xA8 - 0x8C];
    Obj *unkA8;
    u8 padAC[0xD8 - 0xAC];
    ObjFn unkD8;
};

void func_8002D858(Obj *, void *);
f32 func_800385AC(void);
void func_80043328(Obj *, s32, s32);
s32 func_8007E030(Obj *);
s32 func_8007E280(Obj *);
s32 func_8007E3A0(Obj *);
s32 func_8007E4B8(Obj *);
s32 func_8007E674(Obj *);
s32 func_8007E810(Obj *);
s32 func_8007EAC4(Obj *);

void func_8007ECB0(Obj *arg0) {
    s32 ret = 0;
    Obj *other;

    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        arg0->unkD8 = func_8007E280;
        arg0->unk8 = func_800385AC();
        arg0->unk88 = 0;
    }
    func_8002D858(arg0, (u8 *)arg0 + 0x10);
    if (arg0->unkD8 != NULL) {
        ret = arg0->unkD8(arg0);
    }
    if (ret != 0) {
        other = arg0->unkA8;
        arg0->unk88 = 0;
        switch (arg0->unk78) {
        case 0:
            if (ret == 0xDE) {
                arg0->unkD8 = func_8007E030;
            } else {
                arg0->unk78 = 1;
                arg0->unkD8 = func_8007E3A0;
            }
            break;
        case 1:
            switch (ret) {
            case 1:
                arg0->unk78 = 3;
                arg0->unkD8 = func_8007E030;
                break;
            case 2:
                arg0->unk78 = ret;
                arg0->unkD8 = func_8007E810;
                break;
            }
            break;
        case 3:
            arg0->unk78 = 4;
            arg0->unkD8 = func_8007EAC4;
            break;
        case 4:
            arg0->unk78 = 5;
            arg0->unkD8 = func_8007E4B8;
            break;
        case 5:
            switch (ret) {
            case 1:
                arg0->unk78 = ret;
                arg0->unkD8 = func_8007E3A0;
                break;
            case 2:
                arg0->unk78 = 6;
                arg0->unkD8 = func_8007E674;
                break;
            }
            break;
        case 6:
            arg0->unk78 = 1;
            arg0->unkD8 = func_8007E3A0;
            break;
        case 2:
            arg0->unk78 = 0;
            arg0->unkD8 = func_8007E030;
            break;
        default:
            arg0->unk78 = 6;
            arg0->unkD8 = func_8007E030;
            break;
        }
        func_80043328(arg0, arg0->unk74 + arg0->unk78, 0x100);
        func_80043328(other, other->unk74 + arg0->unk78, 0x100);
    }
}
