#include<iostream>
#include<cstring>
using namespace std;

const int N = 102;
int g[N][N];
int c[N];
int topo[N];
int t;
int n,m;

bool dfs(int u){
	c[u] = -1;
	for (int v = 1; v <= n; v++){
		if (g[u][v]){
			if (c[v] < 0)
				return false;
			else if (!c[v] && !dfs(v))
				return false;
		}
	}
	c[u] = 1;
	topo[t] = u;
	t--;
	return true;
}

int main(){
	int x,y;
	while (cin >> n >> m){
		if (n == 0 && m == 0)
			break;

		memset(g,0,sizeof(g));
		memset(c,0,sizeof(c));

		for (int i = 0; i < m; i++){
			cin >> x >> y;
			g[x][y] = 1;
		}
		t = n - 1;

		for (int u = 1; u <= n; u++){
			if (!c[u]){
				dfs(u);
			}
		}

		for (int i = 0; i < n; i++){
			if (!i)
				cout << topo[i];
			else
				cout << " " << topo[i];
		}
		cout << endl;
	}
	return 0;
}
