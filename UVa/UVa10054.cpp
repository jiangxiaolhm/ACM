#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 51;
int T;
int N;
int graph[MAX][MAX];
int degree[MAX];
int parent[MAX];
void initialize();
int ancestor(int x);
bool union_find_sets();
bool euler();
void display(int k);

void initialize(){
	for (int i = 1; i < MAX; i++){
		parent[i] = i;
	}
}

int ancestor(int x){
	return parent[x] == x?x:parent[x] = ancestor(parent[x]);
}

bool union_find_sets(){
	int ai;
	int aj;
	for (int i = 1; i < MAX; i++){
		for (int j = 1; j <= i; j++){
			if (graph[i][j]){
				ai = ancestor(i);
				aj = ancestor(j);
				if (ai != aj){
					parent[ai] = aj;
				}
			}
		}
	}
	
	int p = 0;
	for (int i = 1; i < MAX; i++){
		if (degree[i]){
			p = ancestor(i);
			break;
		}
	}

	for (int i = 1; i < MAX; i++){
		if (degree[i]){
			if (p != ancestor(i))
				return false;
		}
	}
	return true;
}

bool euler(){
	for (int i = 1; i < MAX; i++){
		if (degree[i] && degree[i] % 2){
			return false;
		}
	}
	return true;
}

void display(int k){
	for (int l = 1; l < MAX; l++){
		if (graph[k][l] && degree[k] && degree[l]){
			degree[k]--;
			degree[l]--;
			graph[k][l]--;
			graph[l][k]--;
			display(l);
			cout << l << " " << k << endl;
		}
	}
}

int main(){
	cin >> T;
	for (int i = 1; i <= T; i++){
		memset(graph,0,sizeof(graph));
		memset(degree,0,sizeof(degree));
		initialize();
		cin >> N;
		int x;
		int y;
		for (int j = 1; j <= N;j++){
			cin >> x;
			cin >> y;
			graph[x][y]++;
			graph[y][x]++;
			degree[x]++;
			degree[y]++;
		}

		cout << "Case #" << i << endl;
		if (union_find_sets() && euler()){
			for (int k = 1; k < MAX; k++){
				if (degree[k]){
					display(k);
					break;
				}
			}
		}
		else
			cout << "some beads may be lost" << endl;
		if (i != T)
			cout << endl;
	}
	return 0;
}
