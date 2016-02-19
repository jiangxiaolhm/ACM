#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 10;
const double INF = 1<<29;

int number; //例子次序
int test;	//例子数目

int temp_o[N];	//临时编号
int order[N];	//排序编号

double temp_a[N];	//临时间距
double answer[N];	//节点间距

double temp_l;	//临时总长
double length;	//最终总长

struct Node {
	double x;
	double y;
} point[N];	//点的坐标

void initialize() {	//初始化
	length = INF;
	memset(temp_o,0,sizeof(temp_o));
	memset(order,0,sizeof(order));
	memset(temp_a,0,sizeof(temp_a));
	memset(answer,0,sizeof(answer));
	memset(point,0,sizeof(point));
	for (int i = 0; i < test; i++)
		temp_o[i] = i;
}


double find_length() {
	temp_l = 0;

	for (int i = 0; i < test - 1; i++) {
		int a = temp_o[i];
		int b = temp_o[i+1];

		temp_a[i] = pow(pow(point[a].x - point[b].x,2)+pow(point[a].y - point[b].y,2),0.5) + 16;
		temp_l += temp_a[i];
	}

	return temp_l;
}

int main() {
	number = 1;
	
	while (cin >> test) {
		if (!test)
			break;
		initialize();
		for (int i = 0; i < test; i++) {
			cin >> point[i].x;
			cin >> point[i].y;
		}

		temp_l = find_length();
		if (temp_l < length) {
			length = temp_l;
			for (int i = 0; i < test; i++) {
				order[i] = temp_o[i];
				answer[i] = temp_a[i];
			}
		}

		while (next_permutation(temp_o,temp_o + test)) {
			temp_l = find_length();
			if (temp_l < length) {
				length = temp_l;
				for (int i = 0; i < test; i++) {
					order[i] = temp_o[i];
					answer[i] = temp_a[i];
				}
			}
		}

		cout << "**********************************************************" << endl;
		cout << "Network #" << number << endl;
		number++;
		for (int i = 0; i < test - 1; i++)
			printf("Cable requirement to connect (%.0f,%.0f) to (%.0f,%.0f) is %.2f feet.\n",point[order[i]].x,point[order[i]].y,point[order[i+1]].x,point[order[i+1]].y,answer[i]);
		printf("Number of feet of cable required is %.2f.\n", length);
	}

	return 0;
}
