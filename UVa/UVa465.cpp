#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
using namespace std;

const int N = 200;
const int MaxInt = 2147483647;
const char MaxChar[N] = {"2147483647"};

int main() {
	char temporary[2*N];
	char firstNumber[N];
	char secondNumber[N];
	char sign;
	memset(temporary,0,sizeof(temporary));
	while (gets(temporary)) {
		memset(firstNumber,0,sizeof(firstNumber));
		memset(secondNumber,0,sizeof(secondNumber));
		int lengthOfTemporary = strlen(temporary);
		int position = 0;
		for (; position < lengthOfTemporary; position++)
			if (temporary[position] != '0')
				break;
		for (int i = 0; position < lengthOfTemporary; i++,position++) {
			if (isdigit(temporary[position]))
				firstNumber[i] = temporary[position];
			else
				break;
		}
		for (; position < lengthOfTemporary; position++) {
			if (temporary[position] == '+' || temporary[position] == '*')
				sign = temporary[position];
			else if (isdigit(temporary[position]) && temporary[position] != '0')
				break;
		}
		for (int i = 0; position < lengthOfTemporary; i++,position++) {
			if (isdigit(temporary[position]))
				secondNumber[i] = temporary[position];
			else
				break;
		}
		int lengthOfFirstNumber = strlen(firstNumber);
		int lengthOfSecondNumber = strlen(secondNumber);
		int firstNumberSign = false;
		int secondNumberSign = false;
		cout << temporary << endl;
		if (lengthOfFirstNumber > 10) {
			cout << "first number too big" << endl;
			firstNumberSign = true;
		}
		else if (lengthOfFirstNumber == 10) {
			for (int i = 0; i < 10; i++) {
				if (firstNumber[i] > MaxChar[i]) {
					cout << "first number too big" << endl;
					firstNumberSign = true;
					break;
				}
				else if (firstNumber[i] < MaxChar[i])
					break;
			}
		}
		if (lengthOfSecondNumber > 10) {
			cout << "second number too big" << endl;
			secondNumberSign = true;
		}
		else if (lengthOfSecondNumber == 10) {
			for (int i = 0; i < 10; i++) {
				if (secondNumber[i] > MaxChar[i]) {
					cout << "second number too big" << endl;
					secondNumberSign = true;
					break;
				}
				else if (secondNumber[i] < MaxChar[i])
					break;
			}
		}
		if (sign == '+' || lengthOfFirstNumber && lengthOfSecondNumber) {
			if (firstNumberSign || secondNumberSign) {
				cout << "result too big" << endl;
			}
			else {
				int firstNumberInt = 0;
				int secondNumberInt = 0;
				int temporary2 = MaxInt;
				for (int i = 0; i < lengthOfFirstNumber; i++)
					firstNumberInt += (firstNumber[i] - '0') * pow(10,lengthOfFirstNumber-i-1);
				for (int i = 0; i < lengthOfSecondNumber; i++)
					secondNumberInt += (secondNumber[i] - '0') * pow(10,lengthOfSecondNumber-i-1);
				if (sign == '+')
					temporary2 -= firstNumberInt;
				else if (sign == '*' && firstNumberInt)
					temporary2 /= firstNumberInt;
				if (secondNumberInt > temporary2)
					cout << "result too big" << endl;
			}
		}
	}
	return 0;
}
