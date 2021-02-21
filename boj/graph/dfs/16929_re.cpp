#include <iostream>
#include <cstring>
using namespace std;

struct P{
	int y; int x;
};
const int M = 60;
const P D[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
char arr[M][M];
int r, c;
bool v[M][M], an = false;

void dfs(const P &F, P cur, int d){
	v[cur.y][cur.x] = true;
	for(int i = 0; i < 4; i++){
		P ne = {cur.y + D[i].y, cur.x + D[i].x};
		if(0 > ne.y || ne.y >= r || 0 > ne.x || ne.x >= c) continue;
		if(d >= 4 && ne.y == F.y && ne.x == F.x){
			an = true;
			return;
		}
		else if(v[ne.y][ne.x] || (arr[ne.y][ne.x] != arr[F.y][F.x])) continue;
		dfs(F, ne, d + 1);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int k = 0; k < c; k++) cin >> arr[i][k];
	}
	for(int i = 0; i < r; i++){
		for(int k = 0; k < c; k++){
			P tmp = {i, k};
			an = false;
			memset(v, false, sizeof(v));
			dfs(tmp, tmp, 1);
			if(an){
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}