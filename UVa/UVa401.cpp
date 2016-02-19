#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

const char letter[27] = {"A   3  HIL JM O   2TUVWXY5"};
const char digit[11] = {"01SE Z  8 "};
const int N = 30;

bool isPalindrome(char *str,int len) {
	for (int i = 0,j = len-1; i <= j; i++,j--)
		if (str[i] != str[j])
			return false;
	return true;
}

bool isMirrored(char *str,int len) {
	if (len % 2) {
		if (isupper(str[len/2]) && letter[str[len/2]-'A'] == ' ')
			return false;
		else if (isdigit(str[len/2]) && digit[str[len/2]-'0'] == ' ')
			return false;
	}
	for (int i = 0; i < len/2; i++) {
		if (isupper(str[i]))
			str[i] = letter[str[i]-'A'];
		else if (isdigit(str[i]))
			str[i] = digit[str[i]-'0'];
	}
	return isPalindrome(str,len);
}

int main() {
	char str[N];
	bool p;
	bool m;
	while (cin >> str) {
		int len = strlen(str);
		cout << str;
		p = isPalindrome(str,len);
		m = isMirrored(str,len);
		if (p)
			if (m)
				cout << " -- is a mirrored palindrome." << endl;
			else
				cout << " -- is a regular palindrome." << endl;
		else
			if (m)
				cout << " -- is a mirrored string." << endl;
			else
				cout << " -- is not a palindrome." << endl;
		cout << endl;
		memset(str,0,sizeof(str));
	}
	return 0;
}
