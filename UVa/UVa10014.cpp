/*
	Problem ID: UVa10014
	Problem Name: Simple calculations
	Author: Hongming Lin
	Description:
		This problem is a mathematical problem. I need to derivate the a1 using the given expression.
		a1 = (a0 + a2) / 2 - c1
		...
		ai = (a(i-1) + a(i+1)) / 2 - ci
		Add above i expressions, then
		a1 + ai = a0 + a(i+1) - 2 * (c1 + .. + ci)
		...
		a1 + a1 = a0 + a2 - 2 * (c1)
		Add above i expressions again, then
		a1 = (n * a0 + a(n+1) - 2 * (n * c1 + (n - 1) * c2 + ... + cn) / (n + 1)

		ps. I omitted some steps during the derivation.
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {

	int n;
	// a0
	double a;
	// an+1
	double b;
	// c1, c2,..., cn
	double c[3000];

	int cases;

	cin >> cases;

	while (cases--) {
		cin >> n >> a >> b;

		// sum of c sequence
		double sum = 0;
		// from c1 to cn
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			sum += (n - i) * c[i];
		}
		
		double result = 0;
		result = (n * a + b - 2 * sum) / (n + 1);
		
		printf("%.2f\n", result);
		if (cases)
			cout << endl;
	}

	return 0;
}