#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;

using namespace std;

struct Flower {
	ll flowers;
	ll amount;
};

ll target;
ll answer = 1e+18 + 2;
Flower cheaper, expensive;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int flowers, amount;
	cin >> target;
	cin >> flowers >> amount;
	cheaper = {flowers, amount};
	cin >> flowers >> amount;
	expensive = {flowers, amount};

//	cout << target << endl;
//	cout << cheaper.amount << " " << cheaper.flowers << endl;
//	cout << expensive.amount << " " << expensive.flowers << endl;

	if (cheaper.amount*expensive.flowers > cheaper.flowers*expensive.amount) {
		Flower tmp = cheaper;
		cheaper = expensive;
		expensive = tmp;
	}
//	cout << endl;
//	cout << target << endl;
//	cout << cheaper.flowers << " " << cheaper.amount << endl;
//	cout << expensive.flowers << " " << expensive.amount << endl << endl;
	
	for (int i = 0; i < cheaper.flowers; i++) {
		ll bought = (ll) ceil((double) (target - i * expensive.flowers) / cheaper.flowers);
//		cout << bought << " " << i << endl;;
		bool isOver = false;
		if (bought < 0) {
			bought = 0;
			isOver = true;
		}
		answer = min(answer, expensive.amount * i + cheaper.amount * bought);
		if (isOver) break;
	}
	cout << answer;
}
