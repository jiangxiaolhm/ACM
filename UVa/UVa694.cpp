#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	long long number;
	long long limit;
	int Case = 1;
	while (cin >> number >> limit) {
		if (number < 0 && limit < 0)
			break;
		int current = 1;
		printf("Case %d: A = %lld, limit = %lld, number of terms = ",Case,number,limit);
		Case++;
		while (number > 1) {
			if (number % 2)
				number = number * 3 + 1;
			else
				number = number / 2;
			if (number > limit)
				break;
			current++;
		}
		cout << current << endl;
	}
	return 0;
}
