#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 256

int     anagram     (char* firstStr, char* secondStr);
void    quickSort   (char* x, int n);
void    tolower     (char* str);


int main() {
    char str1[MAXLEN];
    char str2[MAXLEN];

    printf("String 1: "); scanf("%s", str1);
    printf("String 2: "); scanf("%s", str2);

    if (anagram(str1, str2) == 1) {
        printf("Strings are anagrams of each other.");
    }
    else {
        printf("Strings are not anagrams.");
    }
}


/*
    Determines whether a string is an anagram of another string.
    Returns 1 if anagram, else 0.
*/
int anagram(char* firstStr, char* secondStr) {
    // change strings to lower-case
    tolower(firstStr);
    tolower(secondStr);

    // sort character arrays
    quickSort(firstStr, strlen(firstStr));
    quickSort(secondStr, strlen(secondStr));

    // compare sorted strings using strcmp() from string.h
    // strcmp() returns 0 if strings are equal, but according to the task 
    // we have to return 1 if they are anagrams of each other.
    return strcmp(firstStr, secondStr) == 0 ? 1 : 0;
}


/*
    Sorts a given vector using the quicksort algorithm (recursive function).
    Sorting is in-place.
*/
void quickSort(char* x, int n) {
    if (n <= 1) return;                     // only continue if element count > 1

    int j, k;
    char temp;
    for (j = 0, k = 1; k < n; ++k) {
        if (x[k] < x[0]) {                  // compare to pivot, swap values
            ++j;
            if (k == j) continue;
            temp = x[j];
            x[j] = x[k];
            x[k] = temp;
        }
    }

    // swap pivot and last lesser element
    if (j > 0) {
        temp = x[j];
        x[j] = x[0];
        x[0] = temp;
    }

    quickSort(x, j++);          // sort lesser part
    quickSort(x + j, n - j);    // sort greater part; x + j is a pointer to the first greater element
}

/*
    Changes all upper-case characters to lower-case.
*/
void tolower(char* str) {
    int i;
    for (i = 0; i < strlen(str); ++i) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
}