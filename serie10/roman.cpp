#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string int2roman(int n);
int roman2int(string s);

int main(int argc, char *argv[])
{
	if (argc == 2) {
		int z = std::stoi(argv[1]);
		assert(z >= 0 && z <= 3999);
		cout << "Converting to roman..." << endl;
		cout << int2roman(z) << endl;
		cout << "and back to decimal ..." << endl;
		cout << roman2int(int2roman(z)) << endl;
	}
	else {
		cout << "Usage: " << argv[0] << " <0-3999>" << endl;
	}

}

/*
    Converts a decimal number to its roman representation.
*/
string int2roman(int n) {
    string rom;

    string m[] = { "", "M", "MM", "MMM" };
    string c[] = { "", "C", "CC", "CCC", "CD", "D",
                        "DC", "DCC", "DCCC", "CM" };
    string x[] = { "", "X", "XX", "XXX", "XL", "L",
                        "LX", "LXX", "LXXX", "XC" };
    string i[] = { "", "I", "II", "III", "IV", "V",
                        "VI", "VII", "VIII", "IX" };

    string thousands = m[n / 1000];
    string hundereds = c[(n % 1000) / 100];
    string tens = x[(n % 100) / 10];
    string ones = i[n % 10];

    rom = thousands + hundereds + tens + ones;
    return rom;
}

/*
    Converts a roman number to its decimal representation.
*/
int roman2int(string s) {
    int total = 0;
    const char* letters = s.c_str();
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'I') {
            if (i < len && letters[i + 1] == 'V') {
                total += 4;
                ++i;
            }
            else if (i < len && letters[i + 1] == 'X') {
                total += 9;
                ++i;
            }
            else {
                total += 1;
            }
        }
        else if (s[i] == 'V') {
            total += 5;
        }
        else if (s[i] == 'X') {
            if (i < len && letters[i + 1] == 'L') {
                total += 40;
                ++i;
            }
            else if (i < len && letters[i + 1] == 'C') {
                total += 90;
                ++i;
            }
            else {
                total += 10;
            }
        }
        else if (s[i] == 'L') {
            total += 50;
        }
        else if (s[i] == 'C') {
            if (i < len && letters[i + 1] == 'D') {
                total += 400;
                ++i;
            }
            else if (i < len && letters[i + 1] == 'M') {
                total += 900;
                ++i;
            }
            else {
                total += 100;
            }
        }
        else if (s[i] == 'D') {
            total += 500;
        }
        else if (s[i] == 'M') {
            total += 1000;
        }
    }

    return total;
}