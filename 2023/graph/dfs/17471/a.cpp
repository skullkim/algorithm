#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_NODES = 11;
const int MAX_POPULATION = 1e5;

vector<vector<int>> graph(MAX_NODES);
int nodes;
int populations[MAX_NODES];

void dfs(int node, bool vi[]) {
	if (vi[node]) return;

	vi[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];
		dfs(nextNode, vi);
	}
}

bool areAllConnected(vector<int> area) {
	bool vi[MAX_NODES];
	memset(vi, false, sizeof(vi));
	dfs(area[0], vi);

//	for (int i = 1; i < nodes; i++) {
//		cout << i << ":" << vi[i] << ", ";
//	}
//	cout << endl;

	for (int i = 0; i < area.size(); i++) {
		if (!vi[area[i]]) return false;
	}
	return true;
}

int calculatePopulation(vector<int> area) {
	int population = 0;
	for (int i = 0; i < area.size(); i++) {
		population += populations[area[i]];
	}
	return population;
}

int ans = MAX_POPULATION;
void calculatePopulationDiff(vector<int> areaA) {
	vector<int> areaB;
	for (int i = 1; i <= nodes; i++) {
		bool isInAreaA = false;
		for (int k = 0; k < areaA.size(); k++) {
			if (i == areaA[k]) {
				isInAreaA = true;
				break;
			}
		}
		if (!isInAreaA) areaB.push_back(i);
	}

//	cout << "areaA" << endl;
//	for(int i = 0; i < areaA.size(); i++) {
//		cout << areaA[i] << " ";
//	}
//	cout << endl;
//	bool a = areAllConnected(areaA);
//	cout << a << endl;
//	cout << "areaB" << endl;
//	for(int i = 0; i < areaB.size(); i++) {
//		cout << areaB[i] << " ";
//	}
//	cout << endl;
//	bool b = areAllConnected(areaB);
//	cout << b << endl;
//	cout << "===============================" << endl;


	//if (!a || !b) return;
	if (!areAllConnected(areaA) || !areAllConnected(areaB)) return;

	int areaAPopulation = calculatePopulation(areaA);
	int areaBPopulation = calculatePopulation(areaB);

	ans = min(ans, abs(areaAPopulation - areaBPopulation));
}

void devideArea(vector<int> areaA, int currNode) {
	if (areaA.size() == nodes) return;

//	for (int i = 0; i < areaA.size(); i++) {
//		cout << areaA[i] << " ";
//	}
//	cout << endl;
	if (areaA.size() >= 1) {
		calculatePopulationDiff(areaA);
	}

	for (int i = currNode; i <= nodes; i++) {
		areaA.push_back(i);
		devideArea(areaA, i + 1);
		areaA.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> nodes;
	for (int i = 1; i <= nodes; i++) {
		cin >> populations[i];
	}

	for (int i = 1, adjacentNodes; i <= nodes; i++) {
		cin >> adjacentNodes;
		for (int k = 0, n; k < adjacentNodes; k++) {
			cin >> n;
			graph[i].push_back(n);
		}
	}
//
//	cout << "graph:" << endl;
//	for (int i = 1; i <= nodes; i++) {
//		cout << "graph" << i << ": ";
//		for (int k = 0; k < graph[i].size(); k++) {
//			cout << graph[i][k] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//
	vector<int> areaA;
	devideArea(areaA, 1);

	ans == MAX_POPULATION ? cout << -1 : cout << ans;
}
