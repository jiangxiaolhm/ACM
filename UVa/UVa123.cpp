#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

char ignore[60][20];
char title[210][10010];
struct Keyword {
	char keyword[20];
	int origin_1;
	int origin_2;
}k[10010];

bool IsIgnored(char *tmp,char ignore[][20],int t) {
	for (int i = 0; i < t; i++)
		if (!strcmp(tmp,ignore[i]))
			return true;
	return false;
}

bool cmp(Keyword a,Keyword b) {
	if (!strcmp(a.keyword,b.keyword))
		if (a.origin_1 == b.origin_1)
			return a.origin_2 < b.origin_2;
		else
			return a.origin_1 < b.origin_1;
	else
		return strcmp(a.keyword,b.keyword) < 0;
}

int main() {
	memset(ignore,0,sizeof(ignore));
	memset(title,0,sizeof(title));
	memset(k,0,sizeof(k));
	int t_1 = 0;		//the number of ignored words.
	while (cin >> ignore[t_1]) {
		if (ignore[t_1][0] == ':' && ignore[t_1][1] == ':')
			break;
		t_1++;
	}

	int t_2 = 0;		//the number of titles.
	char tmp_1[10010];	//temporary titles.
	getchar();
	while (gets(tmp_1)) {
		//if (tmp_1[0] == ':')	////
		//	break;				////
		int len_1 = strlen(tmp_1);
		for (int i = 0; i < len_1; i++)
			if (isupper(tmp_1[i]))
				tmp_1[i] = tolower(tmp_1[i]);
		strcpy(title[t_2],tmp_1);
		t_2++;
	}
	char tmp_2[20];		//temporary keywords.
	int len_2 = 0;		//the length of temporary keywords.
	int t_3 = 0;		//the number of keywords.
	memset(tmp_2,0,sizeof(tmp_2));
	for (int i = 0; i < t_2; i++) {
		int cnt = true;
		int len_3 = strlen(title[i]);
		for (int j = 0; j < len_3; j++) {
			if (isalpha(title[i][j])) {
				tmp_2[len_2] = title[i][j];
				len_2++;
				cnt = true;
			}
			else if (cnt){
				if (!IsIgnored(tmp_2,ignore,t_1)) {
					strcpy(k[t_3].keyword,tmp_2);
					k[t_3].origin_1 = i;
					k[t_3].origin_2 = j - len_2;
					t_3++;
				}
				memset(tmp_2,0,sizeof(tmp_2));
				len_2 = 0;
				cnt = false;
			}
		}
		if (cnt) {
			if (tmp_2[0] != '\0') {
				if (!IsIgnored(tmp_2,ignore,t_1)) {
					strcpy(k[t_3].keyword,tmp_2);
					k[t_3].origin_1 = i;
					k[t_3].origin_2 = len_3 - len_2;
					t_3++;
				}
				memset(tmp_2,0,sizeof(tmp_2));
				len_2 = 0;
			}
		}
	}

	sort(k,k+t_3,cmp);

	for (int i = 0; i < t_3; i++) {
		for (int j = 0; j < k[i].origin_2; j++)
			cout << title[k[i].origin_1][j];
		for (int j = k[i].origin_2; j < k[i].origin_2 + strlen(k[i].keyword); j++)
			printf("%c",toupper(title[k[i].origin_1][j]));
		for (int j = k[i].origin_2 + strlen(k[i].keyword); j < strlen(title[k[i].origin_1]); j++)
			cout << title[k[i].origin_1][j];
		cout << endl;
	}

	//for (int i = 0; i < t_3; i++)
	//	cout << k[i].keyword << " " << k[i].origin_1 << " " << k[i].origin_2 << endl;
	return 0;
}
