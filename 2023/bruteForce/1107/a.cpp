#include <iostream>
using namespace std;

const int MAX_CHANNEL = 1000000;

int target;
int brokenNumbers;
bool isBroken[12];

int getTheNumberOfPressed(int channel) {
	if (channel == 0) return isBroken[channel] ? -1 : 1;

	int pressed = 0;
	while (channel > 0) {
		if (isBroken[channel % 10]) return -1;
		pressed++;
		channel /= 10;
	}
	return pressed;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> target >> brokenNumbers;
	for (int i = 0, tmp; i < brokenNumbers; i++) {
		cin >> tmp;
		isBroken[tmp] = true;
	}
	
	int ans = abs(target - 100);

	for (int i = 0; i < 1000000; i++) {
		int pressed = getTheNumberOfPressed(i);		
		if (pressed > 0) {
			pressed += abs(target - i);
			ans = min(ans, pressed);
		}
	}
	cout << ans;
}
