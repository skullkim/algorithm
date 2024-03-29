#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int checkPoints, travlers;
	vector<ll> waitingTimes;

	ll maxWaitingTimes = -1, tmp;
	cin >> checkPoints >> travlers;
	for (int i = 0; i < checkPoints; i++) {
		cin >> tmp;
		waitingTimes.push_back(tmp);
		maxWaitingTimes = max(maxWaitingTimes, tmp);
	}

	ll start = 1, end = maxWaitingTimes * travlers, mid, ans;
	while (start <= end) {
		mid = (start + end) / 2;

		ll availableWaitings = 0;
		for (int i = 0; i < checkPoints; i++) {
			availableWaitings += (mid / waitingTimes[i]);
			if (availableWaitings >= maxWaitingTimes * travlers) {
				availableWaitings = (maxWaitingTimes * travlers);
				break;
			}
		}
		//cout << start << " " << mid << " " << end << " " << availableWaitings << endl;

		if (availableWaitings >= travlers) {
			ans = mid;
			end = mid - 1;
		}		
		else start = mid + 1;
	}
	cout << ans;
}
