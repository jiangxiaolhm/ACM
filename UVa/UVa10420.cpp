#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 2100;
const int M = 100;

char s[N][M];
char t[M];
int num[N];

int cmp(const void *a, const void *b) {
	return strcmp((char*)a,(char*)b);
}

int main() {
	int Case;
	
	while (cin >> Case) {
		memset(num,0,sizeof(num));
		getchar();
		for (int i = 0; i < Case; i++) {
			memset(t,0,sizeof(t));
			gets(t);
			for (int j = 0; j < M; j++) {
				if (t[j] != ' ')
					s[i][j] = t[j];
				else
					break;
			}
		}

		qsort(s,Case,sizeof(s[0]),cmp);
	
		int p = 0;
		num[p]++;
		for (int i = 1; i < Case; i++) {
			if (strcmp(s[i],s[i-1]) == 0) {
				num[p]++;
				if (i == Case-1)
					cout << s[i] << " " << num[p] << endl;
			}
			else {
				cout << s[i-1] << " " << num[p] << endl;
				p++;
				num[p]++;
				if (i == Case-1)
					cout << s[i] << " " << num[p] << endl;
			}
		}
	}
	return 0;
}
