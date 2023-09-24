#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<double, pair<int, int>> Promotion;

int getPeople(Promotion p) {
	return p.second.first;
}

int getCost(Promotion p) {
	return p.second.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int minRecruitments, cities;
	cin >> minRecruitments >> cities;

	vector<Promotion> promotiones;
	for (int i = 0, people, cost; i < cities; i++) {
		cin >> cost >> people;
		pair<int, int> p = make_pair(people, cost);
		Promotion promotion = make_pair((double)people / cost, p);
		promotiones.push_back(promotion);
	}

	sort(promotiones.begin(), promotiones.end());

	Promotion efficientPromotion = promotiones.back();
	int recruitable = minRecruitments / getPeople(efficientPromotion);

	int restRecruitments = minRecruitments - getPeople(efficientPromotion) * recruitable;
	int usedAmount = recruitable * getCost(efficientPromotion);

	if (restRecruitments <= 0) {
		cout << usedAmount << "\n";
		return 0;
	}

	int totalUsedAmount = usedAmount + getCost(efficientPromotion);
//	cout << "restRecruitments: " << restRecruitments << " " << "usedAmount: " << usedAmount << endl;
	for (int i = 0; i < promotiones.size() - 1; i++) {
		Promotion promotion = promotiones[i];
		int amount = ceil((double)restRecruitments / getPeople(promotion)) * getCost(promotion);
//		cout << "people: " << getPeople(promotion) << " " 
//			<< "cost: " << getCost(promotion) << " "
//			<< "amount: " << amount << endl;
//		cout << totalUsedAmount << " " << usedAmount + amount << endl;
//		cout << "===========================================" << endl;
		totalUsedAmount = min(totalUsedAmount, usedAmount + amount);
	}
	cout << totalUsedAmount;
	//cout << getPeople(efficientPromotion) * recruitable << " " << restRecruitments << " " << usedAmount;
}
