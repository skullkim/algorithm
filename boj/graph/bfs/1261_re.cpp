#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct P{
	int y; int x;
};
const int M = 105;
const P D[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int r, c, b[M][M], an = M*M, ch[M][M];
bool v[M][M];

void bfs(P st){
	queue<P> q;
	q.push(st);
	while(!q.empty()){
		P now = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			P ne = {now.y + D[i].y, now.x + D[i].x};
			if(0 >= ne.y || ne.y > r || 0 >= ne.x || ne.x > c) continue;
			int w = b[ne.y][ne.x] ? 1 : 0;
			if(ch[now.y][now.x] + w < ch[ne.y][ne.x]){
				ch[ne.y][ne.x] = ch[now.y][now.x] + w;
				q.push(ne);
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c >> r;
	char cht;
	for(int i = 1; i <= r; i++){
		for(int k = 1; k <= c; k++){
			cin >> cht;
			b[i][k] = cht - '0';
			ch[i][k] = M * M;
		}
	}
	ch[1][1] = 0;
	P tmp = {1, 1};
	bfs(tmp);
	cout << ch[r][c];
}