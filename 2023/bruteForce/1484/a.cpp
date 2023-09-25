#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

bool isNaturalNumber(ll number) {
//cout << number << "\n";
	double rootNaturalNumber = (ll)sqrt(number);
	double rootNumber = sqrt(number);
//	cout << rootNaturalNumber << " " 
//		<< rootNumber << " " 
//		<< ((double)rootNaturalNumber == rootNumber) 
//		<< "\n";
	return ((double)rootNaturalNumber == rootNumber);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int MAX_WEIGHT = 1e6;

	int g;
	cin >> g;

	vector<ll> answer;
	for (ll currWeight = 1; currWeight < MAX_WEIGHT; currWeight++) {
		ll powCurrWeight = currWeight * currWeight;
		ll powPreviousWeight = powCurrWeight - g;
		if (powPreviousWeight <= 0 || !isNaturalNumber(powCurrWeight) || !isNaturalNumber(powPreviousWeight)) {
			continue;
		}
		//cout << powCurrWeight << "\n";
		answer.push_back(currWeight);
	}

	if (!answer.size()) {
		cout << -1 << "\n";
		return 0;
	}

	for (auto ans : answer) cout << ans << "\n";
}
