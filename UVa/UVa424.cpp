#include <iostream>
#include <cstring>
using namespace std;

const int N = 150;

int main() {
	char temporary[N];
	int interger[N];
	int sum[N];
	memset(temporary,0,sizeof(temporary));
	memset(sum,0,sizeof(sum));
	while (cin >> temporary) {
		if (!strcmp(temporary,"0"))
			break;
		int lengthOftemporary = strlen(temporary);
		for (int i = 0,j = lengthOftemporary-1; j >= 0; i++,j--)
			interger[i] = temporary[j] - '0';
		for (int i = 0; i < lengthOftemporary; i++) {
			sum[i] += interger[i];
			if (sum[i] > 9) {
				sum[i+1] += sum[i] / 10;
				sum[i] %= 10;
			}
		}
		memset(temporary,0,sizeof(temporary));
		memset(interger,0,sizeof(interger));
	}
	int lengthOfSum = N;
	for (int i = N-1; i >= 0 && !sum[i]; i--)
		lengthOfSum = i;
	for (int i = lengthOfSum-1; i >= 0; i--)
		cout << sum[i];
	if (lengthOfSum == 0)
		cout << '0';
	cout << endl;
	return 0;
}
