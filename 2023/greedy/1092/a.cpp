#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int craneNum, boxNum;
	vector<int> cranes, boxes;

	int craneMaxWeight = -1;
	cin >> craneNum;
	for (int i = 0, tmp; i < craneNum; i++) {
		cin >> tmp;
		cranes.push_back(tmp);
		craneMaxWeight = max (craneMaxWeight, tmp);
	}

	int boxMaxWeight = -1;
	cin >> boxNum;
	for (int i = 0, tmp; i < boxNum; i++) {
		cin >> tmp;
		boxes.push_back(tmp);
		boxMaxWeight = max(boxMaxWeight, tmp);
	}

	if (craneMaxWeight < boxMaxWeight) {
		cout << -1 << "\n";
		return 0;
	}

	stable_sort(cranes.begin(), cranes.end(), greater<>());
	stable_sort(boxes.begin(), boxes.end());

	bool vi[boxes.size()];
	memset(vi, false, sizeof(vi));
	int totalBoxes = boxes.size();
	int ans = 0;
	while (totalBoxes > 0) {
		for (int c = 0; c < craneNum; c++) {
			int craneWeight = cranes[c];
			auto it = lower_bound(boxes.begin(), boxes.end(), craneWeight);
			int idx = (it - boxes.begin());
			if (idx >= boxes.size()) idx = boxes.size() - 1;
			while(vi[idx]) idx--;
			if (boxes[idx] <= craneWeight) {
				vi[idx] = true;
				totalBoxes--;
			}
		}
		ans++;
	}
	cout << ans << "\n";
}
