#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

struct Pos {int y; int x;};

int n, m, ans = 987654321;;
vector<Pos> homes, chickens;
bool vi[20];

void minF(vector<Pos> chi) {
	int tmpAns = 0;
	for(int i = 0; i < homes.size(); i++) {
		int minD = 987654321;
		for (int k = 0; k < chi.size(); k++) {
			Pos chiP = chi[k];
			Pos homP = homes[i];
			int dis = abs(chiP.y - homP.y) + abs(chiP.x - homP.x);
			minD = min(minD, dis);
		}
		tmpAns += minD;
	}
	ans = min(ans, tmpAns);
}

void f(int idx, vector<Pos> t) {
	if (t.size() > m) return;
	if(1 <= t.size() && t.size() <= m) {
//		for (int i = 0; i < t.size(); i++) {
//			cout << t[i].y << " " << t[i].x << endl;
//		}
//		cout << endl;
		minF(t);
	}

	for (int i = idx; i < n; i++) {
		if (vi[i]) continue;
		vi[i] = true;
		t.push_back(chickens[i]);
		f(i + 1, t);
		vi[i] = false;
		t.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int r = 0; r < n; r++) {
		for (int c = 0, tmp; c < n; c++) {
			cin >> tmp;
			Pos pos = {r, c};
			if (tmp == 1) homes.push_back(pos);
			else if (tmp == 2) chickens.push_back(pos);
		}
	}

	vector<Pos> t;
	f(0, t);

	cout << ans;
}
