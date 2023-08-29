#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int row, col;
int graph[10][10];
map<int, bool> squareNumbers;

bool isSquareNumber(int number) {
	int rootNumber = (int)sqrt(number);
	return rootNumber * rootNumber == number;
}

int generateMaxSquareNumber(int currRow, int rowGap, int currCol, int colGap) {
	int number = 0;
	int maxNumber = -1;
	while ((0 <= currRow && currRow < row) && (0 <= currCol && currCol < col)) {
		number *= 10;
		number += graph[currRow][currCol];
		if (isSquareNumber(number)) {
			maxNumber = max(maxNumber, number);
		}
		currRow += rowGap;
		currCol += colGap;
	}
	return maxNumber;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> row >> col;
	string tmp;
	for (int i = 0; i < row; i++) {
		cin >> tmp;
		for (int k = 0; k < col; k++) {
			graph[i][k] = tmp[k] - '0' ;
		}
	}

	int ans = -1;	

	if (row == 1 && col == 1) ans = graph[0][0];

	for (int startRow = 0; startRow < row; startRow++) {
		for (int startCol = 0; startCol < col; startCol++) {
			for (int rowGap = 0; rowGap < row; rowGap++) {
				for (int colGap = 0; colGap < col; colGap++) {
					if (rowGap == 0 && colGap == 0) continue;
					int v1 = generateMaxSquareNumber(startRow, rowGap, startCol, colGap);
					int v2 = generateMaxSquareNumber(startRow, -1 * rowGap, startCol, colGap);
					int v3 = generateMaxSquareNumber(startRow, rowGap, startCol, -1 * colGap);
					int v4 = generateMaxSquareNumber(startRow, -1 * rowGap, startCol, -1 * colGap);
					ans = max(ans, max(max(v1, v2), max(v3, v4)));
				}
			}
		}
	}
	cout << ans;
}
