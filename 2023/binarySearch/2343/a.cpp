#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int videoNum, blueRaies;
	vector<int> videos;

	cin >> videoNum >> blueRaies;
	int limit = 0;
	for (int i = 1, tmp, tmp2 = 0; i <= videoNum; i++) {
		cin >> tmp;
		videos.push_back(tmp);
		tmp2 += videos[i - 1];
		if (i >= blueRaies) {
			tmp2 -= videos[i - blueRaies - 1];
			limit = max(limit, tmp2);
		}
	}

	long long start = 0, end = limit;
	long long ans = 1e10 + 2;
	while (start <= end) {
		long long mid = (start + end) / 2;

		long long tmp = 0;
		int usedBlueraies = 0;
		for (int i = 0; i < videoNum; i++) {
			if (tmp + videos[i] > mid) {
				usedBlueraies++;
				tmp = 0;
				continue;
			}
			tmp += videos[i];
		}

		cout << start << " " << mid << " " << end << " " << usedBlueraies << endl;

		if (usedBlueraies > blueRaies) {
			start = mid + 1;
		} else if (usedBlueraies <= blueRaies) {
			if (usedBlueraies == blueRaies) {
				ans = min(ans, mid);
			}
			end = mid - 1;
		}
	}
	cout << ans;
}
