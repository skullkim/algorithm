#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int n, minN, maxN, x, ans = 0;
vector<ll> v;

void f(int idx, vector<int> t, ll sum, ll maxNN, ll minNN) {
	if (t.size() > n || sum > maxN) return;
	if (t.size() <= n && minN <= sum && sum <= maxN && (maxNN - minNN) >= x) {
		ans++;
		return;
	}

	for (int i = idx; i < n; i++) {
		t.push_back(v[i]);
		f(i + 1, t, sum + v[i], max(maxNN, v[i]), min(minNN, v[i]));
		t.pop_back();
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
	f(0, t, 0, 0, 9876543210);
	cout << ans;
}
