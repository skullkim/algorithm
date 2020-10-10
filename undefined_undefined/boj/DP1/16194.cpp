#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_CARDS = 1e3 + 10;
	int cards, cache[MAX_CARDS], card[MAX_CARDS];
	memset(cache, 0, sizeof(cache));
	cin >> cards;
	for(int i = 1; i <= cards; i++){
		cin >> card[i];
		cache[i] = card[i];
	}
	for(int i = 1; i <= cards; i++){
		for(int j = 1; j <= i; j++){
			cache[i] = min(cache[i], cache[i - j] + card[j]);
		}
	}
	cout << cache[cards];
}
