#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;;
vector<vector<int>> graph;
bool vi[1100];

void dfs(int node) {
	if (vi[node]) return;
	vi[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int nNode = graph[node][i];
		if (vi[nNode]) continue;
		dfs(nNode);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0, n1, n2; i < m; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
	}

	for (int i = 1; i <= n; i++) {
		if (vi[i]) continue;
		ans++;
		dfs(i);
	}

	cout << ans;
}
