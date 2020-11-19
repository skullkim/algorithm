#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_LEN = 1e3 + 10;
	int cache[MAX_LEN];
	memset(cache, 0, sizeof(cache));
	int len, seq[MAX_LEN];
	cin >> len;
	for(int i = 0; i < len; i++) cin >> seq[i];
	int max_len = -1, max_rev_len = -1;
	for(int i = 0; i < len; i++){
		cache[i] = 0;
		for(int k = 0; k < i; k++){
			if(seq[k] < seq[i] && cache[k] + 1 > cache[i]){
				cache[i] = cache[k] + 1;
				max_len = max(cache[i], max_len);	
			}
		}
	}
	memset(cache, 0, sizeof(cache));
	for(int i = len - 1; i >= 0; i--){
		cache[i] = 0;
		for(int k = len - 1; k > i; k--){
			if(seq[k] > seq[i] && cache[k] + 1 > cache[i]){
				cache[i] = cache[k] + 1;
				max_rev_len = max(cache[i], max_rev_len);
			}
		}
	}
	cout << max_len + max_rev_len - 1;
}
