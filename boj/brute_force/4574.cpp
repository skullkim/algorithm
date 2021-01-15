#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct Pos{
	int y;
	int x;
};
const int IDX = 10;
const int LEN = 9;
const Pos DIREC[2] = {{1, 0}, {0, 1}};
int board[IDX][IDX];
bool squars[IDX][IDX], cols[IDX][IDX], rows[IDX][IDX], domino[IDX][IDX];
bool is_ans = false;

int calSquar(Pos pos){
	return pos.y / 3 * 3 + pos.x / 3;
}

void findAns(int curr_s){
	if(curr_s == LEN * LEN){
		is_ans = true;
		return;
	}
	Pos curr = {curr_s / LEN, curr_s % LEN};
	if(board[curr.y][curr.x]){
		findAns(curr_s + 1);
		return;
	}
	for(int d = 0; d < 2; d++){
		Pos next = {curr.y + DIREC[d].y, curr.x + DIREC[d].x};
		if(0 > next.y || next.y >= LEN || 0 > next.x || next.x >= LEN || board[next.y][next.x]) continue;
		for(int i = 1; i <= LEN; i++){
			for(int k = 1; k <= LEN; k++){
				if(i == k || domino[i][k]) continue;
				int s1 = calSquar(curr), s2 = calSquar(next);
				if(squars[s1][i] || rows[curr.y][i] || cols[curr.x][i]) continue;
				if(squars[s2][k] || rows[next.y][k] || cols[next.x][k]) continue;
				squars[s1][i] = true; rows[curr.y][i] = true; cols[curr.x][i] = true;
				squars[s2][k] = true; rows[next.y][k] = true; cols[next.x][k] = true;
				domino[i][k] = true; domino[k][i] = true;
				board[curr.y][curr.x] = i; board[next.y][next.x] = k;
				findAns(curr_s + 1);
				if(is_ans) return;
				squars[s1][i] = false; rows[curr.y][i] = false; cols[curr.x][i] = false;
				squars[s2][k] = false; rows[next.y][k] = false; cols[next.x][k] = false;
				domino[i][k] = false; domino[k][i] = false;
				board[curr.y][curr.x] = 0; board[next.y][next.x] = 0;
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dominos;
	while(true){
		cin >> dominos;
		if(!dominos) return 0;
		memset(squars, false, sizeof(squars));
		memset(rows, false, sizeof(rows));
		memset(cols, false, sizeof(cols));
		memset(domino, false, sizeof(domino));
		memset(board, 0, sizeof(board));
		string loc1, loc2;
		int num1, num2;
		for(int i = 0; i < dominos; i++){
			cin >> num1 >> loc1 >> num2 >> loc2;
			Pos pos1 = {loc1[0] - 'A', loc1[1] - '1'};
			Pos pos2 = {loc2[0] - 'A', loc2[1] - '1'};
			int s1 = calSquar(pos1), s2 = calSquar(pos2);
			squars[s1][num1] = true; rows[pos1.y][num1] = true; cols[pos1.x][num1] = true;
			squars[s2][num2] = true; rows[pos2.y][num2] = true; cols[pos2.x][num2] = true;
			board[pos1.y][pos1.x] = num1; board[pos2.y][pos2.x] = num2;
			domino[num1][num2] = true; domino[num2][num1] = true;
		}
		for(int i = 1; i < IDX; i++){
			cin >> loc1;
			Pos pos = {loc1[0] - 'A', loc1[1] - '1'};
			int s = calSquar(pos);
			squars[s][i] = true; rows[pos.y][i] = true; cols[pos.x][i] = true;
			board[pos.y][pos.x] = i;
		}
		findAns(0);
		if(is_ans){
			static int sudokus = 1;
			cout << "Puzzle " << sudokus++ << "\n";
			for(int i = 0; i < LEN; i++){
				for(int k = 0; k < LEN; k++) cout << board[i][k];
				cout << endl;
			}
			is_ans = false;
		}
	}
}
