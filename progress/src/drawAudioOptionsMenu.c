typedef struct ObjE278 {
    u8 pad0[0x70];
    s32 alpha;
    u8 pad74[0x14];
    s32 sel;
} ObjE278;

extern s32 coss(u16);
extern void func_8002E838(s32);
extern void func_80027038(s32);
extern void setTextColor(s32, s32, s32, s32);
extern void func_80027060(s32, s32, s32, s32);
extern void setTextPos(s32, s32);
extern void func_80027158(s32, s32);
extern void drawCenteredMessage(s32);
extern void drawMessage(s32);
extern void func_8002A360(s32, s32);
extern void drawText(void *);
extern u8 D_800B5DDC[];
extern s32 gAudioVolume[];
extern s32 gCamSpeedScale[];
extern s32 gPadPressed[];
extern s32 D_801073B0[];
extern s32 gTextWaveTime[];

/* Draws the audio options screen: music and sound-effect volume bars that the d-pad adjusts while selected, and the back entry. */
void drawAudioOptionsMenu(ObjE278 *menu) {
    s32 buf[8];
    s32 i;
    s32 j;
    s32 y;
    s32 yoff;
    s32 c;
    s32 col;
    s32 v;
    s32 v_arm;
    s32 v_arm_arm;
    s32 x;
    s32 k;
    s32 changed;

    i = 0;
    
    func_8002E838(menu->alpha / 2);
    func_80027038(0);
    setTextColor(0xCE, 0x10, 0x25, menu->alpha);
    setTextPos(0xA0, 0x14);
    drawCenteredMessage(0x9A);
    func_80027158(0xA0, 0x28);
    v_arm_arm = (((s16) coss((gTextWaveTime[0] * 400) & 0xFFF0) * 127) >> 15) + 0x80;
    v_arm = 0xFF - v_arm_arm / 2;
    func_80027060(v_arm, v_arm, v_arm, menu->alpha);
    for (; i < 3; i++) {
        y = i * 10 + 0x50;
        yoff = i * 10;
        func_80027158(0xA0, y);
        if (i == menu->sel) {
            c = 0xFF;
            setTextColor(c, c, c, menu->alpha);
            col = c;
        } else {
            c = 0x77;
            setTextColor(c, c, c, menu->alpha);
            col = c;
        }
        switch (i) {
        case 0:
            changed = 0;
            if (menu->sel == i) {
                if (gPadPressed[0] & 0x200) {
                    changed = 1;
                    gAudioVolume[0] -= 20;
                }
                if (gPadPressed[0] & 0x100) {
                    changed = 1;
                    gAudioVolume[0] += 20;
                }
                if (D_801073B0[0] < -20) {
                    changed = 1;
                    gAudioVolume[0] -= gCamSpeedScale[0] << changed;
                }
                if (D_801073B0[0] > 20) {
                    changed = 1;
                    gAudioVolume[0] += gCamSpeedScale[0] << changed;
                }
            }
            if (changed) {
                v_arm_arm = gAudioVolume[0];
                if (v_arm_arm > 100) {
                    v_arm_arm = 100;
                }
                if (v_arm_arm <= 0) {
                    v_arm_arm = 0;
                }
                gAudioVolume[0] = v_arm_arm;
                if (v_arm_arm < 10) {
                    v_arm_arm = 0;
                } else if (v_arm_arm < 16) {
                    v_arm_arm = 16;
                }
                func_8002A360(0, v_arm_arm * 327);
            }
            func_80027158(0x50, y);
            drawMessage(0x23);
            {
                s32 yy;

                for (j = 0, yy = yoff; j < 5; j++) {
                    x = j * 10 + 0xA0;
                    k = j * 20;
                    func_80027158(x, yy + 0x50);
                    if (k >= gAudioVolume[0]) {
                        setTextColor(col, 0, 0, 0xFF);
                    } else {
                        setTextColor(col, col, col, 0xFF);
                    }
                    drawText(D_800B5DDC);
                }
            }
            break;
        case 1:
            changed = 0;
            if (menu->sel == i) {
                if (gPadPressed[0] & 0x200) {
                    changed = 1;
                    gAudioVolume[1] -= 20;
                }
                if (gPadPressed[0] & 0x100) {
                    changed = 1;
                    gAudioVolume[1] += 20;
                }
                if (D_801073B0[0] < -20) {
                    changed = 1;
                    gAudioVolume[1] -= gCamSpeedScale[0] << changed;
                }
                if (D_801073B0[0] > 20) {
                    changed = 1;
                    gAudioVolume[1] += gCamSpeedScale[0] << changed;
                }
            }
            if (changed) {
                v_arm_arm = gAudioVolume[1];
                if (v_arm_arm > 100) {
                    v_arm_arm = 100;
                }
                if (v_arm_arm <= 0) {
                    v_arm_arm = 0;
                }
                gAudioVolume[1] = v_arm_arm;
                func_8002A360(1, v_arm_arm * 327);
                func_8002A360(12, 0x80);
                func_8002A360(8, 0x42);
            }
            func_80027158(0x50, y);
            drawMessage(0x24);
            {
                s32 yy;

                for (j = 0, yy = yoff; j < 5; j++) {
                    x = j * 10 + 0xA0;
                    k = j * 20;
                    func_80027158(x, yy + 0x50);
                    if (k >= gAudioVolume[1]) {
                        setTextColor(col, 0, 0, 0xFF);
                    } else {
                        setTextColor(col, col, col, 0xFF);
                    }
                    drawText(D_800B5DDC);
                }
            }
            break;
        case 2:
            drawCenteredMessage(0xA8);
            break;
        }
    }
    setTextColor(0xFF, 0xFF, 0xFF, menu->alpha);
    setTextPos(0x96, 0xCD);
    drawCenteredMessage(0xA9);
}
