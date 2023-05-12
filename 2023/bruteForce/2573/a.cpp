#include <iostream>
#include <vector>

using namespace std;

struct Pos {
	int y;
	int x;
};

const Pos DI[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int MAX_IDX = 301;
int rows, cols;
vector<vector<int>> board(MAX_IDX);
vector<Pos> ices;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> rows >> cols;
	for (int i = 0; i < rows; i++) {
		board[i].resize(cols);
		for (int k = 0; k < cols; k++) {
			cin >> board[i][k];
			if (board[i][k] != 0) {
				Pos pos = {i, k};
				ices.push_back(pos);
			}
		}
	}
	
	int years = 0;
	while(true) {
		int iceBurgs = 0;
		vector<vector<int>> tmpBoard = board;
		for (int i = 0; i < ices.size(); i++) {
			Pos currPos = ices[i];
			int iceHeight = board[currPos.y][currPos.x];
			if (!iceHeight) continue; 
			int seas = 0;
			for (int k = 0; k < 4; k++) {
				Pos neighbor = {currPos.y + DI[k].y, currPos.x + DI[k].x};
				if (0 > neighbor.y || neighbor.y >= rows || 0 > neighbor.x || neighbor.x >= cols) continue;
				if (board[neighbor.y][neighbor.x]) continue;
				seas++;
			}
//
//			cout << "seas: " << seas << endl;
//			cout << currPos.y << " " << currPos.x << endl;
//			cout << "iceBurg:" << iceBurgs << endl;
//			for (int i = 0; i < rows; i++) {
//				for (int k = 0; k < cols; k++) {
//					cout << tmpBoard[i][k] << " ";
//				}
//				cout << endl;
//			}
//			cout << endl;



			if (seas == 4) iceBurgs++;
			if (iceBurgs >= 2) break;
			tmpBoard[currPos.y][currPos.x] = iceHeight - seas >= 0 ? iceHeight - seas : 0;
		}
		board = tmpBoard;

//		cout << "=============================================" << endl;
//		cout << "iceBurg:" << iceBurgs << endl;
//		for (int i = 0; i < rows; i++) {
//			for (int k = 0; k < cols; k++) {
//				cout << board[i][k] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;

		if (iceBurgs >=2) break;
		vector<Pos> tmp;
		for (int i = 0; i < ices.size(); i++) {
			if (board[ices[i].y][ices[i].x] == 0) continue;
			tmp.push_back(ices[i]);
		}
		ices = tmp;
		if (ices.size() == 0) {
			years = 0;
			break;
		}
		years++;
	}
	cout << years;
}
