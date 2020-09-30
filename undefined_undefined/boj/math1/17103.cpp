#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e6 + 10;
	bool cache[MAX_NUM];
	memset(cache, false, sizeof(cache));
	for(int i = 2; i <= MAX_NUM; i++){
		if(!cache[i]){
			for(int j = i + i; j <= MAX_NUM; j += i){
				cache[j] = true;
			}
		}
	}
	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		bool visited[MAX_NUM];
		memset(visited, false, sizeof(visited));
		int ans = 0, target;
		cin >> target;
		for(int i = 2; i <= target; i++){
			if(visited[i] || visited[target - i]) continue;
			if(target - i >= 2 && !cache[i] && !cache[target - i]){
				visited[i] = true; visited[target - i] = true;
				ans++;
			}
		}
		cout << ans << "\n";
	}
}
