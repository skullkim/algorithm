#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int videoNum, blueRaies;
	vector<int> videos;

	cin >> videoNum >> blueRaies;
	int limit = 0, tmp2 = 0;
	for (int i = 0, tmp; i < videoNum; i++) {
		cin >> tmp;
		videos.push_back(tmp);
		tmp2 += videos[i];
	}

	int start = 0, end = tmp2;
	int mid;
	int tmp, usedBlueraies;
	while (start <= end) {
		mid = (start + end) / 2;

		tmp = 0;
		usedBlueraies = 1;
		for (int i = 0; i < videoNum; i++) {
			if (tmp + videos[i] > mid) {
				usedBlueraies++;
				tmp = 0;
			}
			tmp += videos[i];
		}

//cout << start << " " << mid << " " << end << " " << usedBlueraies << endl;

		if (usedBlueraies > blueRaies) {
			start = mid + 1;
		} else if (usedBlueraies <= blueRaies) {
			end = mid - 1;
		}
	}
	cout << start;
}
