#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N1 = 100;
const int N2 = 20;
const int N3 = 300;

struct Rule {
	char in[N1];
	char out[N1];
}rule[N2];

char text[N3];

void Initialize() {
	memset(rule,0,sizeof(rule));
	memset(text,0,sizeof(text));
}

bool Compare(Rule rule,char *text,int position) {
	int lengthOfRuleIn = strlen(rule.in);
	for (int i = 0,j = position; i < lengthOfRuleIn; i++,j++) {
		if (rule.in[i] != text[j])
			return false;
	}
	return true;
}

bool Replace(Rule rule,char *text,int position) {
	char temporary[N3];
	memset(temporary,0,sizeof(temporary));
	strncpy(temporary,text,position);
	strcat(temporary,rule.out);
	int lengthOftemporary = strlen(temporary);
	int lengthOfRuleIn = strlen(rule.in);
	for (int i = lengthOftemporary,j = position+lengthOfRuleIn; text[j]; i++,j++)
		temporary[i] = text[j];
	memset(text,0,sizeof(text));
	if (strcmp(text,temporary))
		strcpy(text,temporary);
	else
		return false;
	return true;
}

int main() {
	int test;
	while (cin >> test) {
		if (!test)
			break;
		Initialize();
		getchar();
		for (int i = 0; i < test; i++) {
			gets(rule[i].in);
			gets(rule[i].out);
		}
		gets(text);
		int lengthOfText = strlen(text);
		for (int i = 0; i < test; i++) {
			int lengthOfRuleIn = strlen(rule[i].in);
			int lengthOfRuleOut = strlen(rule[i].out);
			for (int j = 0; j < lengthOfText;j++) {
				if (Compare(rule[i],text,j)) {
					if (!Replace(rule[i],text,j))
						break;
					j = 0;
					lengthOfText += lengthOfRuleOut - lengthOfRuleIn;
				}
			}
		}
		cout << text << endl;
	}
	return 0;
}
