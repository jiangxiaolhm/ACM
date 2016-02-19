#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

const int N = 50;
const int M = 200;

char rowExcuses[N][M];
char keyword[N][N];
char excuses[N][M];
int searchedNumber[N];
char temporary[N];

void initialize() {
	memset(rowExcuses,0,sizeof(rowExcuses));
	memset(keyword,0,sizeof(keyword));
	memset(excuses,0,sizeof(excuses));
	memset(searchedNumber,0,sizeof(searchedNumber));
	memset(temporary,0,sizeof(temporary));
}

int main() {
	int keywordNumber;
	int excusesNumber;
	int times = 1;

	while (cin >> keywordNumber >> excusesNumber) {
		initialize();
		for (int i = 0; i < keywordNumber; i++) {
			cin >> keyword[i];
			int lengthOfKeyword = strlen(keyword[i]);
			for (int j = 0; j < lengthOfKeyword; j++)
				if (isupper(keyword[i][j]))
					keyword[i][j] = tolower(keyword[i][j]);
		}
		getchar();
		for (int i = 0; i < excusesNumber; i++) {
			gets(rowExcuses[i]);
			int lengthOfExcuses = strlen(rowExcuses[i]);
			for (int j = 0; j < lengthOfExcuses; j++)
				if (isupper(rowExcuses[i][j]))
					excuses[i][j] = tolower(rowExcuses[i][j]);
				else
					excuses[i][j] = rowExcuses[i][j];
		}
		for (int i = 0; i < keywordNumber; i++) {
			for (int j = 0; j < excusesNumber; j++) {
				int lengthOfExcuses = strlen(excuses[j]);
				int lengthOftemporary = 0;
				for (int k = 0; k < lengthOfExcuses; k++) {
					if (isalpha(excuses[j][k]))
						temporary[lengthOftemporary++] = excuses[j][k];
					else {
						if (!strcmp(keyword[i],temporary))
							searchedNumber[j]++;
						memset(temporary,0,sizeof(temporary));
						lengthOftemporary = 0;
					}
				}
			}
		}
		cout << "Excuse Set #" << times++ << endl;
		int mostKeyword = 0;
		for (int i = 1; i < excusesNumber; i++)
			if (searchedNumber[i] > searchedNumber[mostKeyword])
				mostKeyword = i;
		for (int i = 0; i < excusesNumber; i++)
			if (searchedNumber[i] == searchedNumber[mostKeyword])
				cout << rowExcuses[i] << endl;
		cout << endl;
	}
	return 0;
}
