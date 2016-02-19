#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int Case;
	int number;
	int a[2];
	int b[2];
	cin >> Case;
	for (int i = 1; i <= Case; i++) {
		cin >> number;
		int t = 0;
		for (int j = 2; j <= (int)sqrt(number); j++) {
			if (number % j == 0) {
				a[t] = j;
				b[t] = number / j;
				t++;
				if (t == 2)
					break;
			}
		}
		cout << "Case #" << i << ": " << number << " = " << a[0] << " * " << b[0] << " = " << a[1] << " * " << b[1] << endl;
	}
	return 0;
}
