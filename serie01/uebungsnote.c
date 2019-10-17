/*
Description: 
Calculate the ratio of total tasks (80) to finished tasks and 
output whether you passed or not (>=50%)

Input: 
- f ... natural number; number of finished tasks

Output:
- ratio total / finished
- Passed or not (>=50%)
*/

#include <stdio.h>

int main() {
    int f = 0;
    double ratio = 0.;

    // get number of finished tasks
    printf("Finished tasks: ");
    scanf("%d", &f);
    
    // validate input
    if(f < 0)
    {
        printf("Only non-negative numbers allowed.");
        return 0;
    }
    
    // calculate ratio
    ratio = (double)(f / 80.);
    printf ("Ratio: %.2lf %%\n", ratio * 100);

    // print if passed or failed
    if(ratio >= 0.5)
    {
        printf ("-> PASSED. (>=50 %%)\n");
    }
    else
    {
        printf("-> FAILED. (<50 %%)\n");
    }
    

    return 0;
}