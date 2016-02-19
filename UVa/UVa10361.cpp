#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110;

char s_1[N];
char s_2[N];
char s_3[N];
char s_4[N];
char s_5[N];
char s_6[N];
char tmp[N];

void initialize() {
	memset(s_1,0,sizeof(s_1));
	memset(s_2,0,sizeof(s_2));
	memset(s_3,0,sizeof(s_3));
	memset(s_4,0,sizeof(s_4));
	memset(s_5,0,sizeof(s_5));
	memset(s_6,0,sizeof(s_6));
	memset(tmp,0,sizeof(tmp));
}

int main() {
	int Case;
	cin >> Case;
	getchar();
	while (Case--) {
		initialize();
		gets(tmp);
		int len = strlen(tmp);
		int l_1 = 0;
		int i = 0;
		for (i = 0; i < len; i++) {
			if (tmp[i] != '<')
				s_1[l_1++] = tmp[i];
			else
				break;
		}
		int l_2 = 0;
		for (i = i+1; i < len; i++) {
			if (tmp[i] != '>')
				s_2[l_2++] = tmp[i];
			else
				break;
		}
		int l_3 = 0;
		for (i = i+1; i < len; i++) {
			if (tmp[i] != '<')
				s_3[l_3++] = tmp[i];
			else
				break;
		}
		int l_4 = 0;
		for (i = i+1; i < len; i++) {
			if (tmp[i] != '>')
				s_4[l_4++] = tmp[i];
			else
				break;
		}
		int l_5 = 0;
		for (i = i+1; i < len; i++)
			s_5[l_5++] = tmp[i];
		cout << s_1 << s_2 << s_3 << s_4 << s_5 << endl;
		
		gets(s_6);
		int l_6 = strlen(s_6);
		for (int i = 0; i < l_6 - 3; i++)
			cout << s_6[i];
		cout << s_4 << s_3 << s_2 << s_5 << endl;
	}
	return 0;
}
