#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> team;

struct Team{
	char name[50];
	int points;
	int times;
	int wins;
	int ties;
	int losses;
	int goal_d;
	int goals_s;
	int goals_a;
}t[100];

char game[100];

bool cmp(Team a,Team b) {
	if (a.points == b.points)
		if (a.wins == b.wins)
			if (a.goal_d == b.goal_d)
				if (a.goals_s == b.goals_s)
					if (a.times == b.times) {
						for (int i = 0; i < 50; i++) {
							if (isupper(a.name[i]))
								a.name[i] = tolower(a.name[i]);
							if (isupper(b.name[i]))
								b.name[i] = tolower(b.name[i]);
						}
						return strcmp(a.name,b.name) < 0;
					}
					else
						return a.times < b.times;
				else
					return a.goals_s > b.goals_s;
			else
				return a.goal_d > b.goal_d;
		else
			return a.wins > b.wins;
	else
		return a.points > b.points;
}

int main() {
	int t_1;
	cin >> t_1;
	getchar();
	while (t_1--) {
		memset(game,0,sizeof(game));
		if (!team.empty())
			team.clear();
		gets(game);
		int t_2;
		cin >> t_2;
		getchar();
		memset(t,0,sizeof(t));
		for (int i = 0; i < t_2; i++) {
			gets(t[i].name);
			team[t[i].name] = i;
		}
		int t_3;
		char tmp_1[50];
		char tmp_2[50];
		int s_1;
		int s_2;
		char ch;
		cin >> t_3;
		getchar();
		for (int i = 0; i < t_3; i++) {
			memset(tmp_1,0,sizeof(tmp_1));
			memset(tmp_2,0,sizeof(tmp_2));
			int x = 0;	//
			while (ch = getchar()) {
				if ('#' == ch)
					break;
				tmp_1[x] = ch;
				x++;
			}
			tmp_1[x] = '\0';
			scanf("%d",&s_1);
			getchar();
			scanf("%d",&s_2);
			getchar();
			gets(tmp_2);

			t[team[tmp_1]].times += 1;
			t[team[tmp_1]].goal_d += s_1 - s_2;
			t[team[tmp_1]].goals_s += s_1;
			t[team[tmp_1]].goals_a += s_2;

			t[team[tmp_2]].times += 1;
			t[team[tmp_2]].goal_d += s_2 - s_1;
			t[team[tmp_2]].goals_s += s_2;
			t[team[tmp_2]].goals_a += s_1;

			if (s_1 > s_2) {
				t[team[tmp_1]].points += 3;
				t[team[tmp_1]].wins += 1;
				t[team[tmp_2]].losses += 1;
			}
			else if (s_1 == s_2) {
				t[team[tmp_1]].points += 1;
				t[team[tmp_1]].ties += 1;
				t[team[tmp_2]].points += 1;
				t[team[tmp_2]].ties += 1;
			}
			else {
				t[team[tmp_2]].points += 3;
				t[team[tmp_2]].wins += 1;
				t[team[tmp_1]].losses += 1;
			}
		}
		sort(t,t+t_2,cmp);
		
		cout << game << endl;
		for (int i = 0; i < t_2; i++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,t[i].name,t[i].points,t[i].times,t[i].wins,t[i].ties,t[i].losses,t[i].goal_d,t[i].goals_s,t[i].goals_a);
		}
		
		if (t_1)
			cout << endl;
	}
	return 0;
}
