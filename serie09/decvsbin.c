#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

char*   dec2bin     (int n);
int     bin2dec     (char* s);

int main() {
    int dec = 54321;                // 1101 0100 0011 0001
    char bin[] = "10100111001";     // 1337
    
    printf("Binary(%d): %s\n", dec, dec2bin(dec));
    printf("Decimal(%s): %d\n", bin, bin2dec(bin));
}


/*
    Converts a decimal number to its binary representation.
    Given a number n, it subtracts powers of 2 to determine binary values at a position.

    Example: n = 13
    13 >= 2^3, 13-2^3 = 5   ... 1
    5  >= 2^2,  5-2^2 = 1   ... 1
    1  <  2^1, do nothing   ... 0
    1  >= 2^0,  1-2^0 = 0   ... 1

    Binary(13) = 1101
*/
char* dec2bin (int n) {
    assert(n >= 0 && n <= 65535);

    char *bin = malloc(17*sizeof(char));    // max. 16 digits + null-byte
    int i, s;

    for (i = 0, s = 0; i < 16; ++i) {
        if (n >= pow(2, 15 - i)) {
            bin[s++] = '1';
            n -= pow(2, 15 - i);
        }
        else if (s != 0) {      // no leading 0s
            bin[s++] = '0';
        }
    }
    bin[s++] = '\0';
    bin = realloc(bin, s);    // adjust array size

    return bin;
}


/*
    Converts a binary number to its decimal representation.
    Given a binary number, it adds up powers of 2 according to positional 1s.

    Example: s = "1010"
    1 * 2^3 = 8
    0 * 2^2 = 0
    1 * 2^1 = 2
    0 * 2^0 = 0
    Add up 8+0+2+0 = 10

    Decimal("1010") = 10
*/
int bin2dec (char* s) {
    int dec = 0;
    int len = strlen(s);
    int i;

    for (i = 0; i < len; ++i) {
        if (s[i] == '1') {
            dec += pow(2, (len-1)-i);
        }
    }

    return dec;
}