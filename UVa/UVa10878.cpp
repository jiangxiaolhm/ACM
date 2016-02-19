#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 20;
int main() {
	char tape[N];
	while (gets(tape)) {
		memset(tape,0,sizeof(tape));
		while (gets(tape)) {
			if (!strcmp(tape,"___________"))
				break;
			int lengthOfTape = strlen(tape);
			int ascll = 0;
			int power = 7;
			for (int i = 0; i < lengthOfTape; i++) {
				if (tape[i] == 'o') {
					ascll += pow(2,power);
					power--;
				}
				else if (tape[i] == ' ')
					power--;
			}
			printf("%c",ascll);
			memset(tape,0,sizeof(tape));
		}
	}
	return 0;
}
