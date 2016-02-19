#include<iostream>
#include<cstdlib>
using namespace std;

const int N = 10000;
int s[N];
int p;

int cmp(const void *a,const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n;
	int q;
	int num = 1;
	while (cin >> n >> q){
		if (!n && !q)
			break;
		int i;
		int j;
		int s_len;
		for (i = 0; i < n; i++)
			cin >> s[i];
		s_len = i;
		cout << "CASE# " << num << ":" << endl;
		num++;
		qsort(s,s_len,sizeof(int),cmp);
		for (i = 0; i < q; i++) {
			cin >> p;
			for (j = 0; j < n; j++){
				if (p == s[j]){
					cout << p << " found at " << j+1 << endl;
					break;
				}
			}
			if (j == n)
				cout << p << " not found" << endl;
		}
	}
	return 0;
}
