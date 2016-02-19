#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 20005;
int n;
int m;
int sum;
int a[MAX+1];
int b[MAX+1];
int main(){
	while (cin >> n >> m){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		sum = 0;
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1,a+1+n);

		for (int i = 1; i <= m; i++){
			cin >> b[i];
		}
		sort(b+1,b+1+m);

		bool tmp = true;
		int pos = 0;
		for (int i = 1; i <= n; i++){
			for (int j = pos+1; j <= m; j++){
				if (b[j] >= a[i]){
					sum += b[j];
					a[i] = -1;
					b[j] = 0;
					pos = j;
					break;
				}
			}
			if (a[i] > 0){
				cout << "Loowater is doomed!" << endl;
				tmp = false;
				break;
			}
		}
		if (tmp)
			cout << sum << endl;
	}
	return 0;
}
