#include <iostream>
#include <cstring>
using namespace std;

const int N = 200;
const int M = 10;

char ch_num[M];
int power;
int num1[N];
int num2[N];
int ans[N];
bool tmp_dot;
int len;
int t;
int ans_t;

void function() {
	memset(ans,0,sizeof(ans));
	for (int i = 0; i < ans_t; i++) {
		for (int j = 0; j < t; j++) {
			ans[i+j] += num1[i] * num2[j];
			if (ans[i+j] > 9) {
				ans[i+j+1] += ans[i+j] / 10;
				ans[i+j] %= 10;
			}
		}
	}

	memset (num1,0,sizeof(num1));
	for (int i = N-1; i >= 0; i--) {
		if (ans[i] != 0) {
			ans_t = i + 1;
			break;
		}
	}
	
	
	for (int i = 0; i < ans_t; i++)
		num1[i] = ans[i];
}
int main() {
	while (cin >> ch_num >> power) {
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(ans,0,sizeof(ans));
		len = strlen(ch_num);
		tmp_dot = false;
		t = 0;

		//查找.的位置;
		int after_dot = 0;
		for (int i = 0; i < len; i++) {
			if (ch_num[i] == '.')
				tmp_dot = true;
			else if (tmp_dot)
				after_dot++;
		}

		//去除前导0；
		for (int i = 0; i < len; i++) {
			if (ch_num[i] == '.' || (ch_num[i] >= '1' && ch_num[i] <= '9'))
				break;
			else
				ch_num[i] = '\0';
		}

		//去除后导0；
		if (tmp_dot) {
			for (int i = len-1; i >= 0; i--) {
				if (ch_num[i] >= '1' && ch_num[i] <= '9')
					break;
				else if (ch_num[i] == '.') {
					ch_num[i] = '\0';
					len--;
					break;
				}
				else {
					ch_num[i] = '\0';
					after_dot--;
					len--;
				}
			}
		}

		//去除.
		for (int i = 0; i < len; i++) {
			if (ch_num[i] == '.') {
				ch_num[i] = '\0';
				break;
			}
		}

		//由字符转换为整形；
		for (int i = len-1; i >= 0; i--) {
			if (ch_num[i]) {
				num1[t] = ch_num[i] - '0';
				num2[t] = ch_num[i] - '0';
				t++;
			}
		}

		//阶乘函数；
		ans_t = t;
		for (int i = 0; i < power - 1; i++)
			function();

		//输出；
		int tmp;
		tmp = power * after_dot;
		if (tmp > ans_t) {
			cout << '.';
			for (int i = tmp; i > ans_t; i--)
				cout << 0;
		}
		for (int i = ans_t-1; i >= 0; i--) {
			if (i == tmp-1)
				cout << '.';
			cout << ans[i];
		}
		cout << endl;
	}
	
	return 0;
}
