/* identical to guMtxXFML in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
void func_800955C8(f32 *, s32 *);
void func_8009598C(void *, f32, f32, f32, f32 *, f32 *, f32 *);
void guMtxXFML(s32 *m, f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz) { f32 mf[4][4]; func_800955C8(&mf[0][0], m); func_8009598C(mf,x,y,z,ox,oy,oz); }
