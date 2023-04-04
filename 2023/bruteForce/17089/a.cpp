#include <bits/stdc++.h>
using namespace std;

const int MAX = 4010;
const int INF = 987654321;
int nodes, edges, answer = INF;
vector<vector<int>> graph;
bool g[MAX][MAX];
bool vi[MAX]; 

void dfs(int currNode, vector<int> selectedNodes) {
	if (selectedNodes.size() == 3) {
		int lastSelectedNode = selectedNodes.back();
		int n1 = selectedNodes[0], n2 = selectedNodes[1], n3 = selectedNodes[2];
		if (!g[n1][n2] || !g[n1][n3] || !g[n2][n3]) return;
		int sum = 0;

//		for (int i =0; i < selectedNodes.size(); i++) {
//			cout << selectedNodes[i] << "  ";
//		}
//		cout << endl;
//		cout << "========================================" << endl;
//
		for (int i = 0; i < selectedNodes.size(); i++) {
			sum += (graph[selectedNodes[i]].size() - 2);
		}
		answer = min(answer, sum);
		return;
	}

	for (int i = 0; i < graph[currNode].size(); i++) {
		int nextNode = graph[currNode][i];
		if (vi[nextNode]) continue;
		vi[currNode] = true;
		selectedNodes.push_back(nextNode);
		dfs(nextNode, selectedNodes);
		vi[currNode] = false;
		selectedNodes.pop_back();
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

	for (int i = 1; i <= nodes; i++) {
		memset(vi, false, sizeof(vi));
		vector<int> v;
		v.push_back(i);
		vi[i] = true;
		dfs(i, v);
	}

	answer == INF ? cout << -1 : cout << answer;
}
