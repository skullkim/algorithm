#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> Stuff;

const int INF = 987654321;

int getWeight(Stuff st) {
	return st.first;
}

int getValue(Stuff st) {
	return st.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int stuffNum, maxWeight;
	cin >> stuffNum >> maxWeight;
	vector<Stuff> stuffs(stuffNum + 1);
	stuffs[0] = make_pair(0, 0);
	for (int i = 1, weight, value; i <= stuffNum; i++) {
		cin >> weight >> value;
		pair<int, int> stuff = make_pair(weight, value);
		stuffs[i] = stuff;
	}
		
	int cache[stuffNum + 1][maxWeight + 1];
	memset(cache, 0, sizeof(cache));

//	for (int i = 0; i < stuffNum; i++) {
//		cache[i][0] = 0;
//	}
//
//	for (int i = 0; i < maxWeight; i++) {
//		cache[0][i] = 0;
//	}

	for (int stuff = 1; stuff <= stuffNum; stuff++) {
		for (int weight = 1; weight <= maxWeight; weight++) {
			if (getWeight(stuffs[stuff]) > weight) {
				cache[stuff][weight] = cache[stuff - 1][weight];
			} else {
				int addedStuff = cache[stuff - 1][weight - getWeight(stuffs[stuff])] + getValue(stuffs[stuff]);
				cache[stuff][weight] = max(cache[stuff - 1][weight], addedStuff);
			}
		}
	}
	
	cout << cache[stuffNum][maxWeight];
}
