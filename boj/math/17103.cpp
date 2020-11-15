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
	bool visited[MAX_NUM];
	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		int ans = 0;
		int target;
		cin >> target;
		memset(visited, false, sizeof(visited));
		for(int i = 2; i <= target; i++){
			if(visited[i] || visited[target - i]) continue;
			if(target - i >= 2 && !prime_num[i] && !prime_num[target - i]){
				visited[i] = true; visited[target - i] = true;
				ans++;
			}		
		}

		cout << ans << "\n";
	}
}
