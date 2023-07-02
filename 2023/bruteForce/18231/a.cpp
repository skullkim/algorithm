#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_CITIES = 2e3 + 2;

int cities, edges;
vector<vector<int>> graph;
int destroiedCities;
bool isDestroied[MAX_CITIES];
vector<int> ans;
bool isInAns[MAX_CITIES];

bool isBoombTarget(const int& target) {
	if (!isDestroied[target]) return false;
	vector<int> linkedCities = graph[target];
	bool ans = false;
	if (!isInAns[target]) {
		ans = true;
		isInAns[target] = true;
		destroiedCities--;
	}
	for (int i = 0; i < linkedCities.size(); i++) {
		int currCity = linkedCities[i];
		if (!isDestroied[currCity]) return false;
		else if (isDestroied[currCity] && !isInAns[currCity]) {
			ans = true;
			isInAns[currCity] = true;
			destroiedCities--;
		}
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cities >> edges;
	graph.resize(cities + 1);
	for (int i = 0, n1, n2; i < edges; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	cin >> destroiedCities;
	for (int i = 0, n; i < destroiedCities; i++) {
		cin >> n;
		isDestroied[n] = true;
	}
	
//	for (int i = 1; i <= cities; i++) {
//		cout << isDestroied[i] << " ";
//	}
//	cout << endl;

	for (int i = 1; i <= cities; i++) {
		if (!isBoombTarget(i)) continue;
//		cout << i << endl;
		ans.push_back(i);

//		if (!isInAns[i]) {
//			isInAns[i] = true;
//			destroiedCities--;
//		}
//		for (int k = 0; k < graph[i].size(); k++) {
//			if (isInAns[graph[i][k]]) continue;
//			isInAns[graph[i][k]] = true;
//			destroiedCities--;
//		}
	}
	if (ans.size() == 0) {
		cout << -1;
		return 0;
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
