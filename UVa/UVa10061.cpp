#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000;

int s[N];
int f[N];
int n_f[N];

bool isprime(int a) {
	if (a == 2)
		return true;

	for (int i = 2; i <= sqrt(a); i++)
		if (a % i == 0)
			return false;
	return true;
}

double _logbn(double b,double n) {
	return log(n)/log(b);
}

int main() {
	int n;
	int b;
	int n_0;
	int n_d;
	while (cin >> n >> b) {
		memset(f,0,sizeof(f));
		memset(n_f,0,sizeof(n_f));
		int tmp_b;

		if (isprime(b))
			f[b]++;
		else {
			for (int i = 2; i <= b/2; i++) {
				tmp_b = b;
				if (isprime(i)) {
					while (tmp_b % i == 0) {
						f[i]++;
						tmp_b /= i;
					}
				}
			}
		}

		int tmp;
		for (int i = 1; i <= n; i++) {
			tmp = i;
			for (int j = 2; j <= b; j++) {
				if (f[j]) {
					while (tmp % j == 0) {
						n_f[j]++;
						tmp /= j;
					}
				}
			}
		}

		for (int i = 2; i <= b; i++) {
			if (f[i]) {
				n_f[i] /= f[i];
			}
		}
		
		n_0 = n;
		for (int i = 2; i <= b; i++) {
			if (f[i] && n_0 > n_f[i])
				n_0 = n_f[i];
		}

		double s = 0;
		for (int i = 1; i <= n; i++) {
			s += _logbn((double)b,(double)i);
		}
		n_d = (int)s + 1;

		cout << n_0 << " " << n_d << endl;
	}
	return 0;
}
