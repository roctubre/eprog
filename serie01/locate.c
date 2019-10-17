/*
Description: 
Check if a given coordinate (x, y) is inside, outside or 
on the edge of a square with points (0, 0), (L, 0), (L, L), (0, L).

Input: 
- L > 0 ... side length of square
- a, b, c ... Natural numbers

Output:
- Inside or
- Outside or
- on the edge of the square
*/

#include <stdio.h>

int main() {

    double length = 0;
    double x = 0;
    double y = 0;

    // input length of square
    printf("### Square ###\n");
    printf("Length: ");
    scanf("%lf", &length);

    // input (x, y) point of interest
    printf("### Check Point ###\n");
    printf("x: ");
    scanf("%lf", &x);
    printf("y: ");
    scanf("%lf", &y);
    
    // validate input
    if(x <= 0 || y <= 0 || length <= 0)
    {
        printf("Only positive numbers allowed.");
        return 0;
    }

    // check if point is inside the square, else its outside
    if (x >= 0 && x <= length && y >= 0 && y <= length)
    {
        // check if point is on the edge, else its inside
        if(x == 0 || x == length || y == 0 || y == length)
        {
            printf("Point is ON THE EDGE of the square.\n");
        }
        else
        {
            printf("Point is INSIDE the square.\n");
        }
    }
    else
    {  
        printf("Point is OUTSIDE the square.\n");
    }


    return 0;
}