#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e6 + 10;
	int min_num, max_num;
	cin >> min_num >> max_num;
	bool cache[MAX_NUM];
	memset(cache, false, sizeof(cache));
	for(int i = 2; i <= MAX_NUM; i++){
		if(!cache[i]){
			for(int j = i + i; j <= MAX_NUM; j += i){
				cache[j] = true;
			}
		}
	}
	while(min_num <= max_num){
		if(!cache[min_num]) cout << min_num << "\n";
		min_num++;
	}
}
