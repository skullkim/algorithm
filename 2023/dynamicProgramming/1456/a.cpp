#include <iostream>
#include <cstring> 
#include <cmath>
typedef long long ll;

using namespace std;

const int MAX_IDX = 1e7 + 1;
const int MAX = MAX_IDX * 2;
bool isNotPrime[MAX_IDX];
bool isNotPrime2[MAX_IDX * 2];
bool isPrime[MAX_IDX];
bool vi[MAX_IDX];

//bool isPrime(int num) {
//	if (num < MAX_IDX && isNotPrime[num]) return false;
//	else if (MAX_IDX <= num && num <= MAX && isNotPrime2[num - MAX_IDX]) return false;
//	return true;
//}
//
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int start, end;
	cin >> start >> end;
	
	memset(isPrime, true, sizeof(isPrime));

//	isNotPrime[0] = true; isNotPrime[1] = true;
	isPrime[0] = false; isPrime[1] = false;
	for (ll i = 2; i < MAX_IDX; i++) {
		if (!isPrime[i]) continue;
		for (ll k = i + i; k < MAX_IDX; k += i) isPrime[k] = false;
	}

	int ans = 0;
	for (ll k = 2; k < MAX_IDX; k++) {
		if (!isPrime[k]) continue;
		int prime = k * k;
		if (prime % k != 0) break;
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
