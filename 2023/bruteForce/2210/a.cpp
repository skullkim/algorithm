#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Pos {
	int y;
	int x;
};

const Pos pos[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string graph[5][5];
int ans = 0;
map<string, bool> vi;

void f(int r, int c, string str, int dp) {
	if (dp == 6) {
		bool v = vi[str];
		if (!v) {
			vi[str] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		Pos nextPos = {r + pos[i].y, c + pos[i].x};
		if (0 > nextPos.y || nextPos.y >= 5 || 0 > nextPos.x || nextPos.x >= 5) continue;
		f(nextPos.y, nextPos.x, str + graph[r][c], dp + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int k = 0, tmp; k < 5; k++) {
			cin >> tmp;
			graph[i][k] = tmp;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			f(i, k, graph[i][k], 0);
		}
	}

	cout << ans;
}
