#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<char, int> countBoardChar(string board) {
	map<char, int> boardChar;
	for (int i = 0; i < board.size(); i++) {
		char ch = board[i];
		if (!boardChar[ch]) boardChar[ch] = 1;
		else boardChar[ch]++;
	}
	return boardChar;
}

vector<string> filterNonExistentWords(map<char, int> boardChars, vector<string> dictionary) {
	vector<string> existedWords;
	for (int dicIdx = 0; dicIdx < dictionary.size(); dicIdx++) {
		bool exist = true;
		map<char, int> chCount;
		for (int c = 0; c < dictionary[dicIdx].size(); c++) {
			char ch = dictionary[dicIdx][c];
			if (!boardChars[ch]) {
				exist = false;
				break;
			}
			if (!chCount[ch]) chCount[ch] = 1;
			else chCount[ch]++;
		}

		for (auto ch : chCount) {
			if (boardChars[ch.first] < ch.second) {
				exist = false;
				break;
			}
		}

		if (exist) existedWords.push_back(dictionary[dicIdx]);
	}

	return existedWords;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int MAX = 210000;

	vector<string> dictionary;
	string str;
	while (true) {
		cin >> str;
		if (str == "-") break;
		dictionary.push_back(str);
	}

	while (true) {
		string board;
		cin >> board;

		if (board == "#") break;

		map<char, int> boardChars = countBoardChar(board);
		vector<string> existedWords = filterNonExistentWords(boardChars, dictionary);

		map<char, int> used;
		int minUsed = MAX, maxUsed = 0;
		int uniqueChars = boardChars.size();
		for (auto b : boardChars) {
			char boardChar = b.first;
			used[boardChar] = 0;
			for (int k = 0; k < existedWords.size(); k++) {
				bool hasChar = false;
				for (int c = 0; c < existedWords[k].size(); c++) {
					char ch = existedWords[k][c];
					if (boardChar != ch) continue;
					if (!used[ch]) {
						used[ch] = 1;
						uniqueChars--;
					}
					else used[ch]++;
					minUsed = min(minUsed, used[ch]);
					maxUsed = max(maxUsed, used[ch]);
					hasChar = true;
					if (hasChar) {
						break;
					}
				}
			}
		}
		
		if (uniqueChars) {
			minUsed = 0;
		}

		string minUsedChars = "", maxUsedChars = "";
		for (auto u : used) {
			if (minUsed == u.second) minUsedChars += u.first;
			if (maxUsed == u.second) maxUsedChars += u.first;
		}
		
		cout << minUsedChars << " " << minUsed << " "
			<< maxUsedChars << " " << maxUsed << "\n";
	}
}
