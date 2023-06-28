#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct Pos {
	int y;
	int x;
};

typedef pair<Pos, string> pps;

const char PLUS = '+';
const char MINUS = '-';
const char MUL = '*';
const Pos DIRECTION[2] = {{1, 0}, {0, 1}};

int toInt(char c) {
	return c - '0';
}

int parseOperation(string operation) {
	int result = toInt(operation[0]);
	for (int i = 1; i < operation.size() - 1; i += 2) {
		if (operation[i] == PLUS) result += toInt(operation[i + 1]); 
		else if (operation[i] == MINUS) result -= toInt(operation[i + 1]);
		else if (operation[i] == MUL) result *= toInt(operation[i + 1]);
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int boardSize;
	string board[5][5], tmp;
	cin >> boardSize;
	for (int i = 0; i < boardSize; i++) {
		for (int k = 0; k < boardSize; k++) {
			cin >> tmp;
			board[i][k] = tmp;
		}
	}

	int maxVal = -1, minVal = 1e9;
	Pos start = {0, 0};
	pps p = make_pair(start, board[start.y][start.x]);
	queue<pps> q;
	q.push(p);
	while (!q.empty()) {
		pps curr = q.front();
		q.pop();
		if (curr.first.y == boardSize - 1 && curr.first.x == boardSize - 1) {
			int result = parseOperation(curr.second);
			//cout << curr.first.y << " " << curr.first.x << " " << curr.second << " " << result << endl;
			maxVal = max(maxVal, result);
			minVal = min(minVal, result);
			continue;
		}
		for (int i = 0; i < 2; i++) {
			Pos next = {curr.first.y + DIRECTION[i].y, curr.first.x + DIRECTION[i].x};
			if (0 > next.y || next.y >= boardSize || 0 > next.x || next.x >= boardSize) continue;
			string nextOperation = curr.second + board[next.y][next.x];
			pps node = make_pair(next, nextOperation);
			q.push(node);
		}
	}
	cout << maxVal << " " << minVal;
}
