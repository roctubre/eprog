/*
    Variable:
    - Memory with symbolic name
    - Has Datatype information (how to interpret memory)

    Pointer:
    - A variable which contains a memory address
    - By dereferencing (*), it can access the data on that memory address
    - Datatype of pointed memory must be specified for interpretation 

    Pointer PROS:
    - Direct access to memory
    - Provides a way to return more than one value to the functions
    - Reduces storage space and complexity
    - Reduces execution time of the program
    - Provides alternative way to access array elements
    - Can be used to pass informations back and forth between calling and called function
    - Allows dynamic memory allocation and deallocation
    - Allows to build comlix data structures (linked list, stacks, queues,...)
    - Allows dynamic resizing of allocated memory
    - Memory addresses can be extracted

    Pointer CONS:
    - Uninitialized pointers might cause sementation fault
    - Dynamically allocated memory needs to be freed explicitly (if not, leads to memory leak)
    - Pointers are slower than normal variables (pointer: lookup + access)
    - If updated with incorrect values, it might cause memory corruption

*/


#include <stdio.h>

/*
    Swapping values does not work, because datatypes are 
    passed with call by value. 
*/
void swap_old(double x, double y) {
    double tmp;
    tmp = x;
    x = y;
    y = tmp;
}

/*
    Swaps values with call by reference
*/
void swap(double* x, double* y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main() {
    double a = 5;
    double b = 3;
    printf("a = %.0lf, b = %.0lf\n", a, b);
    swap(&a, &b);
    printf("a = %.0lf, b = %.0lf\n", a, b);
}