#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int IDX = 58;
const string DELIMITER = " => ";
int nodes;
vector<vector<int>> graph(IDX);
bool isSame[IDX][IDX], isSameChar[IDX], vi[IDX][IDX];
vector<pair<char, char>> answer;
vector<int> chars;

int charToIndex(char c) {
	return c - 'A';
}

char conditionToChar(int condition) {
	return condition + 'A';
}

void addAnswer(int condition1, int condition2) {
	char c1 = conditionToChar(condition1), c2 = conditionToChar(condition2);
	pair<char, char> tmp = make_pair(c1, c2);
	answer.push_back(tmp);
}

void bfs(int condition) {
	queue<int> q;
	q.push(condition);
	while(!q.empty()) {
		int currCondition = q.front();
		q.pop();
		for (int i = 0; i < graph[currCondition].size(); i++) {
			int nextCondition = graph[currCondition][i];
//			if (!vi[currCondition][nextCondition]) {
//				addAnswer(currCondition, nextCondition);
//				vi[currCondition][nextCondition] = true;
//				q.push(nextCondition);
//			}
			if (condition == nextCondition) continue;
			if (!vi[condition][nextCondition]) {
				addAnswer(condition, nextCondition);
				vi[condition][nextCondition] = true;
				q.push(nextCondition);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string tmp;
	char c, c2;
	cin >> nodes;
	for (int i = 0; i < nodes; i++) {
		cin >> c >> tmp >> c2;
		int condition1 = charToIndex(c), condition2 = charToIndex(c2);
		if (isSame[condition1][condition2]) continue;
		graph[condition1].push_back(condition2);
		isSame[condition1][condition2] = true;
		if (!isSameChar[condition1]) {
			chars.push_back(condition1);
			isSameChar[condition1] = true;
		}
		if (!isSameChar[condition2]) {
			chars.push_back(condition2);
			isSameChar[condition2] = true;
		}
	}

	for (int i = 0; i < chars.size(); i++) {
//		cout << "================================================" << endl;
//		cout << (char)('A' + chars[i]) << endl;
		bfs(chars[i]);
//		for (int i = 0; i < answer.size(); i++) {
//			cout << answer[i].first << DELIMITER << answer[i].second << "\n";
//		}
	}

	stable_sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << DELIMITER << answer[i].second << "\n";
	}


}
