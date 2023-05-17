#include <iostream>
#include <cstring> 
#include <cmath>
typedef long long ll;

using namespace std;

const int MAX_IDX = 1e7 + 1;
bool isPrime[MAX_IDX];
bool vi[MAX_IDX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int start, end;
	cin >> start >> end;
	

	isPrime[0] = true; isPrime[1] = true;
	for (ll i = 2; i < MAX_IDX; i++) {
		if (isPrime[i]) continue;
		for (ll k = i * i; k < MAX_IDX; k += i) isPrime[k] = true;
	}

	int ans = 0;
	for (ll k = 2; k < MAX_IDX; k++) {
		if (k * k > end) break;
		if (isPrime[k]) continue;
		ll prime = k * k;
		while(prime <= end) {
			if (start <= prime) {
				ans++;
			}
			prime *= k;
			if (prime % k != 0) break;
		}
	}
	cout << ans;
}
