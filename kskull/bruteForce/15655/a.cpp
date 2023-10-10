#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void print(vector<int> s) {
	for (auto ss : s ) {
		cout << ss << " ";
	}
	cout << "\n";
	return;
}

void f (vector<int> sequence, vector<int> answer, int idx, int length) {
	if (answer.size() == length) {
		for (auto num : answer) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < sequence.size(); i++) {
		answer.push_back(sequence[i]);
		f(sequence, answer, i + 1, length);
		answer.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int numbers, length;
	vector<int> sequence;
	cin >> numbers >> length;
	for (int i = 0, tmp; i < numbers; i++) {
		cin >> tmp;
		sequence.push_back(tmp);
	}

	sort(sequence.begin(), sequence.end());
	vector<int> answer;
//	bool vi[length];
//	memset(vi, false, sizeof(vi));
	f(sequence, answer, 0, length);
}
