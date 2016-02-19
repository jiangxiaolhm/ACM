#include <iostream>
using namespace std;

int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int Test;
		int s = 0;
		int x;
		int y;
		int z;
		cin >> Test;
		while (Test--) {
			cin >> x >> y >> z;
			s += x * z;
		}
		cout << s << endl;
	}
	return 0;
}
