#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	double h;
	double m;
	double angle;
	while (scanf("%lf:%lf",&h,&m)) {
		if (h == 0 && m == 0)
			break;
		angle = 30 * h - 5.5 * m;
		if (angle < 0)
			angle = 360 + angle;
		if (angle > 180)
			angle = 360 - angle;
		printf("%.3lf\n",angle);
	}
	return 0;
}
