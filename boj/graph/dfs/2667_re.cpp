#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct P{
	int y; int x;
};
const P D[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int M = 30;
int b[M][M], n;
bool v[M][M];
int s = 0, cn = 1;
priority_queue<int, vector<int>, greater<int>> pq;

void f(P c){
	v[c.y][c.x] = true;
	for(int i = 0; i < 4; i++){
		P ne = {c.y + D[i].y, c.x + D[i].x};
		if(0 > ne.y || ne.y >= n || 0 > ne.x || ne.x >= n || v[ne.y][ne.x] || b[ne.y][ne.x] == 0) continue;
		v[ne.y][ne.x] = true;
		cn++;
		f(ne);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	char ch;
	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++){
			cin >> ch;
			b[i][k] = ch - '0';
		}
	}


	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++){
			if(!v[i][k] && b[i][k] == 1){
				P p = {i, k};
				f(p);
				pq.push(cn);
				cn = 1;
			}
		}
	}
	cout << pq.size() << "\n";
	while(!pq.empty()){
		cout << pq.top() << "\n";
		pq.pop();
	}
}
