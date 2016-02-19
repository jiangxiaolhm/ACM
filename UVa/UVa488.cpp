#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int a;
		int b;
		cin >> a >> b;
		while (b--) {
			for (int i = 1; i <= a; i++) {
				for (int j = 1; j <= i; j++) {
					cout << i;
				}
				cout << endl;
			}
			for (int i = a-1; i > 0; i--) {
				for (int j = i; j > 0; j--) {
					cout << i;
				}
				cout << endl;
			}
			if (b)
				cout << endl;
		}
		if (Case)
			cout << endl;
	}
	return 0;
}
