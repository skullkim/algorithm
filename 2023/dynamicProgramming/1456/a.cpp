#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_IDX = 1e7;
const int MAX = MAX_IDX * 2;
bool isNotPrime[MAX_IDX];
bool isNotPrime2[MAX_IDX * 2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int start, end;
	cin >> start >> end;

	isNotPrime[0] = true; isNotPrime[1] = true;
	for (int i = 2; i <= MAX ; i++) {
		if (i < MAX_IDX && isNotPrime[i]) continue;
		else if (MAX_IDX <= i && i <= MAX && isNotPrime2[i - MAX_IDX]) continue;

		for (int k = i + i; k <= MAX; k += i) {
			if (k < MAX_IDX && !isNotPrime[k]) {
				isNotPrime[k] = true;
			}
			else if (MAX_IDX <= k && k <= MAX && !isNotPrime2[k - MAX_IDX]) {
				isNotPrime2[k - MAX_IDX] = true;
			}
		}
	}

	int ans = 0;
	for (int i = start; i <= end; i++) {
		if (i < MAX_IDX && isNotPrime[i]) continue;
		else if (MAX_IDX <= i && i <= MAX && isNotPrime2[i - MAX_IDX]) continue;
		int sqrtVal = (int)sqrt(i);
		double isNumber = sqrt(i) - sqrtVal;
		cout << sqrtVal << endl;
		if (isNumber > 0) continue;
		if (sqrtVal < MAX_IDX && isNotPrime[sqrtVal]) continue;
		else if (MAX_IDX <= sqrtVal && sqrtVal <= MAX && isNotPrime2[sqrtVal - MAX_IDX]) continue;
		cout << i << endl;
		ans++;
	}
	cout << ans;
}
