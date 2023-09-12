#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int classNum;
	cin >> classNum;
	
	vector<pair<int, int>> classes(classNum);
	for (int i = 0, tmp, start, end; i < classNum; i++) {
		cin >> tmp >> start >> end;
		pair<int, int> schedule = make_pair(start, end);
		classes[i] = schedule;
	}

	stable_sort(classes.begin(), classes.end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	int ans = 0;
//	for (int i = 0; i < classNum; i++) {
//		pq.push(classes[i]);
//	}
//	while (!pq.empty()) {
//		cout << pq.top().first << " " << pq.top().second << endl;
//		pq.pop();
//	}
	for (int i = 0; i < classNum; i++) {
		if (pq.empty()) {
			pq.push(classes[i]);
			int s = pq.size();
			ans = max(ans, s);
			continue;
		}
//		cout << pq.top().first << " " << pq.top().second
//			<< " " << classes[i].first << " " << classes[i].second << endl;
		if(pq.top().second <= classes[i].first) {
			pq.pop();
		}
		pq.push(classes[i]);
		int s = pq.size();
		ans = max(ans, s);
	}

	cout << ans;
}
