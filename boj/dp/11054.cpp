#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_LEN = 1e3 + 10;
	int cache_lds[MAX_LEN], cache_lis[MAX_LEN];
	memset(cache_lds, 0, sizeof(cache_lds));
	memset(cache_lis, 0, sizeof(cache_lis));
	int len, seq[MAX_LEN];
	cin >> len;
	for(int i = 0; i < len; i++) cin >> seq[i];
	int max_len = 1, max_rev_len = 1;

	for(int i = 0; i < len; i++){
		cache_lis[i] = 1;
		for(int k = 0; k < i; k++){
			if(seq[k] < seq[i] && cache_lis[k] + 1 > cache_lis[i]){
				cache_lis[i] = cache_lis[k] + 1;
			}
		}
	}

	for(int i = len - 1; i >= 0; i--){
		cache_lds[i] = 1;
		for(int k = len - 1; k > i; k--){
			if(seq[k] < seq[i] && cache_lds[k] + 1 > cache_lds[i]){
				cache_lds[i] = cache_lds[k] + 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < len; i++){
		ans = max(ans, cache_lds[i] + cache_lis[i] - 1);
	}
	cout << ans;
}
