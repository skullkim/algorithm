#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX = 1e6 + 10;
	int cache[MAX];
	memset(cache, 0, sizeof(cache));
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		cache[i] = MAX;
		cache[i] = cache[i - 1] + 1;
		if(i % 2 == 0) cache[i] = min(cache[i], cache[i / 2] + 1);
		if(i % 3 == 0) cache[i] = min(cache[i], cache[i / 3] + 1);
	}
	cout << cache[n];	
}