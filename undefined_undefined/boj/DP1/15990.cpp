#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e5 + 10;
	const int MOD = 1e9 + 9;
	const int SUM = 4;
	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		int num, cache[MAX_NUM][5];
		memset(cache, 0, sizeof(cache));
		cin >> num;
		cache[1][1] = 1; cache[1][2] = 0; cache[1][3] = 0; cache[1][SUM] = 1;
		cache[2][1] = 0; cache[2][2] = 1; cache[2][3] = 0; cache[2][SUM] = 1;
		cache[3][1] = 1; cache[3][2] = 1; cache[3][3] = 1; cache[3][SUM] = 3;
		for(int i = 4; i <= num; i++){
			cache[i][1] = cache[i - 1][2] + cache[i - 1][3];
			cache[i][2] = cache[i - 2][1] + cache[i - 2][3];
			cache[i][3] = cache[i - 3][1] + cache[i - 3][2];
			cache[i][SUM] = cache[i][1] + cache[i][2] + cache[i][3];
		}
		cout << cache[num][SUM] << "\n";
	}
}
