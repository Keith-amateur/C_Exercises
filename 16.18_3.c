#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define DEG_TO_RAD(DEG) (M_PI / 180) * (DEG)
struct rectangular {
    double x;
    double y;
};
struct polar {
    double r;
    double radian;
};

struct rectangular *transform(struct polar);

int main() {
    struct polar point;
    puts("Enter the length");
    scanf("%lf", &point.r);
    puts("Enter the degree");
    double deg;
    scanf("%lf", &deg);
    point.radian = DEG_TO_RAD(deg);
    struct rectangular *p = transform(point);
    printf("x: %f, y: %f\n", p->x, p->y);
}

struct rectangular *transform(struct polar point) {
    static struct rectangular p;
    p.x = point.r * cos(point.radian);
    p.y = point.r * sin(point.radian);
    return &p;
}