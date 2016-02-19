#include<iostream>
#include<cstring>
using namespace std;

const int N = 202;
int n;
int m;
int graph[N][N];
int degree[N];
int father[N];

void initialize(){
	for (int i = 0; i < n; i++)
		father[i] = i;
}

int ancestor(int x){
	return father[x] == x?x:father[x] = ancestor(father[x]);
}

bool union_find_sets(){
	initialize();
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			if (graph[i][j]){
				int ai = ancestor(i);
				int aj = ancestor(j);
				if (ai != aj)
					father[ai] = aj;
			}
		}
	}

	int ff = ancestor(0);
	for (int i = 1; i < n; i++){
		if (father[i] != ff)
			return false;
	}
	return true;
}

bool euler(){
	for (int i = 0; i < n; i++){
		if (degree[i] % 2)
			return false;
	}
	return true;
}

int main(){
	while (cin >> n >> m){
		memset(graph,0,sizeof(graph));
		memset(degree,0,sizeof(degree));
		for (int i = 0; i < n; i++)
			graph[i][i] = 1;

		int x;
		int y;
		for (int i = 0; i < m; i++){
			cin >> x >> y;
			graph[x][y]++;
			graph[y][x]++;
			degree[x]++;
			degree[y]++;
		}
		if (union_find_sets() && euler())
			cout << "Possible" << endl;
		else
			cout << "Not Possible" << endl;
	}
	return 0;
}
