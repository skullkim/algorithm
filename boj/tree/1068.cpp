#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODES = 50;
int nodes, deleted_node, root, ans = 0;
vector<vector<int>> tree(MAX_NODES);

void countLeafNode(int curr_node){
	if(curr_node >= nodes || curr_node == deleted_node) return;
	if(tree[curr_node].size() == 1 && tree[curr_node][0] == deleted_node){
		ans++;
	}
	if(tree[curr_node].empty()){
		ans++;
		return;
	}
	for(int n = 0; n < tree[curr_node].size(); n++){
		int next = tree[curr_node][n];
		if(next == deleted_node) continue;
		countLeafNode(next);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int ROOT = -1;
	cin >> nodes;
	int parent;
	for(int n = 0; n < nodes; n++){
		cin >> parent;
		if(parent == ROOT) root = n;
		else tree[parent].push_back(n);
	}
	cin >> deleted_node;
	countLeafNode(root);
	cout << ans;
}
