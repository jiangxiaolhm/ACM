#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 40;
int num[N];
char str[N];
int ans;

int main() {
	while (cin >> str) {
		if (strcmp(str,"0") == 0)
			break;
		ans = 0;
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			num[i] = str[len-i-1] - '0';
		for (int i = 0; i < len; i++) {
			ans += num[i] * (pow (2,i+1) - 1);
		}
		cout << ans << endl;
		memset(num,0,sizeof(num));
		memset(str,0,sizeof(str));
	}
	return 0;
}
