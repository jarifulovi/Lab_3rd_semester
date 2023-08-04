#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define SIZE 100
int main() {
    int i, n = SIZE;
    double x[SIZE+1], y[SIZE+1], dy[SIZE+1], h, a = 0, b = 2 * PI;
    h = (b - a) / n;
    printf("\"x\",\"f(x)\",\"f\'(x)\"\n");
    x[0] = a;
    for (i = 1; i <= SIZE; i++) x[i] = x[i - 1] + h;
    for (i = 0; i <= SIZE; i++) y[i] = sin(x[i]);

    dy[0] = (y[1] - y[0]) / (x[1] - x[0]);
    for (i = 1; i < SIZE; i++) dy[i] = (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1]);
    dy[n] = (y[n] - y[n - 1]) / (x[n] - x[n - 1]);

    for (i = 0; i <= SIZE; i++) {
        printf("%lf,%lf,%lf\n", x[i], y[i], dy[i]);
    }
    return 0;
}

