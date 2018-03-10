#include<iostream>
#include<cstring>
using namespace std;

const int DIR_X[] = { -1, -1, -1, 0, 0, 1, 1, 1};
const int DIR_Y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int map[100][100];
// number of pockets
int pocket;

void dfs(int x, int y);

void dfs(int x, int y) {
	// mark visited plots as 2
	map[x][y] = 2;
	int adj_x, adj_y;
	for (int i = 0; i < 8; i++) {
		adj_x = x + DIR_X[i];
		adj_y = y + DIR_Y[i];
		if (adj_x >= 0 && adj_x < 100 && adj_y >= 0 && adj_y < 100 && map[adj_x][adj_y] == 1) {
			dfs(adj_x, adj_y);
		}
	}
}

int main() {

	int m, n;
	cin >> m >> n;
	do {
		memset(map, 0, sizeof(map));
		pocket = 0;
		char ch;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> ch;
				if (ch == '@') {
					// mark plots with oil as 1
					
					map[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					
					pocket++;
					
					dfs(i, j);
				}
			}
		}
		cout << pocket << endl;
		cin >> m >> n;
	} while (m != 0);

	return 0;
}