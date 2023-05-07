#include <iostream>
#include <algorithm>

using namespace std;

struct Flower {
	int flowers;
	int amount;
};

long long target;
long long answer = 1e+18 + 2;
Flower f1, f2;

void f(long long currTarget, long long currAmount) {
	if (currTarget <= 0) {
		answer = min(currAmount, answer);
		return;
	}

	f(currTarget - f1.flowers, currAmount + f1.amount);
	f(currTarget - f2.flowers, currAmount + f2.amount);
}

int main(void) {
	ios_base::sync_with_stdio(false);

	int flowers, amount;
	cin >> target;
	cin >> flowers >> amount;
	f1 = {flowers, amount};
	cin >> flowers >> amount;
	f2 = {flowers, amount};

	f(target, 0);
	cout << answer;
}
