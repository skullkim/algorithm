#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
struct Tree{
	int node;
	int parent = -1;
	int cost;
};
vector<vector<Tree>> tree(MAX);
int ans = -1, nodes, root = -1;
bool visited[MAX][MAX];

void calMaxCost(int curr_node, int curr_cost){
	if(visited[curr_node][0]) return;
	visited[curr_node][0] = true;
	ans = max(ans, curr_cost);
	for(int i = 0; i < tree[curr_node].size(); i++){
		if(visited[curr_node][i]) continue;
		visited[curr_node][i] = true;
		visited[i][curr_node] = true;
		calMaxCost(tree[curr_node][i].node, curr_cost + tree[curr_node][i].cost);
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
