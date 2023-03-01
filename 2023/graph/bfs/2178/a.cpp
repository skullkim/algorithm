#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Pos{
	int y; int x;
};
const Pos pos[4] ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int S = 110;

int g[S][S];
int r, c;
bool vi[S][S];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		string tmp;
		cin >> tmp;
		for (int k = 0; k < tmp.size(); k++) {
			char c = tmp[k];
			g[i][k] = atoi(&c);
		}
	}

	queue<pair<Pos, int>> q;
	Pos st = {0, 0};
	q.push(make_pair(st, 1));
	vi[0][0] = true;
	while(!q.empty()) {
		pair<Pos, int> top = q.front();
		q.pop();
		if (top.first.y == r - 1 && top.first.x == c - 1) {
			cout << top.second;
			return 0;
		}

		for(int i = 0; i < 4; i++) {
			Pos next = {top.first.y + pos[i].y, top.first.x + pos[i].x};
			if (0 > next.y || next.y >= r || 0 > next.x || next.x >= c || g[next.y][next.x] == 0) continue;
			if (vi[next.y][next.x]) continue;
			vi[next.y][next.x] = true;
			q.push(make_pair(next, top.second + 1));
		}
	}
}
