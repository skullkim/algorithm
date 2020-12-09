#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 5;
const bool LEFT = true;
const bool RIGHT = false;
struct Tree{
	int left = -1;
	int right = -1;
	int parent = -1;
};
struct Gap{
	int l_gap = MAX + 5;
	int r_gap = -1;
};
Tree tree[MAX];
Gap gap[MAX];
int nodes, max_level = -1, pos = 1;

void inorderSearch(int curr_node, int level){
	if(curr_node <= 0) return;
	inorderSearch(tree[curr_node].left, level + 1);
	pos++;
	gap[level].l_gap = min(gap[level].l_gap, pos);
	gap[level].r_gap = max(gap[level].r_gap, pos);
	max_level = max(max_level, level);
	inorderSearch(tree[curr_node].right, level + 1);
	return;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> nodes;
	Tree tmp;
	for(int n = 0, p; n < nodes; n++){
		cin >> p >> tmp.left >> tmp.right;
		tree[p] = tmp;
		if(tmp.left == -1) tmp.left = 0;
		if(tmp.right == -1) tmp.right = 0;
		if(tree[tmp.left].parent == -1) tree[tmp.left].parent = p;
		if(tree[tmp.right].parent == -1) tree[tmp.right].parent = p;
	}
	int root = -1;
	for(int i = 1; i <= nodes; i++){
		if(tree[i].parent == -1){
			root = i;
			break;
		}
	}
	inorderSearch(root, 1);

	int max_with = 0, level = 0;
	for(int i = 1; i <= max_level; i++){
		int width = gap[i].r_gap - gap[i].l_gap + 1;
		if(max_with < width){
			max_with = width;
			level = i;
		}
	}
	cout << level << " " << max_with;
}
