#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1000;
int result[N] = {0};
int p = 1;
struct tree{
	int place;
	tree *left;
	tree *right;
	tree(){
		place = N/2;
		left = NULL;
		right = NULL;
	}
}*head;

void new_tree(tree t){
	int i;
	cin >> i;
	if (i >= 0) {
		result[t.place] += i;
		t.left = new tree;
		t.left->place = t.place-1;
		new_tree(*t.left);
		t.right = new tree;
		t.right->place = t.place+1;
		new_tree(*t.right);
	}
}

int main(){
	while(1){
		head = new tree;
		int i,j;
		new_tree(*head);
		if (result[N/2] == 0)
			break;
		cout << "Case " << p++ << ":" << endl;
		for (i = N/2; i >= 0; i--)
			if (result[i] == 0)
				break;
		for (j = i+1; j < N; j++)
			if (result[j] == 0)
				break;
			else if (result[j+1])
				cout << result[j] << ' ';
			else
				cout << result[j] << endl;
		memset(result,0,sizeof(result));
		cout << endl;
	}
	return 0;
}
