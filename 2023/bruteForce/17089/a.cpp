#include <bits/stdc++.h>
using namespace std;

const int MAX = 4001;
int nodes, edges, answer = -1;
vector<vector<int>> graph;
bool g[MAX][MAX];
bool vi[MAX]; 

void dfs(int currNode, vector<int> selectedNodes, const int firstSelectedNode) {
	if (selectedNodes.size() == 3) {
		int lastSelectedNode = selectedNodes.back();
		if (!g[lastSelectedNode][firstSelectedNode]) return;
		int sum = 0;

		for (int i =0; i < selectedNodes.size(); i++) {
			cout << selectedNodes[i] << "  ";
		}
		cout << endl;
		cout << "========================================" << endl;

		for (int i = 0; i < selectedNodes.size(); i++) {
			sum += (graph[selectedNodes[i]].size() - 2);
		}
		answer = sum;
		return;
	}

	vi[currNode] = true;
	for (int i = 0; i < graph[currNode].size(); i++) {
		int nextNode = graph[currNode][i];
		if (vi[nextNode]) continue;
		selectedNodes.push_back(nextNode);
		dfs(nextNode, selectedNodes, firstSelectedNode);
		if (answer != -1) return;
		vi[currNode] = false;
		selectedNodes.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> nodes >> edges;
	graph.resize(nodes + 1);
	for (int i = 0, n1, n2; i < nodes; i++) {
		cin >> n1 >> n1;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
		g[n1][n2] = true;
		g[n2][n1] = true;
	}

	for (int i = 1; i <= nodes; i++) {
		memset(vi, false, sizeof(vi));
		vector<int> v;
		v.push_back(i);
		dfs(i, v, i);
	}
}
