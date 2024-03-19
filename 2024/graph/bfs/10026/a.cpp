#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct Pos {
	int y;
	int x;
};

const Pos DIREC[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int maxSize;
vector<vector<char>> graph;
bool vi[100][100];

void bfs(Pos pos, bool isNormal) {
	queue<Pos> q;
	q.push(pos);

	while (!q.empty()) {
		Pos currPos = q.front();
		q.pop();
		vi[currPos.y][currPos.x] = true;

		char currColor = graph[currPos.y][currPos.x];
		for (int i = 0; i <4; i++) {
			Pos nextPos = {currPos.y + DIREC[i].y, currPos.x + DIREC[i].x};
			if (vi[nextPos.y][nextPos.x]) continue;
			if (0 > nextPos.y || nextPos.y >= maxSize 
					|| 0 > nextPos.x || nextPos.x >= maxSize) continue;
			char nextColor = graph[nextPos.y][nextPos.x];
			if (isNormal && currColor != nextColor) continue;
			if (!isNormal && currColor == 'B' && nextColor != 'B') continue;
			if (!isNormal && currColor != 'B' && nextColor == 'B') continue;
			vi[nextPos.y][nextPos.x] = true;
			q.push(nextPos);
		}
	}
}

void printVi() {
	for (int i = 0; i <maxSize; i++) {
		for (int k = 0; k < maxSize; k++) {
			cout <<vi[i][k] <<" ";
		}
		cout <<"\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char tmp;
	cin >> maxSize;
	graph.resize(maxSize);
	for (int i = 0; i < maxSize; i++) {
		for (int k = 0; k < maxSize; k++) {
			cin >> tmp;
			graph[i].push_back(tmp);
		}
	}


	memset(vi, false, sizeof(vi));
	int normal = 0;
	for (int i = 0; i <maxSize; i++) {
		for (int k = 0; k < maxSize; k++) {
			if (vi[i][k]) continue;
			normal++;
			Pos pos = {i, k};
			bfs(pos, true);
		}
	}

	memset(vi, false, sizeof(vi));
	int handycap = 0;
	for (int i = 0; i < maxSize; i++) {
		for (int k = 0; k < maxSize; k++) {
			if (vi[i][k]) continue;
			handycap++;
			Pos pos = {i, k};
			bfs(pos, false);
		}
	}

	cout<< normal << " " << handycap <<"\n";
}

