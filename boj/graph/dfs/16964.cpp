#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_NUM = 1e5 + 10;
int target_idx;
vector<int> target;
vector<vector<int>> graph(MAX_NUM);
bool visited[MAX_NUM], ans = false;;

void isTargetAns(int curr_vertex){
	visited[curr_vertex] = true;
	int i = 0;
	while(i < graph[curr_vertex].size()){
		int next = graph[curr_vertex][i];
		if(!visited[next] && target[target_idx + 1] == next){
			target_idx++;
			isTargetAns(next);
			if(target_idx >= target.size() - 1){
				ans = true;
				return;
			}
			i = 0;
		}
		else i++;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int vertexes;
	cin >> vertexes;
	for(int i = 0, v1, v2; i < vertexes - 1; i++){
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for(int i = 0, tmp; i < vertexes; i++){
		cin >> tmp;
		target.push_back(tmp);
	}
	if(target.front() != 1){
		cout << false;
		return 0;
	}
	isTargetAns(1);
	cout << ans;
}

