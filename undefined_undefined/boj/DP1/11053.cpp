#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_LEN = 1e3 + 5;
	int len, cache[MAX_LEN], seq[MAX_LEN];
	memset(cache, 0, sizeof(cache));
	cin >> len;
	int ans = 0;
	for(int i = 1; i <= len; i++) cin >> seq[i];
	for(int i = 1; i <= len; i++){
		cache[i] = 1;
		for(int k = 1; k < i; k++)
			if(seq[k] < seq[i]) cache[i] = max(cache[i], cache[k] + 1);
		ans = max(ans, cache[i]);
	}
	cout << ans;
}
