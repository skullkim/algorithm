#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e6 + 10;
	bool prime_num[MAX_NUM];
	memset(prime_num, false, sizeof(prime_num));
	for(int i = 2; i < MAX_NUM; i++){
		if(!prime_num[i]){
			for(int k = i + i; k < MAX_NUM; k += i){
				prime_num[k] = true;
			}
		}
	}
	int cache[MAX_NUM];
	memset(cache, 0, sizeof(MAX_NUM));
	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		int ans = 0;
		int target;
		cin >> target;
		if(cache[target]){
			cout << cache[target] << "\n";
			continue;
		}
		for(int i = 2; i <= (target / 2); i++){
			if(!prime_num[i] && !prime_num[target - i]) ans++;
		}
		cout << ans << "\n";
		cache[target] = ans; 
	}
}
