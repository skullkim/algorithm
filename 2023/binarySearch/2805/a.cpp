#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll treeNum, targetAmount;
	vector<ll> trees;

	ll start = 0, end = 0;
	ll tmp;
	cin >> treeNum >> targetAmount;
	for (int i = 0; i < treeNum; i++) {
		cin >> tmp;
		trees.push_back(tmp);
		end = max(end, tmp);
	}

	pair<ll, ll> ans = make_pair(0, 1e9 + 2);
	ll mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		ll sum = 0;
		for (int i = 0; i < treeNum; i++) {
			if ((trees[i] - mid) <= 0) continue;
			sum += (trees[i] - mid);
		}
		
		if (sum < targetAmount) {
			end = mid - 1;
		} else if (sum > targetAmount) {
			start = mid + 1;
			if (ans.second > sum) {
				ans.first = mid;
				ans.second = sum;
			}
		} else {
			ans.first = mid;
			break;
		}
	}
	cout << ans.first;
}
