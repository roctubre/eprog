#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isPalindrome(string);

int main(int argc, char *argv[]) {
	string word;
	
	// get input from from arguments or from user input
	if (argc > 1) {
		word = argv[1];
	}
	else {
		cout << "Enter word: ";
		cin >> word;
	}
	
	// check word if palindrome
	if (isPalindrome(word)) {
        cout << "Is palindrome." << endl;
    }
    else {
        cout << "Is NOT palindrome." << endl;
    }
}

/*
	Check if a given string is a palindrome.
	A palindrome is a word, which when read forward and backward, are spelled the same.
*/
bool isPalindrome(string word) {
    for (int i = 0; i < (int)word.length() / 2; ++i) {
        if (word[i] != word[((int)word.length() - 1) - i]) {
            return false;
        }
    }
    return true;
}