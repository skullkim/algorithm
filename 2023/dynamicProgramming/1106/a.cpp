#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_COST 100010

typedef pair<int, int> Promotion;

int cache[MAX_COST];

vector<Promotion> promotiones;

int getPeople(Promotion p) {
	return p.first;
}

int getCost(Promotion p) {
	return p.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int minRecruitments, cities;
	cin >> minRecruitments >> cities;

	for (int i = 0, cost, people; i < cities; i++) {
		cin >> cost >> people;
		promotiones.push_back({people, cost});
	}

	for (int i = 0; i < cities; i++) {
		Promotion promotion = promotiones[i];
		for (int cost = 0; cost < MAX_COST; cost++) {
			if (cost - getCost(promotion) >= 0) {
				cache[cost] = max(cache[cost], cache[cost - getCost(promotion)] + getPeople(promotion));
			}
		}
	}

	for (int cost = 0; cost < MAX_COST; cost++) {
		if (cache[cost] >= minRecruitments) {
			cout << cost << "\n";
			return 0;
		}
	}
}
