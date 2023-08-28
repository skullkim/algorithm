#include <iostream>
using namespace std;

int ans = 0;
int row, col;
bool hasNemo[26][26];

bool isSquare(int r, int c) {
	int previousRow = r - 1, previousCol = c - 1;
	if ((1 <= previousRow && previousRow <= row) && (1 <= previousCol && previousCol <= col)) {
		return hasNemo[previousRow][previousCol]
			&& hasNemo[previousRow][c]
			&& hasNemo[r][previousCol];
	}
	return false;
}

void f(int currRow, int currCol) {
	if (currRow == row + 1 && currCol == 1) {
		ans++;
		return;
	}
	int nextRow = currRow, nextCol = currCol;

	if (currCol == col) {
		nextRow++;
		nextCol = 1;
	} else nextCol++;

	f(nextRow, nextCol);

	if (isSquare(currRow, currCol)) {
		return;
	}
	hasNemo[currRow][currCol] = true;
	f(nextRow, nextCol);
	hasNemo[currRow][currCol] = false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> row >> col;

	f(1, 1);

	cout << ans;
}
