#include <iostream>
using namespace std;

const int MAX_IDX = 1e7 + 10;

int parents[MAX_IDX];

int findParent(int node) {
	if (parents[node] == node) return node;
	parents[node] = findParent(parents[node]);
	return parents[node];
}

void unionNode(int node1, int node2) {
	int node1Parent = findParent(node1);
	int node2Parent = findParent(node2);

	if (node1Parent < node2Parent) parents[node2Parent] = node1Parent;
	else parents[node1Parent] = node2Parent;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int scenarioes;
	cin >> scenarioes;

	for (int scenario = 1; scenario <= scenarioes; scenario++) {
		cout << "Scenario " << scenario << ":\n";
		int people;
		cin >> people;
		for (int i = 0; i < MAX_IDX; i++) {
			parents[i] = i;
		}

		int relationships;
		cin >> relationships;
		for (int i = 0, p1, p2; i < relationships; i++) {
			cin >> p1 >> p2;
			unionNode(p1, p2);
		}

		int cases;
		cin >> cases;
		for (int i = 0, p1, p2; i < cases; i++) {
			cin >> p1 >> p2;
			int p1Parent = findParent(p1);
			int p2Parent = findParent(p2);
			cout << (p1Parent == p2Parent) << "\n";
		}
		cout << "\n";
	}
}
