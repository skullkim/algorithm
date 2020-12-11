#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 1e5 + 10;
struct Tree{
	int node;
	int cost;
};
vector<vector<Tree>> tree(MAX);
int ans = -1, nodes, root = -1;
map<pair<int, int>, bool> visited;
//bool visited[MAX][MAX];

void calMaxCost(int curr_node, int curr_cost){
	ans = max(ans, curr_cost);
	for(int i = 0; i < tree[curr_node].size(); i++){
		Tree next = tree[curr_node][i];
		pair<int, int> v = make_pair(curr_node, next.node);
		pair<int, int> v2 = make_pair(next.node, curr_node);
		if(visited.count(v)) continue;
		visited[v] = true;
		visited[v2] = true;
		calMaxCost(next.node, curr_cost + next.cost);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> nodes;
	int parent, tmp = 0;
	for(int n = 0; n < nodes; n++){
		cin >> parent;
		int idx = 0;
		while(true){
			Tree t;
			cin >> tmp;
			if(tmp == -1) break;
			t.node = tmp;
			cin >> tmp;
			if(tmp == -1) break;
			t.cost = tmp;
			tree[parent].push_back(t);
		}
	}
	for(int n = 1; n <= nodes; n++) calMaxCost(n, 0);
	cout << ans;
}
