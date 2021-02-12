#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct P{
	int y; int x;
};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX = 55;
	const P D[8] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
	while(true){
		int b[MAX][MAX];
		bool v[MAX][MAX];
		memset(v, false, sizeof(v));
		int is, r, c;
		cin >> c >> r;
		if(r == 0 && c == 0){
			return 0;
		}
		char tm;
		for(int i = 0; i < r; i++){
			for(int k = 0; k < c; k++){
				cin >> tm;
				b[i][k] = (tm - '0');
			}
		}
		int an = 0;
		for(int i = 0; i < r; i++){
			for(int k = 0; k < c; k++){
				if(b[i][k] != 1 || v[i][k]) continue;
				queue<P> q;
				P p = {i, k};
				q.push(p);
				while(!q.empty()){
					P cu = q.front();
					q.pop();
					v[cu.y][cu.x] = true;
					for(int j = 0; j < 8; j++){
						P ne = {cu.y + D[j].y, cu.x + D[j].x};
						if(0 > ne.y || ne.y >= r || 0 > ne.x || ne.x >= c) continue;
						if(v[ne.y][ne.x] || b[ne.y][ne.x] != 1) continue;
						q.push(ne);
					}
				}
				an++;
			}
		}
		cout << an << "\n";
	}
}