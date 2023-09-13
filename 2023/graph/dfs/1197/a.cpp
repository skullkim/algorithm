#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> NodePair;
typedef pair<int, NodePair> Edge;

const int MAX_NODES = 1e5 + 10;
int nodes, edges;
vector<vector<pair<int, int>>> graph(MAX_NODES);
long long ans = 9876543210;

int parents[MAX_NODES];

int findParent(int currNode) {
	if (parents[currNode] == currNode) return currNode;
	return findParent(parents[currNode]);
}

void unionNode(int node1, int node2) {
	int node1Parent = findParent(node1);
	int node2Parent = findParent(node2);

	if (node1Parent != node2Parent) {
		parents[node1Parent] = node2Parent;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	cin >> nodes >> edges;
	for (int i = 0, n1, n2, w; i < edges; i++) {
		cin >> n1 >> n2 >> w;
		NodePair nodePair = make_pair(n1, n2);
		Edge edge = make_pair(w, nodePair);
		pq.push(edge);
	}

	for (int i = 1; i <= nodes; i++) {
		parents[i] = i;
	}

	int usedEdges = 0;
	long long ans = 0;
	while (!pq.empty()) {
		Edge currEdge = pq.top();
		pq.pop();
		int weight = currEdge.first;
		int node1 = currEdge.second.first;
		int node2 = currEdge.second.second;
		int node1Parent = findParent(node1);
		int node2Parent = findParent(node2);
		if (node1Parent == node2Parent) continue;
		ans += weight;
		usedEdges++;
		if (usedEdges == nodes - 1) break;
		unionNode(node1, node2);
	}
	cout << ans;
}
