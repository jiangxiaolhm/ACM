#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 100;
const int INF = 1 << 29;

int main() {
	int Case;
	char str[N];
	int num[N];
	while (cin >> Case) {
		if (!Case)
			break;
		memset(num,0,sizeof(num));
		int min = INF;
		int ans = 0;
		getchar();
		for (int i = 0; i < Case; i++) {
			gets(str);
			for (int j = 0; j < N && str[j]; j++) {
				if (str[j] == ' ')
					num[i]++;
			}
			if (min > num[i])
				min = num[i];
		}
		for (int i = 0; i < Case; i++) {
			if (num[i] > min)
				ans += num[i] - min;
		}
		cout << ans << endl;
	}
	return 0;
}
