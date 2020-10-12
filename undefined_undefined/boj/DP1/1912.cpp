#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e5 + 10;
	int num, cache[MAX_NUM], seq[MAX_NUM];
	memset(cache, -MAX_NUM, sizeof(cache));
	cin >> num;
	for(int i = 0; i < num; i++) cin >>	seq[i];
	cache[0] = seq[0];
	int ans = cache[0];
	for(int i = 1; i < num; i++){
		cache[i] = max(seq[i], cache[i - 1] + seq[i]);
		ans = max(ans, cache[i]);
	}
	cout << ans;
}
