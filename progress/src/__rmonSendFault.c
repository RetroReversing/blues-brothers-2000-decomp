u32 __osRdbSend(u8 *buf, u32 size, u32 type);

void __rmonSendFault(void *thread) {
    volatile float f;
    u8 *tPtr;
    u32 sent = 0;

    f = 0.0f;

    tPtr = (u8 *)thread;
    while (sent < 0x1B0) {
        sent += __osRdbSend(tPtr + sent, 0x1B0 - sent, 2);
    }
}


