#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_CARDS = 1e3 + 10;
int card[MAX_CARDS], cache[MAX_CARDS];
int cards;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> cards;
	for(int i = 1; i <= cards; i++) cin >> card[i];
	for(int i = 1; i <= cards; i++){
		for(int j = 1; j <= i; j++){
			cache[i] = max(cache[i], cache[i - j] + card[j]);
		}
	}
	cout << cache[cards];
}
