#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_CARDS = 1e3 + 10;
int card[MAX_CARDS], cache[MAX_CARDS];
int cards;

void payMaxCost(int bought, int cost){
	if(bought > cards) return;
	cache[bought] = max(cache[bought], cost);
	for(int i = 1; i <= cards; i++){
		payMaxCost(bought + i, cost + card[i]);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> cards;
	for(int i = 1; i <= cards; i++) cin >> card[i];
	payMaxCost(0, 0);
	cout << cache[cards];
}
