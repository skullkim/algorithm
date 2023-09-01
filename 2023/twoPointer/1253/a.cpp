#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}

	stable_sort(numbers.begin(), numbers.end());

	int ans = 0;
	for (int i = 0, target; i < n; i++) {
		target = numbers[i];
		int start = 0, end = n - 1;
		while (true) {
			if (numbers[start] == target) start++;
			if (numbers[end] == target) end--;
			if (start >= end) break;

			int sum = numbers[start] + numbers[end];
			if(sum <= target) {
				if (sum == target) {
					ans++;
					break;
				}
				start++;
			}
			else end--;
		}
	}

	cout << ans;
}
