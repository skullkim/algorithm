#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void f(vector<int> sequence, vector<int> answer, int size, bool vi[]) {
	if (answer.size() == size) {
		for (auto num : answer) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < sequence.size(); i++) {
		if (vi[i]) continue;
		vi[i] = true;
		answer.push_back(sequence[i]);
		f(sequence, answer, size, vi);
		answer.pop_back();
		vi[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> sequence;
	int numbers, size;
	cin >> numbers >> size;
	for (int i = 0, tmp; i < numbers; i++) {
		cin >> tmp;
		sequence.push_back(tmp);
	}

	sort(sequence.begin(), sequence.end());

	bool vi[10];
	memset(vi, false, sizeof(vi));
	vector<int> answer;
	f(sequence, answer, size, vi);
}
