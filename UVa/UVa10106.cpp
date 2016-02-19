#include <iostream>
#include <cstring>
using namespace std;

const int N = 255;

char temporaryA[N];
char temporaryB[N];
int factorA[N];
int factorB[N];
int product[2*N];

void initialize() {
	memset(temporaryA,0,sizeof(temporaryA));
	memset(temporaryB,0,sizeof(temporaryB));
	memset(factorA,0,sizeof(factorA));
	memset(factorB,0,sizeof(factorB));
	memset(product,0,sizeof(product));
}

int main() {
	initialize();
	while (cin >> temporaryA >> temporaryB) {
		int lengthOftemporaryA = strlen(temporaryA);
		int lengthOftemporaryB = strlen(temporaryB);
		for (int i = 0,j = lengthOftemporaryA-1; j >= 0; i++,j--)
			factorA[i] = temporaryA[j] - '0';
		for (int i = 0,j = lengthOftemporaryB-1; j >= 0; i++,j--)
			factorB[i] = temporaryB[j] - '0';
		for (int i = 0; i < lengthOftemporaryA; i++) {
			for (int j = 0; j < lengthOftemporaryB; j++) {
				product[i+j] += factorA[i] * factorB[j];
				if (product[i+j] > 9) {
					product[i+j+1] += product[i+j] / 10;
					product[i+j] %= 10;
				}
			}
		}
		int lengthOfProduct = 2*N;
		for (int i = 2*N-1; i >= 0 && !product[i]; i--)
			lengthOfProduct = i;
		if (!lengthOfProduct)
			cout << "0";
		for (int i = lengthOfProduct-1; i >= 0; i--)
			cout << product[i];
		cout << endl;
		initialize();
	}

	return 0;
}
