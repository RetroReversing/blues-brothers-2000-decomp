typedef struct { f32 m[4][4]; } Mat4;
void func_8004BA8C(Mat4 *, f32);
void func_8004D148(Mat4 *, Mat4 *, Mat4 *);

void func_8004E008(Mat4 *m, f32 a) {
    Mat4 t;
    Mat4 b;

    func_8004BA8C(&t, a);
    func_8004D148(&t, m, &b);
    *m = b;
}
