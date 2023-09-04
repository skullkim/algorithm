#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int craneNum, boxNum;
	vector<int> cranes;
	vector<int> boxes;

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
	stable_sort(boxes.begin(), boxes.end(), greater<>());

	int ans = 0;
	while (!boxes.empty()) {
		for (int i = 0; i < cranes.size(); i++) {
			for (int k = 0; k < boxes.size(); k++) {
				if (cranes[i] < boxes[k]) continue;
				boxes.erase(boxes.begin() + k);
				break;
			}
		}
		ans++;
	}
	
	cout << ans;
}
