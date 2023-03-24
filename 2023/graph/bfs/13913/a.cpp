#include <bits/stdc++.h>
#define pvi pair<vector<int>, int> 
using namespace std;

const int MAX = 100100;
int meP, broP;
bool vi[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> meP >> broP;
	
	queue<pvi> q;
	vector<int> tmp;
	tmp.push_back(meP);
	pvi p = make_pair(tmp, 0);
	q.push(p);
	while(!q.empty()) {
		pvi pv = q.front();
		vi[pv.first.back()] = true;
		q.pop();
		if (pv.first.back() == broP) {
			cout << pv.second << "\n";
			for (int i = 0; i < pv.first.size(); i++) {
				cout << pv.first[i] << " ";
			}
			return 0;
		}
		int currP = pv.first.back();

//		if (pv.first.size() == 5) {
//			for (int i = 0; i < pv.first.size(); i++) {
//				cout << pv.first[i] << " ";
//			}
//			cout << endl;
//			cout << "=======================================" << endl;
//		}
		
		int arr[] = {currP + 1, currP -1, currP * 2};
		for (int i = 0; i < 3; i++) {
			int nextP = arr[i];
			if (0 > nextP || nextP > 100000 || vi[nextP]) continue;
			vi[nextP] = true;
//			vector<int> v (pv.first.begin(), pv.first.end());
			vector<int> v = pv.first;
			v.push_back(nextP);
			pvi tp = make_pair(v, pv.second + 1);
			q.push(tp);
		}
	}
}
