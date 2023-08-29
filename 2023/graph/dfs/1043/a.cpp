#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_PEOPLE = 55;

int people, partyNum, truth;
int joinedPeople;
vector<vector<int>> graph(MAX_PEOPLE);
vector<vector<int>> parties;
bool knowTruth[MAX_PEOPLE], canLie, vi[MAX_PEOPLE];

void dfs(int person, bool vi[]) {
	if (vi[person]) return;

	if (knowTruth[person]) {
		canLie = false;
		return;
	}

	vi[person] = true;

	for (int i = 0; i < graph[person].size(); i++) {
		int next = graph[person][i];
		dfs(next, vi);
		if (!canLie) return;
	}
}

bool hasSamePerson(vector<int> g, int node) {
	for (int i = 0; i < g.size(); i++) {
		if (g[i] == node) return true;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> people >> partyNum >> truth;
	for (int i= 0, p1, p2; i < truth; i++) {
		if (i == 0) {
			cin >> p1;
			knowTruth[p1] = true;
		}
		else {
			cin >> p2;
			graph[p1].push_back(p2);
			graph[p2].push_back(p1);
			knowTruth[p2] = true;
		}
	}

	for (int i = 0, p1, p2; i < partyNum; i++) {
		cin >> joinedPeople;
		vector<int> tmp;
		for (int k = 0; k < joinedPeople; k++) {
			if (k == 0) {
				cin >> p1;
				tmp.push_back(p1);
			}
			else {
				cin >> p2;
				tmp.push_back(p2);
				if (!hasSamePerson(graph[p1], p2)) {
					graph[p1].push_back(p2);
					graph[p2].push_back(p1);
				}
			}
		}
		parties.push_back(tmp);
	}

	int ans = 0;
	for (int i = 0; i < partyNum; i++) {
		for (int k = 0; k < parties[i].size(); k++) {
			bool vi[MAX_PEOPLE];
			memset(vi, false, sizeof(vi));
			canLie = true;
			dfs(parties[i][k], vi);
			if (!canLie) break;
		}
		if (canLie) ans++;
	}
	cout << ans;
}
