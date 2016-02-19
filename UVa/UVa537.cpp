#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
using namespace std;

const int N = 1000;

char str[N];

double get_value(char *str,int j) {
	int i = j;
	int d_n = 0;
	int t = 0;
	int len_s = strlen(str);
	double f = 1;
	char tmp[100];
	bool dot = false;
	memset(tmp,0,sizeof(tmp));
	
	for (; i < len_s; i++) {
		if (isdigit(str[i])) {
			tmp[t++] = str[i];
			if (dot)
				d_n++;
		}
		else if (str[i] == '.')
			dot = true;
		else {
			if (str[i] == 'm')
				f = 0.001;
			else if (str[i] == 'k')
				f = 1000;
			else if (str[i] == 'M')
				f = 1000000;
			break;
		}
	}

	int len_t = strlen(tmp);
	double sum = 0;
	for (int i = 0; i < len_t; i++)
		sum += (tmp[i] - '0') * pow(10,len_t-i-1);

	return sum * f / pow(10,d_n);
}

int main() {
	int Case;
	cin >> Case;
	getchar();

	for (int i = 1; i <= Case; i++) {
		memset(str,0,sizeof(str));
		double P = 0;
		double U = 0;
		double I = 0;
		gets(str);
		int len = strlen(str);

		for (int j = 0; j < len-1; j++) {
			if (str[j+1] == '=') {
				if (str[j] == 'P')
					P = get_value(str,j+2);
				else if (str[j] == 'U')
					U = get_value(str,j+2);
				else if (str[j] == 'I')
					I = get_value(str,j+2);
			}
		}
		
		printf("Problem #%d\n",i);
		//cout << P << endl;
		//cout << U << endl;
		//cout << I << endl;
		if (P && U)
			printf("I=%.2lfA\n",P/U);
		else if (U && I)
			printf("P=%.2lfW\n",U*I);
		else if (I && P)
			printf("U=%.2lfV\n",P/I);
		cout << endl;
	}
	return 0;
}
