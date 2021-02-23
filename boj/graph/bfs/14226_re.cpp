#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int M = 1e3 + 10;
int t, c[M][M];

void bfs(void){
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		pair<int, int> ne[3] = {
			make_pair(now.first, now.first),
			make_pair(now.first + now.second, now.first),
			make_pair(now.first - 1, now.second)
		};
		for(int i = 0; i < 3; i++){
			if(0 >= ne[i].first || ne[i].first >= M || c[ne[i].first][ne[i].second] != -1) continue;
			c[ne[i].first][ne[i].second] = c[now.first][now.second] + 1;
			q.push(ne[i]);
			if(ne[i].first == t){
				cout << c[ne[i].first][ne[i].second] + 1;
				return;
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	memset(c, -1, sizeof(c));
	//for(int i = 1; i <= t * 2; i++) c[i] = M * M;
	//c[1] = 0;
	bfs();
	//cout << c[t];
}