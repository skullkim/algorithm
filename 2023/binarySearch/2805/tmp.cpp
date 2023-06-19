#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> nums;
	for (int i = 1; i <= 10; i++) {
		nums.push_back(i * 2);
	}

	int target;
	cin >> target;

	int start = 0, end = nums.size() - 1;
	while(start <= end) {
		int mid = (start + end) / 2;
		cout << start << " " << mid << " " << end << endl;
		if (target < nums[mid]) {
			end = mid - 1;
		} else if (target > nums[mid]) {
			start = mid + 1;
		} else {
			cout << "found" << "\n";
			break;
		}
	}
}
