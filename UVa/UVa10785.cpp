#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const char vowel[5] = {'A','U','E','O','I'};
const char consonant[21] = {'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};

int main() {
	char ans_v[200];
	char ans_c[200];
	int Case;
	cin >> Case;
	for (int i = 0; i < Case; i++) {
		memset(ans_v,0,sizeof(ans_v));
		memset(ans_c,0,sizeof(ans_c));
		int num;		//number
		int v = 0;		//the v'th vowel
		int n_v = 0;	//the times of the v'th vowel
		int c = 0;		//the c'th consonant
		int n_c = 0;	//the times of the c'th consonant
		cin >> num;
		cout << "Case " << i+1 << ": ";
		for (int j = 0; j < num; j++) {
			if (j % 2 == 0) {
				ans_v[n_v] = vowel[v];
				n_v++;
				if (n_v % 21 == 0) {
					v++;
				}
			}
			else {
				ans_c[n_c] = consonant[c];
				n_c++;
				if (n_c % 5 == 0) {
					c++;
				}
			}
		}
		sort(ans_v,ans_v+n_v);
		sort(ans_c,ans_c+n_c);
		for (int j = 0; j < num; j++) {
			if (j % 2 == 0)
				cout << ans_v[j/2];
			else
				cout << ans_c[j/2];
		}
		cout << endl;
	}
	return 0;
}
