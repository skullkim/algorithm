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

long long currTarget, currAmount = 0;

void f() {
	if (currTarget <= 0) {
		answer = min(currAmount, answer);
		return;
	}

	currTarget -= f1.flowers; currAmount += f1.amount;
	f();
	currTarget += f1.flowers; currAmount -= f1.amount;

	currTarget -= f2.flowers; currAmount += f2.amount;
	f();
	currTarget += f2.flowers; currAmount -= f2.amount;
}

int main(void) {
	ios_base::sync_with_stdio(false);

	int flowers, amount;
	cin >> target;
	cin >> flowers >> amount;
	f1 = {flowers, amount};
	cin >> flowers >> amount;
	f2 = {flowers, amount};

	currTarget = target;

	f();
	cout << answer;
}
