#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 20;
char s[N];
int main(){
	int n;
	cin >> n;
	while (n--){
		memset(s,0,sizeof(s));
		cin >> s;
		int len = strlen(s);
		sort(s,s+len);
		cout << s << endl;
		while (next_permutation(s,s+len)){
			cout << s << endl;
		}
		cout << endl;
	}
	return 0;
}
