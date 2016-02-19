#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000;

struct Node {
	bool sign;
	bool end;
	Node *left;
	Node *right;
}root,node[N];

char encoding[N];
int current = 0;
bool answer = true;

void initialize() {
	root.sign = false;
	root.end = false;
	root.left = NULL;
	root.right = NULL;
	memset(node,0,sizeof(node));
	memset(encoding,0,sizeof(encoding));
	current = 0;
	answer = true;
}

bool buildTree(char *encoding,int position,Node *parentNode) {
	if (parentNode->end) {
		return false;
	}
	if (!parentNode->left)
		parentNode->left = &node[current++];
	if (!parentNode->right)
		parentNode->right = &node[current++];
	if (!encoding[position]) {
		if (parentNode->sign) {
			return false;
		}
		else {
			parentNode->end = true;
			return true;
		}
	}
	parentNode->sign = true;

	if (encoding[position] == '0')
		return buildTree(encoding,position+1,parentNode->left);
	if (encoding[position] == '1')
		return buildTree(encoding,position+1,parentNode->right);
}

int main() {
	int Case = 1;
	initialize();
	while (cin >> encoding) {
		if (!strcmp(encoding,"9")) {
			if (answer)
				cout << "Set " << Case << " is immediately decodable" << endl;
			else
				cout << "Set " << Case << " is not immediately decodable" << endl;
			Case++;
			initialize();
		}
		else {
			answer = answer && buildTree(encoding,0,&root);
			memset(encoding,0,sizeof(encoding));
		}
	}
	return 0;
}
