#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int row, col, ans = 0, maxSize = 0;
vector<pii> stickers, st;
bool vi[110];

bool compareSize(pii f, pii s) {
	pii tmp = make_pair(max(f.first, s.first), max(f.second, s.second));
	return (f.first+s.first <= row && f.second+s.second <= col)
		|| (f.first+s.first <= row && tmp.second <= col)
		|| (f.second+s.second <= col && tmp.first <= row);
}

void f(int size) {
	if (st.size() == 2) {
		pii f = st[0];
		pii s = st[1];
		pii rf = make_pair(f.second, f.first);
		pii rs = make_pair(s.second, s.first);
		if (size > maxSize) return;
		if (compareSize(f, s)
				|| compareSize(f, rs)
				|| compareSize(rf, s)
				|| compareSize(rf, rs)) {
			ans = max(size, ans);
		}
		return;
	}

	for (int i = 0; i < stickers.size(); i++) {
		if (vi[i]) continue;
		int stickerSize = stickers[i].first * stickers[i].second;
		vi[i] = true;
		st.push_back(stickers[i]);
		f(size + stickerSize);
		st.pop_back();
		vi[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> row >> col;
	maxSize = row * col;
	int n;
	cin >> n;
	for (int i = 0, r, c; i < n; i++) {
		cin >> r >> c;
		if (r * c > row * col) continue;
		stickers.push_back(make_pair(r, c));
	}
	if (stickers.size() >= 2) f(0);
	cout << ans;
}
