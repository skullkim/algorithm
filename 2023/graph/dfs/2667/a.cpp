#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int y; int x;
};
const Pos pos[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

const int SIZE = 30;
int g[SIZE][SIZE];
int si, ans;
vector<int> groups;
bool vi[SIZE][SIZE];

void f(const int gindex, int r, int c) {
	if (vi[r][c]) return;
	vi[r][c] = true;
	groups[gindex]++;

	for (int i = 0; i < 4; i++) {
		Pos np = {r + pos[i].y, c + pos[i].x};
		if (0 > np.y || np.y >= si || 0 > np.x || np.x >= si || g[np.y][np.x] == 0) continue;
		f(gindex, np.y, np.x);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> si;
	for (int i = 0; i < si; i++) {
		string row;
		cin >> row;
		for (int k = 0; k < row.size(); k++) {
			char c = row[k];
			g[i][k] = atoi(&c);
		}
	}

	for (int i = 0; i < si; i++) {
		for (int k = 0; k < si; k++) {
			if (vi[i][k] || g[i][k] == 0) continue;
			ans++;
			groups.push_back(0);
			f(groups.size() - 1, i, k);
		}
	}

	sort(groups.begin(), groups.end());
	cout << ans << "\n";
	for (int i = 0; i < groups.size(); i++) cout << groups[i] << "\n";
}
