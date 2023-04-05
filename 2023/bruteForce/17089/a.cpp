#include <bits/stdc++.h>
using namespace std;

const int MAX = 4010;
const int INF = 987654321;
int nodes, edges, answer = INF;
vector<vector<int>> graph;
bool g[MAX][MAX];
bool vi[MAX]; 

void f(int currNode, vector<int> sn) {
	if (sn.size() == 3) {
		int lastSelectedNode = sn.back();
		int n1 = sn[0], n2 = sn[1], n3 = sn[2];
		int sum = 0;

//		for (int i =0; i < sn.size(); i++) {
//			cout << sn[i] << "  ";
//		}
//		cout << endl;
//		cout << "========================================" << endl;
//
		for (int i = 0; i < sn.size(); i++) {
			sum += (graph[sn[i]].size() - 2);
		}
		answer = min(answer, sum);
		return;
	}

	for (int i = currNode + 1; i < nodes; i++) {
		int selectedSize = sn.size();
		if (selectedSize == 1 && !g[sn[0]][i]) continue;
		if (selectedSize == 2 && (!g[sn[0]][i] || !g[sn[1]][i])) continue;
		sn.push_back(i);
		f(i, sn);
		sn.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> nodes >> edges;
	graph.resize(MAX);
	for (int i = 0, n1, n2; i < nodes; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
		g[n1][n2] = true;
		g[n2][n1] = true;
	}

	vector<int> v;
	f(0, v);

	answer == INF ? cout << -1 : cout << answer;
}
