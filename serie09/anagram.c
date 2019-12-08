#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 256

int anagram(char* firstStr, char* secondStr);
int* char2int(char* input, int length);
char* int2char(int* input, int length);
void quickSort(int* x, int n);


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
    int len1 = strlen(firstStr);                        // length of firstStr
    int len2 = strlen(secondStr);                       // length of secondStr
    int* int_firstStr = char2int(firstStr, len1);       // convert firstStr to ASCII representation
    int* int_secondStr = char2int(secondStr, len2);     // convert secondStr to ASCII representation
    char* sorted_firstStr = NULL;                       // sorted characters of firstStr
    char* sorted_secondStr = NULL;                      // sorted characters of secondStr
    int result = 0;                                     // 0 = TRUE, else FALSE

    // sort ascii arrays
    quickSort(int_firstStr, len1);
    quickSort(int_secondStr, len2);
    
    // transform int arrays back to characters
    sorted_firstStr = int2char(int_firstStr, len1);
    sorted_secondStr = int2char(int_secondStr, len2);

    // compare strings using strcmp from string.h
    result = strcmp(sorted_firstStr, sorted_secondStr);

    // cleanup
    free(int_firstStr);
    free(int_secondStr);
    free(sorted_firstStr);
    free(sorted_secondStr);
    int_firstStr = NULL;
    int_secondStr = NULL;
    sorted_firstStr = NULL;
    sorted_secondStr = NULL;

    // strcmp returns 0 if strings are equal, but according to the task 
    // we have to return 1 if they are anagrams of each other.
    return result == 0 ? 1 : 0;
}

void printIntArray(int* array, int length) {
    assert(length > 0);
    int i;
    printf("{%d", array[0]);
    for (i = 1; i < length; ++i) {
        printf(", %d", array[i]);
    }
    printf("}\n");
}


/*
    Creates an integer array from a character array.
    Characters are typecasted into their respective decimal ASCII value.

    Note: Converts upper case characters to lower case.
*/
int* char2int(char* input, int length) {
    int* output = malloc(length*sizeof(int));
    int i;
    for (i = 0; i < length; ++i) {
        output[i] = (int)input[i];
        if (output[i] >= 65 && output[i] <= 90) {   // check if uppercase -> change to lower case
            output[i] += 32;
        }
    }

    return output;
}

/*
    Creates a character array from an integer array.
    Integers are typecasted into their respective character ASCII value.
*/
char* int2char(int* input, int length) {
    char* output = malloc((length+1)*sizeof(char));
    int i;
    for (i = 0; i < length; ++i) {
        output[i] = (int)input[i];
    }
    output[i] = '\0';   // null-byte to mark end of string
    return output;
}


/*
    Sorts a given vector using the quicksort algorithm (recursive function).
*/
void quickSort(int* x, int n) {
    if (n <= 1) return;                     // only continue if element count > 1

    int j, k;
    for (j = 0, k = 1; k < n; ++k) {
        if (x[k] < x[0]) {                  // compare to pivot, swap values
            ++j;
            if (k == j) continue;
            x[j] = x[j] + x[k];
            x[k] = x[j] - x[k];
            x[j] = x[j] - x[k];
        }
    }

    // swap pivot and last lesser element
    if (j > 0) {
        x[0] = x[0] + x[j];
        x[j] = x[0] - x[j];
        x[0] = x[0] - x[j];
    }

    quickSort(x, j++);          // sort lesser part
    quickSort(x + j, n - j);    // sort greater part; x + j is a pointer to the first greater element
}