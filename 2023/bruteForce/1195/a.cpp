#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int toInt(char ch) {
	return ch - '0';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string gearPart1, gearPart2;
	cin >> gearPart1 >> gearPart2;
	if (gearPart1.size() < gearPart2.size()) swap(gearPart1, gearPart2);
	int gearPart1Size = gearPart1.size(), gearPart2Size = gearPart2.size();

	int maxLength = gearPart1Size + gearPart2Size;
	int minLength = maxLength;

	for (int i = 0; i < gearPart1Size; i++) {
		bool possible = true;
		for (int k = 0, ii = i; k < gearPart2Size && ii <= gearPart1Size; k++, ii++) {
			int part1 = toInt(gearPart1[ii]), part2 = toInt(gearPart2[k]);
//			cout << "part1: " << part1 << ", " << ii << endl
//				<< "part2: " << part2 << ", " << k << endl << endl;
			if (part1 + part2 == 4) {
				possible = false;
				break;
			}
		}
		if (possible) {
			int restLength = gearPart1.size() - i;
			if (restLength >= gearPart2.size()) {
				minLength = min(minLength, gearPart1Size);
			} else {
				int tmp = gearPart1Size + (gearPart2Size - restLength);
				minLength = min(minLength, tmp); 
			}
		}
	}


	for (int i = 0; i < gearPart2Size; i++) {
		bool possible = true;
		for (int k = 0, ii = i; k < gearPart1Size && ii <= gearPart2Size; k++, ii++) {
			int part2 = toInt(gearPart2[ii]), part1 = toInt(gearPart1[k]);
//			cout << "part1: " << part1 << ", " << ii << endl
//				<< "part2: " << part2 << ", " << k << endl << endl;
			if (part1 + part2 == 4) {
				possible = false;
				break;
			}
		}
		if (possible) {
			int restLength = gearPart2.size() - i;
			if (restLength >= gearPart1.size()) {
				minLength = min(minLength, gearPart2Size);
			} else {
				int tmp = gearPart2Size + (gearPart1Size - restLength);
				minLength = min(minLength, tmp); 
			}
		}
	}

	cout << minLength;
}
