#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct pos{
	int y;
	int x;
};
const pos DIREC[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int MAX_LEN = 105;
const int LAND = 1;
const int SEA = 0;
int map_len;
bool visited[MAX_LEN][MAX_LEN];
vector<pos> near_sea;
vector<vector<pair<int, int>>> graph(MAX_LEN);

void calTerritoryArea(pos curr_pos, const int & TERRITORY_NUM){
	visited[curr_pos.y][curr_pos.x] = true;
	graph[curr_pos.y][curr_pos.x].second = TERRITORY_NUM;
	for(int i = 0; i < 4; i++){
		pos next = {curr_pos.y + DIREC[i].y, curr_pos.x + DIREC[i].x};
		if(0 > next.y || next.y >= map_len || 0 > next.x || next.x >= map_len || visited[next.y][next.x]) continue;
		if(graph[next.y][next.x].first == SEA){
			if(!near_sea.empty() && near_sea.back().y == curr_pos.y && near_sea.back().x == curr_pos.x) continue;
			near_sea.push_back(curr_pos);
		}
		if(graph[next.y][next.x].first == LAND) calTerritoryArea(next, TERRITORY_NUM);
	 }
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> map_len;
	for(int i = 0; i < map_len; i++){
		for(int k = 0, vertex; k < map_len; k++){
			cin >> vertex;
			graph[i].push_back(make_pair(vertex, 0));
		}
	}
	memset(visited, false, sizeof(visited));
	for(int i = 0, islands = 1; i < map_len; i++){
		for(int k = 0; k < map_len; k++){
			if(graph[i][k].first == LAND && !visited[i][k]){
				calTerritoryArea({i, k}, islands);
				islands++;
			}
		}
	}
	const int INF = 1000;
	int ans = INF;
	for(int i = 0; i < near_sea.size(); i++){
		for(int j = 0; j < near_sea.size(); j++){
			pos land1 = near_sea[i], land2 = near_sea[j];
			if(j == i || (land1.y == land2.y && land1.x == land2.x)) continue;
			if(graph[land1.y][land1.x].second == graph[land2.y][land2.x].second) continue;
			ans = min(ans, abs(land1.y - land2.y) + abs(land1.x - land2.x) - 1);
		}
	}
	cout << ans;
}
