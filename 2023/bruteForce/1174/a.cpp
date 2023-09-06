#include <iostream>
using namespace std;

int cache[100][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int MAX_DIGITS = 10;
	const int MAX_DIGIT = 9;

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++) {
		cache[1][i] = 1;
	}
	
	for (int digit = 2; digit <= MAX_DIGITS; digit++) {
		for (int startNum = 1; startNum <= MAX_DIGIT; startNum++) {
			int d = digit - 1;
			for (int num = startNum - 1; num >= 0; num--) {
				cache[digit][startNum] += cache[d][num];
			}
		}
	}

	if (n <= 10) {
		cout << n - 1 << "\n";
		return 0;
	}
	
	int digits = -1, startNum = -1;
	for (int i = 1; i <= 10; i++) {
		for (int k = 0; k <= 9; k++) {
			if (n - cache[i][k] > 0) {
				n -= cache[i][k];
			} else {
				digits = i;
				startNum = k;
				break;
			}
		}
		if (digits != -1 && startNum != -1) break;
	}

	string ans = to_string(startNum);
	for (int digit = digits - 1; digit >= 1; digit--) {
		for (int num = 0; num < startNum; num++) {
			if (n - cache[digit][num] > 0) {
				n -= cache[digit][num];
			} else {
				ans += to_string(num);
				break;
			}
		}
		if (n == 0) {
			break;
		}
	}
	cout << ans;
}
