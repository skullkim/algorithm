#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> numbers;
	cin >> n;
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}

	int moves;
	cin >> moves;

	for (int target = 0; target < n && moves > 0; target++) {
		pair<int, int> maxVal = make_pair(numbers[target], target);
		for (int i = target + 1; i <= target + moves && i < n; i++) {
			if (maxVal.first >= numbers[i]) continue;
			maxVal = make_pair(numbers[i], i);
		}
		for (int k = maxVal.second; k > target; k--) {
			swap(numbers[k], numbers[k - 1]);
			moves--;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << " ";
	}
}
