#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 110;
const int L = 110;
const int S = 60;

int test;
int temp_l[N];
int length;
int row_n;
int col_n;
char str[N][L];

void initialize() {
	memset(str,0,sizeof(str));
	length = 0;
}

int compare(const void *a,const void *b) {
	return strcmp((char*)a,(char*)b);
}


int main() {
	while (cin >> test) {
		initialize();
		
		for (int i = 0; i < test; i++)
			cin >> str[i];

		qsort(str,test,sizeof(str[0]),compare);

		for (int i = 0; i < test; i++) {
			temp_l[i] = strlen(str[i]);
			if (length < temp_l[i])
				length = temp_l[i];
		}

		row_n = (S - length) / (length + 2) + 1;
		col_n = (test / row_n);
		if (test % row_n)
			col_n++;

		for (int i = 0; i < 60; i++)
			cout << "-";
		cout << endl;

		for (int i = 0; i < col_n; i++) {
			for (int j = 0; j < row_n; j++) {
				int tmp = i + j * col_n;
				cout << str[tmp];
				for (int k = temp_l[tmp]; k < length; k++) {
					cout << " ";
				}
				if (tmp+col_n >= test)
					break;
				if (j != row_n)
					cout << "  ";
			}
			cout << endl;
		}
	}	
	return 0;
}
