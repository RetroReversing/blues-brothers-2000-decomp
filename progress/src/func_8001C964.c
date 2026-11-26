typedef struct Obj Obj;
Obj *func_80022028(s32);
f32 func_8002D340(f32, f32, f32);
void func_8002D620(Obj *);
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ u8 pad10[0x30];
    /* 0x40 */ f32 x0;
    /* 0x44 */ u8 pad44[0x1C];
    /* 0x60 */ s32 f60;
    /* 0x64 */ u8 pad64[0xC];
    /* 0x70 */ s32 f70;
    /* 0x74 */ u8 pad74[4];
    /* 0x78 */ s32 f78;
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[0x28];
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0x14];
    /* 0xC0 */ s32 fC0;
};
extern f32 D_80000C94;
extern f32 D_80000C98;
extern f32 D_80000C9C;
extern f32 D_80000CA0;
extern f32 D_80000CA4;
extern f32 D_80000CA8;
extern f32 D_80000CAC;
extern f32 D_80000CB0;
extern char D_800B9ECC[];
extern char D_800BD170[];
#define FRAMES (*(s32 *)D_800B9ECC)

void func_8001C964(Obj *arg0) {
    Obj *o;
    s32 speed;
    f32 to;
    f32 r;
    f32 a;
    f32 b;
    f32 c;

    if (arg0->f7C == 0) {
        if (arg0->f70 == 1) {
            arg0->x = D_80000C94;
            arg0->y = D_80000C9C;
            arg0->z = D_80000CA0;
        } else {
            arg0->x = D_80000C98;
            arg0->y = D_80000C9C;
            arg0->z = D_80000CA0;
        }
        func_8002D620(arg0);
        arg0->f7C = 1;
        arg0->fC0 = 0;
        o = func_80022028(0);
        o->f60 = *(s32 *)D_800BD170;
        o->f78 -= 350;
        arg0->fA8 = o;
    }
    speed = FRAMES * 5;
    switch (arg0->fC0) {
    case 0:
        to = D_80000CA4;
        r = func_8002D340(to, arg0->z, speed);
        arg0->z = r;
        if (r == to) {
            arg0->fC0++;
        }
        break;
    case 1:
        to = D_80000CA8;
        if (arg0->f70 == 1) {
            to = D_80000CAC;
        }
        r = func_8002D340(to, arg0->x, speed);
        arg0->x = r;
        if (r == to) {
            arg0->fC0++;
        }
        break;
    case 2:
        r = func_8002D340(arg0->x0, arg0->x, speed);
        arg0->x = r;
        if (r == arg0->x0) {
            arg0->fC0++;
        }
        break;
    case 3:
        to = D_80000CB0;
        r = func_8002D340(to, arg0->z, speed);
        arg0->z = r;
        if (r == to) {
            arg0->fC0 = 0;
        }
        break;
    }
    o = arg0->fA8;
    o->x = arg0->x;
    o->y = arg0->y;
    o->z = arg0->z;
}
