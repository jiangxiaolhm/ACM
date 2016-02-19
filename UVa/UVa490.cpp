#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 200;

int main() {
	char str[N][N];
	int t = 0;
	int len = 0;
	while (gets(str[t])) {
		int t_len = strlen(str[t]);
		len = max(len,t_len);
		t++;
	}
	for (int i = 0; i < len; i++) {
		for (int j = t-1; j >= 0; j--) {
			if (str[j][i])
				cout << str[j][i];
			else
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
