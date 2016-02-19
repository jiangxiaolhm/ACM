#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1000;
const int L = 26;

int main() {
	int round;
	char puzzle[N];
	char guess[N];
	bool p_map[L];
	bool g_map[L];
	while (cin >> round) {
		if (round == -1)
			break;
		memset(puzzle,0,sizeof(puzzle));
		memset(guess,0,sizeof(guess));
		memset(p_map,0,sizeof(p_map));
		cin >> puzzle;
		cin >> guess;
		cout << "Round " << round << endl;
		int p_length = strlen(puzzle);
		int g_length = strlen(guess);
		int current = 0;
		int sum = 0;
		for (int i = 0; i < p_length; i++) {
			if (!p_map[puzzle[i]-'a']) {
				p_map[puzzle[i]-'a'] = true;
				sum++;
			}
			
		}
		for (int i = 0; i < g_length; i++) {
			if (p_map[guess[i]-'a']) {
				p_map[guess[i]-'a'] = false;
				sum--;
				if (sum == 0)
					break;
			}
			else
				current++;
		}
		if (current >= 7)
			cout << "You lose." << endl;
		else if (sum)
			cout << "You chickened out." << endl;
		else
			cout << "You win." << endl;
	}
	return 0;
}
