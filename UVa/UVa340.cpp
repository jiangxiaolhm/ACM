#include <iostream>
#include <cstring>
using namespace std;

const int N = 1100;

int a[N];
int b[N];
bool c[N];

int main() {
	int len;
	int Case = 1;
	while (cin >> len) {
		if (!len)
			break;
		for (int i = 0; i < len; i++)
			cin >> a[i];
		bool t = true;
		while (1) {
			for (int j = 0; j < len; j++)
				cin >> b[j];
			if (!b[0])
				break;
			if (t) {
				cout << "Game " << Case << ":" << endl;
				Case++;
				t = false;
			}
			int x = 0;
			int y = 0;
			memset(c,true,sizeof(c));
			for (int j = 0; j < len; j++) {
				if (a[j] == b[j]) {
					b[j] = -1;
					c[j] = false;
					x++;
				}
			}
			for (int j = 0; j < len; j++) {
				if (c[j]) {
					for (int k = 0; k < len; k++) {
						if (a[j] == b[k]) {
							b[k] = -1;
							c[j] = false;
							y++;
						}
					}
				}
			}
			cout << "    (" << x << "," << y << ")" << endl;
		}
	}
	return 0;
}
