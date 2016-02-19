#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int>q;
stack<int>s;
priority_queue<int>p;

int main() {
	int Test;
	int order;
	int tmp;
	while (cin >> Test) {
		bool cnt_q = true;
		bool cnt_s = true;
		bool cnt_p = true;
		int cnt = 3;
		for (int i = 0; i < Test; i++) {
			cin >> order >> tmp;
			if (cnt_q) {
				if (order == 1)
					q.push(tmp);
				else if (!q.empty() && q.front() == tmp)
					q.pop();
				else {
					cnt--;
					cnt_q = false;
				}
			}
			if (cnt_s) {
				if (order == 1)
					s.push(tmp);
				else if (!s.empty() && s.top() == tmp)
					s.pop();
				else {
					cnt--;
					cnt_s = false;
				}
			}
			if (cnt_p) {
				if (order == 1)
					p.push(tmp);
				else if (!p.empty() && p.top() == tmp)
					p.pop();
				else {
					cnt--;
					cnt_p = false;
				}
			}
		}
		if (!cnt)
			cout << "impossible" << endl;
		else if (cnt > 1)
			cout << "not sure" << endl;
		else if (cnt_q)
			cout << "queue" << endl;
		else if (cnt_s)
			cout << "stack" << endl;
		else
			cout << "priority queue" << endl;
		while (!q.empty())
			q.pop();
		while (!s.empty())
			s.pop();
		while (!p.empty())
			p.pop();
	}
	return 0;
}
