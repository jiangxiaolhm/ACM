#include<iostream>
#include<cstring>
using namespace std;

const int INF = 1<<29;
const int MAX = 500;
const int R = 100;
const int C = 50;
int N;
struct cherries{
	int x;
	int y;
}c[2*C];

struct slope{
	double k;
	int num;
}s[2*MAX][2*MAX];

void ini(){
	memset(c,0,sizeof(c));
	memset(s,0,sizeof(s));
}

bool find(int i,int j){
	for (int p = 0; p <= 2*MAX; p++){
		for (int q = 0; q <= 2*MAX; q++){
			if (s[p][q].sign && s[p][q].k == s[i][j].k){
				return true;
			}
		}
	}
	return false;
}

bool cut(int a,int b){
	for (int i = 0; i < 2*N; i++){
		if ((a-MAX)*c[i].x+(b-MAX)*c[i].y > 0)
			s[a][b].num++;
		else if ((a-MAX)*c[i].x+(b-MAX)*c[i].y < 0)
			s[a][b].num--;
		else if ((a-MAX)*c[i].x+(b-MAX)*c[i].y == 0)
			return false;
	}
	if (!s[a][b].num){
		cout << a-MAX << " " << b-MAX << endl;
		return true;
	}
	else
		return false;
}

int main(){
	while (cin >> N){
		if (N == 0)
			break;
		ini();
		for (int i = 0; i < 2*N; i++){
			cin >> c[i].x;
			cin >> c[i].y;
		}
		bool tmp = false;
		for (int i = 0; i <= 2*MAX; i++){
			for (int j = 0; j <= 2*MAX; j++){
				if (cut(i,j)){
					tmp = true;
					break;
				}
			}
			if (tmp)
				break;
		}
	}
	return 0;
}
