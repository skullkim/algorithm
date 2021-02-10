#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct P{
	int y; int x;
};
const int M = 510;
const P D[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const P h [4][4] = {
	{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}}
};
int b[M][M], an = -1;
int r, c;
bool v[M][M];

void dfs(P cu, int nu, int s){
	if(nu == 4){
		//cout << "a";
		//cout << s << "\n";
		an = max(an, s - b[cu.y][cu.x]);
		return;
	}
	v[cu.y][cu.x] = true;
	for(int i = 0; i < 4; i++){
		P n = {cu.y + D[i].y, cu.x + D[i].x};
		if(0 > n.y || n.y >= r || 0 > n.x || n.x >= c) continue;
		if(v[n.y][n.x]) continue;
		dfs(n, nu + 1, s + b[n.y][n.x]);
		v[n.y][n.x] = false;
	}
}

void fh(P cu){
	for(int i = 0; i < 4; i++){
		int s = 0;
		for(int k = 0; k < 4; k++){
			P n = {cu.y + h[i][k].y, cu.x + h[i][k].x};
			if(0 > n.y || n.y >= r || 0 > n.x || n.x >= c){
				s = -1;
				break;
			}
			s += b[n.y][n.x];
		}
		an = max(an, s);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int k = 0; k < c; k++){
			cin >> b[i][k];
		}
	}
	for(int i = 0; i < r; i++){
		for(int k = 0; k < c; k++){
			dfs({i, k}, 0, b[i][k]);
			v[i][k] = false;
			fh({i, k});
		}
	}
	cout << an;
}