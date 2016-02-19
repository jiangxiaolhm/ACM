#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	long long n;
	while (cin >> n) {
		int num2 = 0;
		int num5 = 0;
		int sum = 1;
		for (int i = 1; i <= n; i++) {
			int tmp = i;
			while (tmp % 2 == 0) {
				tmp /= 2;
				num2++;
			}
			while (tmp % 5 == 0) {
				tmp /= 5;
				num5++;
			}
			sum *= tmp;
			sum %= 10;
		}

		if (num2 > num5) {
			for (int i = 0; i < num2 - num5; i++) {
				sum *= 2;
				sum %= 10;
			}
		}
		if (num2 < num5) {
			for (int i = 0; i < num5 - num2; i++) {
				sum *= 5;
				sum %= 10;
			}
		}
		printf("%5lld -> %d\n",n,sum);
	}
	return 0;
}
