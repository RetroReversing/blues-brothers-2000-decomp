typedef struct { f32 x; f32 y; f32 z; } Vec3T;
f32 sqrtf(f32);

f32 vec3Length(Vec3T *v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}
