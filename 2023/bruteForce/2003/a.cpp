#include <iostream>
#include <vector>

using namespace std;

int n, target;
vector<int> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> target;
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	int start = 0, end = 0;
	int sum = 0, ans = 0;;
	while(start < n) {
		if (sum < target && end < n) sum += v[end++];
		else if (sum == target) {
			ans++;
			sum -= v[start++];
		}
		else sum -= v[start++];
	}

	cout << ans;
}
