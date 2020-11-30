#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
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

void calTerritoryArea(pos first_pos, const int TERRITORY_NUM){
	queue<pos> now_pos;
	now_pos.push(first_pos);
	while(!now_pos.empty()){
		pos now = now_pos.front();
		graph[now.y][now.x].second = TERRITORY_NUM;
		visited[now.y][now.x] = true;
		now_pos.pop();
		for(int i = 0; i < 4; i++){
			pos next = {now.y + DIREC[i].y, now.x + DIREC[i].x};
			if(0 > next.y || next.y >= map_len || 0 > next.x || next.x >= map_len) continue;
			if(visited[next.y][next.x]) continue;
			if(graph[next.y][next.x].first == SEA){
				if(near_sea.empty()) near_sea.push_back(now);
				else if(near_sea.back().y != now.y || near_sea.back().x != now.x) near_sea.push_back(now);
				continue;
			}
			now_pos.push(next);
		}
	}
}

int findAns(pos first_pos){
	int min_path = MAX_LEN;
	int now_land = graph[first_pos.y][first_pos.x].second;
	queue<pair<pos, int>> now_pos;
	now_pos.push(make_pair(first_pos, 0));
	while(!now_pos.empty()){
		pair<pos, int> now = now_pos.front();
		now_pos.pop();
		visited[now.first.y][now.first.x] = true;
		for(int i = 0; i < 4; i++){
			pos next_pos = {now.first.y + DIREC[i].y, now.first.x + DIREC[i].x};
			pair<pos, int> next = make_pair(next_pos, now.second + 1);
			if(0 > next.first.y || next.first.y >= map_len || 0 > next.first.x || next.first.x >= map_len) continue;
			if(visited[next.first.y][next.first.x] || graph[next.first.y][next.first.x].second == now_land) continue;
			if(graph[next.first.y][next.first.x].first == LAND && graph[next.first.y][next.first.x].second != now_land){
				min_path = min(min_path, next.second - 1);
 //				if(min_path == 4 && first_pos.y == 4 && first_pos.x == 3 && next.first.y == 7 && next.first.x == 4){
 //					cout << min_path << endl
 //					<< "first " << first_pos.y << " " << first_pos.x << endl
 //					<< "last " << next_pos.y << " " << next_pos.x << endl << endl;
 //				}
//				cout << min_path << endl;
//				cout << "now " << now.first.y << " " << now.first.x << endl
//					<< "next " << next.first.y << " " << next.first.x << endl << endl;
			}	
			else now_pos.push(next);
		}
	}
	return min_path;
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
			if(!visited[i][k] && graph[i][k].first == LAND && graph[i][k].second == 0){
				calTerritoryArea({i, k}, islands);
				islands++;
			}
		}
	}
	int ans = MAX_LEN;
	for(int i = 0; i < near_sea.size(); i++){
		memset(visited, false, sizeof(visited));
		ans = min(ans, findAns(near_sea[i]));
	}
//memset(visited, false, sizeof(visited));
//ans = min(ans, findAns(near_sea[0]));
//cout << near_sea[0].y << " " << near_sea[0].x << endl;
	cout << ans;
}
