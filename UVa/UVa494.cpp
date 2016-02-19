#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

const int N = 10000;

int main() {
	char s[N];
	while (gets(s)) {
		int num = 0;
		bool cnt = true;
		for (int i = 0; i < N && s[i]; i++) {
			if (isalpha(s[i])) {
				if (cnt) {
					cnt = false;
					num++;
				}
			}
			else {
				cnt = true;
			}
		}
		cout << num << endl;
	}
	return 0;
}
