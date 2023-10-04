#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void f(vector<int> sequence, int maxNumber, int length) {
	if (sequence.size() == length) {
		for (auto number : sequence) {
			cout << number << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= maxNumber; i++) {
		sequence.push_back(i);
		f(sequence, maxNumber, length);
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
	vector<int> sequence;
	f(sequence, maxNumber, length);
}
