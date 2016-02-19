#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const char l[4] = {' ','.','x','W'};

int main() {
	int a[42];
	int b[10];
	int t[42];
	int Case;
	cin >> Case;
	while (Case--) {
		memset(a,0,sizeof(a));
		a[20] = 1;
		for (int i = 0; i < 10 ; i++)
			cin >> b[i];
		for (int i = 1; i <= 40; i++)
			cout << l[a[i]];
		cout << endl;
		for (int i = 0; i < 42; i++)
			t[i] = a[i];
		for (int i = 1; i < 50; i++) {
			for (int j = 1; j <= 40; j++) {
				a[j] = b[t[j-1]+t[j]+t[j+1]];
				cout << l[a[j]];
			}
			cout << endl;
			for (int j = 1; j <= 40; j++)
				t[j] = a[j];
		}
		if (Case)
			cout << endl;
	}
	return 0;
}
