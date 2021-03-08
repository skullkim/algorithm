#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct Pos{
	int y; int x;
};
enum{UP, DOWN, LEFT, RIGHT};
const int MAX = 25;
const Pos DIRECTION[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int len, ans = -1;

bool findBlocks(int board[MAX][MAX], deque<int>& dq, bool combined, const Pos& CURR_POS){
	if(!combined && !dq.empty() && dq.back() == board[CURR_POS.y][CURR_POS.x]){
		int tmp = dq.back() + board[CURR_POS.y][CURR_POS.x];
		dq.pop_back();
		dq.push_back(tmp);
		combined = true;
	}
	else{
		combined = false;
		dq.push_back(board[CURR_POS.y][CURR_POS.x]);
	}
	board[CURR_POS.y][CURR_POS.x] = 0;
	return combined;
}

void moveBlocksRow(int board[MAX][MAX], deque<int>& dq, const int& R, const int& DIREC){
	int next_c = DIREC == UP ? 0 : len - 1;
	while(!dq.empty()){
		ans = max(ans, dq.front());
		board[R][next_c] = dq.front();
		dq.pop_front();
		DIREC == UP ? next_c++ : next_c--;
	}
	return;
}

void moveBlocksCol(int board[MAX][MAX], deque<int>& dq, const int& C, const int& DIREC){
	int next_r = DIREC == LEFT ? 0 : len - 1;
	while(!dq.empty()){
		ans = max(ans, dq.front());
		board[next_r][C] = dq.front();
		dq.pop_front();
		DIREC == LEFT ? next_r++ : next_r--;
	}
	return;
}

void playGame(int board[MAX][MAX], int moves){
	if(moves >= 5) return;
	for(int i = 0; i < 4; i++){
		Pos next = DIRECTION[i];
		switch (i){
			case UP:{
				deque<int> dq;
				bool combined = false;
				for(int c = 0; c < len; c++){
					for(int r = 0; r < len; r++){
						if(!board[r][c]) continue;
						Pos tmp = {r, c};
						combined = findBlocks(board, dq, combined, tmp);			
					}
					moveBlocksCol(board, dq, c, UP);
				}
				break;
			}
			case DOWN:{
				deque<int> dq;
				int combined = false;
				for(int c = 0; c < len; c++){
					for(int r = len - 1; r >= 0; r--){
						if(!board[r][c]) continue;
						Pos tmp = {r, c};
						combined = findBlocks(board, dq, combined, tmp);
					}
					moveBlocksCol(board, dq, c, DOWN);
				}
				break;
			}
			case LEFT:{
				deque<int> dq;
				int combined = false;
				for(int r = 0; r < len; r++){
					for(int c = 0; c < len; c++){
						if(!board[r][c]) continue;
						Pos tmp = {r, c};
						combined = findBlocks(board, dq, combined, tmp);
					}
					moveBlocksRow(board, dq, r, LEFT);
				}
				break;
			}
			case RIGHT:{
				deque<int> dq;
				int combined = false;
				for(int r = 0; r < len; r++){
					for(int c = len - 1; c >= 0; c--){
						if(!board[r][c]) continue;
						Pos tmp = {r, c};
						combined = findBlocks(board, dq, combined, tmp);
					}
					moveBlocksRow(board, dq, r, RIGHT);
				}
				break;
			}
		}
		playGame(board, moves + 1);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> len;
	int board[MAX][MAX];
	for(int i = 0; i < len; i++){
		for(int k = 0; k < len; k++) cin >> board[i][k];
	}
	playGame(board, 0);
	cout << ans;
}
