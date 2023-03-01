#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int ans = INF;
int first, t;

void f(int currNum, int cnt) {
	if (currNum > t) return;
	if (currNum == t) {
		ans = min(ans, cnt);
		return;
	}

	f(currNum * 2, cnt + 1);
	f(currNum * 10 + 1, cnt + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> first >> t;
	f(first, 0);

	ans == INF ? cout << -1 : cout << ans + 1;
}
