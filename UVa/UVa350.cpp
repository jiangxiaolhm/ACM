#include <iostream>
#include <cstring>
using namespace std;

const int N = 100000;

int s[N];

int main() {
	int Z,I,M,L;
	int cnt = 0;
	while (cin >> Z >> I >> M >> L) {
		if (Z + I + M + L == 0)
			break;
		cnt++;
		memset(s,0,sizeof(s));
		s[L] = 1;
		int t = 1;
		while (1) {
			L = (Z * L + I) % M;
			if (s[L])
				break;
			t++;
			s[L] = t;
		} 	
		cout << "Case " << cnt << ": " << ++t-s[L] << endl;
	}
	return 0;
}
