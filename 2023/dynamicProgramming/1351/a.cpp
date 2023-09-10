#include <iostream>
#include <map>
using namespace std;

const int MAX_IDX = 1e12 + 1;

map<int, int> cache;
int n, p, q;

int f(int idx) {
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
}
