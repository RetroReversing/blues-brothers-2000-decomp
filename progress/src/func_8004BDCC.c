typedef struct {
    f32 x, y, z;
} Vec3f;

void func_8004BDCC(f32 m[4][4], Vec3f *eye, Vec3f *at)
{
    Vec3f s;
    Vec3f up;
    Vec3f f;
    Vec3f r;
    Vec3f u;
    f32 len;
    f32 len2;

    f = *at;
    f.x -= eye->x;
    f.y -= eye->y;
    f.z -= eye->z;
    len = sqrtf(f.x * f.x + f.y * f.y + f.z * f.z);
    f.x /= len;
    f.y /= len;
    f.z /= len;
    s.x = f.x;
    s.y = 0.0f;
    s.z = f.z;
    len2 = sqrtf(s.x * s.x + s.y * s.y + s.z * s.z);
    s.x /= len2;
    s.y /= len2;
    s.z /= len2;
    up.x = 0.0f;
    up.y = -1.0f;
    up.z = 0.0f;
    r.x = s.y * up.z - s.z * up.y;
    r.y = s.z * up.x - s.x * up.z;
    r.z = s.x * up.y - s.y * up.x;
    u.x = f.y * r.z - f.z * r.y;
    u.y = f.z * r.x - f.x * r.z;
    u.z = f.x * r.y - f.y * r.x;
    m[0][0] = r.x;
    m[0][1] = r.y;
    m[0][2] = r.z;
    m[0][3] = 0.0f;
    m[1][0] = u.x;
    m[1][1] = u.y;
    m[1][2] = u.z;
    m[1][3] = 0.0f;
    m[2][0] = f.x;
    m[2][1] = f.y;
    m[2][2] = f.z;
    m[2][3] = 0.0f;
    m[3][0] = eye->x;
    m[3][1] = eye->y;
    m[3][2] = eye->z;
    m[3][3] = 1.0f;
}
