#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int d = '*' - '1';
	char s[100];
	while (gets(s)) {
		for (int i = 0; i < 100 && s[i]; i++)
			printf("%c",s[i]+d);
		cout << endl;
	}
	return 0;
}
