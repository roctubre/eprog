#include <stdio.h>

/*
    Determines if two lines intersect, are parallel or identical.
    The inputs are three arrays, two which contain two coeffecients and a constant,
    and the last is a result array which contains the intersection point.
    Inputs:
        u = {a, b, c} ... first line, (a)x+(b)y=(c)
        v = {d, e, f} ... second line, (d)x+(e)y=(f)
        s = {s_x, s_y} ... result array; point of intersection, if any
    Outputs:
        0 ... identical
        1 ... parallel
       -1 ... intersect
*/
int geraden(double u[3], double v[3], double s[2]) {
    // compare slopes (-a/b) == (-d/e); from y = (k)x + d
    if (-u[0]/u[1] == -v[0]/v[1]) {
        //compare y-intercept (c/b) == (f/e); from y = kx + (d)
        if (u[2]/u[1] == v[2]/v[1]) {
            return 0;
        }
        return 1;
    }

    // get intersection s (solve for s_x by equalising equations u and v)
    s[0] = (v[2]/v[1] - u[2]/u[1]) / (-u[0]/u[1] + v[0]/v[1]);
    s[1] = (-u[0]/u[1])*s[0] + u[2]/u[1];
    
    return -1;
}

int main() {
    double u[3] = {1,2,3};
    double v[3] = {4,8,13};
    double s[2] = {9,9};
    int output = 0;
    
    // get input
    printf("# First line (a)x+(b)y=(c)\n");
    printf("a: "); scanf("%lf", &u[0]);
    printf("b: "); scanf("%lf", &u[1]);
    printf("c: "); scanf("%lf", &u[2]);
    printf("# Second line (d)x+(e)y=(f)\n");
    printf("d: "); scanf("%lf", &v[0]);
    printf("e: "); scanf("%lf", &v[1]);
    printf("f: "); scanf("%lf", &v[2]);
    
    // validate input
    if (u[0] == 0 || u[1] == 0 || v[0] == 0 || v[1] == 0) {
        printf("Coefficients can't be zero.\n");
        return 0;
    }

    // function call and output
    output = geraden(u, v, s);
    
    if (output == 0) {
        printf("=> IDENTICAL\n");
    }
    else if (output == 1) {
        printf("=> PARALLEL\n");
    }
    else {
        printf("=> INTERSECTION at (%.2lf, %.2lf)\n", s[0], s[1]);
    }
}
