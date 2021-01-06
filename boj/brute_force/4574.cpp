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
const Pos DIREC[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int board[IDX][IDX];
bool squars[IDX][IDX], cols[IDX][IDX], rows[IDX][IDX];
int dominos;

int calSquars(Pos pos){
	double y = (double)pos.y / 3;
	double x = (double)pos.x / 3;
	if(y <= 1.0 && x <= 1.0) return 1;
	else if(y <= 1.0 && 1.0 < x && x <= 2.0) return 2;
	else if(y <= 1.0 && 2.0 < x && x <= 3.0) return 3;
	else if(1.0 < y && y <= 2.0 && x <= 1.0) return 4;
	else if(1.0 < y && y <= 2.0 && 1.0 < x && x <= 2.0) return 5;
	else if(1.0 < y && y <= 2.0 && 2.0 < x && x <= 3.0) return 6;
	else if(2.0 < y && y <= 3.0 && x <= 1.0) return 7;
	else if(2.0 < y && y <= 3.0 && 1.0 < x && x <= 2.0) return 8;
	else if(2.0 < y && y <= 3.0 && 2.0 < x && x <= 3.0) return 9;
	return -1;
}

bool isAns(){
	for(int i = 1; i < IDX; i++){
		for(int k = 1; k < IDX; k++){
			//if(board[i][k] == 0 || !squars[calSquars({i, k})][k] || !rows[i][k] || !cols[k][i]) return false; 
			int num = board[i][k];
			if(num && squars[calSquars({i, k})][num] && rows[i][num] && cols[k][num]) continue;
			else return false;
		}
	}
	return true;
}

bool is_ans =  false;
vector<Pos> empty_pos;

void findAns(int empty_idx){
	if(empty_pos.size() == empty_idx) cout << empty_idx << endl;
	while(board[empty_pos[empty_idx].y][empty_pos[empty_idx].x]) empty_idx++;
	if(empty_pos.size() >= empty_idx && isAns()){
		is_ans = true;
		return;
	}
	Pos curr_pos = empty_pos[empty_idx];
	for(int i = 1; i < IDX; i++){
		int curr_sqr = calSquars(curr_pos);
		if(squars[curr_sqr][i] || rows[curr_pos.y][i] || cols[curr_pos.x][i]) continue;
		board[curr_pos.y][curr_pos.x] = i;
		squars[curr_sqr][i] = true; rows[curr_pos.y][i] = true; cols[curr_pos.x][i] = true;
		for(int k = 0; k < 4; k++){
			Pos next_pos = {curr_pos.y + DIREC[k].y, curr_pos.x + DIREC[k].x};
			int next_sqr = calSquars(next_pos);
			if(0 >= next_pos.y || next_pos.y >= IDX || 0 >= next_pos.x || next_pos.x >= IDX || board[next_pos.y][next_pos.x]) continue;
			for(int n = 1; n < IDX; n++){
				if(squars[next_sqr][n] || rows[next_pos.y][n] || cols[next_pos.x][n]) continue;
				board[next_pos.y][next_pos.x] = n;
				squars[next_sqr][n] = true; rows[next_pos.y][n] = true; cols[next_pos.x][n] = true;
				findAns(empty_idx + 1);
				if(is_ans) return;
				board[next_pos.y][next_pos.x] = 0;
				squars[next_sqr][n] = false; rows[next_pos.y][n] = false; cols[next_pos.x][n] = false;
			}
		}
		board[curr_pos.y][curr_pos.x] = 0;
		squars[curr_sqr][i] = false; rows[curr_pos.y][i] = false; cols[curr_pos.x][i] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int puzzles = 1;
	while(true){
		memset(squars, false, sizeof(squars));
		memset(rows, false, sizeof(rows));
		memset(cols, false, sizeof(cols));
		cin >> dominos;
		if(!dominos) return 0;
		int num;
		string loc;
		for(int i = 0; i < dominos; i++){
			for(int k = 0; k < 2; k++){
				cin >> num >> loc;
				Pos p = {loc[0] - 'A' + 1, loc[1] - '0'};
				board[p.y][p.x] = num;
				squars[calSquars(p)][num] = true;
				rows[p.y][num] = true;
				cols[p.x][num] = true;
			}
		}
		for(int i = 1; i <= 9; i++){
			cin >> loc;
			Pos p = {loc[0] - 'A' + 1, loc[1] - '0'};
			board[p.y][p.x] = i;
			squars[calSquars(p)][i] = true;
			rows[p.y][i] = true;
			cols[p.x][i] = true;
		}
		for(int i = 1; i < IDX; i++){
			for(int k = 1; k < IDX; k++){
				if(board[i][k] == 0) empty_pos.push_back({i, k});
			}
		}
		findAns(0);
		cout << "Puzzle " << puzzles++ << "\n";
		for(int i = 1; i <= 9; i++){
			for(int k = 1; k <= 9; k++) cout << board[i][k];
			cout << "\n";
		}
	}
}
