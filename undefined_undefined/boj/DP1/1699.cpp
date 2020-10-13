#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e5 + 10;
	int num, cache[MAX_NUM];
	memset(cache, 0, sizeof(cache));
	cin >> num;
	vector<int> sqrt_num;
	cache[1] = 1; cache[2] = 2; cache[3] = 3;
	for(int i = 4; i <= num; i++){
		if(sqrt((double)i) == (int)sqrt((double)i)){
			sqrt_num.push_back(i);
			cache[i]++;
		}
		else{
			int min_val = MAX_NUM;
			for(int k = 0; k < sqrt_num.size(); k++){
				min_val = min(min_val, cache[i - sqrt_num[k]]);
			}
			cache[i]++;
			cache[i] += min_val;
		}
	}
	cout << cache[num];
}
