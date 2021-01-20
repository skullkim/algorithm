#include <iostream>
#include <algorithm>
using namespace std;

struct Pos{
	int y;
	int x;
};
const Pos DIREC[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int MAX = 30;
int row, col, ans = 1;
char board[MAX][MAX];
bool visited[MAX][MAX], alph_vi[MAX];

void calMaxLen(Pos curr, int len){
	visited[curr.y][curr.x] = true;
	alph_vi[board[curr.y][curr.x] - 'A'] = true;
	ans = max(ans, len);
	for(int i = 0; i < 4; i++){
		Pos next = {curr.y + DIREC[i].y, curr.x + DIREC[i].x};
		if(0 > next.y || next.y >= row || 0 > next.x || next.x >= col) continue;
		if(visited[next.y][next.x] || alph_vi[board[next.y][next.x] - 'A']) continue;
		calMaxLen(next, len + 1);
		visited[next.y][next.x] = false;
		alph_vi[board[next.y][next.x] - 'A'] = false;
		
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int k = 0; k < col; k++){
			cin >> board[i][k];
		}
	}
	calMaxLen({0, 0}, 1);	
	cout << ans;
}