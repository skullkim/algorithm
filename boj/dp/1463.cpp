#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 10;
int cache[MAX];
int n;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 2; i <= n; i++){
		cache[i] = cache[i - 1] + 1;
		if(i % 3 == 0) cache[i] = min(cache[i / 3] + 1, cache[i]);
		else if(i % 2 == 0) cache[i] = min(cache[i / 2] + 1, cache[i]);
	}
	cout << cache[n];
}
