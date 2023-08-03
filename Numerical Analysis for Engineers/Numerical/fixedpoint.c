#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) ((x)*(x)*(x) + 4*(x)*(x) - 5)
#define EPS 10e-6

double bisection(double a, double b) {
    int i, n = 100;
    double c;
    if (f(a) * f(b) > 0) {
        printf("On interval [%lf, %lf] No root.....\n", a, b);
        return 0.0;
    }
    for (i = 0; i < n; i++) {
        c = (a + b) / 2;
        if (fabs(f(c)) < EPS) {
            return c;
        }
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return 0;
}

int main() {
    int n = 6;
    double A = -10.0, b = -5.0, a;
    double h = (b - A) / n;
    a = A;
    double root;

    for (int i = 0; i < n; i++) {
        double b = a + h;
        root = bisection(a, b);
        if (root != 0.0) {
            printf("The root in the interval [%lf, %lf]: %lf\n", a, b, root);
        }
        a = b;
    }

    return 0;
}

