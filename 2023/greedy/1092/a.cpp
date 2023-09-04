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
	list<int> boxes;

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
	boxes.sort(greater<>());

	int ans = 0;
	while (!boxes.empty()) {
		for (int i = 0; i < craneNum; i++) {
			int craneWeight = cranes[i];
			list<int>::iterator start = boxes.begin();
			for (list<int>::iterator box = start; box != boxes.end(); box++) {
				if (*box <= craneWeight)  {
					list<int>::iterator it = box;
					box--;
					start = box;
					boxes.erase(it);
					break;
				}
			}
		}
		ans++;
	}
	
//	while (!boxes.empty()) {
//		for (int i = 0; i < craneNum && !boxes.empty(); i++) {
//			int craneWeight = cranes[i];
//			if (boxes.front() <= craneWeight) {
//				cout << craneWeight << " " << boxes.front() << endl;
//				boxes.pop_front();
//			}
//		}
//		cout << "===================" << endl;
//		ans++;
//	}

	cout << ans;
}
