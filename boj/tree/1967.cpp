#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1e4 + 5;
struct Tree{
	int node;
	int cost;
};
int nodes, leaf_node, max_cost = -1;
bool visited[MAX];
vector<vector<Tree>> tree(MAX);

void findTreeDiameter(int curr_node, int curr_cost){
	visited[curr_node] = true;
	if(curr_cost > max_cost){
		max_cost = curr_cost;
		leaf_node = curr_node;
	}
	for(int n = 0; n < tree[curr_node].size(); n++){
		Tree next = tree[curr_node][n];
		if(visited[next.node]) continue;
		findTreeDiameter(next.node, curr_cost + next.cost);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> nodes;
	int parent;
	Tree tmp;
	for(int n = 1; n < nodes; n++){
		cin >> parent >> tmp.node >> tmp.cost;
		tree[parent].push_back(tmp);
		tree[tmp.node].push_back({parent, tmp.cost});
	}	
	findTreeDiameter(1, 0);	
	memset(visited, false, sizeof(visited));
	findTreeDiameter(leaf_node, 0);
	cout << max_cost;
}
