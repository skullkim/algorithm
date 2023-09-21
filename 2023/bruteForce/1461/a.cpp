#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int bookNum, maxCarry;
	cin >> bookNum >> maxCarry;

	vector<int> booksPosition;
	booksPosition.push_back(0);
	for (int i = 0, position; i < bookNum; i++) {
		cin >> position;
		booksPosition.push_back(position);
	}

	sort(booksPosition.begin(), booksPosition.end());

	int firstPosition;
	for (int i = 0; i < booksPosition.size(); i++) {
		if (booksPosition[i] != 0) continue;
		firstPosition = i;
	}

	long long minSteps = 0;
	for (int i = 0; i < firstPosition; i += maxCarry) {
		minSteps += (abs(booksPosition[i]) * 2);
	}

	for (int i = booksPosition.size() - 1; i > firstPosition; i -= maxCarry) {
		minSteps += (booksPosition[i] * 2);
	}

	minSteps -= max(abs(booksPosition[0]), booksPosition.back());
	cout << minSteps;
}
