#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool isTargetAns(vector<vector<int>> graph, queue<int> target){
	if(target.front() != 1) return false;
	vector<bool> visited(target.size() + 1, false);
	queue<int> bfs;
	bfs.push(1);
	target.pop();
	while(!bfs.empty()){
		int now = bfs.front();
		bfs.pop();
		visited[now] = true;
		int rest_vertexes = graph[now].size();
		for(int i = 0; i < graph[now].size(); i++){
			int next = graph[now][i];
			if(visited[next]) rest_vertexes--;
		}
		while(rest_vertexes){
			auto next = find(graph[now].begin(), graph[now].end(), target.front());
			if(next != graph[now].end()){
				bfs.push(*next);
				target.pop();
				rest_vertexes--;
			}
			else return false;
		}
	}
	return true;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int vertexes;
	cin >> vertexes;
	vector<vector<int>> graph(vertexes + 1);
	for(int i = 0, v1, v2; i < vertexes - 1; i++){
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	queue<int> target;
	for(int i = 0, tmp; i < vertexes; i++){
		cin >> tmp;
		target.push(tmp);
	}
	cout << isTargetAns(graph, target);
}
