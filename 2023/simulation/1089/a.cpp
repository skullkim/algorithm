#include <iostream>
#include <cstdio>
#include <vector>
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
int cases = 0;
void generateAllPossibleNumbers(vector<int> number, int digits) {
	if (digits == allNumbers.size()) {
		int sum = 0;
		for (int i = 0; i < number.size(); i++) {
			sum *= 10;
			sum += number[i];
		}
		ans += sum;
		cases++;
		return;
	}

	for (int i = 0; i < allNumbers[digits].size(); i++) {
		number.push_back(allNumbers[digits][i]);
		generateAllPossibleNumbers(number, digits + 1);
		number.pop_back();
	}
}

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

//	for (int i = 0; i < allNumbers.size(); i++) {
//		cout << i + 1 << "번째:";
//		for (int k = 0; k < allNumbers[i].size(); k++) {
//			cout << allNumbers[i][k] << ", ";
//		}
//		cout << endl;
//	}
	
	if (!allNumbers.size()) {
		cout << -1;
		return 0;
	}

	vector<int> tmp;
	generateAllPossibleNumbers(tmp, 0);

	//cout << (double)ans / (double)cases;
	printf("%.6lf", (double)ans/cases);
}
