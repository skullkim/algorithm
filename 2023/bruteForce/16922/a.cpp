#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

const int MAX = INT_MAX;
int n, ans = 0, sum = 0;
int arr[4] = {1, 5, 10, 50};
bool vi[INT_MAX];

void f(int currNum, int size) {
	if (size == n) {
		if (!vi[sum]) {
			ans++;
			vi[sum] = true;
		}
		return;
	}

	for (int i = currNum; i < 4; i++) {
		sum += arr[i];
		f(i, size + 1);
		sum -= arr[i];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(vi, false, sizeof(vi));

	cin >> n;
	f(0, 0);
	cout << ans;
}
