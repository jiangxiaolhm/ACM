#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
using namespace std;

const int dx[8] = {0,1,1,1,0,-1,-1,-1};
const int dy[8] = {1,1,0,-1,-1,-1,0,1};
const int N = 60;

char str[N][N];
char tmp[N];

bool judge(char (*str)[N],char *tmp,int x,int y,int pos,int len,int k);
void position(char (*str)[N],char *tmp,const int &row,const int &col) {
	int len = strlen(tmp);
	int pos = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int pos = 0;
			if (tmp[pos] == str[i][j]) {
				pos++;
				if (pos == len) {
					cout << i+1 << " " << j+1 << endl;
					return;
				}
				for (int k = 0; k < 8; k++) {
					if (tmp[pos] == str[i+dx[k]][j+dy[k]]) {
						if (judge(str,tmp,i+dx[k],j+dy[k],pos+1,len,k)) {
							cout << i+1 << " " << j+1 << endl;
							return;
						}
					}
				}
			}
		}
	}
}

bool judge(char (*str)[N],char *tmp,int x,int y,int pos,int len,int k) {
	if (pos == len) {
		return true;
	}
	else if (tmp[pos] == str[x+dx[k]][y+dy[k]]) {
		pos++;
		return judge(str,tmp,x+dx[k],y+dy[k],pos,len,k);
	}
	else {
		return false;
	}
}

int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int row;
		int col;
		cin >> row;
		cin >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> str[i][j];
				if (isupper(str[i][j])) {
					str[i][j] = tolower(str[i][j]);
				}
			}
		}
		int Test;
		cin >> Test;
		getchar();
		for (int i = 0; i < Test; i++) {
			gets(tmp);
			for (int j = 0; tmp[j] && j < N; j++) {
				if (isupper(tmp[j])) {
					tmp[j] = tolower(tmp[j]);
				}
			}
			position(str,tmp,row,col);
			memset(tmp,0,sizeof(tmp));
		}
		if (Case)
			cout << endl;
	}
	return 0;
}
