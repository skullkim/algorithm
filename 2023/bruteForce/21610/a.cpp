#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Pos {
	int y;
	int x;

	bool operator==(const Pos& pos) const {
		return pos.y == y && pos.x == x;
	}
};

struct MovingInfo {
	int direction;
	int spaces;
};

const Pos DIRECTIONS[8] = {
	{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
	{0, 1}, {1, 1}, {1, 0}, {1, -1}
};
const Pos CLOUDY[4] = {{-1, 0}, {-1, 1}, {-2, 0}, {-2, 1}};
const Pos COPYABLE[4] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const int MAX_N = 100;

int board[MAX_N][MAX_N];
int n, m;
vector<MovingInfo> movingInfos;

void printCloudy(vector<Pos> c) {
	for (int i = 0; i < c.size(); i++) {
		cout << c[i].y << " " << c[i].x << endl;
	}
	cout << endl << endl;
}

void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << board[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<Pos> generateFirstCloudy(int n) {
	vector<Pos> cloudy;
	for (int i = 0; i < 4; i++) {
		Pos tmp = {n + CLOUDY[i].y, CLOUDY[i].x};
		cloudy.push_back(tmp);
	}
	return cloudy;
}

vector<Pos> moveCloud(MovingInfo movingInfo, vector<Pos> currCloudy) {
	vector<Pos> cloudy;
//	cout << "curr:" << endl;
//	printCloudy(currCloudy);
	for (int i = 0; i < currCloudy.size(); i++) {
		Pos next = currCloudy[i];
		Pos pos = {next.y + DIRECTIONS[movingInfo.direction].y * movingInfo.spaces,
			next.x + DIRECTIONS[movingInfo.direction].x * movingInfo.spaces};
		if (pos.y < 0) pos.y = abs(n + pos.y);
		else if (pos.y >=0) pos.y = pos.y % n;
		if (pos.x < 0) pos.x = n + pos.x;
		else if (pos.x >=0) pos.x = pos.x % n;
		cloudy.push_back(pos);
	}
//	cout << "new:" << endl;
//	printCloudy(cloudy);
	return cloudy;
}

void rain(vector<Pos> currCloudy) {
//	cout << "board before rain:" << endl;
//	printBoard();
	for (int i = 0; i < currCloudy.size(); i++) {
		Pos pos = currCloudy[i];
		board[pos.y][pos.x]++;
	}
//	cout << "board after rain:" << endl;
//	printBoard();
}

void copyWater(vector<Pos> currCloudy) {
//	cout << "before copy:" << endl;
//	printBoard();
	for (int i = 0; i < currCloudy.size(); i++) {
		int wateredBoards = 0;
		for (int k = 0; k < 4; k++) {
			Pos pos = {currCloudy[i].y + COPYABLE[k].y, currCloudy[i].x + COPYABLE[k].x};
			if (0 > pos.y || pos.y > n || 0 > pos.x || pos.x > n || !board[pos.y][pos.x]) continue;
			wateredBoards++;
		}
		board[currCloudy[i].y][currCloudy[i].x] += wateredBoards; 
	}
//	cout << "after copy:" << endl;
//	printBoard();
}

vector<Pos> generateNewCloudy(vector<Pos> currCloudy) {
	vector<Pos> newCloudy;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			Pos pos = {i, k};
			auto it = find(currCloudy.begin(), currCloudy.end(), pos); 
			if (it != currCloudy.end() || board[i][k] <= 1) continue;
			board[i][k] -= 2;
			newCloudy.push_back(pos);
		}
	}
	return newCloudy;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0, tmp; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> board[i][k];
		}
	}
	for (int i = 0, direction, spaces; i < m; i++) {
		cin >> direction >> spaces;
		MovingInfo movingInfo = {direction - 1, spaces};
		movingInfos.push_back(movingInfo);
	}
	
	vector<Pos> currCloudy = generateFirstCloudy(n);
	for (int i = 0; i < movingInfos.size(); i++) {
		MovingInfo movingInfo = movingInfos[i];
		currCloudy = moveCloud(movingInfo, currCloudy);
		rain(currCloudy);
		copyWater(currCloudy);
		currCloudy = generateNewCloudy(currCloudy);
		cout << "final:" << endl;
		printBoard();
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
		cout << board[i][k] << " ";	
			sum += board[i][k];
		}
		cout << endl;
	}
	cout << sum;
}
