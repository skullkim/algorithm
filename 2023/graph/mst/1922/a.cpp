#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> Node;
typedef pair<int, Node> Edge;

const int MAX_COMPUTERS = 1010;

int nodes, edges;
int parents[MAX_COMPUTERS];

int findParent(int currNode) {
	if (currNode == parents[currNode]) return currNode;
	parents[currNode] = findParent(parents[currNode]);
	return parents[currNode];
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

	cin >> nodes >> edges;

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	for (int i = 0, n1, n2, w; i < edges; i++) {
		cin >> n1 >> n2 >> w;
		Node node = make_pair(n1, n2);
		Edge edge = make_pair(w, node);
		pq.push(edge);
	}

	for (int i = 0; i <= nodes; i++) {
		parents[i] = i;
	}

	int minWeight = 0;
	int usedEdges = 0;
	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();
		int weight = edge.first;
		int node1 = edge.second.first;
		int node2 = edge.second.second;
		int node1Parent = findParent(node1);
		int node2Parent = findParent(node2);
		if (node1Parent == node2Parent) continue;
		unionNode(node1, node2);
		minWeight += weight;
		if (++usedEdges == (nodes - 1)) break;
	}
	cout << minWeight;
}
