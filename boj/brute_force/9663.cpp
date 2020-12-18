#include <iostream>
using namespace std;

const int MAX = 17;
int queens, ans = 0;
bool board[MAX][MAX];

bool possible(int col, int row){
	int c = col -1, r = row - 1;
	while(1 <= c && c <= queens && 1 <= r && r <= queens){
		if(board[r][c]) return false;
		r--; c--;
	}
	c = col - 1; r = row + 1;
	while(1 <= c && c <= queens && 1 <= r && r <= queens){
		if(board[r][c]) return false;
		r--; c++;
	}
	c = col - 1, r = row;
	while(1 <= c && c <= queens && 1 <= r && r <= queens){
		if(board[r][c]) return false;
		c--;
	}
	c = col + 1, r = row;
	while(1 <= c && c <= queens && 1 <= r && r <= queens){
		if(board[r][c]) return false;
		c++;
	}
	c = col - 1; r = row + 1;
	while(1 <= c && c <= queens && 1 <= r && r <= queens){
		if(board[r][c]) return false;
		r++; c--;
	}
	c = col + 1; r = row + 1;
	while(1 <= c && c <= queens && 1 <= r && r <= queens){
		if(board[r][c]) return false;
		r++; c++;
	}	
	return true;
}

void findAllCases(int curr_queen){
	if(curr_queen == queens + 1){
		ans++;
		return;
	}
	for(int i = 1; i <= queens; i++){
		if(!possible(curr_queen, i)) continue;
		board[i][curr_queen] = true;
		findAllCases(curr_queen + 1);
		board[i][curr_queen] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> queens;
	findAllCases(1);	
	cout << ans;
}
