#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void f(vector<int> sequence, int maxNumber, int length, bool vi[]) {
	if (sequence.size() == length) {
		for (auto num : sequence) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = sequence.empty() ? 1 : sequence.back() + 1; i <= maxNumber; i++) {
		sequence.push_back(i);
		f(sequence, maxNumber, length, vi);
		sequence.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int maxNumber, length;
	cin >> maxNumber >> length;

	bool vi[10];
	memset(vi, false, sizeof(vi));
	vector<int>sequence;
	f(sequence, maxNumber, length, vi);
}
