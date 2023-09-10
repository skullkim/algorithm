#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

map<ll, ll> cache;
ll n, p, q;

ll f(ll idx) {
	if (cache[idx]) return cache[idx];

	cache[idx] = f(idx / p) + f(idx / q);
	return cache[idx];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p >> q;
	cache[0] = 1;
	cout << f(n);
	return 0;
}
