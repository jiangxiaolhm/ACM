#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n;
	long long i;
	while (cin >> n) {
		if (n == 0)
			break;
		i = (int)sqrt(n);
		if (i == sqrt(n))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
