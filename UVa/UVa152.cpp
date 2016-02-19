#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 5100;
const int INF = 1 << 29;

struct Node {
	double x;
	double y;
	double z;
}p[N];

int d;
int n[20];

int main() {
	memset(p,0,sizeof(p));
	memset(n,0,sizeof(n));
	double p_x;
	double p_y;
	double p_z;
	int t;
	for (t = 0; t < 5000; t++) {
		cin >> p_x >> p_y >> p_z;
		if (!p_x && !p_y && !p_z)
			break;
		p[t].x = p_x;
		p[t].y = p_y;
		p[t].z = p_z;
	}

	for (int i = 0; i < t; i++) {
		d = INF;
		for (int j = 0; j < t; j++) {
			if (i != j) {
				int tmp = (int)sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2)+pow(p[i].z-p[j].z,2));
				if (d > tmp)
					d = tmp;
			}
		}
		d = (d + 0.5);
		if (d < 10)
			n[d]++;
	}

	for (int i = 0; i < 10; i++)
		printf("%4d",n[i]);
	cout << endl;
	return 0;
}
