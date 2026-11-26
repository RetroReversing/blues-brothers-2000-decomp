typedef struct Actor {
    /* 0x000 */ s32 pad0;
    /* 0x004 */ f32 x;
    /* 0x008 */ f32 y;
    /* 0x00C */ s32 padC;
    /* 0x010 */ s32 flags;
    /* 0x014 */ u8 pad14[0x48];
    /* 0x05C */ s32 alpha;
    /* 0x060 */ u8 pad60[0x14];
    /* 0x074 */ s32 v74;
    /* 0x078 */ s32 pad78;
    /* 0x07C */ s32 state;
    /* 0x080 */ u8 pad80[0x1C];
    /* 0x09C */ void *update;
    /* 0x0A0 */ u8 padA0[8];
    /* 0x0A8 */ struct Actor *target;
    /* 0x0AC */ u8 padAC[0x14];
    /* 0x0C0 */ s32 vC0;
    /* 0x0C4 */ u8 padC4[0xC];
    /* 0x0D0 */ s32 anim;
    /* 0x0D4 */ s32 padD4;
    /* 0x0D8 */ void *next;
    /* 0x0DC */ u8 padDC[0x2C];
} Actor;
void sendCommand(s32, s32);
f32 func_8002DD60(f32);
void func_80043328(Actor *, s32, s32);
void debugPrintf(char *, ...);
extern char D_800085AC[];
extern Actor *D_800AB9BC;
extern Actor *D_800AB9C0;
extern Actor *gCameraTarget;
void func_8001D54C(void);
void func_8005B638(void);

s32 func_8005B424(Actor *arg0) {
    Actor *a;
    f32 dx;
    f32 dy;

    arg0->flags = 0x8000;
    if (arg0->state == 0) {
        arg0->target = NULL;
        for (a = D_800AB9BC; a < D_800AB9C0; a++) {
            if (a->update == func_8001D54C) {
                dx = func_8002DD60(arg0->x - a->x);
                dy = func_8002DD60(arg0->y - a->y);
                if (dx < 850.0f && dy < 850.0f) {
                    arg0->target = a;
                    break;
                }
            }
        }
        arg0->state = 1;
        return 0;
    }
    if (arg0->state == 1 && arg0->target == NULL) {
        debugPrintf(D_800085AC);
    }
    if (arg0->alpha < 0xF4) {
        arg0->alpha += 0x12;
        if (arg0->alpha >= 0xF5) {
            arg0->alpha = 0xFF;
        }
    } else if (func_8002DD60(gCameraTarget->x - arg0->x) < 950.0f) {
        if (arg0->anim == 0xC6) {
            func_80043328(arg0, 0xC8, 0x100);
            if (arg0->target != NULL) {
                arg0->target->vC0 = 1;
                arg0->target->v74 = 1;
            } else {
                func_80043328(arg0, 0xCA, 0x100);
            }
        } else if (arg0->target != NULL && arg0->target->vC0 == 0) {
            arg0->next = func_8005B638;
            arg0->state = 0;
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x21);
        }
    }
}
