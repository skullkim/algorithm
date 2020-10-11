#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_LEN = 95;
	long long cache[MAX_LEN];
	memset(cache, 0, sizeof(cache));
	int len;
	cin >> len;
	cache[1] = 1; cache[2] = 1; cache[3] = 2;
	for(int i = 4; i <= len; i++){
		for(int k = i - 2 ; k >= 0; k--) cache[i] += cache[k];
		cache[i]++;
	}
	cout << cache[len];
}
