#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_LEN = 105;
	const int MOD = 1e9;
	int len;
	int cache[MAX_LEN][11];
	memset(cache, 0, sizeof(cache));
	cin >> len;
	for(int i = 1; i <= 9; i++) cache[1][i] = 1;
	for(int i = 2; i <= len; i++){
		for(int k = 0; k <= 9; k++){
 			cache[i][k] = (cache[i - 1][k - 1] + cache[i - 1][k + 1]) % MOD;
		}
	}
	long long ans = 0;
	for(int i = 0; i <= 9; i++) ans = (ans + cache[len][i]) % MOD;
	cout << ans;
}
