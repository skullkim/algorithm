#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e6 + 10;
	int cache[MAX_NUM];
	memset(cache, 0, sizeof(cache));
	int num;
	cin >> num;
	for(int i = 2; i <= num; i++){
		cache[i] = cache[i - 1] + 1;
		if(i % 3 == 0) cache[i] = min(cache[i / 3] + 1, cache[i]);
		else if(i % 2 == 0) cache[i] = min(cache[i / 2] + 1, cache[i]);
	}
	cout << cache[num];
}
