#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAX = 1e5 + 10;
struct Tree{
	int node;
	int cost;
};
vector<vector<Tree>> tree(MAX);
int ans = -1, nodes, end_node;
bool visited[MAX];

void calMaxCost(int curr_node, int curr_cost){
	visited[curr_node] = true;
	if(curr_cost > ans){
		ans = curr_cost;
		end_node = curr_node;
	}
	for(int i = 0; i < tree[curr_node].size(); i++){
		Tree next = tree[curr_node][i];
		if(visited[next.node]) continue;
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
	calMaxCost(1, 0);
	memset(visited, false, sizeof(visited));
	calMaxCost(end_node, 0);
	cout << ans;
}
