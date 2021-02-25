#include <iostream>
#include <algorithm>
using namespace std;
struct P{
	int y; int x;
};
const int M = 25;
const P D[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int r, c, an = 20;
char arr[M][M]; 

bool drop(P p){
	return 0 > p.y || p.y >= r || 0 > p.x || p.x >= c ? true : false;
}

void f(P c1, P c2, int mo){
	if(mo >= 10 || mo >= an) return;
	for(int i = 0; i < 4; i++){
		P c1_n = {c1.y + D[i].y, c1.x + D[i].x};
		P c2_n = {c2.y + D[i].y, c2.x + D[i].x};
		if(drop(c1_n) ^ drop(c2_n)){
			an = min(an, mo + 1);
			return;
		}
		else if(drop(c1_n) && drop(c2_n)) continue;
		if(arr[c1_n.y][c1_n.x] == '#') c1_n = c1;
		if(arr[c2_n.y][c2_n.x] == '#') c2_n = c2;
		f(c1_n, c2_n, mo + 1);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	P c1 = {-1, -1}, c2 = {-1, -1};
	for(int i = 0; i < r; i++){
		for(int k = 0; k < c; k++){
			cin >> arr[i][k];
			if(arr[i][k] == 'o'){
				c1.y == -1 ? c1 = {i, k} : c2 = {i, k};
			}
		}
	}
	// cout << c1.y << " " << c1.x << endl;
	// cout << c2.y << " " << c2.x << endl;
	f(c1, c2, 0);
	an == 20 ? cout << -1 : cout << an;
}