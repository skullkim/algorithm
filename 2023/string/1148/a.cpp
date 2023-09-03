#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> dictionary;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	while (true) {
		cin >> str;
		if (str == "-") break;
		dictionary.push_back(str);
	}

	while (true) {
		map<char, int> priority;
		string board;
		cin >> board;

		if (board == "#") break;

		map<char, int> boardChar;
		for (int i = 0; i < board.size(); i++) {
			char c = board[i];
			if (!boardChar[c]) {
				boardChar[c] = 1;
				priority[c] = 1;
			}
			else boardChar[c]++;
		}

		vector<string> existWords;
		for (int i = 0; i < dictionary.size(); i++) {
			map<char, int> ch;
			bool canMake = true;
			for (int k = 0; k < dictionary[i].size(); k++) {
				char c = dictionary[i][k];
				if (!ch[c]) ch[c] = 1;
				else ch[c]++;

				if (ch[c] > boardChar[c] || !priority[c]) {
					canMake = false;
					break;
				}
			}
			if (canMake) existWords.push_back(dictionary[i]);
		}

		map<char, bool> vi;
		int minUsed = 200010, maxUsed = 0;
		for (int i = 0; i < board.size(); i++) {
			if (vi[board[i]]) continue;
			vi[board[i]] = true;
			for (int k = 0; k < existWords.size(); k++) {
				bool hasSameChar = false;
				for (int c = 0; c < existWords[k].size(); c++) {
					if (board[i] != existWords[k][c]) continue;
					priority[board[i]]++;
					//cout << board[i] << " " << priority[board[i]] << endl;
					minUsed = min(minUsed, priority[board[i]] - 1);
					maxUsed = max(maxUsed, priority[board[i]] - 1);
					break;
				}
			}
		}

		for (int i = 0; i < board.size(); i++) {
			if (priority[board[i]] == 1) {
				minUsed = 0;
				break;
			}
		}

		string minUsedChar = "", maxUsedChar = "";
		for (auto it : priority) {
			if (minUsed == it.second - 1) minUsedChar += it.first;
			if (maxUsed == it.second - 1) maxUsedChar += it.first;
		}
		cout << minUsedChar << " " << minUsed << " " 
			<< maxUsedChar << " " << maxUsed << "\n";
	}
}
