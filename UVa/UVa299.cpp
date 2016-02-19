#include <iostream>
#include <cstring>
using namespace std;

const int N = 60;

int num[N];
int cnt;

void my_sort(int *str,int len) {
	bool tmp = true;

	while (1) {
		for (int i = 0; i < len-1; i++) {
			if (str[i] > str[i+1])
				tmp = false;
		}
		if (tmp)
			break;
		for (int i = 0; i < len-1; i++) {
			if (str[i] > str[i+1]) {
				cnt++;
				str[i] = str[i] + str[i+1];
				str[i+1] = str[i] - str[i+1];
				str[i] = str[i] - str[i+1];
			}
		}
		tmp = true;
	}
}

int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int Test;
		cin >> Test;
		memset(num,0,sizeof(num));
		cnt = 0;
		for (int i = 0; i < Test; i++)
			cin >> num[i];

		my_sort(num,Test);

		cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
	}
	return 0;
}
