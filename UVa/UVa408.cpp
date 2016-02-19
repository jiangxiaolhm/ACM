#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b) {
	int r = a % b;
	if (r == 0)
		return b;
	else {
		a = b;
		b = r;
		gcd(a,b);
	}
}
int main() {
	int a;
	int b;
	int ans;
	while (cin >> a >> b) {
		if (a > b)
			ans = gcd(a,b);
		else
			ans = gcd(b,a);
		printf("%10d%10d",a,b);
		if (ans == 1)
			cout << "    Good Choice" << endl;
		else
			cout << "    Bad Choice" << endl;
		cout << endl;
	}
}
