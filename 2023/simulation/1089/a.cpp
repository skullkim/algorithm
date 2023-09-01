#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const string NUMBERS[10][5] = {
	{ // 0
		"###",
		"#.#",
		"#.#",
		"#.#",
		"###"
	}, { // 1
		"..#",
		"..#",
		"..#",
		"..#",
		"..#"
	}, { // 2
		"###",
		"..#",
		"###",
		"#..",
		"###"
	}, { // 3
		"###",
		"..#",
		"###",
		"..#",
		"###"
	}, { // 4
		"#.#",
		"#.#",
		"###",
		"..#",
		"..#"
	}, { // 5
		"###",
		"#..",
		"###",
		"..#",
		"###"
	}, { // 6
		"###",
		"#..",
		"###",
		"#.#",
		"###"
	}, { // 7
		"###",
		"..#",
		"..#",
		"..#",
		"..#"
	}, { // 8
		"###",
		"#.#",
		"###",
		"#.#",
		"###"
	}, { // 9
		"###",
		"#.#",
		"###",
		"..#",
		"###"
	}
};

int floors;
string board[5];
vector<vector<int>> allNumbers;

void generateSimilarNumber(int startPoint) {
	vector<int> possibleNumbers;
	for (int i = 0; i < 10; i++) {
		bool isSimilarNumber = true;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (NUMBERS[i][r][c] == '.' && board[r][startPoint + c] == '#') {
					isSimilarNumber = false;
					break;
				}
			}
			if (!isSimilarNumber) break;	
		}
		if (!isSimilarNumber) continue;
		possibleNumbers.push_back(i);
	}
	if (possibleNumbers.size() == 0) return;
	allNumbers.push_back(possibleNumbers);
}

long long ans = 0;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> floors;
	for (int i = 0; i < 5; i++) {
		cin >> board[i];
	}

	for (int startIndex = 0; startIndex < 4 * floors; startIndex += 4) {
		generateSimilarNumber(startIndex);
	}

	if (!allNumbers.size()) {
		cout << -1;
		return 0;
	}

	int possibleCases = 1;
	for (int i = 0; i < allNumbers.size(); i++) {
		possibleCases *= allNumbers[i].size();
	}
	
	int digits = pow(10, allNumbers.size() - 1);
	for (int i = 0; i < allNumbers.size(); i++) {
		int uses = possibleCases / allNumbers[i].size();
		int sum = 0;
		for (int k = 0; k < allNumbers[i].size(); k++) {
			sum += allNumbers[i][k];
		}
		ans += ((long long)uses * sum * digits);
		digits /= 10;
	}

	cout << (double)ans / possibleCases;
}
