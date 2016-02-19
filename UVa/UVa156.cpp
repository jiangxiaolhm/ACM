#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const int N = 100;
const int L = 30;

struct Node1 {
	char s_1[L];
	char s_2[L];
	bool flag;
}a[N];

bool cmp1(Node1 a,Node1 b) {
	return strcmp(a.s_2,b.s_2) < 0;
}

bool cmp2(Node1 a,Node1 b) {
	return strcmp(a.s_1,b.s_1) < 0;
}

int main() {
	char tmp[L];
	int t = 0;
	int len;
	memset(a,0,sizeof(a));
	while ((cin >> tmp) && tmp[0] != '#') {
		strcpy(a[t].s_1,tmp);
		len = strlen(tmp);
		for (int i = 0; i < len; i++)
			if (isupper(tmp[i]))
				tmp[i] = tolower(tmp[i]);
		sort(tmp,tmp+len);
		strcpy(a[t].s_2,tmp);
		t++;
	}
	sort(a,a+t,cmp1);
	//for (int i = 0; i < t; i++)
	//	cout << a[i].s_1 << " " << a[i].s_2 << endl;
	
	if (strcmp(a[0].s_2,a[1].s_2))
		a[0].flag = true;
	for (int i = 1; i < t-1; i++)
		if (strcmp(a[i].s_2,a[i-1].s_2) && strcmp(a[i].s_2,a[i+1].s_2))
			a[i].flag = true;
	if (strcmp(a[t-1].s_2,a[t-2].s_2))
		a[t-1].flag = true;
	sort(a,a+t,cmp2);
	for (int i = 0; i < t; i++) {
		if (a[i].flag)
			cout << a[i].s_1 << endl;
	}
	return 0;
}
