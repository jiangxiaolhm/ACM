#include <iostream>
using namespace std;

int main() {
	long long x;
	long long y;
	while (cin >> x >> y) {
		if (x > y)
			cout << x-y << endl;
		else
			cout << y-x << endl;
	}
	return 0;
}
