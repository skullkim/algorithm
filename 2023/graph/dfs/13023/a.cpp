#include <iostream>
#include <vector>

using namespace std;

int n, e;
bool hasAns;
bool vi[2100];
vector<vector<int>> g;

void f(int node, int depth) {
	if (depth == 5) {
		hasAns = true;
		return;
	}

	vi[node] = true;
	for (int i = 0; i < g[node].size(); i++) {
		int nextN = g[node][i];
		if (vi[nextN]) continue;
		vi[nextN] = true;
		f(nextN, depth + 1);
		if (hasAns) return;
		vi[nextN] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> e;
	g.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}

	for (int i = 0; i < n; i++) {
		if (hasAns) break;
		f(i, 1);
	}

	hasAns ? cout << 1 : cout << 0;
}
