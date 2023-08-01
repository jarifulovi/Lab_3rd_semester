#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (((x)*(x)*(x))+4*((x)*(x))-10)
#define d(x) 3*(x)*(x)+8*(x)
#define EPS 10.0e-6

void bisection(double a, double b) {
    int i,n = 100;
    double c;
    if (f(a)*f(b)>0) {
        printf("On interval [%lf,%lf] there is no root.....\n", a, b);
        exit(0);
    }
    for (i=0;i<n;i++) {
        //printf("%d %lf %lf %lf %lf %lf %lf\n",i+1,a,b,c,f(a),f(b),f(c));
        c = (a + b)/2;
        if (fabs(f(c))<EPS) {
            printf("The root : %lf\n", c);
            break;
        }
        if (f(a)*f(c)<0)
            b = c;
        else
            a = c;
    }
}
void false_position(double a,double b){
    int i,n=100;
    double c;
    if(f(a)*f(b)>0){
        printf("On interval [%lf,%lf] there is no root.....\n", a, b);
        exit(0);
    }
    for(i=0;i<n;i++){
        //printf("%d %lf %lf %lf %lf %lf %lf\n",i+1,a,b,c,f(a),f(b),f(c));
        c = a - (f(a)*(b-a))/(f(b)-f(a));
        if(fabs(f(c))<EPS){
            printf("The root : %lf\n",c);
            break;
        }
        if(f(a)*f(c)<0) b = c;
        else if(f(b)*f(c)<0) a = c;
    }
}
void secant(double a, double b) {
    double c;
    int i,n=100;

    for (i=0;i<n;i++) {
        //printf("%d %lf %lf %lf %lf %lf %lf\n",i+1,a,b,c,f(a),f(b),f(c));
        c = a - (f(a)*(b - a))/(f(b)-f(a));
        if (fabs(f(c))<EPS) {
            printf("The root: %.6lf\n", c);
            return;
        }
        a = b;
        b = c;
    }

    printf("The method did not converge within %d iterations.\n",n);
}
void newton_raphson(double a){
    double c;
    int i, n = 100;

    for (i = 0; i < n; i++) {
        double f_a = f(a);
        double f_prime_a = d(a);

        //printf("%d %lf %lf %lf %lf\n",i + 1,a,f_a,f_prime_a,f_a);

        if (fabs(f_a) < EPS) {
            printf("The root: %.6lf\n", a);
            return;
        }
        c = a - f_a / f_prime_a;

        if (fabs(c - a) < EPS) {
            printf("The root: %.6lf\n", c);
            return;
        }
        a = c;
    }
    printf("The method did not converge within %d iterations.\n", n);
}


int main(){
    double a=1.25,b =1.5;
    bisection(a,b);
    false_position(a,b);
    secant(a,b);
    newton_raphson(a);

    return 0;
}