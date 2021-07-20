#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos {int y; int x;};
const Pos DIREC[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visit[105][105];
char graph[105][105];
int row, col;
Pos start;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> col >> row;
	char tmp;
	for(int i = 0; i < row; i++) {
		for(int k = 0; k < col; k++) {
			cin >> tmp;
			if(tmp == 'C') start = {i, k};
			graph[i][k] = tmp;
		}
	}
	int ans = 987654321;
	queue<pair<Pos, pair<int, int>>> q;
	q.push(make_pair(start, make_pair(-1, 0)));
	while(!q.empty()) {
		pair<Pos, pair<int, int>> curr = q.front();
		if(curr.first.y != start.y && curr.first.x != start.x && graph[curr.first.y][curr.first.x] == 'C') {
			ans = min(ans, curr.second.second);
		}
		q.pop();
		visit[curr.first.y][curr.first.x] = true;
		for(int i = 0; i < 4; i++) {
			Pos next = {curr.first.y + DIREC[i].y, curr.first.x + DIREC[i].x};
			if(0 > next.y || next.y >= row || 0 > next.x || next.x >= col) continue;
			if(visit[next.y][next.x] || graph[next.y][next.x] == '*') continue;
			int curve = curr.second.second;
			int d = curr.second.first;
			if(i != d) {
				d = i;
				curve++;
			}
			q.push(make_pair(next, make_pair(d, curve)));
		}
	}
	cout << ans - 1;	
}
