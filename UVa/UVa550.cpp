#include <iostream>
using namespace std;

int main() {
	int system,last,factor;

	while (cin >> system >> last >> factor) {
		int tmp = factor * last;
		int cnt = 1;
		while (1) {
			if (last == tmp)
				break;
			tmp = tmp % system * factor + tmp / system;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
