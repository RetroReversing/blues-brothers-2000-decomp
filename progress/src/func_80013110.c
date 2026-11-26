s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_8002ADFC(s32, s32, void *);
void *func_8002E374(s32);
extern s32 D_800B81D0;
extern s32 func_80013038;
typedef struct { f32 v; } Field_f32;
typedef struct { s32 v; } Field_s32;
s32 func_80013110(void *arg0)
{
  void *temp_s1;
  s32 q;
  s32 k;
  temp_s1 = func_8002E374(0x90);
  (((Field_s32 *) (((char *) temp_s1) + 0x58))->v) = func_800221C0(0, 1, 1, 1, 0, 0, 1, 0);
k = 0x117;
(((Field_s32 *) (((char *) temp_s1) + 0x5C))->v) = 0x62;
q = (((Field_s32 *) (((char *) temp_s1) + 0x94))->v) / 3;
(((Field_s32 *) (((char *) temp_s1) + 0))->v) = k;
(((Field_s32 *) (((char *) temp_s1) + 0x68))->v) = 0xE;
  (((Field_f32 *) (((char *) temp_s1) + 4))->v) = (((Field_f32 *) (((char *) arg0) + 4))->v);
  (((Field_f32 *) (((char *) temp_s1) + 8))->v) = (((Field_f32 *) (((char *) arg0) + 8))->v);
  (((Field_f32 *) (((char *) temp_s1) + 0xC))->v) = (((Field_f32 *) (((char *) arg0) + 0xC))->v);
  (((Field_s32 *) (((char *) temp_s1) + 0x94))->v) = q;
  if (D_800B81D0 == 0) {
    func_8002ADFC(0x22, 0x1F4, temp_s1);
  }
  (((Field_s32 *) (((char *) temp_s1) + 0x9C))->v) = (s32) &func_80013038;
  (((Field_s32 *) (((char *) temp_s1) + 0))->v) = k;
  return (s32) temp_s1;
}
