#include <bits/stdc++.h>

using namespace std;

int n, minN, maxN, x, ans = 0;
bool vi[17];
vector<int> v;

void f(int idx, vector<int> t, int sum, int maxNN, int minNN) {
	if (t.size() > n || sum > maxN) return;
	if (2 <= t.size() && t.size() <= n 
			&& minN <= sum && sum <= maxN 
			&& (maxNN - minNN) >= x) {
		ans++;
		return;
	}

	for (int i = idx; i < n; i++) {
		if (vi[i]) continue;
		vi[i] = true;
		t.push_back(v[i]);
		f(i + 1, t, sum + v[i], max(maxNN, v[i]), min(minNN, v[i]));
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
	f(0, t, 0, 0, 987654321);
	cout << ans;
}
