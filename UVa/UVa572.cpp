#include<iostream>
#include<cstring>
using namespace std;

struct Plot {
	bool hasOil;
	Plot* pre;
} map[100][100];

int pocket;

// four directions to explore previous plot
const int DIR_X[] = { -1, -1, -1, 0 };
const int DIR_Y[] = { -1, 0, 1, -1 };

void findAdjacent(int x, int y);
Plot* findRoot(Plot* plot);

void findAdjacent(int x, int y) {

	// indexes of adjacent plots
	int adj_x, adj_y;
	// the root of pocket tree of current plot
	Plot *r1 = findRoot(&map[x][y]);
	// the root of pocket tree of adjacent plot
	Plot *r2;

	for (int i = 0; i < 4; i++) {
		adj_x = x + DIR_X[i];
		adj_y = y + DIR_Y[i];
		if (adj_x >= 0 && adj_x <= 100 && adj_y >= 0 && adj_y <= 100) {
			if (map[adj_x][adj_y].hasOil) {
				// on the same pocket
				// current plot's previous plot is the adjacent plot
				r2 = findRoot(&map[adj_x][adj_y]);
				if (r1 != r2) {
					r1->pre = r2;
					r1 = r1->pre;
					pocket--;
				}
			}
		}
	}
}

Plot* findRoot(Plot* plot) {

	if (plot->pre) {
		// path compression
		plot->pre = findRoot(plot->pre);
		return plot->pre;
	}

	return plot;
}

int main() {


	int m, n;

	cin >> m >> n;

	// m != 0
	while (m) {

		memset(map, 0, sizeof(map));
		pocket = 0;

		char ch;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> ch;
				if (ch == '@') {
					pocket++;
					map[i][j].hasOil = true;
					findAdjacent(i, j);
				}
			}
		}
		cout << pocket << endl;

		cin >> m >> n;
	}

	system("pause");
	return 0;
}