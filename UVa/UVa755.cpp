#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
using namespace std;

const int N = 10000000;
const int L = 100;
const int l[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int times[N];

int main() {
	int Case;		//////
	cin >> Case;	//////
	cout << endl;	//////
	while (Case--) {
		memset(times,0,sizeof(times));
		int Test;
		int tmp;
		char str[L];
		bool cnt = false;
		cin >> Test;
		getchar();
		while (Test--) {
			memset(str,0,sizeof(str));
			tmp = 0;
			gets(str);
			for (int i = 0,j = 6; i < L && j >= 0; i++) {
				if (isupper(str[i])) {
					tmp += l[str[i]-'A'] * (int)pow(10,j);
					j--;
				}
				else if (isdigit(str[i])) {
					tmp += (str[i] - '0') * (int)pow(10,j);
					j--;
				}
			}
			times[tmp]++;
			if (times[tmp] > 1)
				cnt = true;
		}
		if (cnt)
			for (int i = 0; i < N; i++)
				if (times[i] > 1)
					printf("%03d-%04d %d\n",i/10000,i%10000,times[i]);
		else
			cout << "No duplicates." << endl;
	}	//////
	return 0;
}
