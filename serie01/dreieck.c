/*
Description: 
Determine the triangle type with 3 given sides. It may take on multiple types.

Input:
Sides of triangle
- a > 0
- b > 0
- c > 0

Output:
Possible Triangle types for a, b, c 
- Equilateral (gleichseitig)
- Isosceles (gleichschenkelig)
- Right (rechtwinkelig)
- Irregular (unregelmäßig)
- Degenerate (eindimensional "entartetes")
- Impossible (unmöglich)
*/

#include <stdio.h>

int main() {
    double a = 0;
    double b = 0;
    double c = 0;

    // get values for sides
    printf("### Triangle sides ###\n");
    printf("Side A: ");
    scanf("%lf", &a);
    printf("Side B: ");
    scanf("%lf", &b);
    printf("Side C: ");
    scanf("%lf", &c);

    // validate input
    if (a <= 0  || b <= 0 || c <= 0)
    {
        printf("Only positive numbers allowed.");
        return 0;
    }

    // set c = max(a, b, c)
    if (a > c)
    {
        a = a + c;
        c = a - c;
        a = a - c;
    }
    if (b > c)
    {
        b = b + c;
        c = b - c;
        b = b - c;
    }

    // Determine triangle type(s)
    printf("\nDetermined triangle type(s):\n");

    if(a + b < c)
    {
        printf("- Impossible\n");
        return 0;
    }
    if(a + b == c)
    {
        printf("- Degenerate\n");
        return 0;
    }
    if(a == b && b == c)
    {
        printf("- Equilateral\n");
    }
    if(a == b)
    {
        printf("- Isosceles\n");
    }
    if(a * a + b * b == c * c)
    {
        printf("- Right\n");
    }
    if(a != b && a != c && b != c)
    {
        printf("- Irregular\n");
    }

    return 0;
}