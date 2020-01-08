#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tolower;

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
	A palindrome is a word, number, phrase, or other sequence of characters 
	which reads the same backward as forward.
*/
bool isPalindrome(string word) {
    for (int i = 0; i < (int)word.length() / 2; ++i) {
        if (tolower(word[i]) != tolower(word[((int)word.length() - 1) - i])) {
            return false;
        }
    }
    return true;
}
