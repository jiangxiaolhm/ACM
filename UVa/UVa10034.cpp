#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 110;
const int INF = 1 << 29;

struct Node {
	double x;
	double y;
}p[N];
int point;
double ans;
double graph[N][N];
double lowcost[N];
double nearvex[N];

void initialize() {
	ans = 0;
	memset(graph,INF,sizeof(graph));
}

void prim(int u) {
	for (int i = 0; i < point; i++)
		lowcost[i] = graph[u][i];
	memset(nearvex,u,sizeof(nearvex));
	nearvex[u] = -1;
	for (int i = 0; i < point; i++) {
		if (i != u) {
			int min = INF;
			int v = 0;
			for (int j = 0; j < point; j++) {
				if (nearvex[j] != -1 && lowcost[j] < min) {
					v = j;
					min = lowcost[j];
				}
			}
			if (v) {
				ans += lowcost[v];
				nearvex[v] = -1;
				for (int j = 0; j < point; j++) {
					if (nearvex[j] != -1 && graph[v][j] < lowcost[j]) {
						lowcost[j] = graph[v][j];
						nearvex[j] = v;
					}
				}
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		initialize();
		cin >> point;
		for (int i = 0; i < point; i++)
			cin >> p[i].x >> p[i].y;
		
		for (int i = 0; i < point; i++) {
			for (int j = 0; j < point; j++) {
				if (i == j)
					continue;
				graph[i][j] = sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
			}
		}
		prim(0);
		printf("%.2lf\n",ans);
		if (test)
			cout << endl;
	}
	return 0;
}
