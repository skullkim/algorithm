#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_front(i);
	}

	bool drop = true;
	while(dq.size() > 1) {
		if (drop) {
			dq.pop_back();
			drop = false;
		} else {
			int tmp = dq.back();
			dq.pop_back();
			dq.push_front(tmp);
			drop = true;
		}
	}
	cout << dq.back();
}
