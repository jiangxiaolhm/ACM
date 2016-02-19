#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 25;
char s[N];

int main(){
	int t;
	cin >> t;
	while (t--){
		memset(s,0,sizeof(s));
		int n;
		int h;
		cin >> n;
		cin >> h;
		for (int i = 0; i < n-h; i++)
			s[i] = '0';
		for (int i = n-h; i < n; i++)
			s[i] = '1';
		cout << s << endl;
		while (next_permutation(s,s+n))
			cout << s << endl;
		if (t > 0)
			cout << endl;
	}
}
