#include <bits/stdc++.h>

using namespace std;

int n, minN, maxN, x, ans = 0;
bool vi[17];
vector<int> v;

int findMax(vector<int> t) {
	int n = 0;
	for (int i = 0; i < t.size(); i++) {
		n = max(n, t[i]);
	}
	return n;
}

int findMin(vector<int> t) {
	int n = 987654321;
	for (int i = 0; i < t.size(); i++) {
		n = min(n, t[i]);
	}
	return n;
}

void f(int idx, vector<int> t, int sum) {
	if (t.size() > n || sum > maxN) return;
	if (2 <= t.size() && t.size() <= n 
			&& minN <= sum && sum <= maxN) {
		int curMin = findMin(t);
		int curMax = findMax(t);
		if ((curMax - curMin) >= x) {
			ans++;
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		if (vi[i]) continue;
		vi[i] = true;
		t.push_back(v[i]);
		f(i + 1, t, sum + v[i]);
		t.pop_back();
		vi[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> minN >> maxN >> x;
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	vector<int> t;
	f(0, t, 0);
	cout << ans;
}
