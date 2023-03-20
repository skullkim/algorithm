#include <bits/stdc++.h>
using namespace std;

int meP, broP;
bool vi[100100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> meP >> broP;
	queue<pair<int, int>> q;
	pair<int, int> tmp = make_pair(meP, 0);
	q.push(tmp);
	while(!q.empty()) {
		pair<int, int> currP = q.front();
		q.pop();
		vi[currP.first] = true;
		if (currP.first == broP) {
			cout << currP.second;
			return 0;
		}
		int arr[] = {currP.first -1, currP.first + 1, currP.first * 2};
		for (int i = 0; i < 3; i++) {
			int p = arr[i];
			if (0 > p || p > 100000 || vi[p]) continue;
			pair<int, int> t = make_pair(p, currP.second + 1);
			q.push(t);
		}
	}
	return 0;
}
