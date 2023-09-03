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
			// board에 존재하지 않는 문자면 추가하지 않는다
			if (!boardChars[ch]) {
				exist = false;
				break;
			}
			if (!chCount[ch]) chCount[ch] = 1;
			else chCount[ch]++;
		}
		
		if (!exist) continue;
		// board에 있는 임의의 알파벳 겟수 < 필요한 알파벳 갯수
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

		for (int i = 0; i < existedWords.size(); i++) {
			cout << existedWords[i] << "\n";
		}

		map<char, int> used;
		int minUsed = MAX, maxUsed = 0;
		int uniqueChars = boardChars.size();
		// board에 있는 문자들을 순회한다.
		// boardChars의 키값을 고유하므로 중복 체크가 필요 없다
		for (auto b : boardChars) {
			char boardChar = b.first;
			used[boardChar] = 0;
			for (int k = 0; k < existedWords.size(); k++) {
				bool hasChar = false;
				for (int c = 0; c < existedWords[k].size(); c++) {
					char ch = existedWords[k][c];
					// 문자열의 문자가 board에 존재하지 않으면
					if (boardChar != ch) continue;
					// 기존에 탐색한 board의 문자 중 사용하지 않은 문자면
					if (!used[ch]) {
						used[ch] = 1;
						uniqueChars--;
					}
					else used[ch]++;
					// board 문자의 최대, 최소 사용 횟수를 갱신한다.
					minUsed = min(minUsed, used[ch]);
					maxUsed = max(maxUsed, used[ch]);
					hasChar = true;
					if (hasChar) {
						break;
					}
				}
			}
		}
		
		if (uniqueChars) { // board에 있는 문자 중 사전에 있는 문자열 스펠링에 사용하지 않은 문제가 있으면
			minUsed = 0;
		}

		// board문자 중 최소, 최대로 많이 사용만 문자들을 찾는다.
		string minUsedChars = "", maxUsedChars = "";
		for (auto u : used) {
			if (minUsed == u.second) minUsedChars += u.first;
			if (maxUsed == u.second) maxUsedChars += u.first;
		}
		
		cout << minUsedChars << " " << minUsed << " "
			<< maxUsedChars << " " << maxUsed << "\n";
	}
}
