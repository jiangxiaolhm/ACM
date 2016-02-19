#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 300;
const int MAX = 50000;

char s_1[N];
char s_2[N];
char dic[MAX][N];

int cmp(const void *a,const void *b) {
	return strcmp((char*)a,(char*)b);
}

int main() {
	int tmp = 0;
	memset(dic,0,sizeof(dic));
	while (cin >> s_1) {
		int t = 0;
		int len = strlen(s_1);
		for (int i = 0; i < len; i++) {
			if (islower(s_1[i])) {
				s_2[t] = s_1[i];
				t++;
			}
			else if (isupper(s_1[i])) {
				s_2[t] = tolower(s_1[i]);
				t++;
			}
			else if (s_2[0]) {
				strcpy(dic[tmp],s_2);
				tmp++;
				t = 0;
				memset(s_2,0,sizeof(s_2));
			}
		}
		if (s_2[0]) {
			strcpy(dic[tmp],s_2);
			tmp++;
		}
		memset(s_1,0,sizeof(s_1));
		memset(s_2,0,sizeof(s_2));
	}
	qsort(dic,tmp,sizeof(char)*N,cmp);
	for (int i = 0; i < tmp; i++) {
		if (i > 0 && strcmp(dic[i],dic[i-1])==0)
			continue;
		cout << dic[i] << endl;	
	}
	return 0;
}
