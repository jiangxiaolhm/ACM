#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num;
	int order;
	int p;
	int q;
	while (cin >> num) {
		if (num == 0)
			break;
		num--;
		order = (int)pow(num,0.5);
		p = num - order * order + 1;
		q = (order + 1) * (order + 1) - num;
		if (order % 2)
			if (p < q)
				cout << p << " " << order+1 << endl;
			else
				cout << order+1 << " " << q << endl;
		else
			if (p < q)
				cout << order+1 << " " << p << endl;
			else
				cout << q << " " << order+1 << endl;
	}
	return 0;
}
